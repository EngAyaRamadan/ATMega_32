/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Aya Ramadan
 */


#include <avr/io.h>
#include <util/delay.h>


#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_interface.h"
#include"LED_interface.h"

void main(void)
{
	LED_TYPE Led_Red={DIO_PORTA,DIO_PIN0,ACTIVE_HIGH};
	LED_TYPE Led_Green={DIO_PORTA,DIO_PIN2,ACTIVE_HIGH};
	LED_TYPE Led_Yellow={DIO_PORTA,DIO_PIN4,ACTIVE_HIGH};

	LED_VoidInit (Led_Red ) ;
	LED_VoidInit (Led_Green ) ;
	LED_VoidInit (Led_Yellow ) ;

	while(1)
	{
		LED_voidOn(Led_Red);
		_delay_ms(6000);
		LED_voidOff(Led_Red);
		LED_voidOn(Led_Green);
		_delay_ms(6000);
		LED_voidOff(Led_Green);
		LED_voidOn(Led_Yellow);
		_delay_ms(2000);
		LED_voidOff(Led_Yellow);
	}



}
