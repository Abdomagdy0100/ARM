/****************************** *********************************************************
 ***************************  - EXIT_Interface.h				 ****************************
*========================    - Created: 18/6/2022	         ===========================
========================    - Author: Abdelrahman Magdy           ===========================
========================     Version : _1_				     ===========================
========================    - Note :
									*-
									*-
 **************************************************************************************/

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/



#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
	EXTI_LINE0 =0,
	EXTI_LINE1   ,
	EXTI_LINE2   ,
	EXTI_LINE3   ,
	EXTI_LINE4   ,
	EXTI_LINE5   ,
	EXTI_LINE6   ,
	EXTI_LINE7   ,
	EXTI_LINE8   ,
	EXTI_LINE9   ,
	EXTI_LINE10  ,
	EXTI_LINE11  ,
	EXTI_LINE12  ,
	EXTI_LINE13  ,
	EXTI_LINE14  ,
	EXTI_LINE15
}EXTI_LINE_t;
typedef enum
{
	EXTI_PORTA =0   ,
	EXTI_PORTB      ,
	EXTI_PORTC      ,
	EXTI_PORTD      ,
	EXTI_PORTE      ,
	EXTI_PORTH =7   ,


}EXTI_PORT_Num;
typedef enum
{
	EXTI_FALLING =0  ,
	EXTI_RAISING     ,
	EXTI_ON_CHANGE
}EXTI_TRIG_t;
void MEXTI_vEnableLine(u8 Copy_u8Line);
void MEXTI_vDisableLine(u8 Copy_u8Line);
void MEXTI_vEventTrigger(EXTI_LINE_t Copy_eLineNum,EXTI_TRIG_t Copy_eEventTrig);
void MEXTI_vSwiTrigger(EXTI_LINE_t Copy_eLineNum);
u8 MEXTI_vGetPending(EXTI_LINE_t Copy_eLineNum);
void MEXTI_vPortConfig(EXTI_PORT_Num Copy_ePortNum,EXTI_LINE_t Copy_eLineNum);

void MEXTI1_vSetCallBack(void (*Ptr1)(void));

void MEXTI0_vSetCallBack(void (*Ptr0)(void));

#endif
