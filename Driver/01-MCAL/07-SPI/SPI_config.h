 /*
 * #################################### SPI_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 July 2024
 *   Layer  :MCAL
 *   SWC    :SPI
 *   Version: 1
*/

#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_


/*Set SPI Interrupt Enable
    1. SPI_INTERRUPT_DISABLE
    2. SPI_INTERRUPT_ENABLE
 */
#define SPI_INTERRUPT_ENABLE_MODE		DISABLE

/*Set Data Order
   1. SPI_DATA_LSB_FIRST
   2. SPI_DATA_MSB_FIRST
 */
#define SPI_DATA_ORDER		      SPI_DATA_LSB_FIRST


/* Select Master/Slave  
    1. SPI_MASTER
    2. SPI_SLAVE 
 */
#define SPI_MASTER_SLAVE_SELECT      SPI_MASTER

/*Set Clock Polarity 
   1. SPI_RISING_LEADING_FALLING_TRAILING
   2. SPI_FALLING_LEADING_RISING_TRAILING
 */
#define SPI_CLOCK_POLARITY  SPI_RISING_LEADING_FALLING_TRAILING

/*Set Clock Phase
   1. SPI_SAMPLE_LEADING_SETUP_TRAILING
   2. SPI_SETUP_LEADING_SAMPLE_TRAILING
 */
#define SPI_CLOCK_PHASE  SPI_SAMPLE_LEADING_SETUP_TRAILING

/*Set Clock Rate
   1. SPI_FREQ_DIVIDED_BY_2
   2. SPI_FREQ_DIVIDED_BY_4
   3. SPI_FREQ_DIVIDED_BY_8
   4. SPI_FREQ_DIVIDED_BY_16
   5. SPI_FREQ_DIVIDED_BY_32
   6. SPI_FREQ_DIVIDED_BY_64
   7. SPI_FREQ_DIVIDED_BY_128
 */
#define SPI_CLOCK_RATE  SPI_FREQ_DIVIDED_BY_4

/*Set SPI Enable
    1. SPI_DISABLE
    2. SPI_ENABLE 
 */
#define SPI_ENABLE_MODE		SPI_ENABLE 

/* Time out for function */
#define SPI_TIMEOUT             10000UL


#endif