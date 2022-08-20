#ifndef HX711ADAPTER_H_INCLUDED
#define HX711ADAPTER_H_INCLUDED

#define LORAMESSAGELENGTH 30

#include <avr/io.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>
#include "util/delay.h"
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "twi_slave_driver.h"
#include "myConstants.h"


#include "uartHardware.h"
#include "Serial.h"
#include "timer.h"
#include "External.h"
#include "../xmegaClocks/xmegaClocks.h"
#include "capaMeasure.h"
#include "adcMessung.h"
#include "BodenfeuchteSensorDefines.h"


void setup();
void TWIC_SlaveProcessData(void);

#endif // HX711ADAPTER_H_INCLUDED
