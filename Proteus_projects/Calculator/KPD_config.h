/*
 * #################################### KPD_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 12 march 2024
 *   Layer  :HALL
 *   SWC    :KEYPAD
 *   Version: 1
*/
/* 4*4 keypad */
#ifndef _KPD_CONFIG_H_
#define _KPD_CONFIG_H_

#define KPD_ROW_INIT DIO_PIN4
#define KPD_ROW_END  DIO_PIN7

#define KPD_COL_INIT DIO_PIN0
#define KPD_COL_END  DIO_PIN3


u8 KPD_u8Buttons[4][4]={{ '7', '8', '9', '/'},
						{ '4', '5', '6', '*'},
						{ '1', '2', '3', '-'},
						{ '?', '0', '=', '+'} };
                       
	
/*
  options
   DIO_PORTA
   DIO_PORTB
   DIO_PORTC
   DIO_PORTD
*/
	               
#define KPD_PORT  DIO_PORTA
/*
  options
   DIO_PIN0
   DIO_PIN1
   DIO_PIN2
   DIO_PIN3
   DIO_PIN4
   DIO_PIN5
   DIO_PIN6
   DIO_PIN7
   
*/
#define KPD_R0 DIO_PIN4
#define KPD_R1 DIO_PIN5
#define KPD_R2 DIO_PIN6
#define KPD_R3 DIO_PIN7


#define KPD_C0 DIO_PIN0
#define KPD_C1 DIO_PIN1
#define KPD_C2 DIO_PIN2
#define KPD_C3 DIO_PIN3


#endif
