#ifndef _AVR_TIME_H_
#define _AVR_TIME_H_

#include <stdint.h>

void avr_time_init(void);
uint32_t avr_time_now(void);

#endif