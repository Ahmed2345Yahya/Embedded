#include "EWH.h"


void set_temp(u8* temp,u8 STATE)
{
	u8 Time = 0;
	u8 up,down;
	while(Time < 25)
	{
		if (STATE == 0)
		{
			break;
		}
		up   = DIO_getPinValue(EWH_UP_BUTTON_PORT,EWH_UP_BUTTON_PIN);
		down = DIO_getPinValue(EWH_DOWN_BUTTON_PORT,EWH_DOWN_BUTTON_PIN);
		if (up == 1)
		{
			if(*temp < 75){
				*temp = *temp + 5;
				Time = 0 ;
			}
		}
		else if (down == 1)
		{
			if(*temp > 35){
				*temp = *temp - 5;
				Time = 0 ;
			}
		}
		else
		{
			Time +=1 ;
		}
		_delay_ms(200);

		SSD_displayMultiNumber(*temp);

	}

}


void EWH_SET_DIRECTION(void)
{
	DIO_setPinDirection(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_OUTPUT); // LED

	DIO_setPinDirection(EWH_SENSOR_PORT,EWH_SENSOR_PIN,DIO_PIN_INPUT);  // sensor

	DIO_setPinDirection(EWH_UP_BUTTON_PORT,EWH_UP_BUTTON_PIN,DIO_PIN_INPUT); // UP PB1
	DIO_setPinDirection(EWH_DOWN_BUTTON_PORT,EWH_DOWN_BUTTON_PIN,DIO_PIN_INPUT); // DOWN PB0

	DIO_setPinDirection(EWH_COOLING_PORT,EWH_COOLING_PIN,DIO_PIN_OUTPUT); // COOLING RELAY
	DIO_setPinDirection(EWH_HEATER_PORT,EWH_HEATER_PIN,DIO_PIN_OUTPUT); // HEATING RELAY
}

void EWH_INIT(void)
{
	ADC_INIT();
	TWI_initMaster();
	SSD_initDirections();
	GI; // global interrupt
	EXTI_enable(EXTI_INT0,EXTI_FALLING_EDGE);
}

void EWH_FIRST_TIME_CHECK(u8 desired_temp)
{
	if (desired_temp < 35 || desired_temp > 75)
	{
		desired_temp = 60;
		EEPROM_writeByte(EEPROM_ADDRES,desired_temp);
	}
}

void EWH_GET_SENSOR (u16* sensor_ptr)
{
	ADC_GET_DIGITAL(SENSOR_CHANAL,sensor_ptr);
}

void EWH_SHUTDOWN(void)
{
	DIO_setPinValue(EWH_COOLING_PORT,EWH_COOLING_PIN,DIO_PIN_HIGH); // COOLING RELAY
	DIO_setPinValue(EWH_HEATER_PORT,EWH_HEATER_PIN,DIO_PIN_HIGH); // HEATING RELAY
	DIO_setPinValue(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_LOW); // LED
}

