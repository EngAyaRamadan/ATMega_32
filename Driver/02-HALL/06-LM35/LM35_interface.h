 /*
 * #################################### LM35_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 13 April 2024
 *   Layer  :HAL
 *   SWC    :LM35
 *   Version: 1
*/

#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

typedef struct{
	
      u8 Copy_u8LM35Channel;
      u8 Copy_u8ADCVoltageReference;
	  
}LM35_TYPE;

void LM35_VoidGetTemp(LM35_TYPE *copy_LM35,u8* Copy_u8TempValue);

#endif
