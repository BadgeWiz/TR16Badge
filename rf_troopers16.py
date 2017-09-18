#!/usr/bin/env python2

"""
If your have Yardstick One lying around, you can use this script to communicate
with your Troopers16-Badge. There's also some messages, we sent around during
the conference, still in the code.

A Trooper's desire to show a message on his badge can be satisfied in the
following manner:
>>> python2 rf_trooper.py --send-msg "Bitcon miner activated"

Length of messages is limited up to 29 chars due reliability reasons.

The new version of the firmware enables the badge, not only to receive but, to
send messages. Try to press the "BOOTLOADER" button while you Troopers-Badge is
powered on. You should see "Currently Sending" on the screen. To see what the
badge is sending use:
>>> python2 rf_trooper.py --rec-msg

This is the reason why several pre defined sentences(and agenda) reside at the
badge's side.

You can use the cmd to show those. Checkout the help text:
>>> python2 rf_trooper.py -h

There's only one byte stating the information type and in case of agenda slots
and the day of the conference.

Command composition:
1 111 1111

The least four bits state the command starting at 0x00 and ends with 0x07.
The first four bits are used only for agenda (and sometimes for misc commands
like the challenge activation.). The first bit is day and the following 3 bits
state the slot of talks.
So if you want to send a reminder for upcomming talks in 10 minutes on the
second day and the third slot.
It's the command 0x06
Slot: 0x20
Day2: 0x80

So the message consists of OR-ed values:  0x06 | 0x20 | 0x80
0xa6
"""

from rflib import *
from time import sleep
import argparse
from sys import stdout

def setup_rf(d):
    d.setFreq(868000000)
    d.makePktFLEN(30)
    d.setMdmModulation(MOD_GFSK)
    d.setMdmSyncMode(SYNCM_30_of_32)
    d.setMdmSyncWord(0xaabb)
    d.setMdmDRate(50000)
    d.setMdmDeviatn(25000)
    d.setEnablePktCRC()

def rec_data(d):
    setup_rf(d)
    d.setModeRX()
    print("Started receiving data. Press CTRL+C to exit.")
    while True:
        print(d.RFrecv())

def send_data(d, data, iterations=25):
    setup_rf(d)
    try:
        data = hex(data)
    # happens if 0xff+text given, otherwise only one byte is interesting
    except TypeError:
        data = str(data)
    print("Sending message '{0!s}' {1!s} times".format(data, iterations))

    for i in range(0, iterations):
        d.RFxmit(str(data))
        stdout.write('.')
        stdout.flush()
        sleep(1)
    print("Finished.")
    d.cleanup()

def talk_reminder(mins, day, slot):
    """
    Helper method to find the code for the talk reminders. The validations
    are made also at the badge.
    """
    slot -= 1
    day -= 1
    day_hex = 0x80  # first bit set, then day two
    slot_hex = slot << 4
    mins_hex = 0
    msg = 0
    if mins == 5:
        mins_hex = 0x06
    elif mins == 10:
        mins_hex = 0x05
    else:
        raise ValueError("There are only two reminders: for 5 and 10minutes.")

    if day == 0:
        if slot > 7 or slot < 0:
            raise ValueError("Slot on day one has to be between 1 and 8")
        day_hex = 0
    elif day == 1:
        if slot > 5 or slot < 0:
            raise ValueError("Slot on day two has to be between 1 and 6")
    else:
        raise ValueError("Day can only be one or two")

    return chr(day_hex | slot_hex | mins_hex)

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--send-msg", type=str, nargs=1, help="Arbitrary messages, up to 28 chars allowed. Send 'em 30 times to make sure they are received.")
    parser.add_argument("--rec-msg", action="store_true", help="Receive messages on the Badges frequence. Listens until canceled via keyboard.")
    parser.add_argument("--activate-challenge", action="store_true", help="Activate badge challenge.")
    parser.add_argument("--good-morning", action="store_true", help="Welcome sleepy Troopers accordingly.")
    parser.add_argument("--good-evening", action="store_true", help="Good bye coffein addicts.")
    parser.add_argument("--talk-in10", type=int, nargs=2, help="Reminder for talk round starting in 10min. Args are DAY(1 or 2) and SLOT(1-8 on day one or 1-6 for day2).")
    parser.add_argument("--talk-in5", type=int, nargs=2, help="Reminder for talk round starting in 10min. Args are DAY(1 or 2) and SLOT(1-8 on day one or 1-6 for day2).")
    parser.add_argument("--shared-dinner", action="store_true", help="Activate badge challenge.")
    parser.add_argument("--speakers-dinner", action="store_true", help="Activate badge challenge.")
    parser.add_argument("--charity-auction", action="store_true", help="Activate badge challenge.")

    a = parser.parse_args()
    msg = None
    if a.send_msg:
        if len(a.msg[0]) < 0 or len(a.msg[0]) > 29:
            print("ERROR: either no message given or text too long (29 chars allowed).")
            exit(1)
        msg = chr(0xff) + a.msg[0]
        # Null bytes are appended at the badge in any way. But sometimes garbage
        # appended during sending. So if message is too small, append 0xff.
        if len(a.msg[0]) < 29:
            msg += chr(0x00)
    if a.rec_msg:
        msg = - 0x01
    if a.activate_challenge:
        msg = chr(0x27)
    if a.good_morning:
        msg = chr(0x00)
    if a.good_evening:
        msg = chr(0x01)
    if a.shared_dinner:
        msg = chr(0x02)
    if a.speakers_dinner:
        msg = chr(0x03)
    if a.charity_auction:
        msg = chr(0x04)
    if a.talk_in10:
        msg = talk_reminder(10, a.talk_in10[0], a.talk_in10[1])
    if a.talk_in5:
        msg = talk_reminder(5, a.talk_in5[0], a.talk_in5[1])

    if msg != None:
        return msg
    else:
        print("ERROR: You have to use one cmd argument!")
        parser.print_help()
        exit(1)

if __name__ == "__main__":
    print("""
.___________..______        ______     ______   .______    _______ .______          _______.    __     __   
|           ||   _  \      /  __  \   /  __  \  |   _  \  |   ____||   _  \        /       |   /_ |   / /   
`---|  |----`|  |_)  |    |  |  |  | |  |  |  | |  |_)  | |  |__   |  |_)  |      |   (----`    | |  / /_   
    |  |     |      /     |  |  |  | |  |  |  | |   ___/  |   __|  |      /        \   \        | | | '_ \  
    |  |     |  |\  \----.|  `--'  | |  `--'  | |  |      |  |____ |  |\  \----.----)   |       | | | (_) | 
    |__|     | _| `._____| \______/   \______/  | _|      |_______|| _| `._____|_______/        |_|  \___/  
    """)
    msg = parse_args()
    device = RfCat()
    try:
        if(msg == - 0x01):
            rec_data(device)
        else:
            send_data(device, msg)
    except KeyboardInterrupt:
        device.cleanup()
        print("\nAborted.")
        exit(1)
