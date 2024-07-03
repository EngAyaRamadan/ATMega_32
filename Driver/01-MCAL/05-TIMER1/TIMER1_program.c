 /*
 * #################################### TIMER1_programe].c #############################
 *   Author : Aya Ramadan
 *   date   : 30 April 2024
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


void (*TIMER1_CallBack[4])(void)={NULL};
/* -------------------------------------*/
void TIMER1_voidInti(void)
{               
   
	/* MODE */
	/*--------------- NORMAL MODE ---------------- */
   #if TIMER1_MODE == TIMER1_NORMAL_MODE
       CLR_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	   CLR_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
	   /* set preload */
       TCNT1=TIMER1_PRELOAD_VALE;
    /*--------------- PHASE PWM MODE ---------------- */
   #elif TIMER1_MODE == TIMER1_PHASE_PWM_8_BIT_MODE || TIMER1_MODE == TIMER1_PHASE_PWM_9_BIT_MODE  || TIMER1_MODE == TIMER1_PHASE_PWM_10_BIT_MODE|| TIMER1_MODE == TIMER1_PHASE_PWM_ICR1_MODE|| TIMER1_MODE == TIMER1_PHASE_PWM_OCR1A_MODE|| TIMER1_MODE == TIMER1_PHASE_FREQ_PWM_OCR1A_MODE || TIMER1_MODE == TIMER1_PHASE_FREQ_PWM_ICR1_MODE 
         #if TIMER1_MODE == TIMER1_PHASE_PWM_8_BIT_MODE
		     SET_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_PWM_9_BIT_MODE
		     CLR_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_PWM_10_BIT_MODE
		     SET_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_PWM_ICR1_MODE
		     CLR_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_PWM_OCR1A_MODE
		     SET_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_FREQ_PWM_ICR1_MODE
		     CLR_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_PHASE_FREQ_PWM_OCR1A_MODE
		     SET_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	         CLR_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
	      #endif
		  
	   OCR1A = TIMER1_CTCA_VALUE;
	   OCR1B =  TIMER1_CTCB_VALUE;
	   
	   #if  TIMER1_MODE == TIMER1_PHASE_FREQ_PWM_ICR1_MODE || TIMER1_MODE == TIMER1_PHASE_PWM_ICR1_MODE
	       ICR1= TIMER1_ICR1_VALE;
		   #if TIMER1_ICR_EDGE == FALLING_EDGE
		        CLR_BIT(TCCR1B,6);
		   #elif TIMER1_ICR_EDGE == RISING_EDGE 
	            SET_BIT(TCCR1B,6);
	       #endif
	   /* SET OCR1A MODE */
	   #if  TIMER1_CTC_OCR1A_MODE == TIMER1_DISCONNECTED_OC
	        CLR_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED
	        SET_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_CLR_ON_CTC_UP_SET_ON_CTC_DWONE_OC
	        CLR_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_SET_ON_CTC_UP_CLR_ON_CTC_DWONE_OC 
	        SET_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
       #endif
	   /* SET OCR1B MODE */
	   #if TIMER1_CTC_OCR1B_MODE == TIMER1_DISCONNECTED_OC
	        CLR_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED
	        SET_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_CLR_ON_CTC_UP_SET_ON_CTC_DWONE_OC
	        CLR_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
	   #elif TTIMER1_CTC_OCR1B_MODE == TIMER1_SET_ON_CTC_UP_CLR_ON_CTC_DWONE_OC 
	        SET_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
       #endif
	  /*--------------- FAST PWM MODE ---------------- */
    #elif TIMER1_MODE == TIMER1_FAST_PWM_8_BIT_MODE || TIMER1_MODE == TIMER1_FAST_PWM_9_BIT_MODE  || TIMER1_MODE == TIMER1_FAST_PWM_10_BIT_MODE  || TIMER1_MODE == TIMER1_FAST_PWM_ICR1_MODE  || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A_MODE 
         #if TIMER1_MODE == TIMER1_FAST_PWM_8_BIT_MODE
		     SET_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
			 SET_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_FAST_PWM_9_BIT_MODE
		     CLR_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_FAST_PWM_10_BIT_MODE
		     SET_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_FAST_PWM_ICR1_MODE
		     CLR_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_FAST_PWM_OCR1A_MODE
		     SET_BIT(TCCR1A,0),SET_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
	     #endif
		  
	   OCR1A = TIMER1_CTCA_VALUE;
	   OCR1B = TIMER1_CTCB_VALUE;
	   
	   #if  TIMER1_MODE == TIMER1_FAST_PWM_ICR1_MODE  
	       ICR1= TIMER1_ICR1_VALE;
		   #if TIMER1_ICR_EDGE == FALLING_EDGE
		        CLR_BIT(TCCR1B,6);
		   #elif TIMER1_ICR_EDGE == RISING_EDGE 
	            SET_BIT(TCCR1B,6);
	       #endif
		   
	   /* SET OCR1A MODE */
	   #if  TIMER1_CTC_OCR1A_MODE == TIMER1_DISCONNECTED_OC01
	        CLR_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED
	        SET_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_CLR_ON_CTC_SET_TOP_OC
	        CLR_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_SET_CTC_CLR_TOP_OC 
	        SET_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
       #endif
	   /* SET OCR1B MODE */
	   #if TIMER1_CTC_OCR1B_MODE == TIMER1_DISCONNECTED_OC
	        CLR_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED
	        SET_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_CLR_ON_CTC_UP_SET_ON_CTC_DWONE_OC
	        CLR_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
	   #elif TTIMER1_CTC_OCR1B_MODE == TIMER1_SET_ON_CTC_UP_CLR_ON_CTC_DWONE_OC 
	        SET_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
       #endif
	   /*--------------- CTC MODE ---------------- */   
	#elif TIMER1_MODE == TIMER1_CTC_ICR1_MODE  ||  TIMER1_MODE ==  TIMER1_CTC_OCR1A_MODE
	     #if TIMER1_MODE == TIMER1_CTC_ICR1_MODE
		     CLR_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),SET_BIT(TCCR1B,4);
         #elif TIMER1_MODE == TIMER1_CTC_OCR1A_MODE
		     CLR_BIT(TCCR1A,0),CLR_BIT(TCCR1A,1);
	         SET_BIT(TCCR1B,3),CLR_BIT(TCCR1B,4);
	     #endif
		  
	   OCR1A = TIMER1_CTCA_VALUE;
	   OCR1B = TIMER1_CTCB_VALUE;
	   
	    #if  TIMER1_MODE == TIMER1_CTC_ICR1_MODE 
	       ICR1= TIMER1_ICR1_VALE;
	        #if TIMER1_ICR_EDGE == FALLING_EDGE
		        CLR_BIT(TCCR1B,6);
		   #elif TIMER1_ICR_EDGE == RISING_EDGE 
	            SET_BIT(TCCR1B,6);
	       #endif
	    /* SET OCR1A MODE */
	   #if  TIMER1_CTC_OCR1A_MODE == TIMER1_DISCONNECTED_OC
	        CLR_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_TOGGLE_OC
	        SET_BIT(TCCR1A,6),CLR_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_CLEAR_OC
	        CLR_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
	   #elif TIMER1_CTC_OCR1A_MODE == TIMER1_SET_OC 
	        SET_BIT(TCCR1A,6),SET_BIT(TCCR1A,7);
       #endif
	   /* SET OCR1B MODE */
	   #if TIMER1_CTC_OCR1B_MODE == TIMER1_DISCONNECTED_OC
	        CLR_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_TOGGLE_OC
	        SET_BIT(TCCR1A,4),CLR_BIT(TCCR1A,5);
	   #elif TIMER1_CTC_OCR1B_MODE == TIMER1_CLEAR_OC
	        CLR_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
	   #elif TTIMER1_CTC_OCR1B_MODE == TIMER1_SET_OC 
	        SET_BIT(TCCR1A,4),SET_BIT(TCCR1A,5);
       #endif
	   
    #endif   
	   
	 /* ------------- INTERRUPT -------------- */
	      TIMSK&= 0b11000011;
	   /*  OVERFLOW INTERRUPT  */   
	   #if TIMER1_OVERFLOW_INTERRUPT == TIMER1_INT_DISABLE_OVERFLOW
              CLR_BIT(TIMSK,2);  
	   #elif TIMER1_OVERFLOW_INTERRUPT == TIMER1_INT_ENABLE_OVERFLOW
              SET_BIT(TIMSK,2);   
	   #endif  
	    /*  COMP_MATCH A INTERRUPT  */   
	   #if TIMER1_COMP_MATCH_A_INTERRUPT  == TIMER1_INT_DISABLE_COMP_MATCH_A 
           CLR_BIT(TIMSK,4);    
	   #elif TIMER1_COMP_MATCH_A_INTERRUPT  == TIMER1_INT_ENABLE_COMP_MATCH_A
          SET_BIT(TIMSK,4);  
	   #endif  
	    /*  COMP_MATCH B INTERRUPT  */   
	   #if  TIMER1_COMP_MATCH_B_INTERRUPT  == TIMER1_INT_DISABLE_COMP_MATCH_B 
            CLR_BIT(TIMSK,3);    
	   #elif  TIMER1_COMP_MATCH_B_INTERRUPT  == TIMER1_INT_ENABLE_COMP_MATCH_B
          SET_BIT(TIMSK,3);  
	   #endif  
        /*  INPUT CAPTURE INTERRUPT  */   
	   #if  TIMER1_INPUT_CAPTURE_INTERRUPT  == TIMER1_INT_DISABLE_INPUT_CAPTURE 
            CLR_BIT(TIMSK,5);    
	   #elif  TIMER1_INPUT_CAPTURE_INTERRUPT  == TIMER1_INT_ENABLE_INPUT_CAPTURE 
           SET_BIT(TIMSK,5); 
	   #endif  
	 /* --------------------- PRESCALLER -------------------- */
	       TCCR1B&= 0b11111000; 
	       TCCR1B|= TIMER1_PRESCALLER; 
	 
}
/* -------------------------------------*/
void TIMER1_voidSetPreload(u16 Copy_u16Preload)
{
	TCNT1=Copy_u16Preload;
}
/* -------------------------------------*/
void TIMER1_voidSetOCRA(u16 Copy_u16OCR);
{
	//DIO_enumSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	OCR1A=Copy_u8OCR;
}
/* -------------------------------------*/
void TIMER1_voidSetOCRB(u16 Copy_u16OCR)
{
	OCR1B=Copy_u16OCR;
}

