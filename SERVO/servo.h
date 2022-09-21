/******************************************************************
   -	.h
   - Created: /5/2022
   - Author: NTI Embedded Team
   - Version : V01
 *****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"	//replace
#include "GPIO_interface.h"	//replace
#include "SYSTIK_interface.h"

///////////////////////////// EXIT \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Generate_PWM_Exit(u16 Copy_u16DutyCyclePercentx10, u32 Copy_u32PeriodInMilli);

void ON_PWM_Exit(void);

void OFF_PWM_Exit(void);

void Servo_angle_Exit(u16 );

///////////////////////////// ENTER \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Generate_PWM_Enter(u16 Copy_u16DutyCyclePercentx10, u32 Copy_u32PeriodInMilli);

void ON_PWM_Enter(void);

void OFF_PWM_Enter(void);

void Servo_angle_Enter(u16 );

