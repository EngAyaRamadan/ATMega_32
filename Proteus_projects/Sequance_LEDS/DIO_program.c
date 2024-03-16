 /*
 * #################################### DIO_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 30 Novamber 2023
 *   Layer  :MCAL
 *   SWC    :DIO/GPIO
 *   Version: 1
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"


   /* function to set the port input or output */
DIO_ErrorStatus DIO_enumSetPortDirection(u8 copy_u8PORT,u8 copy_u8Direction)
{
	DIO_ErrorStatus Loc_enumState =DIO_OK;

		switch(copy_u8PORT)
		{
			case DIO_PORTA: DDRA_REG =copy_u8Direction;break;
			case DIO_PORTB: DDRB_REG =copy_u8Direction;break;
			case DIO_PORTC: DDRC_REG =copy_u8Direction;break;
			case DIO_PORTD: DDRD_REG =copy_u8Direction;break;
			default: Loc_enumState =DIO_NOK;
		}

		
 return Loc_enumState;
}

   /* function to set the value(high or low) in port */ 
DIO_ErrorStatus DIO_enumSetPortValue(u8 copy_u8PORT,u8 copy_u8Value)
{
   DIO_ErrorStatus Loc_enumState=DIO_OK;

	 switch(copy_u8PORT)
	 {
		 case DIO_PORTA:PORTA_REG=copy_u8Value;break;
		 case DIO_PORTB:PORTB_REG=copy_u8Value;break;
		 case DIO_PORTC:PORTC_REG=copy_u8Value;break;
		 case DIO_PORTD:PORTD_REG=copy_u8Value;break;
		 default: Loc_enumState=DIO_NOK;
	 } 

 return Loc_enumState;
}

  /* function to get the value(high or low) from port */ 
DIO_ErrorStatus DIO_enumGetPortValue(u8 copy_u8PORT,u8 *copy_PtrData)
{
	DIO_ErrorStatus Loc_enumState=DIO_OK;
	 switch(copy_u8PORT)
	 {
		 case DIO_PORTA:*copy_PtrData=PINA_REG;break;
		 case DIO_PORTB:*copy_PtrData=PINB_REG;break;
		 case DIO_PORTC:*copy_PtrData=PINC_REG;break;
		 case DIO_PORTD:*copy_PtrData=PIND_REG;break;
		 default: Loc_enumState=DIO_NOK;
	 } 
	
 return Loc_enumState;
}

 /* function to toggle the value(high or low) in port */  
DIO_ErrorStatus DIO_enumTogglePortValue(u8 copy_u8PORT)
{
	DIO_ErrorStatus Loc_enumState=DIO_OK;
	 switch(copy_u8PORT)
	 {
		 case DIO_PORTA:PORTA_REG^=0xff;break;
		 case DIO_PORTB:PORTB_REG^=0xff;break;
		 case DIO_PORTC:PORTC_REG^=0xff;break;
		 case DIO_PORTD:PORTD_REG^=0xff;break;
		 default: Loc_enumState=DIO_NOK;
	 } 
	 
 return Loc_enumState;
}
          /* function to set the pin direction output or input */
DIO_ErrorStatus DIO_enumSetPinDirection(u8 copy_u8PORT,u8 copy_u8Pin,u8 copy_u8Direction)
{
	DIO_ErrorStatus Loc_enumState =DIO_OK;
	if( (copy_u8Direction == DIO_PIN_OUTPUT)  && (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7 ) )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: SET_BIT(DDRA_REG,copy_u8Pin);break;
			case DIO_PORTB: SET_BIT(DDRB_REG,copy_u8Pin);break;
			case DIO_PORTC: SET_BIT(DDRC_REG,copy_u8Pin);break;
			case DIO_PORTD: SET_BIT(DDRD_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	else if( (copy_u8Direction == DIO_PIN_INPUT)  && (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7 ) )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: CLR_BIT(DDRA_REG,copy_u8Pin);break;
			case DIO_PORTB: CLR_BIT(DDRB_REG,copy_u8Pin);break;
			case DIO_PORTC: CLR_BIT(DDRC_REG,copy_u8Pin);break;
			case DIO_PORTD: CLR_BIT(DDRD_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	else 
		Loc_enumState =DIO_NOK;
		
 return Loc_enumState;
}

/* function to set the value(high or low) in pin */
DIO_ErrorStatus DIO_enumSetPinValue(u8 copy_u8PORT,u8 copy_u8Pin,u8 copy_u8Value)
{
	DIO_ErrorStatus Loc_enumState=DIO_OK;
   if( (copy_u8Value == DIO_PIN_HIGH)  && (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7 ) )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: SET_BIT(PORTA_REG,copy_u8Pin);break;
			case DIO_PORTB: SET_BIT(PORTB_REG,copy_u8Pin);break;
			case DIO_PORTC: SET_BIT(PORTC_REG,copy_u8Pin);break;
			case DIO_PORTD: SET_BIT(PORTD_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	else if( (copy_u8Value == DIO_PIN_LOW)  && (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7 ) )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: CLR_BIT(PORTA_REG,copy_u8Pin);break;
			case DIO_PORTB: CLR_BIT(PORTB_REG,copy_u8Pin);break;
			case DIO_PORTC: CLR_BIT(PORTC_REG,copy_u8Pin);break;
			case DIO_PORTD: CLR_BIT(PORTD_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	else 
		Loc_enumState =DIO_NOK;
	
 return Loc_enumState;
}
/* function to get the value(high or low) from pin */ 
DIO_ErrorStatus DIO_enumGetPinValue(u8 copy_u8PORT,u8 copy_u8Pin,u8 *copy_PtrData)
{
	DIO_ErrorStatus Loc_enumState=DIO_OK;
   if( copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7  )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: *copy_PtrData=GET_BIT(PINA_REG,copy_u8Pin);break;
			case DIO_PORTB: *copy_PtrData=GET_BIT(PINB_REG,copy_u8Pin);break;
			case DIO_PORTC: *copy_PtrData=GET_BIT(PINC_REG,copy_u8Pin);break;
			case DIO_PORTD: *copy_PtrData=GET_BIT(PIND_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	
	else 
		Loc_enumState =DIO_NOK;
	
 return Loc_enumState;
}
/* function to toggle the value(high or low) in pin */
DIO_ErrorStatus DIO_enumTogglePinValue(u8 copy_u8PORT,u8 copy_u8Pin)
{
	DIO_ErrorStatus Loc_enumState=DIO_OK;
   if( copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7  )
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA: TOG_BIT(PORTA_REG,copy_u8Pin);break;
			case DIO_PORTB: TOG_BIT(PORTB_REG,copy_u8Pin);break;
			case DIO_PORTC: TOG_BIT(PORTC_REG,copy_u8Pin);break;
			case DIO_PORTD: TOG_BIT(PORTD_REG,copy_u8Pin);break;
			default: Loc_enumState =DIO_NOK;
			
		}
		
	}
	else 
		Loc_enumState =DIO_NOK;
	
 return Loc_enumState;
}
