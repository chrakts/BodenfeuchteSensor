#define EXTERNALS_H_

#include "BodenfeuchteSensor.h"

volatile uint8_t txIsReady = false;
volatile uint8_t rxIsReady = false;
volatile float humiResult[MEAN_NUM];

bool NEXTCapaMeasure = true;
bool NEXTTempMeasure = true;

bool validTemperature = false;

TWI_Slave_t twiSlave;      /*!< TWI slave module. */
