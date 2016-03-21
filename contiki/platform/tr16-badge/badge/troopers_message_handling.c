/*
* File Name     : troopers_message_handling.c
* Purpose       :
* Creation Date : 18-03-2016
* Last Modified : Sun 20 Mar 2016 11:26:21 AM CET
* Created By    :
*
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "lcd.h"
#include "troopers_agenda.h"
#include "troopers_message_handling.h"
#include "troopers_identity.h"

/*
 * Parses the recieved message (of one byte). And returns 0 if received
 * message was valid.
 * 1111 1111
 * info_type  = last four bit, niederwertigstes nibble
 * slots  = second to fourth bits
 * day = first bit
 */
int8_t check_and_parse_msg(const uint8_t * msg,
			   uint8_t * info_type, uint8_t * slot, uint8_t * day)
{

	printf("&day: %p &info: %p &slot: %p\n", day, info_type, slot);
	*info_type = *msg & 0x0F;
	*slot = (*msg & 0x70) / 16;
	*day = (*msg & 0x80) / 128;
	printf("day: %x info: %x slot: %x\n", *day, *info_type, *slot);
	// error checking
	if (*info_type > INFO_TYPE_MAX_SLOTS)
		return 0;
	if (*day < 0 || *day > 1)
		return 0;
	if (*day == 0 && *slot > DAY1_MAX_SLOTS)
		return 0;
	if (*day == 1 && *slot > DAY2_MAX_SLOTS)
		return 0;
	if (*info_type == 7 && (*slot < 0 || *slot > 3))
		return 0;

	return 1;
}

/*
 * Output arbitrary text received via radio.
 */
void output_arbitrary_message(uint8_t * data, uint16_t * length)
{

	static char out_buf[MAX_ARBITRARY_MSG + 1];
	out_buf[MAX_ARBITRARY_MSG] = 0x00;	// let there be a null byte in any case
	strncpy(out_buf, (char *)data, MAX_ARBITRARY_MSG - 1);
	for (uint16_t i = 0; i < MAX_ARBITRARY_MSG; i++) {
		if (out_buf[i] < 32 || out_buf[i] > 126) {
			out_buf[i] = 0x00;
			break;
		}
	}
	for (uint8_t i = 0; i < 9; i++)
		disableScrollingText(i);
	setTextSize(4);
	fillScreen(text_bg);
	displayScrollingText(0, -1, out_buf);
}

/*
 * Prints messages according to given the codes.
 */
void output_fix_messages(const uint8_t * info_type,
			 const uint8_t * slot,
			 const uint8_t * day, uint8_t * is_faked_menu)
{

	switch (*info_type) {
	case 0:
		fillScreen(text_bg);
		setTextSize(3);
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		displayScrollingText(0, -1, "Good morning Trooper!");
		break;
	case 1:
		setTextSize(3);
		fillScreen(text_bg);
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		displayScrollingText(0, 50, "Have a nice evening Trooper!");
		displayScrollingText(1, 100,
				     "Go get some rest (or some more drinks).");
		break;
	case 2:
		setTextSize(3);
		fillScreen(text_bg);
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		displayScrollingText(0, 50,
				     "Shared dinner and Packet Wars afterwards at the Kulturbrauerei.");
		displayScrollingText(1, 100,
				     "Busses at the PMA leaving at 6:30pm");
		break;
	case 3:
		setTextSize(3);
		fillScreen(text_bg);
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		displayScrollingText(0, 50,
				     "Speaker's dinner is at the restaurant Goldenes Schaaf.");
		displayScrollingText(1, 100,
				     "Busses at the PMA leaving at 6:30pm");
		break;
	case 4:
		setTextSize(3);
		fillScreen(text_bg);
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		displayScrollingText(0, 50,
				     "Charity Ruffle starts in a few minutes (12:30pm).");
		displayScrollingText(1, 100,
				     "All Troopers should move to the 2nd floor right now!.");
		break;
	case 5:
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		setTextSize(2);
		fillScreen(text_bg);
		if (*day == 0)
			display_slot(&day1[*slot]);
		else
			display_slot(&day2[*slot]);
		displayScrollingText(8, 210, "IN 10 MINUTES!1!!");
		break;
	case 6:
		for (uint8_t i = 0; i < 9; i++)
			disableScrollingText(i);
		setTextSize(2);
		fillScreen(text_bg);
		if (*day == 0)
			display_slot(&day1[*slot]);
		else
			display_slot(&day2[*slot]);
		displayScrollingText(8, 210, "IN 5 MINUTES!1!!");
		break;
	case 7:
		if (*slot == 0)
			printf
			    ("I am a happy and innocent Trooper's badge.\n\t\t;-)\n");
		else if (*slot == 1)
			printf("And now I am an angry botnet.\n\t\t>:‑)\n");
		else if (*slot == 2)
			/* ACTIVATE GAME */
			printf
			    ("Ooh oh, now you have to find the guy whos name you see on the badge.\n");
		*is_faked_menu = 1;
		print_current_identity(*is_faked_menu);
		/* ACTIVATE GAME */
		break;
	default:
		printf("Troopers16\n");
	}
}
