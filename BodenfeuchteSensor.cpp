#include "BodenfeuchteSensor.h"

void setup()
{
	init_clock(SYSCLK,PLL,true,CLOCK_CALIBRATION);

	PORTA_DIRSET = 0xff;  // nichts angeschlossen
	PORTC_DIRSET = 0b11111100; // I2C-Slave an 0,1
	PORTC_DIRCLR = 0b00000011;
	PORTD_DIRSET = 0xff; // 3x LED und 2x C

  uint8_t i,led;
	led = 0b10000000;
	for(i=0;i<3;i++)
	{
		PORTD_OUT = ~led;
		_delay_ms(100);
		led = led>>1;
	}
	PORTD_OUT = 0xFF; // alle LEDs aus
	init_mytimer();
	TWI_SlaveInitializeDriver(&twiSlave, &TWIC, TWIC_SlaveProcessData);
	TWI_SlaveInitializeModule(&twiSlave, SLAVE_ADDRESS, TWI_SLAVE_INTLVL_LO_gc);

	PMIC_CTRL = PMIC_LOLVLEX_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm;
	sei();

  initTemperatureMessung();
}

int main()
{
uint16_t counter = 0;

  counter = 0;
  setup();

  capaMeasure capa(&PORTD,0,1);

  while(1)
  {
    if( NEXTTempMeasure==true )
    {
      LED_ROT_ON;
      NEXTTempMeasure = false;
      startAdcMeasure();
    }
    if( NEXTCapaMeasure==true )
    {
      LED_GRUEN_ON;
      NEXTCapaMeasure = false;
      humiResult[counter] = capa.makeMeasure();
      LED_GRUEN_OFF;
      counter++;
      if( counter>= MEAN_NUM)
        counter = 0;
    }
  }
}

/*! Simple function that invert the received value in the sendbuffer. This
 *  function is used in the driver and passed on as a pointer to the driver.
 */
void TWIC_SlaveProcessData(void)
{
uint8_t i;
float meanResult = 0.0;

  switch(twiSlave.receivedData[0])
	{
    case adrHumidity:
      for(i=0;i<MEAN_NUM;i++)
        meanResult += humiResult[i];
      meanResult = meanResult / MEAN_NUM;
      twiSlave.sendData[0] = ((uint16_t) meanResult) & 0xff;
      twiSlave.sendData[1] = ((uint16_t) meanResult) >> 8;
    break;
    case adrTemperature:
      twiSlave.sendData[0] = ((uint16_t) temperatureWert) & 0xff;
      twiSlave.sendData[1] = ((uint16_t) temperatureWert) >> 8;
    break;
    case adrId:
      twiSlave.sendData[0] = SLAVE_ADDRESS;
    break;
    default:
      twiSlave.sendData[0] = 0xff;
      twiSlave.sendData[1] = 0xff;
	}
}

/*! TWIC Slave Interrupt vector. */
ISR(TWIC_TWIS_vect)
{
	TWI_SlaveInterruptHandler(&twiSlave);
}

