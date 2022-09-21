/*======================================================================================
===========================   - TFT_interface.h			     ===========================
===========================   - Created: 17/6/2022		 	===========================
===========================   - Author: Shimaa Samir   		===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 


 
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


#ifndef _INTERFACE_H
#define _INTERFACE_H

/*===========   INCLUDE LIB   ===========*/
		 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
	 	 #include  "00_LIB/01_BIT_MATH/BIT_MATH.h"
		 #include "00_LIB/02_Delay/Delay_interface.h"

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/

#define sleep_out_command 0x11
#define color_Mode_Command 0x3A
#define RGB444_data 0x03
#define RGB565_data 0x05
#define RGB666_data 0x06
#define Dispaly_On  0x29
#define x_aderess   0x2A
#define y_aderess   0x2B
#define ram_write   0x2C




void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* Copy_Image);  // const 3shan l memory size in ram is samllest , image htb2a array 3shan ked ktbt pointer
#endif //RCC_INTERFACE_H
