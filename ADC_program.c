
#include "ADC_interface.h"
#include "ATMEGA32_REG.h"
#include "bit_math.h"
#include "STD_TYPES.h"

void ADC_INIT(void)
{
	/*select V_ref to VCC*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	/*choose right adj*/
	CLR_BIT(ADMUX,5);
	
	/*disable auto trigger*/
	CLR_BIT(ADCSRA,5);
	
	/*prescaler init to 125KHZ*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	/*ADC enable*/
	SET_BIT(ADCSRA,7);
}


void ADC_GET_DIGITAL(u8 chanal , u16* digital_val)
{
	if (chanal < 32 && digital_val != NULL)
	{
		/*select chanal number*/
		ADMUX &= 0b11100000;
		ADMUX |= chanal;
		
		/*start conversion*/
		SET_BIT(ADCSRA,6);
		
		/*wait to the conversion ends*/
		while(GET_BIT(ADCSRA,4) == 0);
		
		/*clear the flag to  the next time by typing 1 to it*/
		SET_BIT(ADCSRA,4);
		
		*digital_val = ADC_u16;
	}
}
