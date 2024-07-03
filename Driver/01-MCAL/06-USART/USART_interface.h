 /*
 * #################################### USART_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 28 June 2024
 *   Layer  :MCAL
 *   SWC    :USART
 *   Version: 1
*/

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_


typedef enum{
	     USART_NOK,
         USART_OK,
         USART_IDEL,
         USART_BUSY,
      	 USART_NULL_POINTER	  
}USART_ErrorStatus;

void USART_voidInit (void);
u8   USART_u8TransmitData (u8 Copy_u8Data);
u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData) ;

u8   USART_u8TransmitStringSynch (const u8 *Copy_pchstring);
u8   USART_u8TransmitStringAsynch (const u8 *Copy_pchstring, void (* NotificationFunc)(void));

u8   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
u8   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;

#endif