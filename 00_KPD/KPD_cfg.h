

#ifndef KPD_CFG_H_
#define KPD_CFG_H_
/*Configuration keypad port*/
/*Range: DIO_u8PORTA ~ DIO_u8PORTD*/
#define KPD_Port    	GPIOC_PORT

/*RANG: 0 ~ 8*/
#define KDP_START_PIN   0

#define COLUMN_BEGIN    4
#define COLUMN_NUM      4
#define ROW_BEGIN       0
#define ROW_NUM         4

#endif /* KPD_CFG_H_ */
