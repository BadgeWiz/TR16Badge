
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "troopers_agenda.h"
#include "lcd.h"

void print_day(uint8_t day)
{
	switch (day) {
	case 1:
		for (uint8_t i = 0; i < 8; i++) {
			print_slot(&day1[i]);
		}
		break;
	case 2:
		for (uint8_t i = 0; i < 6; i++) {
			print_slot(&day2[i]);
		}
		break;
	}
}

void print_agenda()
{
	print_day(1);
	print_day(2);
}

void print_event(Event_t * ev)
{
	printf("Title: %s\n", ev->name);

	switch (ev->track) {
	case ATTACK:
		printf("In: Attack & Research\n");
		break;
	case SAP:
		printf("In: SAP Security\n");
		break;
	case EMBEDDED:
		printf("In: Embedded\n");
		break;
	case DEFENSE:
		printf("In: Defense & Management\n");
		break;
	}
}

void print_slot(Slot_t * slot)
{
	if (slot->track1.name != NULL) {
		print_event(&slot->track1);
	}
	if (slot->track2.name != NULL) {
		print_event(&slot->track2);
	}
	if (slot->track3.name != NULL) {
		print_event(&slot->track3);
	}
}

void display_slot(Slot_t * slot)
{
	fillScreen(text_bg);
	if (slot->track1.name != NULL) {
		display_event(0, &slot->track1);
	}
	if (slot->track2.name != NULL) {
		display_event(1, &slot->track2);
	}
	if (slot->track3.name != NULL) {
		display_event(2, &slot->track3);
	}
}

void display_event(uint8_t idx, Event_t * ev)
{
	uint16_t y = 10 + idx * 3 * (text_size & 0x7f) * FONT_HEIGHT;
	displayScrollingText(idx * 3, y, ev->name);

	switch (ev->track) {
	case ATTACK:
		displayScrollingText(idx * 3 + 1,
				     y + (text_size & 0x7f) * FONT_HEIGHT,
				     "In: Attack & Research");
		break;
	case SAP:
		displayScrollingText(idx * 3 + 1,
				     y + (text_size & 0x7f) * FONT_HEIGHT,
				     "In: SAP Security");
		break;
	case EMBEDDED:
		displayScrollingText(idx * 3 + 1,
				     y + (text_size & 0x7f) * FONT_HEIGHT,
				     "In: Embedded");
		break;
	case DEFENSE:
		displayScrollingText(idx * 3 + 1,
				     y + (text_size & 0x7f) * FONT_HEIGHT,
				     "In: Defense & Mgmt");
		break;
	}
}

Slot_t day1[8] = {
	{
	 /* Slot one */
	 {
	  {"Opening Keynote"}
	  ,
//            { "Ben Zevenbergen" },
	  ATTACK,
	  }
	 ,
	 {
	  }
	 ,
	 {
	  }
	 ,
	 }
	,

	{
	 /* Slot two */
	 {
	  {"Hiding your White-Box Designs is Not Enough"}
	  ,
	  //           { "Philippe Teuwen" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Mind The Gap - Exploit Free Whitelisting Evasion Tactics"}
	  ,
	  //{ "Casey Smith" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Patch me if you can"}
	  ,
	  //{ "Damian Poddebniak, Sebastian Schinzel, Andreas Wiegenstein" },
	  SAP,
	  }
	 ,

	 }
	,
	{
	 /* Slot three */
	 {
	  {"Attacking Next-Generation Firewalls"}
	  ,
	  //{ "Felix Wilhelm" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Towards a LangSec-aware SDLC"}
	  ,
	  //{ "Jacob Torrey" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Preventing vulnerabilities in HANA-based deployments"}
	  ,
	  //{ "Juan Perez-Etchegoyen, Nahuel Sanchez" },
	  SAP,
	  }
	 ,
	 }
	,
	{
	 /* Slot four */
	 {
	  {"QNX: 99 Problems but a Microkernel ain't one!"}
	  ,
	  //{ "Georgi Geshev, Alex Plaskett" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Cloud Seeding or Finding weird machines in the cloud crowd sourced economy."}
	  ,
	  //{ "Graeme Neilson, Vladimir Wolstencroft" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"An easy way into your multi-million dollar SAP systems: An unknown default SAP account"}
	  ,
	  //{ "Joris van de Vis" },
	  SAP,
	  }
	 ,
	 }
	,
	{
	 /* Slot five */
	 {
	  {"unrubby: reversing without reversing"}
	  ,
	  //{ "Richo Healey" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Imma Chargin Mah Lazer - How to protect against (D)DoS attacks"}
	  ,
	  //{ "Oliver Matula" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Thanks SAP for the vulnerabilities. Exploiting the unexploitable"}
	  ,
	  //{ "Dmitry Chastuhin, Alexander Polyakov" },
	  SAP,
	  }
	 ,

	 }
	,
	{
	 /* Slot six */
	 {
	  {"I Have the Power(View): Offensive Active Directory with PowerShell"}
	  ,
	  //{ "Will Schroeder" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Learn about the enemy - How to profile national APT hacking group"}
	  ,
	  //{ "Jinwook Chung, Moonbeom Park" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Deep-dive into SAP archive file formats"}
	  ,
	  //{ "Martin Gallo" },
	  SAP,
	  }
	 ,

	 }
	,
	{
	 /* Slot seven */
	 {
	  {"Reverse Engineering a Digital Two-Way Radio"}
	  ,
	  //{ "Travis Goodspeed, Christiane  Ruetten" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Lightning Talks"}
	  ,
	  //{ "An uprising Star" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Crypto code: the 9 circles of testing"}
	  ,
	  //{ "Jean-Philippe Aumasson" },
	  SAP,
	  }
	 ,

	 }
	,
	{
	 /* Slot eight */
	 {
	  {"Freifunk - Building a free and open network"}
	  ,
	  //{ "Ben Oswald" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Lightning Talks"}
	  ,
	  //{ "An uprising Star" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Adrian Dabrowski"}
	  ,
	  //{ "Hollywood Hacking" },
	  SAP,
	  }
	 ,

	 }
	,
};

