/*
  Author : Mohamed Helmi
  Date   : 19-5-2022
  Version: V1
*/

#ifndef SYSTIK_PRIVATE_H
#define SYSTIK_PRIVATE_H

#define SYSTIK_BASE_ADDRESS 0xE000E010
typedef struct
{
	volatile u32 CTRL  ;
    volatile u32 LOAD  ;
    volatile u32 VAL   ;
    volatile u32 CALIB ;
}SYSTIK_t;


#define SYSTIK ((volatile SYSTIK_t*)(SYSTIK_BASE_ADDRESS))

#define STK_ENABLE      0U
#define TICKINT         1U
#define CLKSOURCE       2U
#define COUNTFLAG      16U



#endif