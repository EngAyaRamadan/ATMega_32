 /*
 * #################################### DIO_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 30 Novamber 2023
 *   Layer  :MCAL
 *   SWC    :DIO/GPIO
 *   Version: 1
*/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

  /*DIO_PORTS*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
  /*DIO_PINS*/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
 /*DIRECTION*/
 #define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1
 /*Values*/
#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

typedef enum{
	     DIO_NOK,
         DIO_OK		 
}DIO_ErrorStatus;

            /*PORT*/
DIO_ErrorStatus DIO_enumSetPortDirection(u8 copy_u8PORT,u8 copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue    (u8 copy_u8PORT,u8 copy_u8Value);
DIO_ErrorStatus DIO_enumGetPortValue    (u8 copy_u8PORT,u8 *copy_PtrData); 
DIO_ErrorStatus DIO_enumTogglePortValue (u8 copy_u8PORT);
            /* PIN */
DIO_ErrorStatus DIO_enumSetPinDirection (u8 copy_u8PORT,u8 copy_u8Pin,u8 copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue     (u8 copy_u8PORT,u8 copy_u8Pin,u8 copy_u8Value);
DIO_ErrorStatus DIO_enumGetPinValue     (u8 copy_u8PORT,u8 copy_u8Pin,u8 *copy_PtrData); 
DIO_ErrorStatus DIO_enumTogglePinValue  (u8 copy_u8PORT,u8 copy_u8Pin);


#endif