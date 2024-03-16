/*
 * #################################### LED_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 30 Novamber 2023
 *   Layer  :HALL
 *   SWC    :LED
 *   Version: 1
*/

#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

typedef struct
{
	u8 port;
	u8 pin;
	u8 Active_State;
	
}LED_TYPE;

void LED_VoidInit(LED_TYPE LED_configration);
void LED_VoidOn(LED_TYPE LED_configration);
void LED_VoidOff(LED_TYPE LED_configration);
void LED_voidToggle(LED_TYPE LED_configration);



#endif
