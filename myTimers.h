/*
 * MyTimer.h
 *
 * Created: 11.02.2016 20:20:03
 *  Author: Christof
 */


#ifndef MYTIMERS_H_
#define MYTIMERS_H_

#include "timer.h"
#include "External.h"

#define MYTIMER_NUM	3


enum{TIMER_STARTUP, TIMER_CAPAMEASURE, TIMER_TEMPMEASURE};

void startupTimer(uint8_t test);
void nextCapaMeasure(uint8_t test);
void nextTempMeasure(uint8_t test);

extern volatile TIMER MyTimers[MYTIMER_NUM];

#endif /* MYTIMERS_H_ */
