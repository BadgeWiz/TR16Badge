/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
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
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/**
 * \addtogroup cc26xx-platforms
 * @{
 *
 * \defgroup cc26xx-srf-tag SmartRF+CC13xx/CC26xx EM and the CC2650 SensorTag
 *
 * This platform supports a number of different boards:
 * - A standard TI SmartRF06EB with a CC26xx EM mounted on it
 * - A standard TI SmartRF06EB with a CC1310 EM mounted on it
 * - The new TI SensorTag2.0
 * @{
 */

// file modified to fit Troopers 2016 Badge /ski

#include "ti-lib.h"
#include "contiki.h"
#include "contiki-net.h"
#include "leds.h"
#include "lpm.h"
#include "pwm.h"
#include "gpio-interrupt.h"
#include "dev/watchdog.h"
#include "dev/oscillators.h"
#include "ieee-addr.h"
#include "vims.h"
#include "dev/cc26xx-uart.h"
#include "dev/soc-rtc.h"
#include "rf-core/rf-core.h"
#include "sys_ctrl.h"
#include "uart.h"
#include "sys/clock.h"
#include "sys/rtimer.h"
#include "lib/sensors.h"
#include "button-sensor.h"
#include "dev/serial-line.h"
#include "net/mac/frame802154.h"

#include "lcd.h"

#include "driverlib/driverlib_release.h"

#include <stdio.h>
/*---------------------------------------------------------------------------*/
/** \brief Board specific iniatialisation */
void board_init(void);

void mypin_init(void)
{

	printf("set ip pin type\n");
	/* set ip pin type */
	ti_lib_ioc_pin_type_gpio_input(BOARD_IOID_KEY_BACKDOOR);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LCD_BL);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LCD_BL_PWR_ON);

	printf("clear test pins\n");
	/* Clear everything */
	//ti_lib_gpio_pin_write(BOARD_KEY_BACKDOOR, 0);
	ti_lib_gpio_pin_write(BOARD_LCD_BL, 0);
	ti_lib_gpio_pin_write(BOARD_LCD_BL_PWR_ON, 0);

	printf("set pins on\n");
	/* Test display on */
	ti_lib_gpio_pin_write(BOARD_LCD_BL, 1);
	ti_lib_gpio_pin_write(BOARD_LCD_BL_PWR_ON, 1);

	pwm_start(120);		// 40mA
}

/*---------------------------------------------------------------------------*/
/**
 * \brief Main function for CC26xx-based platforms
 *
 * The same main() is used for all supported boards
 */
int main(void)
{
	/* Enable flash cache and prefetch. */
	ti_lib_vims_mode_set(VIMS_BASE, VIMS_MODE_ENABLED);
	ti_lib_vims_configure(VIMS_BASE, true, true);

	ti_lib_int_master_disable();

	/* Set the LF XOSC as the LF system clock source */
	oscillators_select_lf_xosc();

	lpm_init();

	board_init();

	gpio_interrupt_init();

	/*
	 * Disable I/O pad sleep mode and open I/O latches in the AON IOC interface
	 * This is only relevant when returning from shutdown (which is what froze
	 * latches in the first place. Before doing these things though, we should
	 * allow software to first regain control of pins
	 */
	ti_lib_pwr_ctrl_io_freeze_disable();

	ti_lib_int_master_enable();

	soc_rtc_init();
	clock_init();
	rtimer_init();

	watchdog_init();
	process_init();

	random_init(0x1234);

	/* Character I/O Initialisation */
	cc26xx_uart_init();

	serial_line_init();

	printf("Starting " CONTIKI_VERSION_STRING "\n");
	printf("With DriverLib v%u.%u\n", DRIVERLIB_RELEASE_GROUP,
	       DRIVERLIB_RELEASE_BUILD);
	printf(BOARD_STRING "\n");

	process_start(&etimer_process, NULL);
	ctimer_init();

	energest_init();
	ENERGEST_ON(ENERGEST_TYPE_CPU);

	autostart_start(autostart_processes);

	watchdog_start();

	mypin_init();
	begin();
	led(120);
	lcdInit();

	process_start(&rf_core_process, NULL);

	while (1) {
		uint8_t r;
		do {
			r = process_run();
			watchdog_periodic();
		} while (r > 0);

		/* Drop to some low power mode */
		lpm_drop();
	}
}

/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
