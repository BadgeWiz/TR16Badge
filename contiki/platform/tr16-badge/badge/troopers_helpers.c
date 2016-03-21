
#include <stdio.h>
#include <stdint.h>
#include "troopers_helpers.h"

void hexdump(const void *buffer, size_t size)
{
	size_t i;
	uint8_t *ptr = (uint8_t *) buffer;

	for (i = 0; i < size; i++) {
		if (i && ((i & 3) == 0)) {
			printf(" ");
		}
		if (i % 16 == 0) {
			printf("\n");
		}
		printf(" %02X", *ptr++);
	}
	printf(" [size=%02i]\n", size);
}
