 /*
 * #################################### TIMER0_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 23 April 2024
 *   Layer  :MCAL
 *   SWC    :TIMER
 *   Version: 1
*/


#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_



/* TIMER0 */

/* MODES */
#define TIMER0_NORMAL_MODE     0
#define TIMER0_PHASE_PWM_MODE  1
#define TIMER0_CTC_MODE        2
#define TIMER0_FAST_PWM_MODE   3

#define NON_CTC_VALUE  255

/* COMPARE MATCH OUTPUT MODE NON PWM MODE */
#define TIMER0_DISCONNECTED_OC0  0
#define TIMER0_TOGGLE_OC0        1
#define TIMER0_CLEAR_OC0         2
#define TIMER0_SET_OC0           3

/* COMPARE MATCH OUTPUT MODE FAST PWM MODE */
#define TIMER0_DISCONNECTED_OC0         0
#define TIMER0_CLR_ON_CTC_SET_TOP_OC0   2
#define TIMER0_SET_ON_CTC_CLR_TOP_OC0   3

/* COMPARE MATCH OUTPUT MODE PHASE CORRECT PWM MODE */
#define TIMER0_DISCONNECTED_OC0              0
#define TIMER0_CLR_ON_CTC_UP_SET_DWONE_OC0   2
#define TIMER0_SET_ON_CTC_UP_CLR_DWONE_OC0   3

/* TIMER0 PRESCALLER  */

#define TIMER0_NO_CLOCK      0
#define TIMER0_NO_PRE        1
#define TIMER0_8_PRE         2
#define TIMER0_64_PRE        3
#define TIMER0_256_PRE       4
#define TIMER0_1024_PRE      5
#define TIMER0_EXT_FALLING   6
#define TIMER0_EXT_RISING    7


/* TIMER0 OVERFLOW INTERRUPT */
#define TIMER0_INT_DISABLE_OVERFLOW   1
#define TIMER0_INT_ENABLE_OVERFLOW    2

/* TIMER0 COMP_MATCH INTERRUPT */
#define TIMER0_INT_DISABLE_COMP_MATCH   3
#define TIMER0_INT_ENABLE_COMP_MATCH    4


    

void TIMER0_voidInti(void);
void TIMER0_voidSetCounter(u8 Copy_u8Counter);
u8 TIMER0_u8GetCounter(void);
void TIMER0_voidSetOCR(u8 Copy_u8OCR);
void TIMER0_voidClearFlag(u8 Copy_u8InterruptFlag);
u8 TIMER0_voidGetFlag(u8 Copy_u8InterruptFlag);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Interrupt);
void TIMER0_voidEnableInterrupt(u8 Copy_u8Interrupt);
void TIMER0_voidPWM(u8 Copy_u8TimeOn);
void TIMER0_voidMSecDelay(u64 Copy_u64Milliseconeds);
void TIMER0_voidUSecDelay(u64 Copy_u64Microseconeds);
void TIMER0_voidSetCallBack(void(*Copy_ptrVoidCallBack)(void),u8 Copy_u8Interrupt);


#endif