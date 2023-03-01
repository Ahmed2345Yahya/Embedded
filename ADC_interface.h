

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

#define ADC_chanal_0  0
#define ADC_chanal_1  1
#define ADC_chanal_2  2
#define ADC_chanal_3  3
#define ADC_chanal_4  4
#define ADC_chanal_5  5
#define ADC_chanal_6  6
#define ADC_chanal_7  7


void ADC_INIT(void);
void ADC_GET_DIGITAL(u8 chanal , u16* digital_val);



#endif /* ADC_INTERFACE_H_ */