void TIMER1_u16SetICR1(u16 Copy_u16ISR)
{
	ICR1=Copy_u16ISR;
}
/* -------------------------------------*/
u16 TIMER1_u8GetICR1(void)
{
	return ICR1;
}
/* -------------------------------------*/
void TIMER1_voidChangeEdge(u8 Copy_u8Edge)
{
	 if( Copy_u8Edge == FALLING_EDGE ) 
		 CLR_BIT(TCCR1B,6);
	 else if ( Copy_u8Edge == RISING_EDGE ) 
	      SET_BIT(TCCR1B,6);
}
/* -------------------------------------*/
void TIMER0_voidClearFlag(u8 Copy_u8InterruptFlag)
{
	     SET_BIT(TIFR,Copy_u8InterruptFlag);
}

u8 TIMER0_voidGetFlag(u8 Copy_u8InterruptFlag)
{
	return GET_BIT(TIFR,Copy_u8InterruptFlag);
}
/* -------------------------------------*/
void TIMER1_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt == TIMER1_INT_DISABLE_OVERFLOW)
		CLR_BIT(TIMSK,2);
    else if(Copy_u8Interrupt == TIMER1_INT_DISABLE_COMP_MATCH_A)
		CLR_BIT(TIMSK,4);
	 else if(Copy_u8Interrupt == TIMER1_INT_DISABLE_COMP_MATCH_B)
		CLR_BIT(TIMSK,3);
	 else if(Copy_u8Interrupt == TIMER1_INT_DISABLE_INPUT_CAPTURE)
		CLR_BIT(TIMSK,5);
}
/* -------------------------------------*/
void TIMER1_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	if(Copy_u8Interrupt == TIMER1_INT_ENABLE_OVERFLOW)
		SET_BIT(TIMSK,2);
    else if(Copy_u8Interrupt == TIMER1_INT_ENABLE_COMP_MATCH_A)
		SET_BIT(TIMSK,4);
	 else if(Copy_u8Interrupt == TIMER1_INT_ENABLE_COMP_MATCH_B)
		SET_BIT(TIMSK,3);
	 else if(Copy_u8Interrupt == TIMER1_INT_ENABLE_INPUT_CAPTURE)
		SET_BIT(TIMSK,5);
}
/* -------------------------------------*/
void TIMER1_voidPWM(u16 Copy_u16OCRVALUE, u8 Copy_u8PWMChannal)
{
	if( Copy_u8Channal==PWM_CHANNEL_A)
	{
		DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
		OCR1A= Copy_u16OCRVALUE;
	}
	else if( Copy_u8Channal== PWM_CHANNEL_B)
	{
		DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);
		OCR1B= Copy_u16OCRVALUE;
	}
}
/* -------------------------------------*/
void TIMER1_voidSetCallBack(void(*Copy_ptrVoidCallBack)(void),u8 Copy_u8Interrupt_ID)
{
	if(Copy_ptrVoidCallBack!=NULL)
	{
		TIMER1_CallBack[Copy_u8Interrupt_ID]=Copy_ptrVoidCallBack;
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
		if(TIMER1_CallBack[0]!=NULL)
	{
		TIMER1_CallBack[0]();
		TIMER1_voidClearFlag(TIMER1_INPUT_CAPTURE_FLAG);
	}
	
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
		if(TIMER1_CallBack[1]!=NULL)
	{
		TIMER1_CallBack[1]();
		TIMER0_voidClearFlag(TIMER1_COMP_MATCH_A_FLAG);
	}
	
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
		if(TIMER1_CallBack[2]!=NULL)
	{
		TIMER1_CallBack[2]();
		TIMER0_voidClearFlag(TIMER1_COMP_MATCH_B_FLAG);
	}
	
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
		if(TIMER1_CallBack[1]!=NULL)
	{
		TIMER1_CallBack[3]();
		TIMER0_voidClearFlag(TIMER1_INPUT_CAPTURE_FLAG);
	}
	
}









	
	



	
	
	
	
	
	
	
	
	
	
	
	