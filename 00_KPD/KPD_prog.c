
#include "00_LIB/STD_types.h"
#include "00_LIB/util.h"
#include "00_LIB/Delay_interface.h"
#include "01_MCAL/01_GPIO/GPIO_interface.h"
#include "KPD_interface.h"
#include "KPD_cfg.h"
#include "KPD_private.h"


/*values of the keypad switches*/

const u8 KPD_au8SwitchValue[4][4]=
{
		{'/', 0, 8, 9},
		{7, 8, 9, 6},
		{4, 5, 6, 3},
		{1, 2, 3, 1},
};



void MKPD_vInit(){

	for(u8 u8Column = COLUMN_BEGIN; u8Column < COLUMN_BEGIN + COLUMN_NUM; u8Column++){

		MGPIO_vSetPinMode(KPD_Port, u8Column, OUTPUT);
		MGPIO_vSetOutputType(KPD_Port, u8Column, PUSH_PULL);
		MGPIO_vSetPullType(KPD_Port, u8Column, NORMAL);
		MGPIO_vSetPinOutSpeed(KPD_Port, u8Column, LOW_SPEED);
		MGPIO_vPinOutput(KPD_Port, u8Column, 1);
	}

	for(u8 u8Row = ROW_BEGIN; u8Row < ROW_BEGIN +ROW_NUM; u8Row++){

		MGPIO_vSetPinMode(KPD_Port, u8Row, INPUT);
		MGPIO_vSetOutputType(KPD_Port, u8Row, PUSH_PULL);
		MGPIO_vSetPullType(KPD_Port, u8Row, PULL_UP);
		MGPIO_vSetPinOutSpeed(KPD_Port, u8Row, LOW_SPEED);
	}


}



u8 MKPD_u8GetKey(void)
{
    u8 u8PressedKey=NOT_PRESSED;
	u8 u8Column,u8Row;

	for(u8Column=COLUMN_BEGIN;u8Column<COLUMN_NUM+COLUMN_NUM;u8Column++)
	{
		/*activate the column pins*/
		MGPIO_vPinOutput(KPD_Port, u8Column, 0);
		/*Rows loop*/
		for(u8Row=ROW_BEGIN;u8Row<ROW_BEGIN+ROW_NUM;u8Row++)
		{
			/*check the switch*/
			if(!MGPIO_u8ReadPinValue(KPD_Port, u8Row))
			{
				/*Get the value of the pressed switch*/
				u8PressedKey=KPD_au8SwitchValue[u8Row - ROW_BEGIN][u8Column-COLUMN_BEGIN];
				/*wait till release*/
				while(!MGPIO_u8ReadPinValue(KPD_Port, u8Row));
				Delay_vMsIn16MHz(5);

			}
		}
		MGPIO_vPinOutput(KPD_Port, u8Column, 1);
	}
	return u8PressedKey;

}

