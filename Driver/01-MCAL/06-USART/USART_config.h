 /*
 * #################################### USART_config.h #############################
 *   Author : Aya Ramadan
 *   date   : 28 June 2024
 *   Layer  :MCAL
 *   SWC    :USART
 *   Version: 1
*/

#ifndef _USART_CONFIG_H_
#define _USART_CONFIG_H_

/* Baud Rate and SYSTEM_FREQUENCY to calc UBRR value  */

 /*Set Baud Rate 
     ex:
    >> 2400,4800,9600,14.4k
 */
#define USART_BAUD_RATE					9600UL


/*Set System Frequency
     >> 1,1.8432,2,3.6864,4 MHz
*/
#define SYSTEM_FREQUENCY			   8000000UL

 
/* Set Multi-Processor Communication mode
    1. DISABLE
    2. ENABLE 
 */
#define USART_MPCM                     DISABLE


/*Set RX Complete Interrupt Enable
    1. DISABLE
    2. ENABLE 
 */
#define USART_RX_COMPLETE_INTERRUPT		DISABLE


/*Set TX Complete Interrupt Enable
    1. DISABLE
    2. ENABLE 
 */
#define USART_TX_COMPLETE_INTERRUPT		DISABLE

/*Set UDR Empty Interrupt Enable
    1. DISABLE
    2. ENABLE 
 */
#define USART_UDR_EMPTY_INTERRUPT		DISABLE

/*Set Receiver Enable
    1. DISABLE
    2. ENABLE 
 */
#define USART_RECEIVER_ENABLE		    ENABLE

/*Set Transmitter Enable
    1. DISABLE
    2. ENABLE 
 */
#define USART_TRANSMITTER_ENABLE		ENABLE

/* frame formate */

/*Set Data Size
   1. DATA_SIZE_5_BIT
   2. DATA_SIZE_6_BIT
   3. DATA_SIZE_7_BIT
   4. DATA_SIZE_8_BIT
   5. DATA_SIZE_9_BIT
 */
#define USART_DATA_SIZE		      DATA_SIZE_8_BIT

/*Set USART Mode Select
   1. ASYNCHRONOUS
   2. SYNCHRONOUS
 */
#define USART_MODE				   ASYNCHRONOUS

/*Set Parity Mode
   1. DISABLE
   2. EVEN_PARITY
   3. ODD_PARITY
 */
#define USART_PARITY_MODE			DISABLE

/*Set Stop bit
   1. STOP_BIT_1
   2. STOP_BIT_2
 */
#define USART_STOP_BIT		      STOP_BIT_1

/*Set Clock Polarity (for SYNCHRONOUS mode only)
   1. XCK_RISING_TX_XCH_FALLING_RX
   2. XCK_RISING_RX_XCH_FALLING_TX
 */
#define USART_CLOCK_POLARITY  XCK_RISING_TX_XCH_FALLING_RX

/*Set System Speed
   1. USART_X
   2. USART_2X  (Double Speed Mode)
 */
#define USART_SYSTEM_SPEED		  USART_X

/* Time out for function */
#define USART_TIMEOUT             10000UL

#endif