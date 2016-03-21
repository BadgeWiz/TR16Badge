/*
* File Name     :
* Purpose       :
* Creation Date : 18-03-2016
* Last Modified : Fri 18 Mar 2016 10:33:03 AM CET
* Created By    :
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "lcd.h"
#include "badgeName.h"

void print_current_identity(uint8_t is_faked_menu)
{
	setTextSize(5);
	printf("Printing Name!");
	printf(NAME);
	printf("%c", GROUP);
	for (uint8_t i = 0; i < 9; i++)
		disableScrollingText(i);
	if (!is_faked_menu) {
		switch (GROUP) {
		case '0':
			printf("Color has been set to Attendee\n");
			setTextColor(RGB(0xff, 0xff, 0xff),
				     RGB(0xeb, 0xa4, 0x12));
//        fillScreen(text_bg);
			break;
		case '1':
			printf("Color has been set to Speaker\n");
			setTextColor(RGB(0x00, 0xfd, 0x00),
				     RGB(0x00, 0x00, 0x00));
//         fillScreen(RGB(0x00, 0x00, 0x00));
			break;
		case '2':
			printf("Color has been set to Staff\n");
			setTextColor(RGB(0x00, 0x00, 0x00),
				     RGB(0xed, 0x30, 0x34));
//         fillScreen(RGB(0xff,0xff,0xff));
			break;
		case '3':
			printf("Color has been set to Student\n");
			setTextColor(RGB(0xff, 0xff, 0xff),
				     RGB(0x44, 0xc7, 0xf4));
//         fillScreen(RGB(0xff,0xff,0xff));
			break;
		}
		fillScreen(text_bg);
		displayScrollingText(0, -1, NAME);
	} else {

		switch (GROUP) {
		case '0':
			printf("Attendee with fake!\n");
			setTextColor(RGB(0xff, 0xff, 0xff),
				     RGB(0xeb, 0xa4, 0x12));
			break;
		case '1':
			printf("Speaker with fake!\n");
			setTextColor(RGB(0x00, 0xfd, 0x00),
				     RGB(0x00, 0x00, 0x00));

			break;
		case '2':
			printf("Staff with fake!\n");
			setTextColor(RGB(0x00, 0x00, 0x00),
				     RGB(0xed, 0x30, 0x34));

			break;
		case '3':
			printf("Student with fake!\n");
			setTextColor(RGB(0xff, 0xff, 0xff),
				     RGB(0x44, 0xc7, 0xf4));

			break;
		}
		fillScreen(text_bg);
		setTextSize(2);
		displayText(0, 200, NAME);
		setTextSize(5);
		displayScrollingText(0, 20, FNAME);
	}

}
