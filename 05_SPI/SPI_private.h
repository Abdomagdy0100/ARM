/*==============================================================================================
===============================   - SPI_private.h				 ===============================
===============================   - Created: 20/6/2022			 ===============================
===============================   -  Author: Shimaa Samir    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

/*===============================================================================================

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/***********************************************************************************
	-----> Macros
			*  Base_Address SPI
************************************************************************************/

#define SPI1_BASE_ADDRESS    0x40013000
#define SPI2_BASE_ADDRESS    0x40003800
#define SPI3_BASE_ADDRESS    0x40003C00
#define SPI4_BASE_ADDRESS    0x40013400

typedef struct{
    u32 CPHA        : 1;
    u32 CPOL        : 1;
    u32 MSTR        : 1;
    u32 BR          : 3;
    u32 SPE         : 1;
    u32 LSBFIRST    : 1;
    u32 SSI         : 1;
    u32 SSM         : 1;
    u32 RXONLY      : 1;
    u32 DFF         : 1;
    u32 CRCNEXT     : 1;
    u32 CRCEN       : 1;
    u32 BIDIOE      : 1;
    u32 BIDIMODE    : 1;
    //u32 RESERVED    : 16;

}CR1_REG;

/***********************************************************************************
----->	Struct
		*  Register Map :SPI
************************************************************************************/

typedef struct{
	
  volatile  CR1_REG CR1  ;		/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
  volatile  u32 CR2      ;		/*!< SPI control register 2,                             Address offset: 0x04 */
  volatile  u32 SR       ;		/*!< SPI status register,                                Address offset: 0x08 */
  volatile  u32 DR       ;		/*!< SPI data register,                                  Address offset: 0x0C */
  volatile  u32 CRCPR    ;		/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
  volatile  u32 RXCRCR   ;		/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
  volatile  u32 TXCRCR   ;		/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
  volatile  u32 I2SCFGR  ;		/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
  volatile  u32 I2SPR    ;		/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
}SPI_t;


/***********************************************************************************
*     --> Pointer To STRUCT From SPI_t
************************************************************************************/
#define    MSPI1    (( SPI_t  *)(SPI1_BASE_ADDRESS))
#define    MSPI2    (( SPI_t  *)(SPI2_BASE_ADDRESS))
#define    MSPI3    (( SPI_t  *)(SPI3_BASE_ADDRESS))
#define    MSPI4    (( SPI_t  *)(SPI4_BASE_ADDRESS))


#endif //SPI_PRIVATE_H

/*************************************************************************************
*******************           End of guard of file  	  	       *******************
*************************************************************************************/
