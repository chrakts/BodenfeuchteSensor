#ifndef MYCONSTANTS_H_INCLUDED
#define MYCONSTANTS_H_INCLUDED

//enum{QUARZ,CLK2M,CLK32M};

#define SYSCLK CLK32M

#define PLL 0

#define CLOCK_CALIBRATION 0x83

#define MEAN_NUM 16

#define LED_ROT_ON		PORTD_OUTCLR = PIN6_bm
#define LED_ROT_OFF		PORTD_OUTSET = PIN6_bm
#define LED_ROT_TOGGLE	PORTD_OUTTGL = PIN6_bm
#define LED_GRUEN_ON		PORTD_OUTCLR = PIN7_bm
#define LED_GRUEN_OFF		PORTD_OUTSET = PIN7_bm
#define LED_GRUEN_TOGGLE	PORTD_OUTTGL = PIN7_bm
#define LED_BLAU_ON		PORTD_OUTCLR = PIN5_bm
#define LED_BLAU_OFF		PORTD_OUTSET = PIN5_bm
#define LED_BLAU_TOGGLE	PORTD_OUTTGL = PIN5_bm


#endif // MYCONSTANTS_H_INCLUDED
