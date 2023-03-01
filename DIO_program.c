


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

#include "DIO_interface.h"

/* Pin Apis */
void DIO_setPinDirection(u8 portId, u8 pinId, u8 pinDirection)
{
	switch(portId)
	{
		case DIO_PORTA:
		if(pinDirection == DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRA,pinId);
		}
		else
		{
			CLR_BIT(DDRA,pinId);
		}
		break;

		case DIO_PORTB:
		if(pinDirection == DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRB,pinId);
		}
		else
		{
			CLR_BIT(DDRB,pinId);
		}
		break;

		case DIO_PORTC:
		if(pinDirection == DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRC,pinId);
		}
		else
		{
			CLR_BIT(DDRC,pinId);
		}
		break;

		case DIO_PORTD:
		if(pinDirection == DIO_PIN_OUTPUT)
		{
			SET_BIT(DDRD,pinId);
		}
		else
		{
			CLR_BIT(DDRD,pinId);
		}
		break;
	}
}


void DIO_setPinValue(u8 portId, u8 pinId, u8 pinValue)
{
	switch(portId)
	{
		case DIO_PORTA:
		if(pinValue == DIO_PIN_HIGH)
		{
			SET_BIT(PORTA,pinId);
		}
		else
		{
			CLR_BIT(PORTA,pinId);
		}
		break;

		case DIO_PORTB:
		if(pinValue == DIO_PIN_HIGH)
		{
			SET_BIT(PORTB,pinId);
		}
		else
		{
			CLR_BIT(PORTB,pinId);
		}
		break;

		case DIO_PORTC:
		if(pinValue == DIO_PIN_HIGH)
		{
			SET_BIT(PORTC,pinId);
		}
		else
		{
			CLR_BIT(PORTC,pinId);
		}
		break;

		case DIO_PORTD:
		if(pinValue == DIO_PIN_HIGH)
		{
			SET_BIT(PORTD,pinId);
		}
		else
		{
			CLR_BIT(PORTD,pinId);
		}
		break;
	}
}


u8 DIO_getPinValue(u8 portId, u8 pinId)
{
	u8 pinState;

	switch(portId)
	{
		case DIO_PORTA:
		pinState = GET_BIT(PINA,pinId);
		break;

		case DIO_PORTB:
		pinState = GET_BIT(PINB,pinId);
		break;

		case DIO_PORTC:
		pinState = GET_BIT(PINC,pinId);
		break;

		case DIO_PORTD:
		pinState = GET_BIT(PIND,pinId);
		break;
	}

	return pinState;
}


void DIO_togglePinValue(u8 portId, u8 pinId)
{
	switch(portId)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA,pinId);
		break;

		case DIO_PORTB:
		TOG_BIT(PORTB,pinId);
		break;

		case DIO_PORTC:
		TOG_BIT(PORTC,pinId);
		break;

		case DIO_PORTD:
		TOG_BIT(PORTD,pinId);
		break;
	}
}


void DIO_activatePullUp(u8 portId, u8 pinId)
{
	switch(portId)
	{
		case DIO_PORTA:
		SET_BIT(PORTA,pinId);
		break;

		case DIO_PORTB:
		SET_BIT(PORTB,pinId);
		break;

		case DIO_PORTC:
		SET_BIT(PORTC,pinId);
		break;

		case DIO_PORTD:
		SET_BIT(PORTD,pinId);
		break;
	}
}
