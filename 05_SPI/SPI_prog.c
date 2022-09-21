/*=======================================================================================
============================   - SPI_program.c				 ============================
============================   - Created:20/6/2022			 ============================
============================   -  Author: Shimaa Samir   ============================
============================   - Version : _1_				 ============================
============================   - Note :  
									     *-
									     *-
=======================================================================================*/ 

/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include  "00_LIB/00_STD_TYPES/STD_TYPES.h"
	 	 #include  "00_LIB/01_BIT_MATH/BIT_MATH.h"
		 #include "00_LIB/02_Delay/Delay_interface.h"

/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include"01_MCAL/05_SPI/SPI_config.h"
		#include"01_MCAL/05_SPI/SPI_interface.h"
		#include"01_MCAL/05_SPI/SPI_private.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	



void (* MSPI1_CallBack)(void) = '\0' ;

/********************************************************** Start_FUNCTION  **********************************************************/


void MSPI_vInit(u8 Copy_u8SPIIndex)
{
	/* Create Var from CR1_REG */
	CR1_REG cfg ;

	/* 1.SET PHASE */
	cfg.CPHA = SPI_PHASE;
	/* 2.SET PLO */
	cfg.CPOL = SPI_POLARITY;
	/* 3.SET MASTER OR SLAVE */
	cfg.MSTR = SPI_MASTER_SLAVE;
	/* 4.SET BOUD RATE */
	cfg.BR = BUAD_RATE;

	/* 5.SET SSM */
	cfg.SSM = SSM_STATE;

	/* 6.SET SSI */
	cfg.SSI = SSI_STATE;
	/* 7.SET DATA ORDER */
	cfg.LSBFIRST = DATA_ORDER;
	/* 8.SET DATA FORMAT */
	cfg.DFF = DATA_FORMAT;

	switch (Copy_u8SPIIndex)
	{
	case _SPI_1_ : MSPI1 -> CR1 =cfg; break;
	case _SPI_2_ : MSPI2 -> CR1 =cfg; break;
	case _SPI_3_ : MSPI3 -> CR1 =cfg; break;
	case _SPI_4_ : MSPI4 -> CR1 =cfg; break;
	default      : /*  */ break;

	}

}



/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
void MSPI_vEnable(u8 Copy_u8SPIIndex)
{
	switch (Copy_u8SPIIndex)
	{
	    case _SPI_1_ : MSPI1 -> CR1 . SPE=1U; break;
		case _SPI_2_ : MSPI2 -> CR1 . SPE=1U; break;
		case _SPI_3_ : MSPI3 -> CR1 . SPE=1U; break;
		case _SPI_4_ : MSPI4 -> CR1 . SPE=1U; break;
		default      : /*  */ break;


	}



}


/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI_vDisable(u8 Copy_u8SPIIndex)
{
	switch (Copy_u8SPIIndex)
		{
		    case _SPI_1_ : MSPI1 -> CR1 . SPE=0U; break;
			case _SPI_2_ : MSPI2 -> CR1 . SPE=0U; break;
			case _SPI_3_ : MSPI3 -> CR1 . SPE=0U; break;
			case _SPI_4_ : MSPI4 -> CR1 . SPE=0U; break;
			default      : /*  */ break;


		}


}




/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/

u16 MSPI1_u16TrasRes( u16 Copy_u16Data )
{
	u16 L_u16Data =0;
	while (GET_BIT(MSPI1 -> SR , 7));
	MSPI1 -> DR = Copy_u16Data;
	while (GET_BIT(MSPI1 -> SR , 7));
	L_u16Data = MSPI1 -> DR;
	return L_u16Data;




}

/*********************************************************** END_ FUNCTION   *********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
void MSPI1_vSetCallBack( void (* ptr)(void) )
{
	/* Set CallBack */
	MSPI1_CallBack = ptr ;
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void SPI1_IRQHandler(void)
{

	/* Excute Call Back*/
	MSPI1_CallBack();
}

/*********************************************************** END_ FUNCTION   *********************************************************/
