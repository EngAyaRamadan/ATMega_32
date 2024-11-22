/*
 * #################################### CLCD_program.c #############################
 *   Author : Aya Ramadan
 *   date   : 21 march 2024
 *   Layer  :HALL
 *   SWC    :CLCD
 *   Version: 1
*/
#include<util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_extrachar.h"



void CLCD_voidInti(void)
{

	#if CLCD_MODE==8
	 _delay_ms(50);
	 DIO_enumSetPortDirection(CLCD_DATA_PORT,0xff);
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_EN,DIO_PIN_OUTPUT);

	 CLCD_voidSendCommand(LCD_HOME);
	 _delay_ms(1);

	 CLCD_voidSendCommand(EIGHT_BITS);
	 _delay_ms(1);

	  CLCD_voidSendCommand(LCD_DISPLAY_ON_CURSORON);
	 _delay_ms(1);

	 CLCD_voidClearScreen();

	  CLCD_voidSendCommand(LCD_ENTRY_MODE);
	 _delay_ms(1);


	#elif CLCD_MODE==4
	 _delay_ms(50);
	 #if LCD_DATA_PIN== LCD_LOW_NIBBLE
	  DIO_enumSetLowNibbleDirection(CLCD_DATA_PORT,0x0f);
	 #elif LCD_DATA_PIN== LCD_HIGH_NIBBLE
	  DIO_enumSetHighNibbleDirection(CLCD_DATA_PORT,0xf0);
	 #endif
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_OUTPUT);
	 DIO_enumSetPinDirection (CLCD_CONTROLER_PORT,CLCD_EN,DIO_PIN_OUTPUT);

	 CLCD_voidSendCommand(LCD_HOME);
	 _delay_ms(30);

	 CLCD_voidSendCommand(FOUR_BITS);
	 _delay_ms(1);

	  CLCD_voidSendCommand(LCD_DISPLAY_ON_CURSOROFF);
	 _delay_ms(1);

	 CLCD_voidClearScreen();

	  CLCD_voidSendCommand(LCD_ENTRY_MODE);
	 _delay_ms(1);


	#endif

}

void CLCD_voidSendData(u8 copy_u8Data)
{
	#if CLCD_MODE==8
	DIO_enumSetPortValue (CLCD_DATA_PORT,copy_u8Data);
	DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_HIGH);
	DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();

	#elif CLCD_MODE==4
	 DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_HIGH);
	 DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_LOW);
	 #if LCD_DATA_PIN== LCD_LOW_NIBBLE
	  DIO_enumSetLowNibbleValue  (CLCD_DATA_PORT, copy_u8Data);
	  CLCD_voidSendFallingEdge();
	  DIO_enumSetLowNibbleValue  (CLCD_DATA_PORT, copy_u8Data>>4);
	  CLCD_voidSendFallingEdge();
	 #elif LCD_DATA_PIN== LCD_HIGH_NIBBLE
	  DIO_enumSetHighNibbleValue (CLCD_DATA_PORT, copy_u8Data);
	  CLCD_voidSendFallingEdge();
	  DIO_enumSetHighNibbleValue (CLCD_DATA_PORT, copy_u8Data<<4);
	  CLCD_voidSendFallingEdge();
	  #endif

	#endif
	_delay_ms(1);


}
void CLCD_voidSendCommand(u8 copy_u8Command)
{

	#if CLCD_MODE==8
	DIO_enumSetPortValue (CLCD_DATA_PORT, copy_u8Command);
	DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_LOW);
	DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();
	#elif CLCD_MODE==4
	  DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RS,DIO_PIN_LOW);
	  DIO_enumSetPinValue  (CLCD_CONTROLER_PORT,CLCD_RW,DIO_PIN_LOW);
	 #if LCD_DATA_PIN== LCD_LOW_NIBBLE
	  DIO_enumSetLowNibbleValue  (CLCD_DATA_PORT, copy_u8Command);
	  CLCD_voidSendFallingEdge();
	  DIO_enumSetLowNibbleValue  (CLCD_DATA_PORT, copy_u8Command>>4);
	  CLCD_voidSendFallingEdge();
	 #elif LCD_DATA_PIN== LCD_HIGH_NIBBLE
	  DIO_enumSetHighNibbleValue (CLCD_DATA_PORT, copy_u8Command);
	  CLCD_voidSendFallingEdge();
	  DIO_enumSetHighNibbleValue (CLCD_DATA_PORT, copy_u8Command<<4);
	  CLCD_voidSendFallingEdge();
	 #endif
	#endif
	_delay_ms(1);


}
void CLCD_voidSendString(const u8 *copy_u8PtrString)
{
	u8 LOC_u8Iterator=0;
	while(copy_u8PtrString[LOC_u8Iterator]!='\0')
	{
		CLCD_voidSendData(copy_u8PtrString[LOC_u8Iterator]);
		++LOC_u8Iterator;
	}
}
void CLCD_voidSetPosition(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 LOC_Data;

	if( copy_u8Row>2 || copy_u8Row<1 || copy_u8Col<1 || copy_u8Col>16)
	{
		LOC_Data=LCD_SetCurser;
	}
	else if(copy_u8Row==CLCD_ROW_1)
	{
		LOC_Data=(LCD_SetCurser+(copy_u8Col-1));
	}
	else if(copy_u8Row==CLCD_ROW_2)
	{
		LOC_Data=((LCD_SetCurser+64)+(copy_u8Col-1));
	}
	CLCD_voidSendCommand(LOC_Data);
	_delay_ms(1);


}
void CLCD_voidSendNumber(u64 copy_u64Number)
{
	u64 Loc_ReversNumber=1;
	if(copy_u64Number==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(copy_u64Number>0)
		{
			Loc_ReversNumber=Loc_ReversNumber*10+(copy_u64Number%10);
			copy_u64Number/=10;
		}
		while(Loc_ReversNumber>1)
		{
			CLCD_voidSendData((Loc_ReversNumber%10) + 48);
			Loc_ReversNumber/=10;
		}
	}

}
void CLCD_voidSendFloatNumber           ( f32 Copy_f32Number    )
{
	CLCD_voidSendNumber((u64)Copy_f32Number);
	if((((u64)(Copy_f32Number*100))%100)!=0)
	{
		CLCD_voidSendData('.');
		CLCD_voidSendNumber((((u64)(Copy_f32Number*100))%100));
	}

}
void CLCD_voidSendExtraChar(u8 copy_u8Row,u8 copy_u8Col )
{
	u8 LOC_u8Iterator=0;
	CLCD_voidSendCommand(LCD_CGRAM);
	for(LOC_u8Iterator=0;LOC_u8Iterator<sizeof(CLCD_u8Extrachar)/sizeof(CLCD_u8Extrachar[0]);++LOC_u8Iterator)
	{
		CLCD_voidSendData(CLCD_u8Extrachar[LOC_u8Iterator]);
	}
	CLCD_voidSetPosition(copy_u8Row,copy_u8Col);
	for(LOC_u8Iterator=0;LOC_u8Iterator<8;++LOC_u8Iterator)
	{
		CLCD_voidSendData(LOC_u8Iterator);
	}

}
void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(10);
}
/* use only in this file */
static void CLCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue(CLCD_CONTROLER_PORT,CLCD_EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_CONTROLER_PORT,CLCD_EN,DIO_PIN_LOW);
	_delay_ms(1);
}

