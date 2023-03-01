

#ifndef EWH_H_
#define EWH_H_


#define  F_CPU 16000000ul
#include <util/delay.h>
#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EEPROM_interface.h"
#include "SPI_interface.h"
#include "SSD_interface.h"
#include "TWI_interface.h"
#include "EXTI_interface.h"
#include "ADC_interface.h"
#include "EWH_config.h"



void set_temp(u8* temp,u8 STATE);
void EWH_SET_DIRECTION(void);
void EWH_INIT(void);
void EWH_FIRST_TIME_CHECK(u8 desired_temp);
void EWH_GET_SENSOR (u16* sensor_ptr);
void EWH_SHUTDOWN(void);


#endif /* EWH_H_ */
