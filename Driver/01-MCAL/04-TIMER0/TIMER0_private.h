 /*
 * #################################### TIMER0_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 23 April 2024
 *   Layer  :MCAL
 *   SWC    :TIMER
 *   Version: 1
*/


#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_


/* timer0 */
#define TCCR0  *((volatile u8 *)(0x53))
#define TCNT0  *((volatile u8 *)(0x52))
#define OCR0   *((volatile u8 *)(0x5C))
#ifndef TIMSK
   #define TIMSK  *((volatile u8 *)(0x59))
#endif
#ifndef TIFR
   #define TIFR   *((volatile u8 *)(0x58))
#endif
/*-----------*/

#ifndef NULL 
   #define NULL 0
#endif


/* INT VECTOR ID */
#define TIMER0_COMP_MATCH_ID  0
#define TIMER0_OVERFLOW_ID    1


/* TIMER0 FLAGS */
#define TIMER0_OVERFLOW_FLAG   0
#define TIMER0_COMP_MATCH_FLAG 1

#endif