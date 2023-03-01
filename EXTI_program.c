


 /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"


void EXTI_enable(EXTI_source interruptSource,EXTI_trigger interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;

			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;

			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;

			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
		}

		SET_BIT(GICR,6); //enable INT0
		break;

		case EXTI_INT1:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;

			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
		}

		SET_BIT(GICR,7); //enable INT1
		break;

		case EXTI_INT2:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,6);
			break;

			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,6);
			break;
		}

		SET_BIT(GICR,5); //enable INT2
		break;
	}
}


void EXTI_disable(EXTI_source interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,6); //disable INT0
		break;

		case EXTI_INT1:
		CLR_BIT(GICR,7); //disable INT1
		break;

		case EXTI_INT2:
		CLR_BIT(GICR,5); //disable INT2
		break;
	}
}
