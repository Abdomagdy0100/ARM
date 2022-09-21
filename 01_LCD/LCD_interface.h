

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/****************************************************/
/****************Public Definitions******************/
/****************************************************/
/*LCD control commands*/
#define LCD_CLR                  0x01 /* replace all characters with ASCII 'space' */
#define LCD_HOME                 0x02 /* return cursor to first position on first line */
#define LCD_ENTRYMODE            0x06 // shift cursor from left to right on read/write
#define LCD_DISPOFF              0x08 // turn display off
#define LCD_DISPON_CURSON        0x0F // display on, cursor off, don't blink character
#define LCD_FUNCRESET            0x30 // reset the LCD
#define LCD_FUNCSET_8BIT         0x38 // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR            0x80 // set cursor position
#define LCD_DISPON_CURSBLINK     0x0D //display on , cursor blinking
#define LCD_DISPON_CURSOFF       0x0C //display on ,cursor off

/****************************************************/
/****************Public Functions********************/
/****************************************************/

void LCD_vidInit(void);

void LCD_vidSendCommand(u8 u8CmdCopy);

void LCD_vidWriteChar(u8 u8DataCopy);

void LCD_vidWriteString(u8* pu8StringCopy);

void LCD_vidGotoXY(u8 u8ColCopy,u8 u8RowCopy);

void LCD_vidClearLine(u8 u8LineCopy);

void LCD_vidWriteCustomChar(u8* u8CharCopy, u8 u8CharLocationCopy);
/* To convert to assci */
void LCD_vidWriteInt(u32);
#endif /* LCD_INTERFACE_H_ */
