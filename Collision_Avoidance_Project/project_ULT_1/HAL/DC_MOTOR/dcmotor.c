/*
 * dcmotor.c
 *
 *  Created on: Sep 13, 2023
 *      Author: dell
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "dcmotor.h"
#include <avr/delay.h>

void DCMOTOR_Init(void)
{
	 DIO_enumSetPortDirection(DCMOTOR_PORT,0x0f);
}


void DCMOTOR_Stop(void)
{
	DIO_enumSetPinValue(DCMOTOR_PORT,BLUE,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,PINK,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,YELLOW,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,ORANGE,DIO_PIN_LOW);
}

void DCMOTOR_CW(void)
{
	DIO_enumSetPinValue(DCMOTOR_PORT,BLUE,DIO_PIN_HIGH);
	DIO_enumSetPinValue(DCMOTOR_PORT,PINK,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,YELLOW,DIO_PIN_HIGH);
	DIO_enumSetPinValue(DCMOTOR_PORT,ORANGE,DIO_PIN_LOW);

}
void DCMOTOR_CCW(void)
{
	DIO_enumSetPinValue(DCMOTOR_PORT,BLUE,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,PINK,DIO_PIN_HIGH);
	DIO_enumSetPinValue(DCMOTOR_PORT,YELLOW,DIO_PIN_LOW);
	DIO_enumSetPinValue(DCMOTOR_PORT,ORANGE,DIO_PIN_HIGH);

}

