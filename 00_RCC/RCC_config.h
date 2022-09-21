/*======================================================================================
========================    - RCC_config.h					 ===========================
========================    - Created: 17/6/2022			     ===========================
========================    -  Author: Shimaa Samir      ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/ 
/***
 *      _____   _____ _____             _____ ____  _   _ ______ _____ _____ 
 *     |  __ \ / ____/ ____|           / ____/ __ \| \ | |  ____|_   _/ ____|
 *     | |__) | |   | |       ______  | |   | |  | |  \| | |__    | || |  __ 
 *     |  _  /| |   | |      |______| | |   | |  | | . ` |  __|   | || | |_ |
 *     | | \ \| |___| |____           | |___| |__| | |\  | |     _| || |__| |
 *     |_|  \_\\_____\_____|           \_____\____/|_| \_|_|    |_____\_____|
 *                                                                           
 *                                                                           
 */

/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

/*=======================================================================================
=====================     guard of file will call on time in .c  	=====================
=========================================================================================*/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*
	- CLKSRC option :
			         1) HSI
			         2) HSE
			         3) PLL
*/
      #define CLKSRC  HSE
/*
   - HSE option :
                 1)_HSE_CRYSTAL
                 2)_HSE_RC
*/

       #define HSE_SRC  _HSE_CRYSTAL
/*
   - PLL option :
	            1) _HSE_PLL
                2) _HSI_PLL
 */
      #define PLL_SRC _HSE_PLL

#endif // RCC_CONFIG_H

/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/
