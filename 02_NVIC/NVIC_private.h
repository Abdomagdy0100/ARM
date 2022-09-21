/*==============================================================================================
===============================   - NVIC_private.h				 ===============================
========================   		  - Created: 19/6/2022	         ===========================
========================    	 - Author: Abdelrahman Magdy           ===========================
========================    	  Version : _1_				     ===========================
========================        - Note :
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

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_ISER0  (*(volatile u32*)0XE000E100)     /*enable interrupt from  0   to   31  */
#define NVIC_ISER1  (*(volatile u32*)0XE000E104)     /*enable interrupt from  32  to   63  */
#define NVIC_ISER2  (*(volatile u32*)0XE000E108)     /*enable interrupt from  64  to   96  */

#define NVIC_ICER0  (*(volatile u32*)0XE000E180)     /*disable interrupt from  0   to   31  */
#define NVIC_ICER1  (*(volatile u32*)0XE000E184)     /*disable interrupt from  32  to   63  */
#define NVIC_ICER2  (*(volatile u32*)0XE000E188)     /*disable interrupt from  64  to   96  */

#define NVIC_ISPR0  (*(volatile u32*)0XE000E200)     /*set pending flag from  0   to   31  */
#define NVIC_ISPR1  (*(volatile u32*)0XE000E204)     /*set pending flag from  32  to   63  */
#define NVIC_ISPR2  (*(volatile u32*)0XE000E208)     /*set pending flag from  64  to   96  */

#define NVIC_ICPR0  (*(volatile u32*)0XE000E280)     /*clear pending flag from  0   to   31  */
#define NVIC_ICPR1  (*(volatile u32*)0XE000E284)     /*clear pending flag from  32  to   63  */
#define NVIC_ICPR2  (*(volatile u32*)0XE000E288)     /*clear pending flag from  64  to   96  */

#define NVIC_IABR0  (*(volatile u32*)0xE000E300)     /*get Active Flag from  0   to   31  */
#define NVIC_IABR1  (*(volatile u32*)0xE000E304)     /*get Active Flag from  32  to   63  */
#define NVIC_IABR2  (*(volatile u32*)0xE000E308)     /*get Active Flag from  64  to   96  */

#define NVIC_IP0   (*(volatile u32*)0xE000E400)
typedef struct
{
 volatile u32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
 volatile u32 RESERVED0[24U];
 volatile u32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
 volatile u32 RESERVED1[24U];
 volatile u32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
 volatile u32 RESERVED2[24U];
 volatile u32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
 volatile u32 RESERVED3[24U];
 volatile u32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
 volatile u32 RESERVED4[56U];
 volatile u8  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
 volatile u32 RESERVED5[644U];
 volatile u32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_t;

#define NVIC_STIR   (*(volatile u32*)0xE000EF00)

#define NVIC        ((volatile NVIC_t*)0XE000E100)

#define GROUP4_SUB0   0x05FA0300    /*4bit for group  0bit for Sub*/
#define GROUP3_SUB1   0x05FA0400    /*3bit for group  1bit for Sub*/
#define GROUP2_SUB2   0x05FA0500    /*2bit for group  2bit for Sub*/
#define GROUP1_SUB3   0x05FA0600    /*1bit for group  3bit for Sub*/
#define GROUP0_SUB4   0x05FA0700    /*0bit for group  4bit for Sub*/

#define SCB_AIRCR     (*(volatile u32*)(0xE000ED00+0x0C))

#define NVIC_IPR    ((volatile u8*)0XE000E400)



#endif
