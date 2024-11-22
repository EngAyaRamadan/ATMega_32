
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"

void TIMER1_voidResetInti(void)
{
	/*PRESCALLER*/
		TCCR1B&= 0b11111000;
		TCCR1B|= TIMER1_PRESCALLER;
		/*set control register to normal mode operation */
     	TCCR1A = 0;
     	/* clear ICU Flag */
	    TIFR = (1<<5);
	    /*set ICU noise canceler*/
	    SET_BIT(TCCR1B,7);
	    /* clear counter register */
	    TCNT1=0;
}

void TIMER1_voidClearFlag(u8 Copy_u8InterruptFlag)
{
	SET_BIT(TIFR,Copy_u8InterruptFlag);
}

u8 TIMER1_voidGetFlag(u8 Copy_u8InterruptFlag)
{
	return GET_BIT(TIFR,Copy_u8InterruptFlag);
}

void TIMER1_voidSetICREdge(u8 Copy_u8ICREdge)
{
	if (Copy_u8ICREdge == FALLING_EDGE)
		CLR_BIT(TCCR1B,6);
	else if( Copy_u8ICREdge == RISING_EDGE)
		SET_BIT(TCCR1B,6);
}

void TIMER1_voidSetStopTimer(void )
{
	TCCR1B=0;
}
