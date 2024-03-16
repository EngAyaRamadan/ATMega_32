 /*
 * #################################### EXTI_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 march 2024
 *   Layer  :HALL
 *   SWC    :EXTI
 *   Version: 1
*/
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_
/*
 interrupt lines
options
  1-EXTI_LINE0
  2-EXTI_LINE1
  3-EXTI_LINE2
*/

#define EXTI_LINE  EXTI_LINE0

/*
sense mode
options
  1-EXTI_FALLING_EDGE
  2-EXTI_RISING_EDGE
  3-EXTI_LOW_LEVEL
  4-EXTI_ON_CHANGE

*/

#define EXTI_SENSE_MODE  EXTI_FALLING_EDGE


#endif