 /*
 * #################################### EXTI_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 march 2024
 *   Layer  :HALL
 *   SWC    :EXTI
 *   Version: 1
*/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

/* interrupt register */
#define MCUCR   *((volatile u8* )(0x55))
#define MCUCSR  *((volatile u8* )(0x54))
#define GIFR    *((volatile u8* )(0x5A))
#define GICR    *((volatile u8* )(0x5B))

/* status register >>global interrupt enable>>bit 7 */
#define SREG    *((volatile u8* )(0x5B))
#define NULL 0



#endif