 /*
 * #################################### EXTI_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 march 2024
 *   Layer  :HALL
 *   SWC    :EXTI
 *   Version: 1
*/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

/* number in macro for the same bin in GICR register */

#define EXTI_LINE0 6 
#define EXTI_LINE1 7
#define EXTI_LINE2 5

#define EXTI_LOW_LEVEL     0
#define EXTI_ON_CHANGE     1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

void EXTI_voidIntit(void);
void EXTI_voidSetSignalLatch(u8 copy_u8SenseMode,u8 copy_u8line);
/* flag */
u8 EXTI_voidGetFlag (u8 copy_u8line);
void EXTI_voidClearFlag (u8 copy_u8line);

/* bin interrupt function */
void EXTI_voidEnableInterrupt (u8 copy_u8line);
void EXTI_voidDisableInterrupt(u8 copy_u8line);

 /* global interrupt function */
void EXTI_voidEnableGlobalInterrupt (void);
void EXTI_voidDisableGlobalInterrupt(void);

void EXTI_voidSetCallBack(void (*copy_ptrvoidcallback)(void),u8 copy_u8line);
#endif