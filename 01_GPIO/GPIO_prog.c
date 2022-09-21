/****************************** *********************************************************
 ***************************  - GPIO_program.c				 ****************************
*========================    - Created: 17/6/2022	         ===========================
========================    - Author: Abdelrahman Magdy           ===========================
========================     Version : _1_				     ===========================
========================    - Note :
									*-
									*-
 **************************************************************************************/

 
/**************************************************************************************************
 *       _____ _____ _____ ____             _____  _____   ____   _____ _____            __  __ 
 *      / ____|  __ \_   _/ __ \           |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |
 *     | |  __| |__) || || |  | |  ______  | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |
 *     | | |_ |  ___/ | || |  | | |______| |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |
 *     | |__| | |    _| || |__| |          | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |
 *      \_____|_|   |_____\____/           |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|
 *                                                                                              
 *                                                                                              
 **************************************************************************************************/

/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
	#include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
	#include  "00_LIB/01_BIT_MATH/BIT_MATH.h"
	#include "00_LIB/02_Delay/Delay_interface.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
	#include"01_MCAL/01_GPIO/GPIO_private.h"
	#include"01_MCAL/01_GPIO/GPIO_interface.h"
	#include"01_MCAL/01_GPIO/GPIO_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




void GPIO_vSetMode(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Mode	Copy_u8Mode)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Mode<=GPIO_Analog))
	{
		switch(Copy_u8GPIOPortNum)
		{
		case GPIO_A: MGPIOA->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_B: MGPIOB->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_C: MGPIOC->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_D: MGPIOD->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_E: MGPIOE->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_H: MGPIOH->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		default: /*error*/;
		}
	}else
	{
		/*error*/
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetType(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Output_Type	Copy_u8Type)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Type<=OpenDrain))
		{
			switch(Copy_u8GPIOPortNum)
			{
			case GPIO_A: MGPIOA->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_B: MGPIOB->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_C: MGPIOC->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_D: MGPIOD->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_E: MGPIOE->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_H: MGPIOH->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			default: /*error*/;
			}
		}else
		{
			/*error*/
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetSpeed(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Speed	Copy_u8Speed)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Speed<=VeryHighSpeed))
		{
			switch(Copy_u8GPIOPortNum)
			{
			case GPIO_A: MGPIOA->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_B: MGPIOB->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_C: MGPIOC->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_D: MGPIOD->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_E: MGPIOE->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_H: MGPIOH->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			default: /*error*/;
			}
		}else
		{
			/*error*/
		}
}

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void GPIO_vSetPullUpPullDown(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_PUPD	Copy_u8PullUpPullDown)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8PullUpPullDown<=Pull_Down))
			{
				switch(Copy_u8GPIOPortNum)
				{
				case GPIO_A: MGPIOA->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_B: MGPIOB->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_C: MGPIOC->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_D: MGPIOD->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_E: MGPIOE->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_H: MGPIOH->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				default: /*error*/;
				}
			}else
			{
				/*error*/
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetAlternateFunction(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_AF	Copy_u8AF)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8AF<=AF15))
	{
		switch(Copy_u8GPIOPortNum)
		{
		case GPIO_A: MGPIOA->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_B: MGPIOB->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_C: MGPIOC->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_D: MGPIOD->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_E: MGPIOE->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_H: MGPIOH->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		default: /*error*/;
		}
	}else
	{
		//error
	}
}
/*void GPIO_vSetAlternateFunction(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_AF	Copy_u8AF)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8AF<=AF15))
	{
		if(Copy_u8Pin<=7)
		{
			switch(Copy_u8GPIOPortNum)
								{
								case GPIO_A: GPIOA->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_B: GPIOB->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_C: GPIOC->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_D: GPIOD->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_E: GPIOE->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_H: GPIOH->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								default: //error;
								}
		}else if(Copy_u8Pin<=15)
		{
			Copy_u8Pin %=8;
			switch(Copy_u8GPIOPortNum)
											{
											case GPIO_A: GPIOA->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_B: GPIOB->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_C: GPIOC->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_D: GPIOD->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_E: GPIOE->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_H: GPIOH->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											default: //error;
											}
		}
	}else
	{
		//error
	}
}
*/

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vWritePinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_State Copy_u8State)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8State<=HighState))
	{
		switch(Copy_u8State)
		{
		case LowState:
			Copy_u8Pin +=16;
			switch(Copy_u8GPIOPortNum)
								{
								case GPIO_A: SET_BIT(MGPIOA->BSRR,Copy_u8Pin);break;
								case GPIO_B: SET_BIT(MGPIOB->BSRR,Copy_u8Pin);break;
								case GPIO_C: SET_BIT(MGPIOC->BSRR,Copy_u8Pin);break;
								case GPIO_D: SET_BIT(MGPIOD->BSRR,Copy_u8Pin);break;
								case GPIO_E: SET_BIT(MGPIOE->BSRR,Copy_u8Pin);break;
								case GPIO_H: SET_BIT(MGPIOH->BSRR,Copy_u8Pin);break;
								default: /*error*/;
								}
			break;
			case HighState:
				switch(Copy_u8GPIOPortNum)
									{
									case GPIO_A: SET_BIT(MGPIOA->BSRR,Copy_u8Pin);break;
									case GPIO_B: SET_BIT(MGPIOB->BSRR,Copy_u8Pin);break;
									case GPIO_C: SET_BIT(MGPIOC->BSRR,Copy_u8Pin);break;
									case GPIO_D: SET_BIT(MGPIOD->BSRR,Copy_u8Pin);break;
									case GPIO_E: SET_BIT(MGPIOE->BSRR,Copy_u8Pin);break;
									case GPIO_H: SET_BIT(MGPIOH->BSRR,Copy_u8Pin);break;
									default: /*error*/;
									}
				break;
				default: /*error*/;
		}
	}else
	{
		/*error*/
	}
}


