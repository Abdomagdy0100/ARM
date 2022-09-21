/****************************** *********************************************************
 ***************************  -NVIC_program.c				 ****************************
*========================    - Created: 19/6/2022	         ===========================
========================    - Author: Shimaa Samir           ===========================
========================     Version : _1_				     ===========================
========================    - Note :
									*-
									*-
 **************************************************************************************/

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
	 	 #include  "00_LIB/01_BIT_MATH/BIT_MATH.h"
		 #include "00_LIB/02_Delay/Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include"01_MCAL/02_NVIC/NVIC_private.h"
		#include"01_MCAL/02_NVIC/NVIC_interface.h"
		#include"01_MCAL/02_NVIC/NVIC_config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/



void MNVIC_vEnableIRQ(IRQn_t Copy_tIRQ)
{
	if(Copy_tIRQ<=31)
	{
		NVIC->ISER[0]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=63)
	{
		Copy_tIRQ-=32;
		NVIC->ISER[1]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=84)
	{
		Copy_tIRQ-=64;
		NVIC->ISER[1]=(1U<<Copy_tIRQ);
	}
	else 
	{
		/*return error*/
	}
}
void MNVIC_vDisableIRQ(IRQn_t Copy_tIRQ)
{
	if(Copy_tIRQ<=31)
	{
		NVIC->ICER[0]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=63)
	{
		Copy_tIRQ-=32;
		NVIC->ICER[1]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=84)
	{
		Copy_tIRQ-=64;
		NVIC->ICER[1]=(1U<<Copy_tIRQ);
	}
	else 
	{
		/*return error*/
	}
}
void MNVIC_vSetPindeng(IRQn_t Copy_tIRQ)
{
	if(Copy_tIRQ<=31)
	{
		NVIC->ISPR[0]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=63)
	{
		Copy_tIRQ-=32;
		NVIC->ISPR[1]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=84)
	{
		Copy_tIRQ-=64;
		NVIC->ISPR[1]=(1U<<Copy_tIRQ);
	}
	else 
	{
		/*return error*/
	}
	
}
void MNVIC_vClearSetPindeng(IRQn_t Copy_tIRQ)
{
	if(Copy_tIRQ<=31)
	{
		NVIC->ICPR[0]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=63)
	{
		Copy_tIRQ-=32;
		NVIC->ICPR[1]=(1U<<Copy_tIRQ);
	}
	else if(Copy_tIRQ<=84)
	{
		Copy_tIRQ-=64;
		NVIC->ICPR[1]=(1U<<Copy_tIRQ);
	}
	else 
	{
		/*return error*/
	}
}

u8 MNVIC_u8GetActiveFlag(IRQn_t Copy_tIRQ)
{
	u8 L_u8GetActiveFlag = 0U;
	if(Copy_tIRQ<=31)
	{
		L_u8GetActiveFlag = GET_BIT(NVIC->IABR[0],Copy_tIRQ);
	}
	else if(Copy_tIRQ<=63)
	{
		Copy_tIRQ-=32;
		L_u8GetActiveFlag = GET_BIT(NVIC->IABR[1],Copy_tIRQ);
	}
	else if(Copy_tIRQ<=84)
	{
		Copy_tIRQ-=64;
		L_u8GetActiveFlag = GET_BIT(NVIC->IABR[2],Copy_tIRQ);
	}
	else 
	{
		/*return error*/
	}
	return L_u8GetActiveFlag;
}
void MNVIC_vSetGroupPriority(IRQn_t Copy_tIRQ,u8 Copy_u8Group,u8 Copy_u8Sub)
{
	
	SCB_AIRCR=PRI_GROUP;
	#if PRI_GROUP==GROUP4_SUB0
	NVIC->IP[Copy_tIRQ]=((Copy_u8Group<<0)<<(4));
	#elif PRI_GROUP==GROUP3_SUB1
	NVIC->IP[Copy_tIRQ]=(((Copy_u8Group<<1)|(Copy_u8Sub))<<(4));
	#elif PRI_GROUP==GROUP2_SUB2
	NVIC->IP[Copy_tIRQ]=(((Copy_u8Group<<2)|(Copy_u8Sub))<<(4));
	#elif PRI_GROUP==GROUP1_SUB3
	NVIC->IP[Copy_tIRQ]=(((Copy_u8Group<<3)|(Copy_u8Sub))<<(4));
	#elif PRI_GROUP==GROUP0_SUB4
	NVIC->IP[Copy_tIRQ]=((Copy_u8Sub)<<(4));
	#endif


}
