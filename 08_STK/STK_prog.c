/****************************************************************
 ************   - STK_program.c                ******************
 ***********    - Created: 5/19/2022		   ******************
 ***********    - Author: Abdelrahman_Magdy    ******************
 ***********    - Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 
#include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
#include  "00_LIB/01_BIT_MATH/BIT_MATH.h"


#include "01_MCAL/08_STK/STK_interface.h"
#include "01_MCAL/08_STK/STK_private.h"
#include "01_MCAL/08_STK/STK_config.h"


/* Global Var Take Function address */
void (  * MSTK_CallBack )(void) = 0U;
/* Global Var To set Mode */
volatile u8 G_u8Set_Mode   = 0U;
/* ProtoType of Handler of SysTick */
void SysTick_Handler(void);

/********************************************************** Start_FUNCTION  **********************************************************/
/*
	Function Only Apply The Clock From Configer (AHB or( AHB/8---> 1MHZ) So 1 = 1Msec & Disable SysTick Interrupt & Disa-ble SysTick
*/
void MSTK_vInit(void)
{
	#if _MSTK_CLK_SRC == _MSTK_CLK_AHB
	/* Disable Count ,Disable SysTick Interrupt   , Set CLK AHB*/
		CLR_BIT(MSTK -> CTRL,STK_ENABLE);
		CLR_BIT(MSTK -> CTRL,TICKINT);
		SET_BIT(MSTK -> CTRL,CLKSOURCE);
	#elif _MSTK_CLK_SRC == _MSTK_CLK_AHB_8
	/* Disable Count ,Disable SysTick Interrupt  , Set CLK AHB / 8 */
	    CLR_BIT(MSTK -> CTRL,STK_ENABLE);
		CLR_BIT(MSTK -> CTRL,TICKINT);
		CLR_BIT(MSTK -> CTRL,CLKSOURCE);
	#else
		/* ERROR */
	#endif
}
/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*
	Function Take Count or Ticks So Timer Count Them And you Config ( Tick = Time ) MSec  ---> Make Delay (Synchronous_Fun)
*/
void MSTK_vBusyWait(u32 Copy_u32TicksNUM)
{
	/* 1) Load Value Of Ticks in Load REG  */
		MSTK->LOAD = Copy_u32TicksNUM;
	/* 2) Strat Timer */
		SET_BIT(MSTK->CTRL ,STK_ENABLE);
	/* 3) Wait Count Flag Raise */
		while( GET_BIT(MSTK->CTRL,COUNTFLAG) == 0U );
	/* 4) Stop Timer */
		MSTK ->VAL = 0U;
		MSTK ->LOAD = 0U;
		CLR_BIT(MSTK->CTRL ,STK_ENABLE);
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/* 
	Function  Return The Remaining Time
*/
u32 MSTK_u32GetRemainingTime(void)
{
	u32 L_u32RemainingTime = 0U ;
	L_u32RemainingTime= MSTK ->VAL ;
	return L_u32RemainingTime;

}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* 
	Function  Return The Remaining Time
*/
u32 MSTK_u32GetElapsedTime(void)
{
	u32 L_u32ElapsedTime = 0U ;
	L_u32ElapsedTime= (  (MSTK ->LOAD)  -   (MSTK ->VAL)) ;
	return L_u32ElapsedTime;
	
}

/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* 
	Function To Enable Interrupt
*/
void MSTK_vEnableINT(void)
{
	SET_BIT(MSTK -> CTRL,TICKINT);
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* 
	Function To Disable Interrupt
*/
void MSTK_vDisableINT(void)
{
	CLR_BIT(MSTK -> CTRL,TICKINT);
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* - The Same Of Function (3) But Only Differant At ISR Will Not Mack Load And Value = 0 */
			 /*  Send Time To Clock it And What Will Call After Time Finsh   */						
		      /* Global Var Take Adress Of Function And
										After Time Out ISR Call The Global_Var Which Point To Function  
*/
void MSTK_vSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* ptr)(void))
{
	/* 1) Load Ticks in Load Reg */
	MSTK -> LOAD = Copy_u32TicksNUM;
	/* 2) Set CallBack  */
	MSTK_CallBack = ptr;
	/* 3) Set Mode Periodic */
	G_u8Set_Mode = _MODE_PERIODIC  ;
	/* 4) Enable For Interrput */
	SET_BIT(MSTK->CTRL ,TICKINT );
	/* 5) Start Time */
	SET_BIT(MSTK->CTRL , STK_ENABLE);
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* 	- Function Asynchronous Take Tick And Start To Count Them , Give Flag And Work One Time ,
		And Give Me Function And i Will Resive In Pointer To Function To Call it After Counting Ticks .
		I Will Tick The Adress Of Function And Give It To Global Var ( Call back )  And ISR D o this Func */				
			/* Only One Time */	
void MSTK_vSetIntervalSingle(u32 Copy_u32TicksNUM , void (* ptr)(void))
{
	/* 1) Load Ticks in Load Reg */
	MSTK -> LOAD = Copy_u32TicksNUM;
	/* 2) Set CallBack  */
	MSTK_CallBack = ptr;
	/* 3) Set Mode Single */
	G_u8Set_Mode = _MODE_SINGLE;
	/* 4) Enable For Interrput */
	SET_BIT(MSTK->CTRL ,TICKINT );
	/* 5) Start Time */
	SET_BIT(MSTK->CTRL , STK_ENABLE);

	
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/

/*
		- Function Will Stop The Interval If It Was Periodic Or Single
*/
void MSTK_voidStopInterval(void) 
{
	       /* Disable Interrupt*/
		CLR_BIT(MSTK->CTRL,TICKINT);
	       /* Stop Timer */
	    MSTK ->VAL = 0U;
		MSTK ->LOAD = 0U;
		CLR_BIT(MSTK->CTRL ,STK_ENABLE);



	
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/

/*
		- Handler  for Periodic & Single Mode 
*/
void SysTick_Handler(void)
{

	u8 L_u8Temp=0U;
	MSTK_CallBack();
	if (G_u8Set_Mode == _MODE_SINGLE )
	{
		  /* Disable Interrupt*/
		CLR_BIT(MSTK->CTRL,TICKINT);
	       /* Stop Timer */
	    MSTK ->VAL = 0U;
		MSTK ->LOAD = 0U;
		CLR_BIT(MSTK->CTRL ,STK_ENABLE);
		

	}
	/* Clear By Reading it*/
		L_u8Temp =GET_BIT(MSTK->CTRL,COUNTFLAG);

}
/*********************************************************** END_ FUNCTION   *********************************************************/
