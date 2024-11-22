/*
 * #################################### CLCD_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 21 march 2024
 *   Layer  :HALL
 *   SWC    :CLCD
 *   Version: 1
*/

#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_
/*
SET LCD MODE
   1-4
   2-8
*/
#define CLCD_MODE 8

#if CLCD_MODE== 4
#define LCD_DATA_PIN  LCD_HIGH_NIBBLE
#endif
/* choose port that want to connect the data pins 8-pins "one port"*/
#define CLCD_DATA_PORT  DIO_PORTA
/* choose port that want to connect the control pins 3-pins "RS,RW,EN"*/
#define CLCD_CONTROLER_PORT  DIO_PORTB
/* control pins */
#define CLCD_RS  DIO_PIN7
#define CLCD_RW  DIO_PIN6
#define CLCD_EN  DIO_PIN5

#endif
