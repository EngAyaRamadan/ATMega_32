 /*
 * #################################### TIMER1_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 30 April 2024
 *   Layer  :MCAL
 *   SWC    :TIMER
 *   Version: 1
*/


#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

#define TIMER1_INPUT_CAPTURE_FLAG  5

/* TIMER1 ICR EDGE */
#define  FALLING_EDGE 0
#define  RISING_EDGE  1

void TIMER1_voidResetInti(void);
void TIMER1_voidClearFlag(u8 Copy_u8InterruptFlag);
u8 TIMER1_voidGetFlag(u8 Copy_u8InterruptFlag);
void TIMER1_voidSetICREdge(u8 Copy_u8ICREdge);
void TIMER1_voidSetStopTimer(void );

#endif
