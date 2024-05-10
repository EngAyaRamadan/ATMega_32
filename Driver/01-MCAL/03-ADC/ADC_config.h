 /*
 * #################################### ADC_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 7 April 2024
 *   Layer  :MCAL
 *   SWC    :ADC
 *   Version: 1
*/


#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/*
   Options:
      1-ADC_DISABLE  
      2-ADC_ENABLE    
*/
 #define ADC_STATUS ADC_ENABLE

/*
   Options:
      1-ADC_INT_DISABLE  
      2-ADC_INT_ENABLE     
*/

 #define ADC_INT_STATUS ADC_INT_ENABLE

 /*
   >>Reffrence Voltage
   Options:
      1-INTERNAL_2_56  
      2- AVCC  
      3- AREF  
 */
 #define ADC_VREF AVCC

 /*
   >>Read Result
   Options:
      1-RIGHT_ADJUSTED 
      2-LEFT_ADJUSTED    
 */
 #define ADC_ADJUSTED RIGHT_ADJUSTED

  /*
   >>PRESCALLER
   Options:
       1-ADC-PRE_2   
       2-ADC-PRE_4   
       3-ADC-PRE_8   
       4-ADC-PRE_16  
       5-ADC-PRE_32  
       6-ADC-PRE_64  
       7-ADC-PRE_128  
 */
 #define ADC_PRESCALLER ADC_PRE_64

/*
   >>Channel
   Options:
       single ended channel
          1-ADC0  
          2-ADC1  
          3-ADC2  
          4-ADC3  
          5-ADC4  
          6-ADC5  
          7-ADC6  
          8-ADC7 
       diffrential channel 
          1-ADC_DIFF_00_10x  
          2-ADC_DIFF_10_10x   
          3-ADC_DIFF_00_200x  
          4-ADC_DIFF_10_200x  
          5-ADC_DIFF_22_10x  
          6-ADC_DIFF_32_10x   
          7-ADC_DIFF_22_200x  
          8-ADC_DIFF_32_200x  
          9-ADC_DIFF_01_1x  
          10-ADC_DIFF_11_1x  
          11-ADC_DIFF_21_1x  
          12-ADC_DIFF_31_1x  
          13-ADC_DIFF_41_1x  
          14-ADC_DIFF_51_1x  
          15-ADC_DIFF_61_1x  
          16-ADC_DIFF_71_1x  
          17-ADC_DIFF_02_1x  
          18-ADC_DIFF_12_1x  
          19-ADC_DIFF_22_1x  
          20-ADC_DIFF_32_1x  
          21-ADC_DIFF_42_1x  
          22-ADC_DIFF_52_1x  		  
 */
 #define ADC_CHANNEL ADC0

/*
   >>TRIGGERING SOURCE
   Options:
          1-ADC_FREE_RUNNING  
          2-ADC_ANALOG_COMPARATOR  
          3-ADC_EXTI0  
          4-ADC_TIM0_CTC  
          5-ADC_TIM0_OVF   
          6-ADC_TIM1_CTC_CHANNEL_B  
          7-ADC_TIM1_OVF  
          8-ADC_TIM1_ICU
          9-ADC_SINGLE_CONVERSION		  
    		  
 */
 #define ADC_TRIGGERING_SOURCE  ADC_SINGLE_CONVERSION
/* time out for sync */
 #define ADC_TIMEOUT 50000

#endif
