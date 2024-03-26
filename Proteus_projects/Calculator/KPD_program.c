/*
 * #################################### KPD_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 12 march 2024
 *   Layer  :HALL
 *   SWC    :KEYPAD
 *   Version: 1
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include<util/delay.h>

void KPD_voidInit(void)
{
	 DIO_enumSetPinDirection (KPD_PORT,KPD_R0 ,DIO_PIN_INPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_R1 ,DIO_PIN_INPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_R2 ,DIO_PIN_INPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_R3 ,DIO_PIN_INPUT);
	 
	 
	 DIO_enumSetPinDirection (KPD_PORT,KPD_C0 ,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_C1 ,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_C2 ,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (KPD_PORT,KPD_C3 ,DIO_PIN_OUTPUT);
	 
	 DIO_enumSetPortValue    (KPD_PORT,0xff);

	
}


u8 KPD_u8GetPressed(void)
{
    u8 loc_u8ReturnData=NOT_PRESSED;
    u8 loc_u8GetPressed;
	u8 loc_u8ROW;
	u8 loc_u8COL;
	
	for(loc_u8COL=KPD_COL_INIT;loc_u8COL<= KPD_COL_END;loc_u8COL++)  
	{
	  DIO_enumSetPinValue (KPD_PORT,loc_u8COL,DIO_PIN_LOW);
		for(loc_u8ROW=KPD_ROW_INIT;loc_u8ROW<=KPD_ROW_END;loc_u8ROW++)
			 {
				 DIO_enumGetPinValue  (KPD_PORT,loc_u8ROW,&loc_u8GetPressed);
				 if(loc_u8GetPressed == 0)
				 {
					 _delay_ms(50);
					 DIO_enumGetPinValue  (KPD_PORT,loc_u8ROW,&loc_u8GetPressed);
					 if(loc_u8GetPressed == 0)
					 {
						 loc_u8ReturnData=KPD_u8Buttons[loc_u8ROW-KPD_ROW_INIT][loc_u8COL-KPD_COL_INIT];
						 
					 }
					 
					 DIO_enumGetPinValue  (KPD_PORT,loc_u8ROW,&loc_u8GetPressed);
					 while(loc_u8GetPressed == 0)
					 {
						 DIO_enumGetPinValue  (KPD_PORT,loc_u8ROW,&loc_u8GetPressed);
					 }
					 break;
				 }
				 
			 }
	    DIO_enumSetPinValue (KPD_PORT,loc_u8COL,DIO_PIN_HIGH);
	}
return loc_u8ReturnData;
}

