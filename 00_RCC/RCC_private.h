/*==============================================================================================
===============================   - RCC_private.h				 ===============================
===============================   - Created: 17/6/2022			 ===============================
===============================   -  Author: Shimaa Samir    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 
/***
 *      _____   _____ _____            _____  _____       __      _______ _______ ______ 
 *     |  __ \ / ____/ ____|          |  __ \|  __ \     /\ \    / /_   _|__   __|  ____|
 *     | |__) | |   | |       ______  | |__) | |__) |   /  \ \  / /  | |    | |  | |__   
 *     |  _  /| |   | |      |______| |  ___/|  _  /   / /\ \ \/ /   | |    | |  |  __|  
 *     | | \ \| |___| |____           | |    | | \ \  / ____ \  /   _| |_   | |  | |____ 
 *     |_|  \_\\_____\_____|          |_|    |_|  \_\/_/    \_\/   |_____|  |_|  |______|
 *                                                                                       
 *                                                                                       
 */
/*===============================================================================================

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
/*================================================================
	-----> Macros
			*  Base_Address is			0x4002 3800 	
=================================================================*/

#define  MRCC_BASE_ADDRESS     0x40023800

/*================================================================
	-----> Struct
			*  Register Map
=================================================================*/
typedef struct
{
	 volatile u32 CR;                 
	 volatile u32 PLLCFGR;
	 volatile u32 CFGR;
	 volatile u32 CIR;
	 volatile u32 AHB1RSTR;
	 volatile u32 AHB2RSTR;
	 volatile u32 Reserved_0[2];
	 volatile u32 APB1RSTR;
	 volatile u32 APB2RSTR;
	 volatile u32 Reserved_1[2];
	 volatile u32 AHB1ENR;
	 volatile u32 AHB2ENR;
	 volatile u32 Reserved_2[2];
	 volatile u32 APB1ENR;
	 volatile u32 APB2ENR;
	 volatile u32 Reserved_3[2];
	 volatile u32 AHB1LPENR;
	 volatile u32 AHB2LPENR;
	 volatile u32 Reserved_4[2];
	 volatile u32 APB1LPENR;
	 volatile u32 APB2LPENR;
	 volatile u32 Reserved_5[2];
	 volatile u32 BDCR;
	 volatile u32 CSR;
	 volatile u32 Reserved_6[2];
	 volatile u32 SSCGR;
	 volatile u32 PLLI2SCFGR;
	 volatile u32 Reserved;
	 volatile u32 DCKCFCR;
	
}RCC_t;

/*----------------------------------*/
#define CSSON 19U
/*----------------------------------*/


/*================================================================
	-)Struct Macros :
			*  Base_Address RRC 				
=================================================================*/
//#define MRCC  (RCC_t*)(RCC_BASE_ADDRESS)
#define MRCC      ((RCC_t *)(MRCC_BASE_ADDRESS))
#endif //RCC_PRIVATE_H
