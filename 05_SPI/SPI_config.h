/*======================================================================================
========================    - SPI_config.h					 ===========================
========================    - Created: 20/6/2022			     ===========================
========================    -  Author: Abdelrahman Magdy      ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/ 


/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

/*=======================================================================================
=====================     guard of file will call on time in .c  	=====================
=========================================================================================*/


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/*
 *    OPTIONS :
 *               READ_WRITE
 *               WRITE_READ
 */

typedef enum{
    READ_WRITE = 0U, /*WRITE Then READ */
    WRITE_READ
}Phase_t;
#define SPI_PHASE 		WRITE_READ

typedef enum{
    IDLE_0= 0U,
    IDLE_1
}Polarity_t;
#define SPI_POLARITY 	IDLE_1

typedef enum{
    SLAVE = 0U,
    MASTER
}Master_slave_t;
#define SPI_MASTER_SLAVE	MASTER

typedef enum{
	GND= 0U ,
	VCC
}SSI_t;
#define SSI_STATE 		VCC

typedef enum{
	SWITCH_CLOSE =0U ,
	SWITCH_OPEN
}SSM_t;
#define SSM_STATE 		SWITCH_OPEN

typedef enum{
    B_2 = 0U,
    B_4,
    B_8,
    B_16,
    B_32,
    B_64,
    B_128,
    B_256,
}Baud_rate_t;
#define BUAD_RATE  B_2

typedef enum{
    MSB_FIRST =0U,
    LSB_FIRST
}Frame_format_t;
#define  DATA_ORDER  MSB_FIRST

typedef enum{
    S_8_BIT,
    S_16_BIT
}Data_sizet_t;
#define DATA_FORMAT S_8_BIT




#endif /* SPI_CONFIG_H_ */

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/
