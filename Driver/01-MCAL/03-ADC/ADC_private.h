 /*
 * #################################### ADC_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 7 April 2024
 *   Layer  :MCAL
 *   SWC    :ADC
 *   Version: 1
*/
#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

/* Registers */
#define ADMUX   *((volatile u8 *)(0x27))
#define ADCSRA  *((volatile u8 *)(0x26))
#define ADCH    *((volatile u8 *)(0x25))
#define ADCL    *((volatile u8 *)(0x24))        
#define SFIOR   *((volatile u8 *)(0x50))    

/* ISR SOURCE */
#define SINGLE_CHANNEL_ASYNC 0
#define CHAIN_CHANNEL_ASYNC  1

#endif