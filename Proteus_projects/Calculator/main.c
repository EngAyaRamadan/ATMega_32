
/*
 * main.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Aya Ramadan
 */




#include <avr/io.h>
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "calculator_function.h"
void main(void)
{
	/* initialization component */
	KPD_voidInit();
	CLCD_voidInti();

	calculator();
}


