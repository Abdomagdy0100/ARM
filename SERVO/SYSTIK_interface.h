/*
  Author : Mohamed Helmi
  Date   : 19-5-2022
  Version: V1
*/

#ifndef SYSTIK_INTERFACE_H
#define SYSTIK_INTERFACE_H

#define MSTK_CLK_AHB    0U
#define MSTK_CLK_AHB_8  1U

#define MODE_SINGLE     0U
#define MODE_PERIODIC   1U


void MSTK_vInit(void);

void MSTK_vBusyWait(u32 Copy_u32TicksNum);

u32  MSTK_u32GetRemTime(void);

u32  MSTK_u32GetElapsedTime(void);

void MSTK_vEnableInterrupt(void);

void MSTK_vDisableInterrupt(void);

void MSTK_vSingleInterval(u32 Copy_u32Time ,void (*Func_Ptr)(void));

void MSTK_vPeriodicInterval(u32 Copy_u32Time ,void (*Func_Ptr)(void));







#endif
