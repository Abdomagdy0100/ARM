/*=======================================================================================
============================   - RCC_program.c				 ============================
============================   - Created: 17/6/2022			 ============================
============================   -  Author: Abdelrahman Magdy   ============================
============================   - Version : _1_				 ============================
============================   - Note :  
									     *-
									     *-
=======================================================================================*/ 
/***
 *      _____   _____ _____            _____  _____   ____   _____ _____            __  __ 
 *     |  __ \ / ____/ ____|          |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |
 *     | |__) | |   | |       ______  | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |
 *     |  _  /| |   | |      |______| |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |
 *     | | \ \| |___| |____           | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |
 *     |_|  \_\\_____\_____|          |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|
 *                                                                                         
 *                                                                                         
 */
/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
	 	 #include  "00_LIB/01_BIT_MATH/BIT_MATH.h"
		 #include "00_LIB/02_Delay/Delay_interface.h"

/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include"01_MCAL/00_RCC/RCC_config.h"
		#include"01_MCAL/00_RCC/RCC_interface.h"
		#include"01_MCAL/00_RCC/RCC_private.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	- Function To Enable Prepheral :
	
							       - BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/


void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	switch(BusName)
	{
		case AHB1:SET_BIT( MRCC-> AHB1ENR,Copy_u8PerNum ); break;
		case AHB2:SET_BIT( MRCC-> AHB2ENR,Copy_u8PerNum ); break;
		case APB1:SET_BIT( MRCC-> APB1ENR,Copy_u8PerNum ); break;
		case APB2:SET_BIT( MRCC-> APB2ENR,Copy_u8PerNum ); break;
		default :     /*BusName_t error*/                    break;
	}
	
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

 /*
	- Function To Disable Prepheral :
	
							       - BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2  , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/

void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
		switch(BusName)
	{
		case AHB1:CLR_BIT( MRCC -> AHB1ENR,Copy_u8PerNum ); break;
		case AHB2:CLR_BIT( MRCC -> AHB2ENR,Copy_u8PerNum ); break;
		case APB1:CLR_BIT( MRCC -> APB1ENR,Copy_u8PerNum ); break;
		case APB2:CLR_BIT( MRCC -> APB2ENR,Copy_u8PerNum ); break;
		default :     /*BusName_t error*/                    break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

/*
* Function To Enable Security System
*/

void MRCC_vEnableSecuritySystem(void)
{
	
	SET_BIT( MRCC -> CR,CSSON );
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Disable Security System
*/

void MRCC_vDisableSecuritySystem(void)
{
	
	CLR_BIT( MRCC -> CR,CSSON );
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
 */

void MRCC_vInitSystemCLK(void)
{
	#if      CLKSRC == HSI
			// ENABLE HSI
			SET_BIT( MRCC -> CR , 0U  );
			// CONFIG HSI
			CLR_BIT(MRCC -> CFGR , 0U);
			CLR_BIT(MRCC -> CFGR , 1U);
	#elif	 CLKSRC == HSE
			// ENABLE HSE
			SET_BIT(MRCC -> CR , 16U );
			// CONFIG HSE
			SET_BIT(MRCC -> CFGR , 0U);
			CLR_BIT(MRCC -> CFGR , 1U);
			#if    HSE_SRC == _HSE_CRYSTAL
			//CLEAR BY PASS 
				CLR_BIT(MRCC -> CR , 18U  );
			#elif  HSE_SRC == _HSE_RC 
			//SET BY PASS
				SET_BIT(MRCC -> CR , 18U  );
			#else
				/* Error CLKSRC */
			#endif
			
	#elif    CLKSRC == PLL
			#if PLL_SRC == _HSE_PLL 
				/*1-Enable HSE */
				SET_BIT(MRCC->CR,16U);
				/* while ( GET_BIT(RCC_CR, 17)==0);*/
				/*2- Disable PLL*/
				CLR_BIT(MRCC->CR,24U);
				/* while ( GET_BIT(RCC_CR, 25)==0);*/
				/* 3- PLL From HSE */
				SET_BIT(MRCC->PLLCFGR, 22U);
				/*4- Enable PLL*/
				SET_BIT(MRCC->CR,24U);
				/* 5- System Clk  PLL */
				CLR_BIT(MRCC->CFGR,0U);
				SET_BIT(MRCC->CFGR,1U);
				/*************************/
				#if HSE_SRC == _HSE_RC
					/* - Enable BYP */
					SET_BIT(MRCC->CR,18U);
				#elif HSE_SRC == _HSE_CRYSTAL
					/*- Disable BYP */
					CLR_BIT(MRCC->CR,18U);
				#else
					/*	ERROR HSE_SRC	*/
				#endif
 /*****************************************************************/
			#elif PLL_SRC == _HSI_PLL  
				/*Enable HSI */
				SET_BIT(MRCC->CR,0U);
				/*2- Disable PLL*/
				CLR_BIT(MRCC->CR,24U);
				/* 3- PLL From HSI */
				CLR_BIT(MRCC->PLLCFGR, 22U);
				/*4- Enable PLL*/
				SET_BIT(MRCC->CR,24U);
				/* 5- System Clk  PLL */
				CLR_BIT(MRCC->CFGR,0U);
				SET_BIT(MRCC->CFGR,1U);
			#else 
				/* Error PLL_SRC*/
			#endif
	#else
			/*Error SystemCLK */
	#endif

}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/


void MRCC_vOutMCO_1(MCO1_OP_t MC1_0SRC )
{
 switch(MC1_0SRC)
 {
	 case MCO1_HSI :
		 CLR_BIT(MRCC-> CFGR, 21U);
		 CLR_BIT(MRCC-> CFGR, 22U);
	 break;
	 case MCO1_LSE : 
		SET_BIT(MRCC-> CFGR,21U);
		CLR_BIT(MRCC-> CFGR,22U);
	 break;
	 case MCO1_HSE : 
		CLR_BIT(MRCC-> CFGR,21U);
		SET_BIT(MRCC-> CFGR,22U);
	 break;
	 case MCO1_PLL : 
		SET_BIT(MRCC ->CFGR,21U);
		SET_BIT(MRCC ->CFGR,22U);
	 break;
	 default:
	 break;
 }
}

/*====================================================   END_ FUNCTION   ====================================================*/

void MRCC_vOutMCO_1Pre(MCO_1_Pre_t PreMco_1 )
{
	switch(PreMco_1)
	{
		case MCO_1_Div_1:
				CLR_BIT(MRCC ->CFGR,24U);
				CLR_BIT(MRCC ->CFGR,25U);
				CLR_BIT(MRCC ->CFGR,26U);
		break;
		case MCO_1_Div_2:
				CLR_BIT(MRCC ->CFGR,24U);
				CLR_BIT(MRCC ->CFGR,25U);
				SET_BIT(MRCC ->CFGR,26U);
		break;
		case MCO_1_Div_3:
				SET_BIT(MRCC ->CFGR,24U);
				CLR_BIT(MRCC ->CFGR,25U);
				SET_BIT(MRCC ->CFGR,26U);
		break;
		case MCO_1_Div_4:	
				CLR_BIT(MRCC ->CFGR,24U);
				SET_BIT(MRCC ->CFGR,25U);
				SET_BIT(MRCC ->CFGR,26U);
		break;
		case MCO_1_Div_5:
				SET_BIT(MRCC ->CFGR,24U);
				SET_BIT(MRCC ->CFGR,25U);
				SET_BIT(MRCC ->CFGR,26U);
		break;
		default:
		break;
	}
}

/*====================================================   END_ FUNCTION   ====================================================*/


