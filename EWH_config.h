

#ifndef EWH_CONFIG_H_
#define EWH_CONFIG_H_

#define EWH_LED_PORT  DIO_PORTC
#define EWH_LED_PIN   DIO_PIN7

#define EWH_SENSOR_PORT  DIO_PORTA
#define EWH_SENSOR_PIN   DIO_PIN2

#define EWH_UP_BUTTON_PORT  DIO_PORTD
#define EWH_UP_BUTTON_PIN   DIO_PIN6

#define EWH_DOWN_BUTTON_PORT  DIO_PORTB
#define EWH_DOWN_BUTTON_PIN   DIO_PIN0

#define EWH_COOLING_PORT  DIO_PORTA
#define EWH_COOLING_PIN   DIO_PIN0

#define EWH_HEATER_PORT  DIO_PORTA
#define EWH_HEATER_PIN   DIO_PIN1

#define GI SET_BIT(SREG,7)       // global interrupt

#define EEPROM_ADDRES  201

#define SENSOR_CHANAL  ADC_chanal_1



#endif /* EWH_CONFIG_H_ */
