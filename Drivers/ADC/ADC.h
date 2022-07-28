


#ifndef ADC_H_
#define ADC_H_

#include "../std_macros"
#include "../typedef"
#include "GPIO.h"

void ADC_init(void);

uint16 ADC_convert_read(void);


#endif /* ADC_H_ */