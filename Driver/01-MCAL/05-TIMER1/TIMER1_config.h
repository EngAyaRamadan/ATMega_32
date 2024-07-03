 /*
 * #################################### TIMER1_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 30 April 2024
 *   Layer  :MCAL
 *   SWC    :TIMER
 *   Version: 1
*/


#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_

/*
  SET MODE
    1-TIMER1_NORMAL_MODE                
    2-TIMER1_PHASE_PWM_8_BIT_MODE       
    3-TIMER1_PHASE_PWM_9_BIT_MODE       
    4-TIMER1_PHASE_PWM_10_BIT_MODE      
    5-TIMER1_CTC_OCR1A_MODE             
    6-TIMER1_FAST_PWM_8_BIT_MODE        
    7-TIMER1_FAST_PWM_9_BIT_MODE        
    8-TIMER1_FAST_PWM_10_BIT_MODE       
    9-TIMER1_PHASE_FREQ_PWM_ICR1_MODE   
    10-TIMER1_PHASE_FREQ_PWM_OCR1A_MODE  
    11-TIMER1_PHASE_PWM_ICR1_MODE        
    12-TIMER1_PHASE_PWM_OCR1A_MODE       
    13-TIMER1_CTC_ICR1_MODE              
    14-TIMER1_FAST_PWM_ICR1_MODE         
    15-TIMER1_FAST_PWM_OCR1A_MODE        
   
*/

#define TIMER1_MODE  TIMER1_NORMAL_MODE
       /* NORMAL mode */
 #define TIMER1_PRELOAD_VALE  0
 
 #define TIMER1_CTCA_VALUE  200
 #define TIMER1_CTCB_VALUE 150
  /* ICR1 */
 #define TIMER1_ICR1_VALE  100
/*    
   SET ICR1 EDGE
       1-FALLING_EDGE     
       2-RISING_EDGE      
*/
#define TIMER1_ICR_EDGE FALLING_EDGE


/*
   SET COMPARE MATCH OUTPUT MODE FOR CTC
           1-TIMER1_DISCONNECTED_OC  
           2-TIMER1_TOGGLE_OC        
           3-TIMER1_CLEAR_OC         
           4-TIMER1_SET_OC       


   SET COMPARE MATCH OUTPUT MODE FOR FAST
           1-TIMER1_DISCONNECTED_OC01 
           2-TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED         
           3-TIMER1_CLR_ON_CTC_SET_TOP_OC         
           4-TIMER1_SET_CTC_CLR_TOP_OC 	

  SET COMPARE MATCH OUTPUT MODE FOR PHASE AND PHASE & FREQUANCY
           1-TIMER1_DISCONNECTED_OC 
           2-TIMER1_TOGGLE_OC1A_ON_CTC_OC1B_DISCONNECTED         
           3-TIMER1_CLR_ON_CTC_UP_SET_ON_CTC_DWONE_OC         
           4-TIMER1_SET_ON_CTC_UP_CLR_ON_CTC_DWONE_OC 

*/
#define TIMER1_CTC_OCR1A_MODE  TIMER1_TOGGLE_OC
#define TIMER1_CTC_OCR1B_MODE  TIMER1_SET_OC 


/*
 SET TIMER1 PRESCALLER  
    1-TIMER1_NO_CLOCK      
    2-TIMER1_NO_PRE        
    3-TIMER1_8_PRE         
    4-TIMER1_64_PRE        
    5-TIMER1_256_PRE       
    6-TIMER1_1024_PRE      
    7-TIMER1_EXT_FALLING   
    8-TIMER1_EXT_RISING    

*/

#define TIMER1_PRESCALLER   TIMER1_NO_PRE

/*
 SET TIMER1 ICR NOISE CANCELER
  1-DISABLE
  2-Enable
*/

#define TIMER1_ICR_NOISE_CANCELER  DISABLE


/*
 SET TIMER1 OVERFLOW INTERRUPT 
  1-TIMER1_INT_DISABLE_OVERFLOW
  2-TIMER1_INT_ENABLE_OVERFLOW
*/
#define TIMER1_OVERFLOW_INTERRUPT  TIMER1_INT_DISABLE_OVERFLOW

/*
 SET TIMER1 COMP_MATCH_A INTERRUPT 
    1-TIMER1_INT_DISABLE_COMP_MATCH_A
    2-TIMER1_INT_ENABLE_COMP_MATCH_A
*/
#define TIMER1_COMP_MATCH_A_INTERRUPT  TIMER1_INT_DISABLE_COMP_MATCH_A

/*
 SET TIMER1 COMP_MATCH_B INTERRUPT 
    1-TIMER1_INT_DISABLE_COMP_MATCH_B
    2-TIMER1_INT_ENABLE_COMP_MATCH_B
*/
#define TIMER1_COMP_MATCH_B_INTERRUPT  TIMER1_INT_DISABLE_COMP_MATCH_B

/*
 SET TIMER1 INPUT_CAPTURE INTERRUP 
    1-TIMER1_INT_DISABLE_INPUT_CAPTURE
    2-TIMER1_INT_ENABLE_INPUT_CAPTURE
*/
#define TIMER1_INPUT_CAPTURE_INTERRUPT  TIMER1_INT_DISABLE_INPUT_CAPTURE





#endif