
/*
 * ####################################Button_porgrame.c #############################
 *   Author : Aya Ramadan
 *   date   : 28 Junuary 2024
 *   Layer  :HALL
 *   SWC    :Bush_Button
 *   Version: 1
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Button_interface.h"



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Button_interface.h"

void SW_VoidInit ( SW_Type SW_Configuration)
{
	DIO_enumSetPinDirection( SW_Configuration.Port , SW_Configuration.Pin ,DIO_PIN_INPUT);
	if( SW_Configuration.Pull_State == SW_PULL_UP )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin ,DIO_PIN_HIGH);
	}
	else if( SW_Configuration.Pull_State == SW_FLOATING )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin ,DIO_PIN_LOW);
	}

}
u8 SW_u8GetPressed( SW_Type SW_Configuration)
{
	u8 LOC_u8Result = 0;
	u8 LOC_u8PinValue=0;

	if( SW_Configuration.Pull_State == SW_PULL_UP )
	{
		DIO_enumGetPinValue ( SW_Configuration.Port , SW_Configuration.Pin ,&LOC_u8PinValue);
		if(LOC_u8PinValue==0)
		{
			LOC_u8Result=SW_PRESSED;
		}
		else if(LOC_u8PinValue==1)
		{
			LOC_u8Result=SW_NOT_PRESSED;
		}
	}
	else if( SW_Configuration.Pull_State == SW_FLOATING )
	{
		DIO_enumGetPinValue ( SW_Configuration.Port , SW_Configuration.Pin ,&LOC_u8PinValue);
		if(LOC_u8PinValue==1)
		{
			LOC_u8Result=SW_PRESSED;
		}
		else if(LOC_u8PinValue==0)
		{
			LOC_u8Result=SW_NOT_PRESSED;
		}
	}

	return LOC_u8Result;
}

