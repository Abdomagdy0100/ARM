/****************************************************************
 ************  - STK_interface.h               ******************
 ***********   - Created: 5/19/2022			   ******************
 ***********   - Author: Abdelrahman_Magdy     ******************
 ***********   - Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

/**************		The Archictect Give The API		**************/
/**************  Application Public Interface   **************/
/*****************************************************************
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
******************************************************************/



#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

	#include  "00_LIB/00_STD_TYPES/STD_TYPES.h"






#define _MSTK_CLK_AHB             0U
#define _MSTK_CLK_AHB_8			  1U

#define _MODE_SINGLE              0U
#define _MODE_PERIODIC            1U

/*	1- Function Only Apply The Clock From Configer ( AHB or( AHB/8---> 1MHZ) So 1 = 1Msec & Disable SysTick Interrupt & Disa-ble SysTick  */
void MSTK_vInit(void);

/*  2- Function Take Count or Ticks So Timer Count Them And you Config ( Tick = Time ) MSec  ---> Make Delay (Synchronous_Fun)*/
void MSTK_vBusyWait(u32 Copy_u32TicksNUM);

/* 	3- Function  Return The Remaining Time */
u32 MSTK_u32GetRemainingTime(void);

/*  4- Function  Return The Remaining Time */
u32 MSTK_u32GetElapsedTime(void);

/*  5- Function To Enable Interrupt */
void MSTK_vEnableINT(void);

/*  6- Function To Disable Interrupt */
void MSTK_vDisableINT(void);

void MSTK_vSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* ptr)(void));
void MSTK_vSetIntervalSingle(u32 Copy_u32TicksNUM , void (* ptr)(void));
void MSTK_voidStopInterval(void) ;

/*  9- Function To Stop The Interval If It Was Periodic Or Single*/















#endif

/****************************************************************
***********              End of guard               *************
******************************************************************/
