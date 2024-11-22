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
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/UART/UART_interface.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/ULS/ULS_interface.h"

void main()
{
	LED_TYPE LED_Yellow = {DIO_PORTC,DIO_PIN2,ACTIVE_HIGH};
	LED_TYPE LED_Red = { DIO_PORTC,DIO_PIN1,ACTIVE_HIGH};
	LED_TYPE LED_green = { DIO_PORTC,DIO_PIN0,ACTIVE_HIGH};
	LED_VoidInit(LED_Yellow);
	LED_VoidInit(LED_Red);
	LED_VoidInit(LED_green);

	MUART_voidInitialization();


	/* --------------------------------  DC Motor -------------------------------------------- */
	DIO_enumSetPinDirection(DIO_PORTC, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);

	unsigned short T_OFF=0,TOTAL_T=0,T_ON,Distance=0;
	ULS_voidInti();
	CLCD_voidInti();

	while(1)
	{
		TIMER1_voidResetInti();
		ULS_voidSendTr();

		TIMER1_voidSetICREdge(RISING_EDGE);
		while (TIMER1_voidGetFlag(TIMER1_INPUT_CAPTURE_FLAG) == 0);

		T_OFF = ICR1;  /* save the value of capture register */
		TIMER1_voidClearFlag(TIMER1_INPUT_CAPTURE_FLAG);  	/* Clear ICU flag */

		TIMER1_voidSetICREdge(FALLING_EDGE);
		while (TIMER1_voidGetFlag(TIMER1_INPUT_CAPTURE_FLAG) == 0);

		TOTAL_T = ICR1;  		/* save value of capture register */
		TIMER1_voidClearFlag(TIMER1_INPUT_CAPTURE_FLAG);  	/* Clear ICU flag */
		TIMER1_voidSetStopTimer() ; 		/* Stop the timer */

		T_ON= TOTAL_T - T_OFF;
		//Distance=((T_ON*34600)/(F_CPU*2)) ;
		Distance=((T_ON*0.0346)/2) ;
		/*--------------------  Worset Case "The Car must Stop NOW" --------------------------- */
		if (Distance>=90)
		{
			LED_VoidOff(LED_green);
			LED_VoidOff(LED_Red);
			LED_VoidOn(LED_Yellow);

			CLCD_voidSetPosition ( 1,3 );
			CLCD_voidSendString("Safe");
			CLCD_voidSetPosition ( 2,6 );
			MUART_voidSendData('S');
			_delay_ms(50);
		}
		else
		{
			LED_VoidOff(LED_Yellow);

			CLCD_voidSetPosition ( 1,1 );
			CLCD_voidSendString("warnning d=");
			CLCD_voidSendNumber(  Distance     );
			CLCD_voidSendString("cm");
			_delay_ms(30);

			if(Distance>50)
			{
				DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_HIGH);
				LED_VoidOff(LED_Red);
				LED_VoidOn(LED_green);
				CLCD_voidSetPosition    ( 2,1 );
				CLCD_voidSendString("Decrease Speed");

				CLCD_voidSetPosition    (  2,3 );
				//	MUART_voidSendString("I Decrease Speed");
				MUART_voidSendData('D');
			}
			else if(Distance<50)
			{
				LED_VoidOff(LED_green);
				LED_VoidOn(LED_Red);
				CLCD_voidSetPosition ( 2,1 );
				CLCD_voidSendString("You must stop");
				DIO_enumSetPinValue(DIO_PORTC, DIO_PIN5, DIO_PIN_LOW);
				_delay_ms(30);
				//MUART_voidSendString("I Must Stop");
				MUART_voidSendData('M');
			}
			_delay_ms(30);
		}
		CLCD_voidClearScreen();
	}

}
