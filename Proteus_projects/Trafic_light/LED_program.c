/*
 * #################################### LED_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 30 Novamber 2023
 *   Layer  :HALL
 *   SWC    :LED
 *   Version: 1
*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"


/* this function initialize the pin which connected to led as output pin */
void LED_VoidInit (LED_TYPE LED_configration )
{
	DIO_enumSetPinDirection(LED_configration.port,LED_configration.pin,DIO_PIN_OUTPUT);
}
	  
	/* this function to make led on when the pin out high(source connection)   */
void LED_voidOn(LED_TYPE LED_configration)
{
 if(LED_configration.Active_State == ACTIVE_HIGH)
  {
	 DIO_enumSetPinValue (LED_configration.port  , LED_configration.pin, DIO_PIN_HIGH  );
  }
 else if(LED_configration.Active_State == ACTIVE_LOW)
  {
	 DIO_enumSetPinValue (LED_configration.port  , LED_configration.pin, DIO_PIN_LOW  );
  }
	
}

   /* this function to make led on when the pin out low(sink connection)   */
void LED_voidOff(LED_TYPE LED_configration)
{
 if( LED_configration.Active_State == ACTIVE_HIGH)
  {
	 DIO_enumSetPinValue ( LED_configration.port, LED_configration.pin, DIO_PIN_LOW );
  }
 else if( LED_configration.Active_State == ACTIVE_LOW)
  {
	 DIO_enumSetPinValue ( LED_configration.port, LED_configration.pin,  DIO_PIN_HIGH );
  }
}
   /*this function toggle led pin */
void LED_voidToggle(LED_TYPE LED_configration)
{
	DIO_enumTogglePinValue ( LED_configration.port, LED_configration.pin );
}
