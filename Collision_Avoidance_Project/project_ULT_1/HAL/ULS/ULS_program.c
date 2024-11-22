#include <util/delay.h>

#include "../../HAL/ULS/ULS_config.h"
#include "../../HAL/ULS/ULS_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"


void ULS_voidInti()
{
	DIO_enumSetPinDirection (TR_PORT,TR_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (ECHO_PORT,ECHO_PIN,DIO_PIN_INPUT);

}
void ULS_voidSendTr(void)
{
	DIO_enumSetPinValue(TR_PORT,TR_PIN,DIO_PIN_HIGH);
	_delay_us(20);
	DIO_enumSetPinValue(TR_PORT,TR_PIN,DIO_PIN_LOW);
}
