/*
 * IR_Sensor.c
 *
 *  Created on: Jan 25, 2022
 *      Author: abdul
 */

#include "IR_Sensor.h"

void IR_init(void)
{
	//RCC
	SET_BITS(RCC->AHB1ENR, IR_RCC_MSK);

	//INPUT
	CLR_BITS(IR_GPIO->MODER, (0x3 << (Entrance*2))); // clear pin bits
	CLR_BITS(IR_GPIO->MODER, (0x3 << (Exit*2))); // clear pin bits

	//IR1 PULLUP
	CLR_BITS(IR_GPIO->PUPDR, (0x3 << (Entrance*2))); // clear pin bits
	SET_BITS(IR_GPIO->PUPDR, (0x1 << (Entrance*2))); // pin has pullup

	//IR2 PULLUP
	CLR_BITS(IR_GPIO->PUPDR, (0x3 << (Exit*2))); // clear pin bits
	SET_BITS(IR_GPIO->PUPDR, (0x1 << (Exit*2))); // pin has pullup
}

/*if the result from get_Bit is equal*/

Bool IR_IfActivated(u8 Copy_u8IRNumber)
{
	Bool Local_BoolCheck = GET_BIT(IR_GPIO->IDR,Copy_u8IRNumber);
	return Local_BoolCheck;
}









