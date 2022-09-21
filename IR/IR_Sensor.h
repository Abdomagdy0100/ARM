/*
 * IR_Sensor.h
 *
 *  Created on: Jan 25, 2022
 *      Author: abdul
 */
#include "stm32f4xx.h"
#include "data_types.h"
#include "bit_handle.h"
#ifndef INC_IR_SENSOR_H_
#define INC_IR_SENSOR_H_
#define Entrance					1
#define Exit						2
#define IR_GPIO						GPIOC
#define IR_RCC_MSK					RCC_AHB1ENR_GPIOCEN_Msk


void IR_init(void);
Bool IR_IfActivated(u8);


#endif /* INC_IR_SENSOR_H_ */
