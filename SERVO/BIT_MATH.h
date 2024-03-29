/******************************************************************
   -	.h
   - Created: /5/2022
   - Author: NTI Embedded Team
   - Version : V01
 *****************************************************************/


 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_


 #define SET_BIT(REG , BITNUM) REG |= 1U<<BITNUM
 #define CLR_BIT(REG , BITNUM) REG &= ~(1U<<BITNUM)
 #define TOG_BIT(REG , BITNUM) REG ^= 1U<<BITNUM
 #define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1U )

/*
MRCC_vDisableableClock(AHB1, 0U );
*/

 #endif /* BIT_MATH_H_ */
