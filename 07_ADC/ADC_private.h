/*==============================================================================================
===============================   - ADC_private.h				 ===============================
===============================   - Created: 17/6/2022			 ===============================
===============================   -  Author: Abdelrahman Magdy    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

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

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
 
/*================================================================
	-----> Macros
			*  ADC_Base_Address is		0x40012000 	
=================================================================*/

#define  ADC_BASE_ADDRESS    		 0x40012000

/*================================================================
	-----> Struct
			*  Register Map
=================================================================*/
typedef struct 
{
	volatile u32 AWDCH 		:5;
	volatile u32 EOCIE 		:1;
	volatile u32 AWDIE 		:1;
	volatile u32 JEOCIE 	:1;
	volatile u32 SCAN   	:1;
	volatile u32 AWDSGL  	:1;
	volatile u32 JAUTO   	:1;
	volatile u32 DISCEN 	:1;
	volatile u32 JDISCEN 	:1;
	volatile u32 DISCNUM 	:3;
	volatile u32 Reserved0  :6;
	volatile u32 JAWDEN 	:1;
	volatile u32 AWDEN 		:1;
	volatile u32 RES 		:2;
	volatile u32 OVRIE 		:1;
	volatile u32 Reserved1  :5;
	
}CR1_t;


typedef struct 
{
	volatile u32 ADON 		:1;
	volatile u32 CONT 		:1;
	volatile u32 Reserved1  :6;
	volatile u32 DMA	 	:1;
	volatile u32 DDS 		:1;
	volatile u32 EOCS 		:1;
	volatile u32 ALIGN 		:1;
	volatile u32 reserved2	:4;
	volatile u32 JEXTSEL 	:3;
	volatile u32 JEXTEN		:2;
	volatile u32 JSWSTART 	:1;
	volatile u32 reserved3 	:4;
	volatile u32 EXTEN 		:2;
	volatile u32 SWSTART 	:1;
	volatile u32 reserved4 	:1;
	
}CR2_t;



typedef struct
{
	volatile u32 	 SR;
	CR1_t 		 	 CR1;
	CR2_t		 	 CR2;
	volatile u32 	 SMPR1;
	volatile u32 	 SMPR2;
	volatile u32 	 JOFR[4];
	volatile u32 	 HTR;
	volatile u32 	 LTR;
	volatile u32	 SQR1;
	volatile u32	 SQR2;
	volatile u32	 SQR3;
	volatile u32	 JSQR;
	volatile u32 	 JDR[4];
	volatile u32 	 DR;

}ADC_t;


typedef struct
{
	volatile u32 	 SR;
	volatile u32  	 CR1;
	volatile u32 	 CR2;
	volatile u32 	 SMPR1;
	volatile u32 	 SMPR2;
	volatile u32 	 JOFR[4];
	volatile u32 	 HTR;
	volatile u32 	 LTR;
	volatile u32	 SQR1;
	volatile u32	 SQR2;
	volatile u32	 SQR3;
	volatile u32	 JSQR;
	volatile u32 	 JDR[4];
	volatile u32 	 DR;

}ADC1_t;

/*================================================================
	-)Struct Macros :
			*  Base_Address  				
=================================================================*/
#define MADC ((ADC_t*)(ADC_BASE_ADDRESS))
#define CCR   (*(( volatile u32* )(ADC_BASE_ADDRESS + 0x304)))
#define MADC1 ((ADC1_t*)(ADC_BASE_ADDRESS))


#endif //END ADC
