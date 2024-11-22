/*
 * main.c
 *
 *  Created on: Jul 18, 2024
 *      Author: QUADRO
 */



#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"

#include "../HAL/CLCD/CLCD_interface.h"


void main()
{
	CLCD_voidInti();
	MUART_voidInitialization();

	/* --------------------------------  DC Motor -------------------------------------------- */
	DIO_enumSetPinDirection(DIO_PORTC, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);

	while(1)
	{

		u8 LOC_u8Receive = MUART_voidRecieveData();
		_delay_ms(100);
		if (LOC_u8Receive == 'S')
			{
				CLCD_voidSendString     ( "Safe"  );
				DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);
				_delay_ms(150);
			}
		else if (LOC_u8Receive == 'M')
		{
			CLCD_voidSendString     ( "You must stop"  );
			DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);
			_delay_ms(150);
		}
		else if(LOC_u8Receive == 'D'){

			CLCD_voidSendString  ( "Should Decrease"  );
			DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);
		}
		CLCD_voidClearScreen();
	}


}
