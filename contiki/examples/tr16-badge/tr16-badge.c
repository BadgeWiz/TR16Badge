/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         TR16 Badge
 * \author
 *         ERNW Badge Team <info@ernw.de>
 */

#include "contiki.h"
#include <stdint.h>
#include <stdio.h>		/* For printf() */
#include <string.h>
#include "lpm.h"
#include "dev/serial-line.h"
#include "button-sensor.h"
#include "ti-lib.h"
#include "pwm.h"
#include "net/packetbuf.h"
#include "sys/clock.h"
#include "sys/rtimer.h"
#include "dev/cc26xx-uart.h"
/*---------------------------------------------------------------------------*/
/* RF core and RF HAL API */
#include "hw_rfc_dbell.h"
#include "hw_rfc_pwr.h"
/*---------------------------------------------------------------------------*/

#include "eeprom.h"
#include "troopers_eeprom.h"
#include "troopers_message_handling.h"
#include "troopers_identity.h"
#include "troopers_agenda.h"
#include "troopers_config.h"
#include "troopers_helpers.h"
#include "troopers_rfc_settings.h"
#include "troopers_rfc_cmd.h"
#include "lcd.h"

#include "badgeName.h"

void print_stored_message(uint8_t index);
void print_queue_data(rfc_dataEntryGeneral_t * dataEntry);

static process_event_t event_display_message, event_received_message,
    event_do_scroll;

static uint8_t is_faked = 0;
static uint8_t solution_str[17] = "i_met_my_trooper";

static uint8_t message[MESSAGELENGTH];
static dataQueue_t q;

static uint8_t solving = 0;
static char solution[17];
static uint8_t input_cnt;

static int16_t timeout = 0;

static uint8_t filling = 0;
static uint8_t tx_buffer_input_length = 0;
static uint8_t tx_buffer[MESSAGELENGTH];
static uint8_t sending = 0;
static uint8_t specan = 0;

void print_queue_data(rfc_dataEntryGeneral_t * dataEntry)
{
	/* view received messages via UART */
	rfc_dataEntryGeneral_t *entry;
	entry = dataEntry;
	printf("Message buffer\n");
	hexdump(&entry->data, PACKETLENGTH);
	printf("\n");
}

void uart_specan()
{
	static rfc_propRxOutput_t rx_stats;
	for (uint8_t f = 0; f < 8; f++) {
		troopers_rfc_init_tune(900 + f, 0);
		troopers_rfc_receive(&q, &rx_stats);
		int8_t rssi = troopers_rfc_get_rssi();
		rssi = rssi + 0x80;
		for (uint8_t i = 0; i < rssi; i++) {
			printf("#");
		}
		printf("\n");
		troopers_rfc_abort();
	}
}

void toggle_identity()
{
	if (is_faked) {
		is_faked = 0x00;
	} else {
		is_faked = 0x01;
	}
}

void print_help()
{
	printf("Hi, I'm your Help-Menue\n");
	printf("'a' for the Agenda\n");
	printf("'i' for your Identity\n");
	if (is_faked) {
		printf("'r' for resolving the naming trouble\n");
		printf("\n\tDetails about the game:\n");
		printf
		    ("\tLooks like you want (or was forced to) solve this challenge.\n");
		printf
		    ("\tIn order to get a token and reset your old name on the badge\n");
		printf
		    ("\tYou have to find the person whos name you see on your badge!\n");
		printf
		    ("\tIf you found her/him, take him to the soldering station with you\n");
		printf
		    ("\tIf the names match Troopers will help you to get you a 'Challenge Token'!\n\n");
	}
	printf("\n'h' for ... I think you already know\n");
}

void print_rfc_status()
{
	setTextSize(5);
	fillScreen(text_bg);
	displayScrollingText(0, -1, "Currently Sending\n");
}

void solve_game()
{
	printf
	    ("To resolve the naming issue find the corresponding person who has your name!\n");
	printf
	    ("If you found them go to the soldering station. They will help you.\n");
	solving = 1;
	input_cnt = 0;
	printf("Press q to quit input\n");
	printf
	    ("Enter the super secret! (Only known at the soldering station)\n");
}

