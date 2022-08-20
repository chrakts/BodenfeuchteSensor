#ifndef EXTERNAL_H_INCLUDED
#define EXTERNAL_H_INCLUDED

#include "myConstants.h"
#include "BodenfeuchteSensor.h"


extern uint8_t outputPins[];

extern volatile  uint8_t txIsReady;
extern volatile  uint8_t rxIsReady;

extern bool NEXTCapaMeasure;
extern bool NEXTTempMeasure;

extern volatile float humiResult[];

extern TWI_Slave_t twiSlave;      /*!< TWI slave module. */

extern bool validTemperature;

#endif // EXTERNAL_H_INCLUDED


