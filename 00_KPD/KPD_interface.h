

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_
/********************************************/
/************Public definitions**************/
/********************************************/
#define NOT_PRESSED     255

/********************************************/
/************Public functions****************/
/********************************************/

/*
*Description: Function to get the pressed key in 4x4 keypad
*Parameters	: void
*return		: u8 [the number of the pressed switch]
*scope		: public
*/
u8 MKPD_u8GetKey(void);

void MKPD_vInit();

#endif /* KPD_INTERFACE_H_ */
