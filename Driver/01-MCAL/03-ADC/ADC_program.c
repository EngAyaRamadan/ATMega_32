 /*
 * #################################### ADC_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 7 April 2024
 *   Layer  :MCAL
 *   SWC    :ADC
 *   Version: 1
*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"


#include"ADC_config.h"
#include"ADC_private.h"
#include"ADC_interface.h"


/* static variable for ISR */
static void(*ADC_ptrNotificationFunc)(void)= NULL;
static u16 *ADC_u16ptrAsyncConversionResult= NULL;
static u8 ADC_u8ISRState;

/* static variable for ADC Chain */
static u8 ADC_u8Index=0;
static u8 ADC_u8ChainSize;
static u8* ADC_u8ptrChainChannle;


/* initialization function for ADC */ 
void ADC_voidInit (void)
{
	/* Select The voltage Reference */
	   #if ADC_VREF == AREF
	      CLR_BIT(ADMUX,7);
		  CLR_BIT(ADMUX,6);
	   #elif ADC_VREF == INTERNAL_2_56
	      SET_BIT(ADMUX,7);
		  SET_BIT(ADMUX,6);
	   #elif ADC_VREF == AVCC
	     CLR_BIT(ADMUX,7);
		 SET_BIT(ADMUX,6);
	   #else 
		   #error "Wrong ADC_VREF config"
	   #endif

    /* Select The type of adjust result */
       #if ADC_ADJUSTED == RIGHT_ADJUSTED 
	      CLR_BIT(ADMUX,5);
	   #elif ADC_ADJUSTED ==LEFT_ADJUSTED
	      SET_BIT(ADMUX,5);
	   #else 
		   #error "Wrong ADC_ADJUSTED config"
	   #endif
		/* Select the ADC CHANNEL  */
	  /* #if ADC_CHANNEL >= ADC0 && ADC_CHANNEL <= ADC_DIFF_52_1x
	      ADMUX&= 0xE0; 
	      ADMUX|= ADC_CHANNEL ; 
	   #else 
		   #error "Wrong ADC_CHANNEL config"
	   #endif
	  */
	/* Select the ADC PRESCALLER  */
	   #if ADC_PRESCALLER >= 0 && ADC_PRESCALLER <= 7
	      ADCSRA&= 0xF8; 
	      ADCSRA|= ADC_PRESCALLER ;

       #else 
		   #error "Wrong ADC_PRESCALLER config"	  
	   #endif
	

	/* Select the ADC TRIGGERING SOURCE   */
	   #if ADC_TRIGGERING_SOURCE == ADC_SINGLE_CONVERSION
	         CLR_BIT(ADCSRA,5);

	   #elif ADC_TRIGGERING_SOURCE == ADC_FREE_RUNNING
	         SET_BIT(ADCSRA,5);
	      CLR_BIT(SFIOR,7);CLR_BIT(SFIOR,6);CLR_BIT(SFIOR,5);

	   #elif ADC_TRIGGERING_SOURCE == ADC_ANALOG_COMPARATOR
	      SET_BIT(ADCSRA,5);
	      CLR_BIT(SFIOR,7);CLR_BIT(SFIOR,6); SET_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_EXTI0
	      SET_BIT(ADCSRA,5);
	      CLR_BIT(SFIOR,7);SET_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_TIM0_CTC
	      SET_BIT(ADCSRA,5);
	      CLR_BIT(SFIOR,7);SET_BIT(SFIOR,6); SET_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_TIM0_OVF
	      SET_BIT(ADCSRA,5);
	      SET_BIT(SFIOR,7);CLR_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_TIM1_CTC_CHANNEL_B
	      SET_BIT(ADCSRA,5);
	      SET_BIT(SFIOR,7);CLR_BIT(SFIOR,6); SET_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_TIM1_OVF
	      SET_BIT(ADCSRA,5);
	      SET_BIT(SFIOR,7);SET_BIT(SFIOR,6); CLR_BIT(SFIOR,5);
		  
	   #elif ADC_TRIGGERING_SOURCE == ADC_TIM1_ICU
	      SET_BIT(ADCSRA,5);
	      SET_BIT(SFIOR,7);SET_BIT(SFIOR,6); SET_BIT(SFIOR,5);

       #else
		   #error "Wrong ADC_TRIGGERING_SOURCE config"
	   #endif
	
	/* enable ADC INT */
       #if ADC_INT_STATUS == ADC_INT_DISABLE
           CLR_BIT(ADCSRA,3);
       #elif ADC_INT_STATUS == ADC_INT_ENABLE
	       SET_BIT(ADCSRA,3);
  #else
		   #error "Wrong ADC_INT_STATUS config"
       #endif

    /* enable ADC */
       #if ADC_STATUS == ADC_DISABLE
           CLR_BIT(ADCSRA,7);
       #elif ADC_STATUS == ADC_ENABLE
	       SET_BIT(ADCSRA,7);
       #else 
		   #error "Wrong ADC_STATUS config"
       #endif
}
/* ADC STATUS */
void ADC_voidEnable (void)
{
	SET_BIT(ADCSRA,7);
}

void ADC_voidDisable (void)
{
	 CLR_BIT(ADCSRA,7);
}
/* INTERRUPT STATUS */
void ADC_voidInterruptEnable (void)
{
	 SET_BIT(ADCSRA,3);
}

