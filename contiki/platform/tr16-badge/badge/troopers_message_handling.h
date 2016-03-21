
#ifndef __TROOPERS_MESSAGE_HANDLING_H__
#define __TROOPERS_MESSAGE_HANDLING_H__

#define DAY1_MAX_SLOTS 7
#define DAY2_MAX_SLOTS 5
#define INFO_TYPE_MAX_SLOTS 7 
#define MAX_ARBITRARY_MSG 29
#define DEF_TIMEOUT 30


int8_t check_and_parse_msg(
        const uint8_t *msg,
        uint8_t *info_type,
        uint8_t *slot,
        uint8_t *day);

void output_arbitrary_message(uint8_t *data, uint16_t *length);

void output_fix_messages(
        const uint8_t *info_type,
        const uint8_t *slot,
        const uint8_t *day,
        uint8_t *menu);

#endif
