/*======================================================================================
========================    - UART_config.h					 ===========================
========================    - Created: 17/6/2022			     ===========================
========================    -  Author: Abdelrahman Magdy      ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/ 


/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_
/*Mode*/
/*
USART modes for (ENABLED) USART1 USART2 USART6:

	UART_ASYNC							Asynchronous mode
	UART_HWFCTRL						Hardware flow control
	UART_MULITBUFFCOM					Multibuffer communication (DMA)
	UART_MPC							Multiprocessor communication
	UART_SYNC							Synchronous
	UART_SMARTCARD						Smartcard
	UART_HALFDUPLEX						Half-duplex (single-wire mode)
	UART_IRDA							IrDA
	UART_LIN							LIN

	or UART_DISABLE						Disable UART
*/
#define UART1_MODE				UART_ASYNC
#define UART2_MODE				UART_DISABLE
#define UART6_MODE				UART_ASYNC
/*Parity Mode*/
/*
USART Parity Modes for (ENABLED) USART1 USART2 USART6:

	UART_PARITY_EVEN                    Even parity
	UART_PARITY_ODD                     Odd parity

	or UART_PARITY_DISABLE				Disable UART Parity
*/
#define UART1_PARITY_MODE				UART_PARITY_DISABLE
#define UART2_PARITY_MODE				UART_PARITY_DISABLE
#define UART6_PARITY_MODE				UART_PARITY_DISABLE
/*Stop Bits*/
/*
USART Stop Bits for (ENABLED) USART1 USART2 USART6:

	ONE_STOP_BIT				     00: 1 Stop bit
	HALF_STOP_BIT                    01: 0.5 Stop bit
	ONE_HALF_STOP_BITS               10: 2 Stop bits
	TWO_STOP_BITS                    11: 1.5 Stop bit
*/
#define UART1_STOP_BITS				ONE_STOP_BIT
#define UART2_STOP_BITS				ONE_STOP_BIT
#define UART6_STOP_BITS				ONE_STOP_BIT
	/*Character size*/
/*
USART Stop Bits for (ENABLED) USART1 USART2 USART6:

	EIGHT_DATA_BITS				     0: 1 Start bit, 8 Data bits, n Stop bit
	NINE_DATA_BITS                   1: 1 Start bit, 9 Data bits, n Stop bit
*/
#define UART1_WORD			EIGHT_DATA_BITS
#define UART2_WORD			EIGHT_DATA_BITS
#define UART6_WORD			EIGHT_DATA_BITS
	/*Clock Polarity and Phase*/
/*
USART Clock Polarity and Phase for (Synchronous) USART1 USART2 USART6:


	STEADY_LOW_FIRST_READ
	STEADY_LOW_FIRST_WRITE
	STEADY_HIGH_FIRST_READ
	STEADY_HIGH_FIRST_WRITE
*/
#define UART1_SYNC_CLK			STEADY_HIGH_FIRST_WRITE
#define UART2_SYNC_CLK			STEADY_HIGH_FIRST_WRITE
#define UART6_SYNC_CLK			STEADY_HIGH_FIRST_WRITE
	/*Baud Rate*/

#endif /* MCAL_UART_UART_CONFIG_H_ */
