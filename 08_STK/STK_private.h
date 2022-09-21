/*****************************************************************
 ************  - STK_private.h                  ******************
 ***********   - Created:5/19/2022			    ******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _1_				    ******************
 ***********								    ******************
 ****************************************************************/

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/**** Include  ***/


#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 CTRL   ;
	volatile u32 LOAD   ;
	volatile u32 VAL    ;
	volatile u32 CALIB  ;  

}STK_t;

#define MSTK             (( STK_t     *)(STK_BASE_ADDRESS))
 
 
#define STK_ENABLE    0U
#define TICKINT       1U
#define CLKSOURCE     2U
#define COUNTFLAG     16U


#endif //STK_PRIVATE.H

/****************************************************************
***********              End of guard               *************
******************************************************************/
