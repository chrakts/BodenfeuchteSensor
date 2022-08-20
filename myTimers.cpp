#include "myTimers.h"


// 1:  9.9  ms
// 2:  19.8 ms
// 5:  49.4 ms
//10:  99.0 ms
//101: 1000 ms

volatile TIMER MyTimers[MYTIMER_NUM]= {
  {TM_START,RESTART_NO,5000,0,startupTimer},
  {TM_START,RESTART_YES,10,0,nextCapaMeasure},
  {TM_START,RESTART_YES,10,0,nextTempMeasure}
};


void nextTempMeasure(uint8_t test)
{
  NEXTTempMeasure = true;
}

void nextCapaMeasure(uint8_t test)
{
  NEXTCapaMeasure = true;
}

void startupTimer(uint8_t test)
{
  MyTimers[TIMER_CAPAMEASURE].value = 100;
  MyTimers[TIMER_TEMPMEASURE].value = 100;
}
