

/*******************Header file inclusions**************/

//#define F_CPU 12000000
#include "00_LIB/std_types.h"
#include "00_LIB/util.h"
#include "00_LIB/Delay_interface.h"
#include "LCD_cfg.h"
#include "01_MCAL/01_GPIO/GPIO_interface.h"
#include "LCD_interface.h"



/********************************************************/



void LCD_vidInit(void)
{

	Delay_vMsIn16MHz(35);
	/* SET MODE 8 BIT */
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);
	Delay_vMsIn16MHz(1);
	/* LCD DISPLAY ON AND CURSUR OFF */
	LCD_vidSendCommand(LCD_DISPON_CURSOFF );
	Delay_vMsIn16MHz(1);
    /* CLEAR */
	LCD_vidSendCommand(LCD_CLR);
	Delay_vMsIn16MHz(5);
	/* LCD_ENTRYMODE  */
	LCD_vidSendCommand(LCD_ENTRYMODE);
	Delay_vMsIn16MHz(5);
	/* CURSER TO HOME */
	LCD_vidSendCommand(LCD_HOME);
	Delay_vMsIn16MHz(15);

}
/* Edit here */
void LCD_vidSendCommand(u8 u8CmdCopy)
{
	/*set RS to low*/
	MGPIO_vPinOutput(DIO_u8ContPort,RS_PIN,0);
	/*set R/W to low*/
	MGPIO_vPinOutput(DIO_u8ContPort,RW_PIN,0);
	/*set E to High*/
	MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,1);
	Delay_vMsIn16MHz(1);
	/*send command on data bus send by byte take the start of A0 */
	MGPIO_vPortOutputOneByte(DIO_u8DataPort, u8CmdCopy,0);
	/*set E to low*/
	MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,0);
	/*delay for 5 ms for E to settle in*/
	Delay_vMsIn16MHz(5);
	MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,1);
	Delay_vMsIn16MHz(10);
}


/* Edit here */
void LCD_vidWriteChar(u8 u8DataCopy)
{
		if(u8DataCopy==255)return;
		/*set RS to High*/
		MGPIO_vPinOutput(DIO_u8ContPort,RS_PIN,1);
		/*set R/W to low*/
		MGPIO_vPinOutput(DIO_u8ContPort,RW_PIN,0);
		/*set E to High*/
		MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,1);
		/*send command on data bus*/
		MGPIO_vPortOutputOneByte(DIO_u8DataPort, u8DataCopy,0);
		/*set E to low*/
		MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,0);
		/*delay for 5 ms for E to settle in*/
		Delay_vMsIn16MHz(5);
		MGPIO_vPinOutput(DIO_u8ContPort,E_PIN,1);
		Delay_vMsIn16MHz(10);
}


void LCD_vidGotoXY(u8 u8ColCopy,u8 u8RowCopy)
{
	u8 xAddress,posAddress;
	switch(u8RowCopy)
	{
	case 1:
		xAddress=0x00;
		break;

	case 2:
		xAddress=0x40;
		break;
	}

	posAddress=xAddress+u8ColCopy;
	posAddress|=0x80;
	LCD_vidSendCommand(posAddress);
	Delay_vMsIn16MHz(5);
}


void LCD_vidWriteString(u8* pu8StringCopy)
{
	u8 counter=0;
	while(pu8StringCopy[counter]!='\0')
	{
		LCD_vidWriteChar(pu8StringCopy[counter]);
		counter++;
	}

}


void LCD_vidWriteCustomChar(u8* u8CharCopy, u8 u8CharLocationCopy)
{
	u8 counter,address;
	address=0x40|(u8CharLocationCopy)<<3;
	LCD_vidSendCommand(address);
	Delay_vMsIn16MHz(1);
	for(counter=0;counter<8;counter++)
	{
		LCD_vidWriteChar(u8CharCopy[counter]);
		Delay_vMsIn16MHz(5);
	}
}


void LCD_vidWriteInt(u32 Number)
{
	u8 start=2;
	u16 Digits[10]={0};
	u16 Dnum=9,temp=0;

	if(Number>=10000){start=1;}

	do
	{
		temp=Number%10;
		Number=Number/10;
		--Dnum;
		Digits[Dnum]=temp + '0';
	}while(Number!=0);




	for(u8 counter=start;counter<=9;counter++)
	{
		if(Digits[counter]==0)
		{
			continue;
		}

		LCD_vidWriteChar(Digits[counter]);
	}
}