/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void GPIO_vGetPinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,u8 *Copy_pu8ReadValue)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_pu8ReadValue!=0))
			{
				switch(Copy_u8GPIOPortNum)
				{
				case GPIO_A: *Copy_pu8ReadValue=GET_BIT(MGPIOA->IDR,Copy_u8Pin);break;
				case GPIO_B: *Copy_pu8ReadValue=GET_BIT(MGPIOB->IDR,Copy_u8Pin);break;
				case GPIO_C: *Copy_pu8ReadValue=GET_BIT(MGPIOC->IDR,Copy_u8Pin);break;
				case GPIO_D: *Copy_pu8ReadValue=GET_BIT(MGPIOD->IDR,Copy_u8Pin);break;
				case GPIO_E: *Copy_pu8ReadValue=GET_BIT(MGPIOE->IDR,Copy_u8Pin);break;
				case GPIO_H: *Copy_pu8ReadValue=GET_BIT(MGPIOH->IDR,Copy_u8Pin);break;
				default: /*error*/;
				}
			}else
			{
				/*error*/
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vLockPin(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin)
{

}
/*====================================================   END_ FUNCTION   ====================================================*/
void MGPIO_vPortOutputOneByte(GPIO_PortNum	Copy_u8GPIOPortNum, u8 Copy_u8Data, u8 Copy_u8StartBit)
{

	switch(Copy_u8GPIOPortNum){
		case GPIO_A :
							/* In ODR  shift ( 0000 0000 ) to the start bit & sheft data to the start bit  */
			MGPIOA->ODR = (MGPIOA->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case GPIO_B :
			MGPIOB->ODR = (MGPIOB->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case GPIO_C :
			MGPIOC->ODR = (MGPIOC->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case GPIO_D :
			MGPIOD->ODR = (MGPIOD->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case GPIO_E :
			MGPIOE->ODR = (MGPIOE->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
		case GPIO_H :
			MGPIOH->ODR = (MGPIOH->ODR & ~(0xff << (Copy_u8StartBit ))) | (Copy_u8Data << (Copy_u8StartBit));
			break;
	}

}
