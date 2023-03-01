#include "EWH.h"


u8 state = 1;
u8 * ptr = &state;

int main(void)
{
	EWH_SET_DIRECTION();
	EWH_INIT();

	u16 sensor;
	u8 desired_temp;
	EWH_FIRST_TIME_CHECK(desired_temp);
	EEPROM_readByte(EEPROM_ADDRES,&desired_temp);
	u8 up = 0 ;
	u8 down = 0 ;

    while (1)
    {
		EWH_GET_SENSOR(&sensor);
		if (state == 1)
		{
			// go to setting temp
			up   = DIO_getPinValue(EWH_UP_BUTTON_PORT,EWH_UP_BUTTON_PIN);
			down = DIO_getPinValue(EWH_DOWN_BUTTON_PORT,EWH_DOWN_BUTTON_PIN);

			if (up == 1 || down == 1)
			{
				_delay_ms(500);
				set_temp(& desired_temp,state);
				EEPROM_writeByte(EEPROM_ADDRES,desired_temp);
			}
			// end of the setting temp mode
			SSD_displayMultiNumber(sensor);

			// heating code ////////////////////////////////////
			if (sensor <= desired_temp-5)
			{
				DIO_setPinValue(EWH_HEATER_PORT,EWH_HEATER_PIN,DIO_PIN_LOW);
				while(sensor != desired_temp)
				{
					EWH_GET_SENSOR(&sensor);
					if (state == 0)
					{
						break;
					}
					EEPROM_readByte(EEPROM_ADDRES,&desired_temp);
					up   = DIO_getPinValue(EWH_UP_BUTTON_PORT,EWH_UP_BUTTON_PIN);
					down = DIO_getPinValue(EWH_DOWN_BUTTON_PORT,EWH_DOWN_BUTTON_PIN);
					if (up == 1 || down == 1)
					{
						_delay_ms(500);
						set_temp(& desired_temp,state);
						EEPROM_writeByte(EEPROM_ADDRES,desired_temp);
						break;
					}
					SSD_displayMultiNumber(sensor);
					DIO_setPinValue(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_HIGH);
					display(sensor,200);
					ADC_GET_DIGITAL(ADC_chanal_2,&sensor);
					DIO_setPinValue(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_LOW);
					display(sensor,200);
				}
				DIO_setPinValue(EWH_HEATER_PORT,EWH_HEATER_PIN,DIO_PIN_HIGH);

			}
			//////////////////////////////////////////////////////////////////

			else if (sensor >= desired_temp+5)
			{
				DIO_setPinValue(EWH_COOLING_PORT,EWH_COOLING_PIN,DIO_PIN_LOW);
				while(sensor != desired_temp)
				{
					EWH_GET_SENSOR(&sensor);
					if (state == 0)
					{
						break;
					}
					EEPROM_readByte(EEPROM_ADDRES,&desired_temp);
					up   = DIO_getPinValue(EWH_UP_BUTTON_PORT,EWH_UP_BUTTON_PIN);
					down = DIO_getPinValue(EWH_DOWN_BUTTON_PORT,EWH_DOWN_BUTTON_PIN);
					if (up == 1 || down == 1)
					{
						_delay_ms(500);
						set_temp(& desired_temp,state);
						EEPROM_writeByte(EEPROM_ADDRES,desired_temp);
						break;
					}
					SSD_displayMultiNumber(sensor);
					DIO_setPinValue(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_HIGH);
				}
				DIO_setPinValue(EWH_LED_PORT,EWH_LED_PIN,DIO_PIN_LOW);
				DIO_setPinValue(EWH_COOLING_PORT,EWH_COOLING_PIN,DIO_PIN_HIGH);
			}
		}
		else
		{
			EWH_SHUTDOWN();
		}

    }

}

void __vector_1(void)__attribute__ ((signal));
void __vector_1(void)
{
	if (state == 1)
	{
		*ptr = 0;
	}
	else
	{
		*ptr = 1;
	}

}

