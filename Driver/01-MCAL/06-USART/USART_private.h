 /*
 * #################################### USART_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 28 June 2024
 *   Layer  :MCAL
 *   SWC    :USART
 *   Version: 1
*/

#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_


   /* DATA Register ( TXB/RXB )*/
#define UDR     *(( volatile u8* ) 0x2C)
 /* Control registers */
#define UCSRA   *(( volatile u8* ) 0x2B)
/*  UCSRA bits */
#define UCSRA_RXC     7  /* USART Receive Complete */
#define UCSRA_TXC     6  /* USART Transmit Complete */
#define UCSRA_UDRE    5  /* USART Data Register Empty */
#define UCSRA_FE      4  /* USART Frame Error */
#define UCSRA_DOR     3  /* USART Data OverRun */
#define UCSRA_PE      2  /* USART Parity Error */
#define UCSRA_U2X     1  /* USART Double Transmission Speed */
#define UCSRA_MPCM    0  /* USART Multi-processor Communication Mode */


#define UCSRB   *(( volatile u8* ) 0x2A)
/*  UCSRB bits */
#define UCSRB_RXCIE     7  /* RX Complete Interrupt Enable */
#define UCSRB_TXCIE     6  /*  TX Complete Interrupt Enable */
#define UCSRB_UDRIE     5   /* Data Register Empty Interrupt Enable */
#define UCSRB_RXEN      4  /*  Receiver Enable */
#define UCSRB_TXEN      3  /* Transmitter Enable */
#define UCSRB_UCSZ2     2  /* Character Size */
#define UCSRB_RXB8      1  /*  Receive Data Bit 8 */
#define UCSRB_TXB8      0  /*  Transmit Data Bit 8 */


#define UCSRC   *(( volatile u8* ) 0x40)
/*  UCSRC bits */
#define UCSRC_URSEL     7  /*  Register Select */
#define UCSRC_UMSEL     6  /* USART Mode Select */
#define UCSRC_UPM1      5  /* Parity Mode */
#define UCSRC_UPM0      4  /* Parity Mode */
#define UCSRC_USBS      3  /* Stop Bit Select */
#define UCSRC_UCSZ1     2  /* Character Size */
#define UCSRC_UCSZ0     1  /* Character Size */
#define UCSRC_UCPOL     0  /* Clock Polarity */

/* Baud Rate Register */
#define UBRRL   *(( volatile u8* ) 0x29)

#define UBRRH   *(( volatile u8* ) 0x40)
#define UBRRH_URSEL		7  /* Register Select */



 /* macros for initialization */
#define DISABLE  0
#define ENABLE   1
/* Data SIZE */
#define DATA_SIZE_5_BIT		                    0
#define DATA_SIZE_6_BIT		                    1
#define DATA_SIZE_7_BIT		                    2
#define DATA_SIZE_8_BIT		                    3
#define DATA_SIZE_9_BIT		                    7
/* USART OPERATION MODE */
#define ASYNCHRONOUS		                    0
#define SYNCHRONOUS 		                    1

/* PARITY MODE */
/* #define DISABLE  0 */
#define EVEN_PARITY			                    2
#define ODD_PARITY 			                    3
 /* NUMBER OF STOP BIT */
#define STOP_BIT_1			                    0
#define STOP_BIT_2			                    1
 /* CLOCK POLARITY (synchronouos) */
#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1
/* USART SPEED */
#define USART_X			                        0
#define USART_2X			                    1


#endif







