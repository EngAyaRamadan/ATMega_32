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



/* TIMER0 */

/* MODES */
#define TIMER1_NORMAL_MODE                0

#define TIMER1_PHASE_PWM_8_BIT_MODE       1
#define TIMER1_PHASE_PWM_9_BIT_MODE       2
#define TIMER1_PHASE_PWM_10_BIT_MODE      3

#define TIMER1_CTC_OCR1A_MODE             4

#define TIMER1_FAST_PWM_8_BIT_MODE        5
#define TIMER1_FAST_PWM_9_BIT_MODE        6
#define TIMER1_FAST_PWM_10_BIT_MODE       7

#define TIMER1_PHASE_FREQ_PWM_ICR1_MODE   8
#define TIMER1_PHASE_FREQ_PWM_OCR1A_MODE  9

#define TIMER1_PHASE_PWM_ICR1_MODE        10
#define TIMER1_PHASE_PWM_OCR1A_MODE       11

#define TIMER1_CTC_ICR1_MODE              12

#define TIMER1_FAST_PWM_ICR1_MODE         14
#define TIMER1_FAST_PWM_OCR1A_MODE        15

/* COMPARE MATCH OUTPUT MODE NON PWM MODE */
#define TIMER1_DISCONNECTED_OC  0
#define TIMER1_TOGGLE_OC        1
#define TIMER1_CLEAR_OC         2
#define TIMER1_SET_OC           3

/* COMPARE MATCH OUTPUT MODE FAST PWM MODE */
#define TIMER1_DISCONNECTED_OC01                      0
#define TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED   1
#define TIMER1_CLR_ON_CTC_SET_TOP_OC                  2
#define TIMER1_SET_CTC_CLR_TOP_OC                     3

/* COMPARE MATCH OUTPUT MODE PHASE CORRECT PWM MODE */
#define TIMER1_DISCONNECTED_OC                        0
#define TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED   1
#define TIMER1_CLR_ON_CTC_UP_SET_ON_CTC_DWONE_OC      2
#define TIMER1_SET_ON_CTC_UP_CLR_ON_CTC_DWONE_OC      3

/* TIMER1 PRESCALLER  */

#define TIMER1_NO_CLOCK      0
#define TIMER1_NO_PRE        1
#define TIMER1_8_PRE         2
#define TIMER1_64_PRE        3
#define TIMER0_256_PRE       4
#define TIMER0_1024_PRE      5
#define TIMER0_EXT_FALLING   6
#define TIMER0_EXT_RISING    7

/* TIMER1 ICR EDGE */
#define FALLING_EDGE     0
#define RISING_EDGE      1


#define DISABLE   0
#define Enable    1

/* INTERRUPT */
#define TIMER1_INT_DISABLE_OVERFLOW 0
#define TIMER1_INT_ENABLE_OVERFLOW  1

#define TIMER1_INT_DISABLE_COMP_MATCH_A 2
#define TIMER1_INT_ENABLE_COMP_MATCH_A  3

#define TIMER1_INT_DISABLE_COMP_MATCH_B  4
#define TIMER1_INT_ENABLE_COMP_MATCH_B   5
 
#define TIMER1_INT_DISABLE_INPUT_CAPTURE 6
#define TIMER1_INT_ENABLE_INPUT_CAPTURE  7


/* TIMER1 FLAGS */
#define TIMER1_OVERFLOW_FLAG       2
#define TIMER1_COMP_MATCH_A_FLAG   4
#define TIMER1_COMP_MATCH_B_FLAG   3   
#define TIMER1_INPUT_CAPTURE_FLAG  5
 
/* INT VECTOR ID */
#define TIMER1_INPUT_CAPTURE_ID 0
#define TIMER1_COMP_MATCH_A_ID  1
#define TIMER1_COMP_MATCH_B_ID  2
#define TIMER1_OVERFLOW_ID      3

#define PWM_CHANNEL_A  0
#define PWM_CHANNEL_B  1


void TIMER1_voidInti(void);

void TIMER1_voidSetPreload(u16 Copy_u16Preload);
void TIMER1_voidSetOCRA(u16 Copy_u16OCR);
void TIMER1_voidSetOCRB(u16 Copy_u16OCR);
void TIMER1_u8SetICR1(u16 Copy_u16ISR);
u16 TIMER1_u8GetICR1(void);

void TIMER1_voidChangeEdge(u8 Copy_u8Edge);

void TIMER0_voidClearFlag(u8 Copy_u8InterruptFlag);
u8 TIMER0_voidGetFlag(u8 Copy_u8InterruptFlag);

void TIMER1_voidDisableInterrupt(u8 Copy_u8Interrupt);
void TIMER1_voidEnableInterrupt(u8 Copy_u8Interrupt);

void TIMER1_voidPWM(u16 Copy_u16OCRVALUE, u8 u8 Copy_u8PWMChannal);
void TIMER1_voidSetCallBack(void(*Copy_ptrVoidCallBack)(void),u8 Copy_u8Interrupt_ID);


#endif