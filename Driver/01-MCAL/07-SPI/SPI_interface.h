 /*
 * #################################### SPI_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 1 July 2024
 *   Layer  :MCAL
 *   SWC    :SPI
 *   Version: 1
*/

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_



typedef struct
{
	u8 SPI_u8InterruptEnable ;
	u8 SPI_u8SPIEnable ;
	u8 SPI_u8DataOrder ;
	u8 SPI_u8MasterSlaveSelect ;
	u8 SPI_u8ClockPolarity ;
	u8 SPI_u8ClockPhase ;
	u8 SPI_u8ClockRate ;
}SPI_CONFIG;

typedef struct
{
	u8 * Copy_u8TData ;
	u8 * Copy_u8RData ;
	u8 Copy_u8BufferSize ;
	void(* NotificationFuncn)(void) ;
}SPI_BUFFER;

enum SPI_STATE{
	   SPI_OK,
	   SPI_NOK,
	   SPI_IDLE,
	   SPI_BUSY,
	   TIMEOUT_STATE,
	   BUSY_STATE
};
/* pre build config */
void SPI_VoidInit(void) ;
/*post build*/
u8 SPI_u8InitConfig (SPI_CONFIG * spi) ;

u8 SPI_u8Tranceive (u8 Copy_u8TData , u8 * Copy_u8RData) ;
U8 SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize) ;
u8 SPI_u8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer) ;


#endif