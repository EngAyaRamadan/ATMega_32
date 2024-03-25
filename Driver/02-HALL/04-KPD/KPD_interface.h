/*
 * #################################### KPD_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 12 march 2024
 *   Layer  :HALL
 *   SWC    :KEYPAD
 *   Version: 1
*/

#ifndef _KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_

#define NOT_PRESSED 0XFF
void KPD_voidInit(void);
u8 KPD_u8GetPressed(void);

#endif
