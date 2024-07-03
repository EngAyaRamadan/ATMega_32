 /*
 * #################################### TIMER0_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 23 April 2024
 *   Layer  :MCAL
 *   SWC    :TIMER
 *   Version: 1
*/


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_interface.h"
#include"TIMER_config.h"
#include"TIMER_private.h"
#include"TIMER_interface.h"


void (*TIMER0_CallBack[2])(void)={NULL};
/* -------------------------------------*/
void TIMER0_voidInti(void)
{
	/* MODE */
	TCCR0&= 0b11001111; /* to assign COMP_MATCH MODE */
	#if   TIMER0_MODE == TIMER0_NORMAL_MODE
	         /* SET MODE BIT */
	       CLR_BIT(TCCR0,6);  CLR_BIT(TCCR0,3);
		     /* SET PRELOAD VALUE */
		   TCNT0=TIMER0_PRELOAD_VALE;
	#elif TIMER0_MODE == TIMER0_PHASE_PWM_MODE
	          /* SET MODE BIT */
	        SET_BIT(TCCR0,6); CLR_BIT(TCCR0,3);
			/* SET COMPARE MATCH OUTPUT MODE */
			TCCR0|= (TIMER0_OC0_PHASE_PWM_MODE<<4);
			  /* SET CTC VALUE */
			DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
			OCR0=TIMER0_CTC_VALUE;
	#elif TIMER0_MODE == TIMER0_CTC_MODE
	        CLR_BIT(TCCR0,6); SET_BIT(TCCR0,3);
		    TCCR0|= (TIMER0_OC0_NON_PWM_MODE<<4);
			  /* SET CTC VALUE */
			DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
			OCR0=TIMER0_CTC_VALUE;
	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
	        SET_BIT(TCCR0,6); SET_BIT(TCCR0,3);
		    TCCR0|= (TIMER0_OC0_FAST_PWM_MODE<<4);
			  /* SET CTC VALUE */
			DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
			OCR0=TIMER0_CTC_VALUE;
	#endif
	
	 
	 /* INTERRUPT */
	      TIMSK&= 0b11111100;
	   /*  OVERFLOW INTERRUPT  */   
	   #if TIMER0_OVERFLOW_INTERRUPT == TIMER0_INT_DISABLE_OVERFLOW
           TIMSK&= (~TIMER0_OVERFLOW_INTERRUPT);  
	   #elif TIMER0_OVERFLOW_INTERRUPT == TIMER0_INT_ENABLE_OVERFLOW
           TIMSK|= (TIMER0_OVERFLOW_INTERRUPT-1);   
	   #endif  
	    /*  COMP_MATCH INTERRUPT  */   
	   #if TIMER0_COMP_MATCH_INTERRUPT  == TIMER0_INT_DISABLE_COMP_MATCH 
           TIMSK&= (~((TIMER0_OVERFLOW_INTERRUPT-2)<<1));  
	   #elif TIMER0_COMP_MATCH_INTERRUPT  == TIMER0_INT_ENABLE_COMP_MATCH 
           TIMSK|= (TIMER0_COMP_MATCH_INTERRUPT-2);  
	   #endif  

	 /* PRESCALLER */
	       TCCR0&= 0b11111000; 
	       TCCR0|= TIMER0_PRESCALLER; 
	 
}
/* -------------------------------------*/
void TIMER0_voidSetCounter(u8 Copy_u8Counter)
{
	TCNT0=Copy_u8Counter;
}
/* -------------------------------------*/
u8 TIMER0_u8GetCounter(void)
{
	return TCNT0;
}
/* -------------------------------------*/
void TIMER0_voidSetOCR(u8 Copy_u8OCR)
{
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	OCR0=Copy_u8OCR;
}
/* -------------------------------------*/
void TIMER0_voidClearFlag(u8 Copy_u8InterruptFlag)
{
	SET_BIT(TIFR,Copy_u8InterruptFlag);
}

/* -------------------------------------*/
u8 TIMER0_voidGetFlag(u8 Copy_u8InterruptFlag)
{
	return GET_BIT(TIFR,u8 Copy_u8InterruptFlag);
	
}
/* -------------------------------------*/
void TIMER0_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt==TIMER0_INT_DISABLE_OVERFLOW)
	    TIMSK&= (~TIMER0_OVERFLOW_INTERRUPT);
    else if(Copy_u8Interrupt==TIMER0_INT_DISABLE_COMP_MATCH)
		TIMSK&= (~((TIMER0_OVERFLOW_INTERRUPT-2)<<1));
}
/* -------------------------------------*/
void TIMER0_voidEnableInterrupt(u8 Copy_u8Interrupt)  
{
	if(Copy_u8Interrupt==TIMER0_INT_ENABLE_OVERFLOW)
	    TIMSK|= (TIMER0_OVERFLOW_INTERRUPT-1);
    else if(Copy_u8Interrupt==TIMER0_INT_ENABLE_COMP_MATCH)
		   TIMSK|= (TIMER0_COMP_MATCH_INTERRUPT-2);        
}

/* -------------------------------------*/
void TIMER0_voidPWM(u8 Copy_u8TimeOn)
{
	DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	OCR0=Copy_u8TimeOn;
}
/* -------------------------------------*/
void TIMER0_voidMSecDelay(u64 Copy_u64Milliseconeds)
{
	 TCCR0&= 0b11111000; 
	 TCCR0|= TIMER0_64_PRE ;
	 for(u64 counter=0;counter<Copy_u64Milliseconeds;counter++)
	 {
		 TCNT0=131;
		 while(GET_BIT(TIFR,TIMER0_OVERFLOW_FLAG)!=1);
		 SET_BIT(TIFR,TIMER0_OVERFLOW_FLAG);	 
	 }
}
/* -------------------------------------*/
void TIMER0_voidUSecDelay(u64 Copy_u64Microseconeds)
{
	 TCCR0&= 0b11111000; 
	 TCCR0|= TIMER0_NO_PRE ;
	for(u64 counter=0;counter<Copy_u64Microseconeds;counter++)
	 {
		 TCNT0=248;
		 while(GET_BIT(TIFR,TIMER0_OVERFLOW_FLAG)!=1);
		 SET_BIT(TIFR,TIMER0_OVERFLOW_FLAG);	 
	 }
	
}
/* -------------------------------------*/
void TIMER0_voidSetCallBack(void(*Copy_ptrVoidCallBack)(void),u8 Copy_u8Interrupt_ID)
{
	
	if(Copy_ptrVoidCallBack!=NULL)
	{
		TIMER0_CallBack[Copy_u8Interrupt_ID]=Copy_ptrVoidCallBack;
	}
	
}
	
	
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
		if(TIMER0_CallBack[0]!=NULL)
	{
		TIMER0_CallBack[0]();
		TIMER0_voidClearFlag(TIMER0_COMP_MATCH_FLAG);
	}
	
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
		if(TIMER0_CallBack[1]!=NULL)
	{
		TIMER0_CallBack[1]();
		TIMER0_voidClearFlag(TIMER0_OVERFLOW_FLAG);
	}
	
}


	
	
	
	
	
	
	
	
	
	
	
	