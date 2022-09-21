/*=======================================================================================
============================   - _program.c				 ============================
============================   - Created: 17/6/2022			 ============================
============================   -  Author: Abdelrahman Magdy   ============================
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
		#include"01_MCAL/07_ADC/ADC_config.h"
		#include"01_MCAL/07_ADC/ADC_interface.h"
		#include"01_MCAL/07_ADC/ADC_private.h"
		#include"01_MCAL/00_RCC/RCC_interface.h"
		#include"01_MCAL/01_GPIO/GPIO_interface.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




void (*MADC1_CallBack)(void);

/*====================================================   Start_FUNCTION   ====================================================*/
/*
		>>> ALTF_01 ,PA0 >>TIM2_CH1 & TIM2_ETR 
		>>> ALTF_01 ,PA1 >>TIM2_CH2 
*/


void M_AdcInit(void)
{
	MRCC_vEnableClock(APB2 ,PERIPHERAL_EN_ADC1);
	GPIO_vSetMode(GPIO_PORT ,GPIO_PINS,GPIO_Analog);
	GPIO_vSetType(GPIO_PORT ,GPIO_PINS ,PushPull);
	GPIO_vSetSpeed(GPIO_PORT ,GPIO_PINS ,MediumSpeed);
	GPIO_vSetPullUpPullDown(GPIO_PORT ,GPIO_PINS ,Float);
	
	MADC -> CR1 .RES    = ADC_Resolution;
	MADC -> CR2 .ALIGN  = ADC_DATA_ALIGNMENT;
	MADC -> CR1 .JAUTO  = Disable;
	MADC -> CR1 .SCAN   = Disable;
	MADC -> CR1 .EOCIE  = Disable;
	MADC -> CR1 .JEOCIE = Disable;
	MADC -> CR2 .EOCS   = Enable;
	MADC -> CR2 .CONT   = Disable;
	CCR |=	(Prescaller<<(16)) ;


}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 void M_AdcEnable(void)
 {	
	 MADC -> CR2.ADON =0b1;
 }
 /*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 void M_AdcDisable(void)
 {
	 MADC -> CR2.ADON =0b0;
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 //FOR ENABLE  DIRECT SINGLE MODE 
 void M_Adc1StartConv(ADC_MODE_t Copy_u8_MODE_TYPE)
 {
	 H_Lcd_Write_String("IAM HERE ");
	 H_Lcd_Clr();
	 switch (Copy_u8_MODE_TYPE)
	 {

		 case (Regular ) :H_Lcd_Write_String("1 ");  MADC -> CR2.SWSTART  = 0b1;H_Lcd_Clr();H_Lcd_Write_String("2 ");   break;
		 case (Injected) : MADC -> CR2.JSWSTART = 0b1; break;
		 default :                                     break;
		 H_Lcd_Clr();H_Lcd_Write_String(" BYE ");

	 }
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

// << SWSTART & JSWSTART >> BITS TO START CONVERT 




void M_Adc1StopConv(ADC_MODE_t Copy_u8_MODE_TYPE)
{

	  switch (Copy_u8_MODE_TYPE)
	 { 
		 case (Regular ) : MADC -> CR2.SWSTART  = 0b0; break;
		 case (Injected) : MADC -> CR2.JSWSTART = 0b0; break;
		 default :                                       break;
	 }
	 
	
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	1) CHOOSE MODE >> REGULAR OR Injected 
	2) CHOOSE SEQ REGULAR   MDAC -> SQR1,2,3  >>REGULAR
							MDAC -> JSQR      >> Injected
	3)LENGTH (NO. OF CONVERSAION  MDAC -> SQR1,2,3 .L 		>>REGULAR
								  MDAC -> JSQR.JL           >> Injected
 */
 void M_Adc1OrderSelection(ADC_MODE_t Copy_u8_MODE_TYPE , SequenceNum_t Copy_u8SequenceNum , ChannelNum_t Copy_u8ChannelNum)
 {
	 
	 #if Copy_u8_MODE_TYPE == Regular
	 MADC ->SQR1    |= No_of_conversion <<20;
	 if(Copy_u8SequenceNum>=1 && Copy_u8SequenceNum<=6)
	 {
		 MADC ->SQR3 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else if(Copy_u8SequenceNum>=7 && Copy_u8SequenceNum<=12)
	 {
		 MADC ->SQR2 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else if (Copy_u8SequenceNum>=7 && Copy_u8SequenceNum<=12)
	 {
		 MADC ->SQR1 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else 
	 {
		 /*Error Sequance */
	 }	
	 
	 #elif Copy_u8_MODE_TYPE == Injected
	 	 MADC ->JSQR    |= No_of_conversion <<20;
	 	 MADC ->JSQR 	|= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 #endif
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 u16 M_Adc1GetInjectedRead(ChannelNum_t Copy_u8ChannelNum)
 {
	 u16 Local_u16_ReadingData = 0;

	 
	 switch (Copy_u8ChannelNum)
	 {
		 while ((GET_BIT(MADC ->SR ,2))==0); // end of the conversion of all injected channels in the group bit jeoc
	 
		 //get data 
		 case (ChannelNum_1 ) : Local_u16_ReadingData = MADC ->JDR[0];  break;
		 case (ChannelNum_2 ) : Local_u16_ReadingData = MADC ->JDR[1];  break;
		 case (ChannelNum_3 ) : Local_u16_ReadingData = MADC ->JDR[2];  break;
		 case (ChannelNum_4 ) : Local_u16_ReadingData = MADC ->JDR[3];  break;
		 default              :                                       break;
	 }
	 return Local_u16_ReadingData;       //return it
 }
 
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 u16 M_Adc1GetRegularRead(void)
 {
	 u16 Local_u16_ReadingData = 0;
	 //while ((GET_BIT(MDAC ->SR ,1))==0); // end of the conversion of all injected channels in the group bit eoc
	 while ((GET_BIT(MADC ->SR ,4))==1); //wait until conversion end bit strt
	 Local_u16_ReadingData = MADC ->DR;  //get data
	 return Local_u16_ReadingData;       //return it
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void M_Adc1SetCallBack(void (* ptr)(void))
{
	MADC1_CallBack = ptr;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void ADC_IQHandeler(void)
{
	MADC1_CallBack();
}
/*====================================================   END_ FUNCTION   ====================================================*/









