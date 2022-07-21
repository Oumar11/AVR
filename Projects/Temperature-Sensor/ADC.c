#include "ADC.h"

void ADC_init(void)
{
	 // This is Only for this project..

SET_BIT(ADMUX,REFS0); //configure VREF
SET_BIT(ADMUX,REFS1);
SET_BIT(ADCSRA,ADEN); // enable ADC

SET_BIT(ADCSRA,ADPS2); //  Adjust ADC clock
SET_BIT(ADCSRA,ADPS1);
}

uint16 ADC_convert_read(void)
{
	uint16 ADC_data = 0;
	
	SET_BIT(ADCSRA, ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));

	SET_BIT(ADCSRA,ADIF); // clearing ADIF
	
	ADC_data = (ADCL);
	ADC_data |= (ADCH << 8);
	
	
	return ADC_data;
	
}