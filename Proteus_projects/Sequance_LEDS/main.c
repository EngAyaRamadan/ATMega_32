/*
 * main.c
 *
 *  Created on: feb 2, 2024
 *      Author: Aya Ramadan
 */
#include<avr/io.h>
#include<util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "BUTTON_interface.h"
void main()
{

	LED_TYPE LED_1={DIO_PORTA,DIO_PIN1,ACTIVE_HIGH};
	LED_TYPE LED_2={DIO_PORTA,DIO_PIN2,ACTIVE_HIGH};
	LED_TYPE LED_3={DIO_PORTA,DIO_PIN3,ACTIVE_HIGH};
	LED_TYPE LED_4={DIO_PORTA,DIO_PIN4,ACTIVE_HIGH};
	LED_TYPE LED_5={DIO_PORTA,DIO_PIN5,ACTIVE_HIGH};

	SW_Type sw_1={DIO_PORTB,DIO_PIN1,SW_PULL_UP };
	SW_Type sw_2={DIO_PORTB,DIO_PIN3,SW_PULL_UP};
	SW_Type sw_3={DIO_PORTB,DIO_PIN5,SW_PULL_UP };


	LED_VoidInit(LED_1);
	LED_VoidInit(LED_2);
	LED_VoidInit(LED_3);
	LED_VoidInit(LED_4);
	LED_VoidInit(LED_5);

	SW_VoidInit ( sw_1 );
	SW_VoidInit ( sw_2 );
	SW_VoidInit ( sw_3 );

	while(1)
	{
		volatile u8 sequance_1=SW_u8GetPressed(sw_1);
		volatile u8 sequance_2=SW_u8GetPressed(sw_2);
		volatile u8 sequance_3=SW_u8GetPressed(sw_3);

	if(sequance_1==SW_PRESSED &&sequance_2==SW_NOT_PRESSED && sequance_3 ==SW_NOT_PRESSED )
		{
			_delay_ms(150); /* delay for Pulsing time */
			if(sequance_1==SW_PRESSED &&sequance_2==SW_NOT_PRESSED && sequance_3 ==SW_NOT_PRESSED )
			{
				LED_VoidOn(LED_1);
				LED_VoidOn(LED_2);
				LED_VoidOn(LED_3);
				LED_VoidOn(LED_4);
				LED_VoidOn(LED_5);
				_delay_ms(1000);
				LED_voidOff(LED_1);
				LED_voidOff(LED_2);
				LED_voidOff(LED_3);
				LED_voidOff(LED_4);
				LED_voidOff(LED_5);
				_delay_ms(1000);
			}
		}

	else if( sequance_1==SW_NOT_PRESSED&&sequance_2==SW_PRESSED && sequance_3 ==SW_NOT_PRESSED )
		{
			_delay_ms(150);
			if( sequance_1==SW_NOT_PRESSED&&sequance_2==SW_PRESSED && sequance_3 ==SW_NOT_PRESSED )
			{
				LED_VoidOn(LED_1);
				_delay_ms(500);
				LED_VoidOn(LED_2);
				_delay_ms(500);
				LED_VoidOn(LED_3);
				_delay_ms(500);
				LED_VoidOn(LED_4);
				_delay_ms(500);
				LED_VoidOn(LED_5);
				_delay_ms(500);

				LED_voidOff(LED_5);
				_delay_ms(500);
				LED_voidOff(LED_4);
				_delay_ms(500);
				LED_voidOff(LED_3);
				_delay_ms(500);
				LED_voidOff(LED_2);
				_delay_ms(500);
				LED_voidOff(LED_1);
				_delay_ms(500);
			}
		}

		else if( sequance_1==SW_NOT_PRESSED &&sequance_2==SW_NOT_PRESSED && sequance_3 ==SW_PRESSED)
		{
			_delay_ms(150);
			if( sequance_1==SW_NOT_PRESSED &&sequance_2==SW_NOT_PRESSED && sequance_3 ==SW_PRESSED)
			{
				LED_VoidOn(LED_1);
				LED_VoidOn(LED_5);
				_delay_ms(500);
				LED_VoidOn(LED_2);
				LED_VoidOn(LED_4);
				_delay_ms(500);
				LED_VoidOn(LED_3);
				_delay_ms(500);


				LED_voidOff(LED_3);
				_delay_ms(500);
				LED_voidOff(LED_2);
				LED_voidOff(LED_4);
				_delay_ms(500);
				LED_voidOff(LED_1);
				LED_voidOff(LED_5);
				_delay_ms(500);
			}
		}

	}


}