void check_solution()
{
	for (uint8_t i = 0; i < 16; i++) {
		if (solution_str[i] != solution[i]) {
			printf("Wrong answer! :-(\n");
			solving = 0;
			return;
		}
	}
	printf("\n\nSOLVED. Original name will be resetted. \n");
	printf("Trooper deserves the Token!.\n");
	solving = 0;
	is_faked = 0;
	print_current_identity(is_faked);
}

void print_identities()
{
	print_current_identity(is_faked);
}

void fill_tx_buffer(uint8_t c)
{
	if (tx_buffer_input_length < PACKETLENGTH) {
		tx_buffer[tx_buffer_input_length] = c;
	}
	tx_buffer_input_length += 1;
	if ('\n' == c) {
		filling = 0;
		tx_buffer_input_length = 0;
	}
}

void toggle_sending()
{
	if (sending) {
		sending = 0;
	} else {
		sending = 1;
	}
}

void toggle_specan()
{
	if (specan) {
		specan = 0;
	} else {
		specan = 1;
	}
}

int uart_rx_callback(uint8_t c)
{

	if (solving) {
		switch (c) {
		case 'q':
			solving = 0;
			break;
		default:
			if (input_cnt < 16) {
				solution[input_cnt] = c;
				input_cnt++;
				if (input_cnt >= 16)
					check_solution();
			} else {
				check_solution();
			}
			break;
		}
	} else if (filling) {
		fill_tx_buffer(c);
	} else {
		switch (c) {
		case 'a':
			print_agenda();
			break;
		case 'h':
			print_help();
			break;
		case 'p':
			print_queue_data((rfc_dataEntryGeneral_t *) message);
			break;
		case 'i':
			print_current_identity(is_faked);
			break;
		case 'r':
			if (is_faked) {
				solve_game();
			} else {
				printf("Function currently not available!\n");
			}
			break;
		case 's':
			printf("specan\n");
			toggle_specan();
			break;
		case 't':
			filling = 1;
			tx_buffer_input_length = 0;
			printf
			    ("please provide 30 Bytes of data and hit return\n");
			break;
		}
	}
	return 1;
}

/*---------------------------------------------------------------------------*/
PROCESS(output_messages_process, "Output Messages process");
PROCESS(rfcore_process, "RF-Core process");
PROCESS(uart_receive_process, "UART Receive process");
PROCESS(display_pin_process, "Display PIN process");
PROCESS(scroll_process, "Text Scroll process");
/*---------------------------------------------------------------------------*/
AUTOSTART_PROCESSES(&output_messages_process, &rfcore_process,
		    &uart_receive_process, &display_pin_process,
		    &scroll_process);
/*---------------------------------------------------------------------------*/

PROCESS_THREAD(uart_receive_process, ev, data)
{
	PROCESS_BEGIN();
	cc26xx_uart_set_input(uart_rx_callback);

	while (1) {
		PROCESS_YIELD();
	}
	PROCESS_END();
}

PROCESS_THREAD(display_pin_process, ev, data)
{
	PROCESS_BEGIN();
	printf("*** PROCESS_THREAD PIN started ***\n");
	static struct etimer timer;
	static uint8_t button_pressed = 0;
	etimer_set(&timer, CLOCK_SECOND / 3);
	print_identities();
	while (1) {
		if (ti_lib_gpio_pin_read(BOARD_KEY_BACKDOOR)) {
			print_identities();
			printf("Backdoor key pressed on=%u\n", button_pressed);
			toggle_sending();
		}
		PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
		etimer_reset(&timer);
	}
	PROCESS_END();
}

PROCESS_THREAD(scroll_process, ev, data)
{
	PROCESS_BEGIN();
	printf("*** PROCESS_THREAD Scroll started ***\n");
	while (1) {
		PROCESS_WAIT_EVENT_UNTIL(ev == event_do_scroll);
		for (uint8_t i = 0; i < 9; i++)
			displayScrollingText(i, -2, NULL);
	}
	PROCESS_END();
}

