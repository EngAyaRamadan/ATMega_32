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
LCD modes
there is two modes 
>>>>4-bit
>>>>8-bit
*/
#define CLCD_MODE 8

/* choose port that want to connect the data pins 8-pins "one port"*/
#define CLCD_DATA_PORT  DIO_PORTC
/* choose port that want to connect the control pins 3-pins "RS,RW,EN"*/
#define CLCD_CONTROLER_PORT  DIO_PORTD
/* control pins */
#define CLCD_RS  DIO_PIN0
#define CLCD_RW  DIO_PIN1
#define CLCD_EN  DIO_PIN2

#endif