void ADC_voidInterruptDisable (void)
{
	 CLR_BIT(ADCSRA,3);
}
/* FUNCTION FOR RESULT  OF A SYNC  */
u8 ADC_u16GetResltSync(u8 Copy_u8channel,u16 *Copy_u16PtrResult)
{
	u8 Local_u8ErrorState= ADC_OK;
	if( Copy_u16PtrResult!=NULL )
	{
		u32 Local_32TimeOutCounter=0;
		/* Select the ADC CHANNEL  */
		  ADMUX&= 0xE0; 
	      ADMUX|= Copy_u8channel ; 
	/*start conversion */
	SET_BIT(ADCSRA,6);
	while((GET_BIT(ADCSRA,4)== 0 )&& Local_32TimeOutCounter < ADC_TIMEOUT )
	{
		Local_32TimeOutCounter++;
	}
	if(Local_32TimeOutCounter == ADC_TIMEOUT)
	{
		 Local_u8ErrorState=ADC_NOK;
	}
	else
	{
		/* clear flag bit (must) */
		 SET_BIT(ADCSRA,4);
		 #if ADC_ADJUSTED == RIGHT_ADJUSTED  
	      *Copy_u16PtrResult=(ADCL|(ADCH<<8));   
	     #elif ADC_ADJUSTED ==LEFT_ADJUSTED
	      *Copy_u16PtrResult=ADCH;
		 #endif
	}
	}
	else
	{
		 Local_u8ErrorState=ADC_NOK;
	}
	
	return Local_u8ErrorState;
}


/* FUNCTION TO START CONVERSION OF ASYNC */
u8 ADC_u16StartConversionAsync(u8 Copy_u8channel,u16 *Copy_u16PtrResult,void(*Copy_ptrNotificationFunc)(void))
{
	u8 Local_u8ErrorState= ADC_OK;
	if(Copy_ptrNotificationFunc != NULL)
	{
		 ADC_u8ISRState=SINGLE_CHANNEL_ASYNC;
		/* intialize ISR function */
		ADC_ptrNotificationFunc = Copy_ptrNotificationFunc;
		ADC_u16ptrAsyncConversionResult=Copy_u16PtrResult;
		/* Select the ADC CHANNEL  */
		  ADMUX&= 0xE0; 
	      ADMUX|= Copy_u8channel ; 
		/*start conversion */
	    SET_BIT(ADCSRA,6);
		/* enable ADC interrupt */
		SET_BIT(ADCSRA,3);
	}
	
	else 
	{
		Local_u8ErrorState= ADC_NOK;
	}
		
	return Local_u8ErrorState;
}


u8 ADC_u16StartChainAsync(Chain_t * copy_chain)
{
	u8 Local_u8ErrorState= ADC_OK;
	if(copy_chain != NULL  && (copy_chain->NotificationFunc != NULL))
	{
		 ADC_u8ISRState=CHAIN_CHANNEL_ASYNC;
		 
		 ADC_u8ChainSize=copy_chain->size;
		 ADC_u8ptrChainChannle=copy_chain->channel;
		 ADC_u16ptrAsyncConversionResult=copy_chain->result;
		/* intialize ISR function */
		ADC_ptrNotificationFunc = copy_chain->NotificationFunc;
		
		ADC_u8Index=0;
		/* Select the ADC CHANNEL  */
		 ADMUX&= 0xE0;
		 ADMUX|= ADC_u8ptrChainChannle[ADC_u8Index] ;
		/*start conversion */
	    SET_BIT(ADCSRA,6);
		/* enable ADC interrupt */
		SET_BIT(ADCSRA,3);
	}
	
	else 
	{
		Local_u8ErrorState= ADC_NOK;
	}
		
	return Local_u8ErrorState;
}



void __vector_17 (void) __attribute__((signal));
void __vector_17 (void)
{
	if (ADC_u8ISRState==SINGLE_CHANNEL_ASYNC)
	{
		 #if ADC_ADJUSTED == RIGHT_ADJUSTED  
	      *ADC_u16ptrAsyncConversionResult=(ADCL|(ADCH<<8));   
	     #elif ADC_ADJUSTED ==LEFT_ADJUSTED
	      *ADC_u16ptrAsyncConversionResult=ADCH;
		 #endif
		 /* CALL FUNCTION */ 
		 ADC_ptrNotificationFunc();
		 /* DISABLE ADC CONVERSSION COMPLETE INTERRUPT */
		 CLR_BIT(ADCSRA,3);
	}
	else{
		
		   #if ADC_ADJUSTED == RIGHT_ADJUSTED  
	        *ADC_u16ptrAsyncConversionResult=(ADCL|(ADCH<<8));   
	       #elif ADC_ADJUSTED ==LEFT_ADJUSTED
	        *ADC_u16ptrAsyncConversionResult=ADCH;
		   #endif
		   
		   ++ADC_u8Index;
		   if(ADC_u8Index==ADC_u8ChainSize)
		   {
			   /* CALL FUNCTION */ 
		     ADC_ptrNotificationFunc();
		      /* DISABLE ADC CONVERSSION COMPLETE INTERRUPT */
		     CLR_BIT(ADCSRA,3);
		   }
		   else
		   {
			   /* Select the ADC CHANNEL  */
		        ADMUX&= 0xE0; 
	            ADMUX|= ADC_u8ptrChainChannle[ADC_u8Index] ;
			   	/*stsrt conversion */
	            SET_BIT(ADCSRA,6);
		   }
		
	}
	
}
