Slot_t day2[6] = {
	{
	 /* Slot one */
	 {
	  {"2nd Day Keynote"}
	  ,
	  //{ "Rodrigo Branco" },
	  ATTACK,
	  }
	 ,
	 {
	  }
	 ,
	 {
	  }
	 ,
	 }
	,
	{
	 /* Slot two */
	 {
	  {"Passive Intelligence Gathering and Analytics - It's all Just Metadata!"}
	  ,
	  //{ "Christopher Truncer" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Real-life Software-Defined Security"}
	  ,
	  //{ "Ivan Pepelnjak" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Broadcasting your attack: Security testing DAB radio in cars"}
	  ,
	  //{ "Andy Davis" },
	  EMBEDDED,
	  }
	 ,

	 }
	,
	{
	 /* Slot three */
	 {
	  {"THE KINGS IN YOUR CASTLE - All the lame threats that own you but will never make you famous"}
	  ,
	  //{ "Marion Marschalek, Raphael Vinot" },
	  ATTACK,
	  }
	 ,
	 {
	  {"BetterCrypto: three years in"}
	  ,
	  //{ "Aaron Zauner" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"The road to secure Smart Cars: ENISA approach"}
	  ,
	  //{ "Cedric Levy-Bencheton" },
	  EMBEDDED,
	  }
	 ,

	 }
	,
	{
	 /* Slot four */
	 {
	  {"Rapid Radio Reversing"}
	  ,
	  //{ "Michael Ossmann" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Attacking & Protecting Big Data Environments"}
	  ,
	  //{ "Birk Kauer, Matthias Luft" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Medical Device Security: Hack or Hype?"}
	  ,
	  //{ "Kevin Fu" },
	  EMBEDDED,
	  }
	 ,

	 }
	,
	{
	 /* Slot five */
	 {
	  {"The Joy of Sandbox Mitigations"}
	  ,
	  //{ "James Forshaw" },
	  ATTACK,
	  }
	 ,
	 {
	  {"How to Implement an SDL in a Large Company"}
	  ,
	  //{ "Arne Ludtke" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"How easy to grow robust botnet with low hanging fruits (IoT) - for free"}
	  ,
	  //{ "Attila Marosi" },
	  EMBEDDED,
	  }
	 ,

	 }
	,
	{
	 /* Slot six */
	 {
	  {"Caring for file formats"}
	  ,
	  //{ "Ange Albertini" },
	  ATTACK,
	  }
	 ,
	 {
	  {"Russian attack: Live demos of their steps, tools, techniques"}
	  ,
	  //{ "Sun Huang, Wayne Huang" },
	  DEFENSE,
	  }
	 ,
	 {
	  {"Unpatchable: Living with a vulnerable implanted device"}
	  ,
	  //{ "Marie Moe" },
	  EMBEDDED,
	  }
	 ,

	 }

};
