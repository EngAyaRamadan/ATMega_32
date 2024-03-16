 /*
 * #################################### EXTI_programe.c #############################
 *   Author : Aya Ramadan
 *   date   : 1 march 2024
 *   Layer  :HALL
 *   SWC    :EXTI
 *   Version: 1
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/* array of pointer to function>> there is three External interrupt
INT0,INT1,INT2 each External interrupt has own ISR */
void (*EXTI_CallBack[3])(void)={NULL};

/* this function for prebuild configration */
void EXTI_voidIntit(void)
{
 #ifdef EXTI_LINE
 
    #if EXTI_LINE==EXTI_LINE0
	     DIO_enumSetPinDirection (DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
		 
	   #if EXTI_SENSE_MODE==EXTI_LOW_LEVEL
	       CLR_BIT(MCUCR , 0); CLR_BIT(MCUCR , 1);
		 
	   #elif EXTI_SENSE_MODE==EXTI_ON_CHANGE
	       SET_BIT(MCUCR , 0); CLR_BIT(MCUCR , 1);
		   
	   #elif EXTI_SENSE_MODE==EXTI_FALLING_EDGE
	       CLR_BIT(MCUCR , 0); SET_BIT(MCUCR , 1);
		  DIO_enumSetPinValue  (DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
		   
	   #elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
	       SET_BIT(MCUCR , 0); SET_BIT(MCUCR , 1);
	   #endif
	   
	#elif EXTI_LINE==EXTI_LINE1
	     DIO_enumSetPinDirection (DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
		 
	   #if EXTI_SENSE_MODE==EXTI_LOW_LEVEL
	       CLR_BIT(MCUCR , 2); CLR_BIT(MCUCR , 3);
		   
	   #elif EXTI_SENSE_MODE==EXTI_ON_CHANGE
	       SET_BIT(MCUCR , 2); CLR_BIT(MCUCR , 3);
		   
	   #elif EXTI_SENSE_MODE==EXTI_FALLING_EDGE
	       CLR_BIT(MCUCR , 2); SET_BIT(MCUCR , 3);
		   DIO_enumSetPinValue  (DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
		   
	   #elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
	        SET_BIT(MCUCR , 2); SET_BIT(MCUCR , 3);
	   #endif
	   
	#elif EXTI_LINE==EXTI_LINE2
	     DIO_enumSetPinDirection (DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);
		 
	   #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
	        CLR_BIT(MCUCSR , 6);
		    DIO_enumSetPinValue  (DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	   #elif EXTI_SENSE_MODE==EXTI_RISING_EDGE
	        SET_BIT(MCUCSR , 6); 
			
	   #endif
	#endif      	   
 #endif
	
}
/* this function for post build configration */
void EXTI_voidSetSignalLatch(u8 copy_u8SenseMode,u8 copy_u8line)
{
	if(copy_u8line>=EXTI_LINE0 && copy_u8line<=EXTI_LINE1)
	  {
		 copy_u8line=(6-copy_u8line)*-2; 
         switch(copy_u8SenseMode)
		 {
            case EXTI_LOW_LEVEL:    CLR_BIT(MCUCR,copy_u8line); CLR_BIT(MCUCR,(copy_u8line+1)); break;
            case EXTI_ON_CHANGE:    SET_BIT(MCUCR,copy_u8line); CLR_BIT(MCUCR,(copy_u8line+1)); break;
            case EXTI_FALLING_EDGE: CLR_BIT(MCUCR,copy_u8line); SET_BIT(MCUCR,(copy_u8line+1));
			if(copy_u8line==0){DIO_enumSetPinValue  (DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);}
			else if(copy_u8line==1){DIO_enumSetPinValue  (DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);}break;
			case EXTI_RISING_EDGE:  SET_BIT(MCUCR,copy_u8line); SET_BIT(MCUCR,(copy_u8line+1));break;
		 }			 
	  }
	
	else
	 {
		   switch(copy_u8SenseMode)
		 {
            case EXTI_FALLING_EDGE:  CLR_BIT(MCUCSR,6);
			   DIO_enumSetPinValue  (DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH) ;break;
			case EXTI_RISING_EDGE:   SET_BIT(MCUCSR,6);break;
		 }	
	  }	
}

/* global interrupt function */
void EXTI_voidEnableGlobalInterrupt (void)
{
	SREG |=(1<<7);
}
void EXTI_voidDisableGlobalInterrupt(void)
{
	SREG &=~(1<<7);
	
}

/* enable interrupt prepheral */
void EXTI_voidEnableInterrupt (u8 copy_u8line)
{
	SET_BIT( GICR,copy_u8line);  
}

void EXTI_voidDisableInterrupt(u8 copy_u8line)
{
	CLR_BIT( GICR,copy_u8line);
}

/*functions for flag */
void EXTI_voidClearFlag (u8 copy_u8line)
{
	SET_BIT( GIFR,copy_u8line); 
}

u8 EXTI_voidGetFlag (u8 copy_u8line)
{
	return GET_BIT(GIFR,copy_u8line);
}

/* to set the ISR function */
void EXTI_voidSetCallBack(void (*copy_ptrvoidcallback)(void),u8 copy_u8line)
{
	if(copy_ptrvoidcallback !=NULL)
	{
		EXTI_CallBack[copy_u8line-5]=copy_ptrvoidcallback; //INT2 ,INT0,INT1
	}
}

/* ISR>>>>INT0 */
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	if(EXTI_CallBack[1]!=NULL)
	{
		EXTI_CallBack[1]();
		EXTI_voidClearFlag (EXTI_LINE0);
	}
	
}


/* ISR>>>>INT1 */
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	if(EXTI_CallBack[2]!=NULL)
	{
		EXTI_CallBack[2]();
		EXTI_voidClearFlag (EXTI_LINE1);
		
	}
	
}
/* ISR>>>>INT2 */
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if(EXTI_CallBack[0]!=NULL)
	{
		EXTI_CallBack[0]();
		EXTI_voidClearFlag (EXTI_LINE2);
	}
	
}























