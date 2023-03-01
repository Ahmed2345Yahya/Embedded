


#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h"


void SSD_initDirections(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
}

void SSD_SHUTDOWN(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
}

void SSD_displayNumber(u8 desiredNumber,u8 ssdId)
{
	switch(ssdId)
	{
		case SSD_ONE:
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		SSD_writeHalfPort(desiredNumber);
		break;

		case SSD_TWO:
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		SSD_writeHalfPort(desiredNumber);
		break;
	}
}


void SSD_displayMultiNumber(u8 desiredNumber)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);

	SSD_writeHalfPort(desiredNumber/10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);

	SSD_writeHalfPort(desiredNumber%10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
}

/*
void SSD_displayMultiNumber(u8 diseredNumber)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	SSD_writeHalfPort(diseredNumber/10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	_delay_ms(10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	SSD_writeHalfPort(diseredNumber%10);
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	_delay_ms(10);
}*/


void SSD_writeHalfPort(u8 value)
{
	if(GET_BIT(value,0) == 1)
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}

	if(GET_BIT(value,1) == 1)
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}

	if(GET_BIT(value,2) == 1)
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}

	if(GET_BIT(value,3) == 1)
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
}

void display(u8 data , u8 TIME)
{
	for (u8 i ; i < TIME ; i +=20)
	{
		SSD_displayMultiNumber(data);
	}
}
