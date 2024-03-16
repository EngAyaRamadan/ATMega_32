/*
 * ####################################Button_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 28 Junuary 2024
 *   Layer  :HALL
 *   SWC    :Bush_Button
 *   Version: 1
*/




#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#define SW_FLOATING 0
#define SW_PULL_UP 1

#define SW_PRESSED 1
#define SW_NOT_PRESSED 0

typedef struct
{
u8 Port ;
u8 Pin ;
u8 Pull_State;
}SW_Type;


void SW_VoidInit ( SW_Type SW_Configuration);
u8 SW_u8GetPressed( SW_Type SW_Configuration);



#endif
