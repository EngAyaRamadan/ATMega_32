 /*
 * #################################### SPI_private.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 July 2024
 *   Layer  :MCAL
 *   SWC    :SPI
 *   Version: 1
*/

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

/*SPI Control Register*/
#define SPCR  *((volatile u8*)0x2D)
#define SPCR_SPIE  7   /*SPI Interrupt Enable*/
#define SPCR_SPE   6   /*SPI Enable*/
#define SPCR_DORD  5   /*Data Order*/
#define SPCR_MSTR  4   /*Master/Slave Select*/
#define SPCR_CPOL  3   /*Clock Polarity*/
#define SPCR_CPHA  2   /*Clock Phase*/
#define SPCR_SPR1  1   /*SPI Clock Rate Select 1*/
#define SPCR_SPR0  0   /*SPI Clock Rate Select 0*/

/*SPI Status Register*/
#define SPSR  *((volatile u8*)0x2E)
#define SPSR_SPIF   7   /*SPI Interrupt Flag*/
#define SPSR_WCOL   6   /*Write COLlision Flag*/
#define SPSR_SPI2X  0   /*Double SPI Speed Bit*/

/*SPI Data Register*/
#define SPDR  *((volatile u8*)0x2F)




  /*macros*/
#define SPI_INTERRUPT_DISABLE 0
#define SPI_INTERRUPT_ENABLE  1

#define SPI_DATA_LSB_FIRST  0
#define SPI_DATA_MSB_FIRST  1


#define SPI_MASTER  0
#define SPI_SLAVE   1


#define SPI_RISING_LEADING_FALLING_TRAILING  0
#define SPI_FALLING_LEADING_RISING_TRAILING  1

#define SPI_SAMPLE_LEADING_SETUP_TRAILING    0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING    1

#define SPI_FREQ_DIVIDED_BY_2     0
#define SPI_FREQ_DIVIDED_BY_4     1
#define SPI_FREQ_DIVIDED_BY_8     2
#define SPI_FREQ_DIVIDED_BY_16    3
#define SPI_FREQ_DIVIDED_BY_32    4
#define SPI_FREQ_DIVIDED_BY_64    5
#define SPI_FREQ_DIVIDED_BY_128   6

#define SPI_DISABLE  0
#define SPI_ENABLE   1


#endif