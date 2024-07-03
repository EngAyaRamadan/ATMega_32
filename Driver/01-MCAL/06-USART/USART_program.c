 /*
 * #################################### USART_programe.c #############################
 *   Author : Aya Ramadan
 *   date   : 28 June 2024
 *   Layer  :MCAL
 *   SWC    :USART
 *   Version: 1
*/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"

#include <util/delay.h>

static u8 USART_u8STATE =USART_IDEL;

/*Global variable to carry the Transmit Data*/
static const u8 * USART_pu8TransmitData = NULL ;

/*Global variable to carry the Receive Data*/
static u8 * USART_pu8ReceiveData = NULL ;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 USART_u8Index ;

/*Global variable to carry the buffer size*/
static u8 USART_u8BufferSize ;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* USART_pvNotificationFunc)(void)= NULL;

/* This function initialize USART depend on config.h */
void USART_voidInit (void)
{
	 u16 local_u16UBBR_value=0;
		/* System Speed  */
	#if USART_MODE == ASYNCHRONOUS && USART_SYSTEM_SPEED == USART_X
	    CLR_BIT( UCSRA,CSRA_U2X);
			/* calculate the value of baud rate register  */
	    local_u16UBBR_value= (u16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)-1);
	#elif USART_MODE == ASYNCHRONOUS && USART_SYSTEM_SPEED == USART_2X
	    SET_BIT( UCSRA,CSRA_U2X);
	    local_u16UBBR_value= (u16)((SYSTEM_FREQUENCY / (8 * USART_BAUD_RATE)-1);
	#elif USART_MODE == SYNCHRONOUS
	    CLR_BIT( UCSRA,CSRA_U2X);
		local_u16UBBR_value= (u16)((SYSTEM_FREQUENCY / (2 * USART_BAUD_RATE)-1);
	#else  
		#error "Wrong USART_SYSTEM_SPEED or USART_SYSTEM_SPEED config "
	#endif
	
	  /* clear URSEL bit to select UBRRH  */ 
	  UCSRC |=0x7F;
	/* Set baud rate register value */
	   UBRRH = (u8)(local_u16UBBR_value>>8); /* access first */
	   UBRRL = (u8) local_u16UBBR_value ; 
       
	/*  Multi-Processor Communication mode */
	#if USART_MPCM == DISABLE
	    CLR_BIT( UCSRA,UCSRA_MPCM);
	#elif USART_MPCM == ENABLE
	    SET_BIT( UCSRA,UCSRA_MPCM);
	#else  
		#error "Wrong USART_MPCM config "
	#endif
	
	  /* frame formate */
    /* Set URSEL bit to select UCSRC  */
     UCSRC |=0xFF;
   
    /* Data Size */
   #if USART_DATA_SIZE == DATA_SIZE_5_BIT
	    CLR_BIT( UCSRC,UCSRC_UCSZ0);
		CLR_BIT( UCSRC,UCSRC_UCSZ1 );
		CLR_BIT( UCSRB,UCSRB_UCSZ2);
	#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
	    SET_BIT( UCSRC,UCSRC_UCSZ0);
		CLR_BIT( UCSRC,UCSRC_UCSZ1 );
		CLR_BIT( UCSRB,UCSRB_UCSZ2);
	#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
	    CLR_BIT( UCSRC,UCSRC_UCSZ0);
		SET_BIT( UCSRC,UCSRC_UCSZ1 );
		CLR_BIT( UCSRB,UCSRB_UCSZ2);
	#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
	    SET_BIT( UCSRC,UCSRC_UCSZ0);
		SET_BIT( UCSRC,UCSRC_UCSZ1 );
		CLR_BIT( UCSRB,UCSRB_UCSZ2);
	#elif USART_DATA_SIZE == DATA_SIZE_9_BIT
	    SET_BIT( UCSRC,UCSRC_UCSZ0);
		SET_BIT( UCSRC,UCSRC_UCSZ1 );
		SET_BIT( UCSRB,UCSRB_UCSZ2);
	#else  
		#error "Wrong USART_DATA_SIZE config "
    #endif

/* Parity Mode  */
	#if USART_PARITY_MODE == DISABLE
	    CLR_BIT( UCSRC,UCSRC_UPM0 );
		CLR_BIT( UCSRC,UCSRC_UPM1);
	#elif USART_PARITY_MODE == EVEN_PARITY
	    CLR_BIT( UCSRC,UCSRC_UPM0 );
		SET_BIT( UCSRC,UCSRC_UPM1);
	#elif USART_PARITY_MODE == ODD_PARITY
		SET_BIT( UCSRC,UCSRC_UPM0 );
		SET_BIT( UCSRC,UCSRC_UPM1);
	#else  
		#error "USART_PARITY_MODE config "
	#endif
  
  	/* Stop bit  */
	#if USART_STOP_BIT == STOP_BIT_1
	    CLR_BIT( UCSRC,UCSRC_USBS);
	#elif USART_STOP_BIT == STOP_BIT_2
	    SET_BIT( UCSRC,UCSRC_USBS);
	#else  
		#error "Wrong USART_STOP_BIT config "
	#endif
	
   	/* USART Mode  */
	#if USART_MODE == SYNCHRONOUS
	    SET_BIT( UCSRC,UCSRC_UMSEL);
	#elif USART_MODE == ASYNCHRONOUS
	    CLR_BIT( UCSRC,UCSRC_UMSEL);
	#else  
		#error "Wrong USART_MODE config "
	#endif

   /* Clock Polarity (for SYNCHRONOUS mode only)  */
	#if USART_MODE == SYNCHRONOUS && USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
	    CRL_BIT( UCSRC,UCSRC_UCPOL);
	#elif USART_MODE == SYNCHRONOUS && USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
	    SET_BIT( UCSRC,UCSRC_UCPOL);
	#elif USART_MODE == ASYNCHRONOUS 
	    CRL_BIT( UCSRC,UCSRC_UCPOL);
	#else  
		#error "Wrong USART_CLOCK_POLARITY config "
	#endif
	
/* interrupt */
	/* RX Complete Interrupt */
	#if USART_RX_COMPLETE_INTERRUPT == DISABLE
	    CLR_BIT( UCSRB,UCSRB_RXCIE);
	#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
	    SET_BIT( UCSRB,UCSRB_RXCIE);
	#else  
		#error "Wrong USART_RX_COMPLETE_INTERRUPT config "
	#endif
	
	/* TX Complete Interrupt */
	#if USART_TX_COMPLETE_INTERRUPT == DISABLE
	    CLR_BIT( UCSRB,UCSRB_TXCIE);
	#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
	    SET_BIT( UCSRB,UCSRB_TXCIE);
	#else  
		#error "Wrong USART_TX_COMPLETE_INTERRUPT config "
	#endif
	/* UDR Empty Interrupt */
	#if USART_UDR_EMPTY_INTERRUPT == DISABLE
	    CLR_BIT( UCSRB,UCSRB_UDRIE);
	#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
	    SET_BIT( UCSRB,UCSRB_UDRIE);
	#else  
		#error "Wrong USART_UDR_EMPTY_INTERRUPT config "
	#endif
	
		/* Transmitter Enable */
	#if USART_TRANSMITTER_ENABLE == DISABLE
	    CLR_BIT( UCSRB,UCSRB_TXEN);
	#elif USART_TRANSMITTER_ENABLE == ENABLE
	    SET_BIT( UCSRB,UCSRB_TXEN);
	#else  
		#error "Wrong USART_TRANSMITTER_ENABLE config "
	#endif
	
    		/* Receiver Enable */
	#if USART_RECEIVER_ENABLE == DISABLE
	    CLR_BIT( UCSRB,UCSRB_RXEN);
	#elif USART_RECEIVER_ENABLE == ENABLE
	    SET_BIT( UCSRB,UCSRB_RXEN);
	#else  
		#error "Wrong USART_RECEIVER_ENABLE config "
	#endif
	
	/* set pin direction of transmeter and reciver */
	 DIO_enumSetPinDirection (DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
     DIO_enumSetPinDirection (DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
    
}

u8   USART_u8TransmitData (u8 Copy_u8Data)
{
	
	u8 Local_u8ErrorState= USART_OK;
	u32 Local_32TimeOutCounter=0;
	
	if( USART_u8STATE == USART_IDEL)
	{
		USART_u8STATE = USART_BUSY;
		/* Wait for empty transmit buffer to send the data and avoid overrun data*/
	  while( (GET_BIT(UCSRA,UCSRA_UDRE)== 0 )&& Local_32TimeOutCounter < USART_TIMEOUT )
	    {
		   Local_32TimeOutCounter++;
	    }
	  if(Local_32TimeOutCounter == USART_TIMEOUT)
	   {
		 Local_u8ErrorState=USART_NOK;
	   }
	  else
	  {
		UDR= Copy_u8Data;
	  }
	  USART_u8STATE = USART_IDEL;
	}
	
	else
	{
		 Local_u8ErrorState=USART_BUSY;
	}
	
	return Local_u8ErrorState;
	
}

u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData) 
{
	
	u8 Local_u8ErrorState= USART_OK;
	u32 Local_32TimeOutCounter=0;
	
	if( Copy_u8ReceviedData != NULL)
	{
	  if(USART_u8STATE == USART_IDEL)
	  { 
        USART_u8STATE = USART_BUSY;
		/*Wait until a receive complete*/
	    while( (GET_BIT(UCSRA,UCSRA_RXC)== 0 )&& Local_32TimeOutCounter < USART_TIMEOUT )
	    {
		   Local_32TimeOutCounter++;
	    }
	    if(Local_32TimeOutCounter == USART_TIMEOUT)
	    {
		 Local_u8ErrorState=USART_NOK;
	    }
	    else
	    {
		   * Copy_u8ReceviedData=UDR;
	    }
		 USART_u8STATE = USART_IDEL;
	  }
	 else
	  {
		 Local_u8ErrorState= USART_BUSY	 ;
	  }
	
	}
	
	else
	{
		 Local_u8ErrorState= USART_NULL_POINTER	 ;
	}
	
	return Local_u8ErrorState;
	
}
u8   USART_u8TransmitStringSynch (const u8 *Copy_pchstring)
{
	
	
	u8 Local_u8ErrorState= USART_OK;
	u32 local_u32IndexString=0;
	if(Copy_pchstring!=NULL)
	{
	   while( Copy_pchstring[local_u32IndexString]!= '\0' )
	    {
			Local_u8ErrorState= USART_u8TransmitData (Copy_pchstring[local_u32IndexString]);
			local_u32IndexString++;
		   if(Local_u8ErrorState != USART_OK)
		      return Local_u8ErrorState;
	    }
		
	}
	else
	{
	  Local_u8ErrorState= USART_NULL_POINTER ;
		
	}
	
	return Local_u8ErrorState;
	
}
u8   USART_u8TransmitStringAsynch (const u8 *Copy_pchstring, void (* NotificationFunc)(void))
{
	u8 Local_u8ErrorState= USART_OK;
	
	if( USART_u8STATE == USART_IDEL)
	{
	  if(Copy_pchstring != NULL && (NotificationFunc !=NULL))
	   {
		   USART_u8STATE = USART_BUSY;
		   
		   /*set global data*/
		   USART_pu8TransmitData=Copy_pchstring;
		   USART_pvNotificationFunc=NotificationFunc;
		   
		  /* Set Index to first element */
           USART_u8Index=0 ;
		  /* Send first Data */
		   UDR= USART_pu8TransmitData[USART_u8Index];
		  /* USART Transmit Interrupt Enable */
		   SET_BIT( UCSRB,UCSRB_TXCIE);
	   }
	  else
	  {
		Local_u8ErrorState= USART_NULL_POINTER;
	  }
	 
	}
	
	else
	{
		 Local_u8ErrorState=USART_BUSY;
	}
	
	return Local_u8ErrorState;
	
}


u8   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) 
{
	u8 Local_u8ErrorState= USART_OK;
	u32 Local_32Index=0;
	
	if( Copy_pchString != NULL)
	{
	    while(Local_32Index < Copy_uint32BufferSize)
	    {
			Local_u8ErrorState=USART_u8RecevieData(&Copy_pchString[Local_32Index]);
			Local_32Index++;
		   
		    if(Local_u8ErrorState != USART_OK)
	          {
		         return Local_u8ErrorState;
	          }
	    }  
	}
	else
	{
		 Local_u8ErrorState= USART_NULL_POINTER	 ;
	}
	
	return Local_u8ErrorState;
	
}
u8   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) 
{
	
	u8 Local_u8ErrorState= USART_OK;
	
	if( USART_u8STATE == USART_IDEL)
	{
	  if(Copy_pchstring != NULL && (NotificationFunc !=NULL))
	   {
		   USART_u8STATE = USART_BUSY;
		   
		   /*set global data*/
		   USART_pu8ReceiveData=Copy_pchstring;
		   USART_pvNotificationFunc=NotificationFunc;
		   USART_u8BufferSize=Copy_uint32BufferSize;
		   
		  /* Set Index to first element */
           USART_u8Index=0 ;
		  
		  /* USART Transmit Interrupt Enable */
		   SET_BIT( UCSRB,UCSRB_RXCIE);
	   }
	  else
	  {
		Local_u8ErrorState= USART_NULL_POINTER;
	  }
	
	}
	
	else
	{
		 Local_u8ErrorState=USART_BUSY;
	}
	
	return Local_u8ErrorState;
}


/* ISR for RX complete */
void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void)
{
	/*Receive next Data*/
	USART_pu8ReceiveData[USART_u8Index] = UDR ;

	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	if (USART_u8Index == USART_u8BufferSize)
	{
		/*Send Data Complete*/

		USART_u8Index=0;
		/*USART is now IDLE*/
		USART_u8State = IDLE ;

		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Recieve Interrupt Disable*/
		CLR_BIT(UCSRB , UCSRB_RXCIE) ;
	}
	else
	{
		/*Do Noting*/
	}
}

/* ISR for TX complete */
void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{

	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	if (USART_pu8TransmitData[USART_u8Index] == '\0')
	{
		/*Receive Data Complete*/
		USART_u8Index=0;

		/*USART is now IDLE*/
		USART_u8State = IDLE ;

		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Transmit Interrupt Disable*/
		CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	}
	else
	{
		/*Send Data not Complete*/
		/*Send next Data*/
		UDR = USART_pu8SendData[USART_u8Index] ;
	}
}