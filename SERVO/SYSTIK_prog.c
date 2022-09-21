/*
  Author : Mohamed Helmi
  Date   : 19-5-2022
  Version: V1
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTIK_interface.h"
#include "SYSTIK_private.h"
#include "SYSTIK_config.h"

void MSTK_vInit(void)
{
	#if MSTK_CLK_SRC == MSTK_CLK_AHB_8
	    
		SYSTIK->CTRL=0;
	#elif MSTK_CLK_SRC == MSTK_CLK_AHB
	    SET_BIT(SYSTIK->CTRL,CLKSOURCE);
		CLR_BIT(SYSTIK->CTRL,STK_ENABLE);
		CLR_BIT(SYSTIK->CTRL,TICKINT);
	
	#else 
		
	#endif
}
void MSTK_vBusyWait(u32 Copy_u32TicksNum)
{
	SYSTIK->LOAD = Copy_u32TicksNum;
	SET_BIT(SYSTIK->CTRL,STK_ENABLE);
	
	while(GET_BIT(SYSTIK->CTRL,COUNTFLAG) == 0 );
	
	
	CLR_BIT(SYSTIK->CTRL,STK_ENABLE);
	SYSTIK->LOAD = 0;
	SYSTIK->VAL = 0;
	
}
u32  MSTK_u32GetRemTime(void)
{
	return SYSTIK->VAL ;
}
u32  MSTK_u32GetElapsedTime(void)
{
	return ((SYSTIK->LOAD) - (SYSTIK->VAL));
}
void MSTK_vEnableInterrupt(void)
{
	SET_BIT(SYSTIK->CTRL,TICKINT);
}
void MSTK_vDisableInterrupt(void)
{
	CLR_BIT(SYSTIK->CTRL,TICKINT);
}
u8 G_Interval_t = 0;
void (*STK_vCallBack)(void);
void MSTK_vSingleInterval(u32 Copy_u32Time ,void (*Func_Ptr)(void))
{
	SYSTIK->LOAD = Copy_u32Time;
	SET_BIT(SYSTIK->CTRL,STK_ENABLE);
	SET_BIT(SYSTIK->CTRL,TICKINT);
	
	G_Interval_t = MODE_SINGLE;
	
	STK_vCallBack=Func_Ptr;
	
}
void MSTK_vPeriodicInterval(u32 Copy_u32Time ,void (*Func_Ptr)(void))
{
	SYSTIK->LOAD = Copy_u32Time;
	SET_BIT(SYSTIK->CTRL,STK_ENABLE);
	SET_BIT(SYSTIK->CTRL,TICKINT);
	
	G_Interval_t = MODE_PERIODIC;
	
	STK_vCallBack=Func_Ptr;
}

void SysTick_Handler(void)
{
	STK_vCallBack();
	if( G_Interval_t == MODE_SINGLE )
	{
		CLR_BIT(SYSTIK->CTRL,STK_ENABLE);
	    SYSTIK->LOAD = 0;
	    SYSTIK->VAL = 0;
	}
}
