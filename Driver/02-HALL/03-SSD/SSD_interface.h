/*
 * ####################################SEVEN_SEGMENT_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 14 February 2024
 *   Layer  :HALL
 *   SWC    :SEVEN SEGMENT
 *   Version: 1
*/

#ifndef _SEVEN_SEGMENT_INTERFACE_H_
#define _SEVEN_SEGMENT_INTERFACE_H_
/* macros for conection_type */
#define COMMAN_CATHOD 1
#define COMMAN_ANODE  0
/* macros for  PORT */
#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3

/* macros for Pins */
#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7

typedef struct
{
	u8 port;
	u8 conection_type;	/* comman anode , comman cathod */
    u8 EnablePort;   /* port which comman pin is connected */
	u8 EnablePin;    /* comman pin */
}SSD_Type;


void SSD_voidinti(SSD_Type copy_configration);
void SSD_voidEnable(SSD_Type copy_configration);
void SSD_voidDisable(SSD_Type copy_configration);
void SSD_void_display(SSD_Type copy_configration,u8 copy_u8_number);


#endif
