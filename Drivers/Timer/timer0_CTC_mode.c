/*
 * timer0_CTC_mode.c
 *
 * Created: 5/23/2022 7:03:21 PM
 *  Author: Mohamed Yasser
 */ 
#include "timer0_CTC_mode.h"

void T0_CTC_Init(uint8 OCRVal)/* OCRVal = 252 */
{
	/*set timer0 mode to CTC mode*/
	
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
		
		/* set F_timer0 = F_CPU/1024 = 8000000/1024 = 7812 Hz */
		/* tick time = (1024/8000000) = 0.128 mSec. */
		/* set OCR register value to (252) */  
		/* each OCR compare happens after : (252) x 0.128ms = 0.032256s */
		/* ( 0.032256 x 31 ) = 1S ... so after this counts for (31) times, one sec will be evaluated*/ 
		
	OCR0 = OCRVal;
	
	SET_BIT(TCCR0, CS00);	/* Setting up the prescaling options */
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);	
		
	
	/*Enable interrupt of CTC mode*/
	
	sei(); //enable I-bit
	SET_BIT(TIMSK, OCIE0); //enable bit of timer0 CTC interrupt
}