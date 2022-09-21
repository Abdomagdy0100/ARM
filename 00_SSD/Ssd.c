/*=======================================================================================
============================   - SSD_program.c				 ============================
============================   - Created: 21/6/2022			 ============================
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
		#include "01_MCAL/01_GPIO/GPIO_interface.h"
		#include "01_MCAL/00_RCC/RCC_interface.h"
		
		
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "Ssd.h"
		#include "SsdCfg.h"

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void H_Ssd_Init()
{
	MRCC_vInitSystemCLK();
	MRCC_vEnableClock(AHB1,_PERIPHERAL_EN_GPIOA);
	
	#if Ssd_Mode == DIRECT_MODE
	u8 Local_u8_SSD_START_PINS = 0;
	while(Local_u8_SSD_START_PINS<=6)
	{
	MGPIO_vSetPinMode(GPIOA , Local_u8_SSD_START_PINS,MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIOA , Local_u8_SSD_START_PINS,PUSH_PULL);
	MGPIO_vSetPullType(GPIOA , Local_u8_SSD_START_PINS,PULL_OFF);
	MGPIO_vSetPinOutSpeed(GPIOA , Local_u8_SSD_START_PINS,MEDIUM_SPEED);

	Local_u8_SSD_START_PINS++;
	}
	
	
	#elif Ssd_Mode == ENCODED_MODE
	u8 Local_u8_SSD_START_PINS = 0;
	while(Local_u8_SSD_START_PINS<=3)
	{
	MGPIO_vSetPinMode(GPIOA , Local_u8_SSD_START_PINS,MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIOA , Local_u8_SSD_START_PINS,PUSH_PULL);
	MGPIO_vSetPinOutSpeed(GPIOA , Local_u8_SSD_START_PINS,MEDIUM_SPEED);
	MGPIO_vSetPullType(GPIOA , Local_u8_SSD_START_PINS,PULL_OFF);
	Local_u8_SSD_START_PINS++;
	}
	
	#endif
}

/*====================================================   Start_FUNCTION   ====================================================*/
 
/*====================================================   END_ FUNCTION   ====================================================*/

static void H_Ssd_Display(u8 Local_u8_Ssd_Display_Number)
{
	
	
	#if Ssd_Mode == DIRECT_MODE
	
	switch(Local_u8_Ssd_Display_Number)
	{
	case 0:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,LOW);
	break;
	case 1:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,LOW);
	break;
	case 2:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 3:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 4:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 5:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 6:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 7:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,LOW);
	break;
	case 8:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;
	case 9:
	MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_E_PIN,LOW);
	MGPIO_vWriteData(GPIOA,SSD_F_PIN,HIGH);
	MGPIO_vWriteData(GPIOA,SSD_G_PIN,HIGH);
	break;          
	default:
	break;
}
	#elif Ssd_Mode == ENCODED_MODE
	
	switch(Local_u8_Ssd_Display_Number)
	{
		case 0:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 1:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 2:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 3:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 4:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 5:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 6:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 7:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,LOW);
		break;
		case 8:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
		break;
		case 9:
		MGPIO_vWriteData(GPIOA,SSD_A_PIN,HIGH);
		MGPIO_vWriteData(GPIOA,SSD_B_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_C_PIN,LOW);
		MGPIO_vWriteData(GPIOA,SSD_D_PIN,HIGH);
		break;
		default:
		break;
	}
	#endif
}
void H_Ssd_Write(u8 Local_u8_Num)
{
	


		H_Ssd_Display(Local_u8_Num);
		Delay_vMsIn16MHz(1);
		

	
}

/*====================================================   Start_FUNCTION   ====================================================*/
 
/*====================================================   END_ FUNCTION   ====================================================*/

void H_Ssd_CountUp(u8 Local_u8_CountUp)
{
	u8 Local_num = 0;
	while (Local_num != Local_u8_CountUp)
	{
		H_Ssd_Write(Local_num);
		Local_num++;
	}
	H_Ssd_Write(Local_num);
	
}

/*====================================================   Start_FUNCTION   ====================================================*/
 
/*====================================================   END_ FUNCTION   ====================================================*/

void H_Ssd_CountDown(s8 Local_s8_CountDown)
{
	s8 Local_s8_num = 0;
	while (Local_s8_num != Local_s8_CountDown)
	{
		H_Ssd_Write(Local_s8_CountDown);
		Local_s8_CountDown--;
	}
}

/*====================================================   Start_FUNCTION   ====================================================*/
 
/*====================================================   END_ FUNCTION   ====================================================*/


void H_Ssd_Disable()
{
	u8 Local_u8_SSD_START_PINS = 0;
	while(Local_u8_SSD_START_PINS<=6)
	{
	MGPIO_vWriteData(GPIOA,Local_u8_SSD_START_PINS,LOW);
	Local_u8_SSD_START_PINS ++ ;
	}
}
