 /*
 * #################################### LM35_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 13 April 2024
 *   Layer  :HAL
 *   SWC    :LM35
 *   Version: 1
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "LM35_interface.h"
#include "ADC_interface.h"

/* LM35>> 10mv/ْc */
void LM35_VoidGetTemp(LM35_TYPE* copy_LM35,u8* Copy_u8TempValue)
{
	u16 Local_u16AnalogValue;
	u16 Local_u16ADCResult;
      /* convert from v to>>> mv */
	u16 Local_u16VoltageReference=(copy_LM35->Copy_u8ADCVoltageReference)*1000;
	  /* GET DIGITAL VALUE */
	ADC_u16GetResltSync( copy_LM35->Copy_u8LM35Channel , &Local_u16ADCResult  );

	/* convert Degital to analog */
	Local_u16AnalogValue= (((u32)Local_u16ADCResult * (u32) Local_u16VoltageReference )/1024UL);
	/* GET actual Tempreture */
	*Copy_u8TempValue=Local_u16AnalogValue/10;
	
}

