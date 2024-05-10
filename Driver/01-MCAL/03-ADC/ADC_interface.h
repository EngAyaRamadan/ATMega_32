 /*
 * #################################### ADC_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 7 April 2024
 *   Layer  :MCAL
 *   SWC    :ADC
 *   Version: 1
*/

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
/* ADC STATUS */
#define ADC_DISABLE 0
#define ADC_ENABLE  1
 /* ADC INTERRUPT STATUS */
#define ADC_INT_DISABLE 0
#define ADC_INT_ENABLE  1


 /* single ended channel*/
#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7
  /* diffrential channel */
#define ADC_DIFF_00_10x   8
#define ADC_DIFF_10_10x   9
#define ADC_DIFF_00_200x  10
#define ADC_DIFF_10_200x  11
#define ADC_DIFF_22_10x   12
#define ADC_DIFF_32_10x   13
#define ADC_DIFF_22_200x  14
#define ADC_DIFF_32_200x  15
 
#define ADC_DIFF_01_1x  16
#define ADC_DIFF_11_1x  17
#define ADC_DIFF_21_1x  18
#define ADC_DIFF_31_1x  19
#define ADC_DIFF_41_1x  20
#define ADC_DIFF_51_1x  21
#define ADC_DIFF_61_1x  22
#define ADC_DIFF_71_1x  23

#define ADC_DIFF_02_1x  24
#define ADC_DIFF_12_1x  25
#define ADC_DIFF_22_1x  26
#define ADC_DIFF_32_1x  27
#define ADC_DIFF_42_1x  28
#define ADC_DIFF_52_1x  29

 /* Reffrence Voltage */
 #define INTERNAL_2_56  0
 #define AVCC  1
 #define AREF  2

 /*  Read Result adjust */
 #define RIGHT_ADJUSTED 0
 #define LEFT_ADJUSTED  1
 
 /* TRIGGERING SOURCE */
 
#define ADC_FREE_RUNNING         0
#define ADC_ANALOG_COMPARATOR    1
#define ADC_EXTI0                2
#define ADC_TIM0_CTC             3
#define ADC_TIM0_OVF             4
#define ADC_TIM1_CTC_CHANNEL_B   5
#define ADC_TIM1_OVF             6
#define ADC_TIM1_ICU             7

#define ADC_SINGLE_CONVERSION    8 

/* PRESCALLER */

#define ADC_PRE_2   0
#define ADC_PRE_4   2
#define ADC_PRE_8   3
#define ADC_PRE_16  4
#define ADC_PRE_32  5
#define ADC_PRE_64  6
#define ADC_PRE_128 7


#define NULL 0
typedef enum{
	     ADC_NOK,
         ADC_OK		 
}ADC_ErrorStatus;

/* struct for ADC Chain */
typedef struct 
{
	u8* channel;
	u8* size;
	u16* result;
	void (*NotificationFunc)(void);
}Chain_t;


void ADC_voidInit (void);

void ADC_voidEnable (void);
void ADC_voidDisable (void);
void ADC_voidInterruptEnable (void);
void ADC_voidInterruptDisable (void);

u8 ADC_u16GetResltSync(u8 Copy_u8channel,u16 *Copy_u16PtrResult);
u8 ADC_u16StartConversionAsync(u8 Copy_u8channel,u16 *Copy_u16PtrResult,void(*Copy_ptrNotificationFunc)(void));
u8 ADC_u16StartChainAsync(Chain_t * copy_chain);

#endif
