/*======================================================================================
===========================   - SSD_interface.h			     ===========================
===========================   - Created: 17/6/2022		 ===========================
===========================   - Author: Shimaa Samir   ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 


 
/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

#ifndef SSD_H_
#define SSD_H_




/*****************************************_PROTOTYPES_******************************************/
void H_Ssd_Init(void);
void H_Ssd_Write(u8);
void H_Ssd_CountUp(u8);
void H_Ssd_CountDown(s8);
void H_Ssd_Disable(void);



#endif /* SSD_H_ */