/*
 * ####################################SEVEN_SEGMENT_programe.c #############################
 *   Author : Aya Ramadan
 *   date   : 14 February 2024
 *   Layer  :HALL
 *   SWC    :SEVEN SEGMENT
 *   Version: 1
*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"

static u8 local_u8SSDArr[10]=SSD_NUMBER_ARR;

/* function for intialization seven segment */
void SSD_voidinti(SSD_Type copy_configration)
{
    DIO_enumSetPortDirection(copy_configration.port ,0xff); /* 0xff to make all pin is output pin */
}


/* function to display any number on seven_segment */
void SSD_void_display(SSD_Type copy_configration,u8 copy_u8_number)
{

	if(copy_configration.conection_type == COMMAN_CATHOD)
	{
		DIO_enumSetPortValue (copy_configration.port, local_u8SSDArr[copy_u8_number]);
	}
	else if(copy_configration.conection_type == COMMAN_ANODE)
	{
		DIO_enumSetPortValue (copy_configration.port, ~ local_u8SSDArr[copy_u8_number]);
	}
}

/* function to Enable the seven_segment  */
void SSD_voidEnable(SSD_Type copy_configration)
{
	DIO_enumSetPinDirection (copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_OUTPUT);
	if(copy_configration.conection_type == COMMAN_CATHOD)
	{
		DIO_enumSetPinValue(copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_LOW);
	}
	else if(copy_configration.conection_type == COMMAN_ANODE)
	{
		DIO_enumSetPinValue(copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_HIGH);
	}
}
/* function to disable the seven_segment */
void SSD_voidDisable(SSD_Type copy_configration)
{
	DIO_enumSetPinDirection (copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_OUTPUT);
	if(copy_configration.conection_type == COMMAN_CATHOD)
	{
		DIO_enumSetPinValue(copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_HIGH);
	}
	else if(copy_configration.conection_type == COMMAN_ANODE)
	{
		DIO_enumSetPinValue(copy_configration.EnablePort,copy_configration.EnablePin,DIO_PIN_LOW);
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
