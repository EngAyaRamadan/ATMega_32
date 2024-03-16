 /*
 * #################################### DIO_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 30 Novamber 2023
 *   Layer  :MCAL
 *   SWC    :DIO/GPIO
 *   Version: 1
*/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

 /*PORTA*/
#define PINA_REG  *(( volatile u8 *)0x39)
#define DDRA_REG  *(( volatile u8 *)0x3A)
#define PORTA_REG *(( volatile u8 *)0x3B)
 /*PORTB*/
#define PINB_REG  *(( volatile u8 *)0x36)
#define DDRB_REG  *(( volatile u8 *)0x37)
#define PORTB_REG *(( volatile u8 *)0x38)
 /*PORTC*/
#define PINC_REG  *(( volatile u8 *)0x33)
#define DDRC_REG  *(( volatile u8 *)0x34)
#define PORTC_REG *(( volatile u8 *)0x35)
 /*PORTD*/
#define PIND_REG  *(( volatile u8 *)0x30)
#define DDRD_REG  *(( volatile u8 *)0x31)
#define PORTD_REG *(( volatile u8 *)0x32)


#endif