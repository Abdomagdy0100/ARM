/*=======================================================================================
============================   - TFT_program.c				 ============================
============================   - Created: 17/6/2022			 ============================
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
		#include"01_MCAL/00_RCC/RCC_interface.h"
		#include"01_MCAL/01_GPIO/GPIO_interface.h"
		#include"01_MCAL/05_SPI/SPI_interface.h"
		#include"01_MCAL/08_STK/STK_interface.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
		#include"02_HAL/03_TFT/TFT_interface.h"
		#include"02_HAL/03_TFT/TFT_config.h"
		#include"02_HAL/03_TFT/TFT_private.h"
/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
 void HTFT_voidInit(void)
 {

	 	MGPIO_vSetPinMode(TFT_A0_PIN,MODE_OUTPUT);//CONT
	 	MGPIO_vSetPinOutPutType(TFT_A0_PIN,PUSH_PULL);
	 	MGPIO_vSetPinOutSpeed(TFT_A0_PIN,LOW_SPEED);

	 	MGPIO_vSetPinMode(TFT_RST_PIN,MODE_OUTPUT);//RES
	 	MGPIO_vSetPinOutPutType(TFT_RST_PIN,PUSH_PULL);
	 	MGPIO_vSetPinOutSpeed(TFT_RST_PIN,LOW_SPEED);

		MGPIO_vSetPinMode(SCK_PIN,MODE_ALTF);//SCK
		MGPIO_vSetPinAltFn(SCK_PIN,ALTF_5);
		MGPIO_vSetPinOutPutType(SCK_PIN,PUSH_PULL);
		MGPIO_vSetPinOutSpeed(SCK_PIN,VERY_HIGH_SPEED);

		MGPIO_vSetPinMode(MOSI_PIN,MODE_ALTF);//MOSI
		MGPIO_vSetPinAltFn(MOSI_PIN,ALTF_5);
		MGPIO_vSetPinOutPutType(MOSI_PIN,PUSH_PULL);
		MGPIO_vSetPinOutSpeed(MOSI_PIN,VERY_HIGH_SPEED);

	 	//  MSTK_vInit();

	 	 /*rest puls*/
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_LOW);
		  MSTK_vBusyWait(1);
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_LOW);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(120000);

		  /*sleep out mode*/
		  voidWriteCommand(sleep_out_command);

		  /*dealy 150ms*/
		  MSTK_vBusyWait(150000);

		  /*color mode*/
		  voidWriteCommand(color_Mode_Command);
		  VoidWriteData(RGB565_data);

		  /*display on*/
		  voidWriteCommand(Dispaly_On);


	 
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u32 counter = 0;
	/*set x aderess*/

	voidWriteCommand(x_aderess);
	VoidWriteData(0);  //start byte 0 0
	VoidWriteData(0);
	VoidWriteData(0);  //END BYTE 0 127
	VoidWriteData(239);

	/*set Y aderess*/

	voidWriteCommand(y_aderess);
	VoidWriteData(0);  //start byte
	VoidWriteData(0);
	VoidWriteData(0);
	VoidWriteData(319);

	/*RAM WRITE  */
	voidWriteCommand(ram_write);
	for(counter =0; counter <76800 ;counter++)
	{
		/*write the high byte / pixel*/
		VoidWriteData(Copy_Image[counter ]>>8);
		/*write the low byte / pixel*/
		VoidWriteData(Copy_Image[counter ]&0x00ff);

	}

}
/*====================================================   END_ FUNCTION   ====================================================*/
static void voidWriteCommand(u8 Copy_u8Command)
{

	/* set data pin to low A0*/
	MGPIO_vWriteData(TFT_A0_PIN,_LOW);
	/*send command over spi*/
	MSPI1_u16TrasRes(Copy_u8Command);
}

static void VoidWriteData(u16 Copy_u8Data)
{
	/* set data pin to high A0*/
	MGPIO_vWriteData(TFT_A0_PIN,_HIGH);
	/*send data over spi*/
	MSPI1_u16TrasRes(Copy_u8Data);
	
}