PROCESS_THREAD(rfcore_process, ev, data)
{
	PROCESS_BEGIN();
	printf("*** PROCESS_THREAD rfcore_process started ***\n");
	static struct etimer timer;
	static uint8_t counter = 0x00;
	static rfc_propRxOutput_t rx_stats;

	rfc_dataEntryGeneral_t *gentry;
	gentry = (rfc_dataEntryGeneral_t *) message;

	etimer_set(&timer, CLOCK_SECOND);
	event_display_message = process_alloc_event();
	event_received_message = process_alloc_event();

	troopers_rfc_init_queue(&q, message);
	printf("initial gentry Status %i\n", gentry->status);
	uint8_t *cmd;
	uint8_t info_type = 0;
	uint8_t slot = 0;
	uint8_t day = 0;
	while (1) {
		PROCESS_WAIT_EVENT();
		if (ev == PROCESS_EVENT_TIMER) {
			troopers_rfc_init();
			if (specan) {
				uart_specan();
				toggle_specan();
			} else if (sending && timeout <= 0) {
				printf("currently sending\n");
				hexdump(tx_buffer, PACKETLENGTH);
				timeout = DEF_TIMEOUT;
				troopers_rfc_send(tx_buffer);
				print_rfc_status();
			} else if (timeout <= 0) {
				if (timeout == 0) {
					print_current_identity(is_faked);
					timeout--;
				}
				troopers_rfc_receive(&q, &rx_stats);

				if (DATA_ENTRY_STATUS_FINISHED ==
				    gentry->status) {
					printf("nrxok %i", rx_stats.nRxOk);
					printf("nrxNok %i", rx_stats.nRxNok);
					printf("nrxIgn %i",
					       rx_stats.nRxIgnored);
					printf("\n");
					printf("entry Status %i\n",
					       gentry->status);
					printf
					    ("received message but will it be valid?\n");
					cmd = &gentry->data + 2;
					hexdump(cmd, PACKETLENGTH);
					if (cmd[0] == 0xFF) {
						output_arbitrary_message(++cmd,
									 &gentry->
									 length);
					} else {
						info_type = 0;
						slot = 0;
						day = 0;

						if (check_and_parse_msg
						    (cmd, &info_type, &slot,
						     &day))
							output_fix_messages
							    (&info_type, &slot,
							     &day, &is_faked);
						else {
							etimer_reset(&timer);
							timeout = DEF_TIMEOUT;
							process_post
							    (&output_messages_process,
							     event_display_message,
							     &counter);
							troopers_rfc_init_queue
							    (&q, message);
							continue;
						}
					}
					timeout = DEF_TIMEOUT;
					process_post(&output_messages_process,
						     event_display_message,
						     &counter);
					troopers_rfc_init_queue(&q, message);

				} else
				    if (!
					(DATA_ENTRY_STATUS_PENDING ==
					 gentry->status)) {
					printf("not finished\n");
					cmd = &gentry->data + 2;
					hexdump(cmd, PACKETLENGTH);
					if (cmd[0] == 0xFF) {
						output_arbitrary_message(++cmd,
									 &gentry->
									 length);
					} else {
						info_type = 0;
						slot = 0;
						day = 0;

						if (check_and_parse_msg
						    (cmd, &info_type, &slot,
						     &day))
							output_fix_messages
							    (&info_type, &slot,
							     &day, &is_faked);
						else {
							etimer_reset(&timer);
							timeout = DEF_TIMEOUT;
							process_post
							    (&output_messages_process,
							     event_display_message,
							     &counter);
							troopers_rfc_init_queue
							    (&q, message);
							continue;
						}
					}
					timeout = DEF_TIMEOUT;
					process_post(&output_messages_process,
						     event_display_message,
						     &counter);
					troopers_rfc_init_queue(&q, message);
				}
			} else
				timeout--;

			if (0 == (counter % 2)) {
				process_post(&scroll_process, event_do_scroll,
					     &counter);
			}
			etimer_reset(&timer);
			counter++;
		}
	}
	PROCESS_END();
}

PROCESS_THREAD(output_messages_process, ev, data)
{
	PROCESS_BEGIN();
	printf("*** PROCESS_THREAD output_messages_process started ***\n");

	while (1) {
		PROCESS_WAIT_EVENT_UNTIL(ev == event_display_message);
		print_queue_data((rfc_dataEntryGeneral_t *) message);
	}
	PROCESS_END();
}
