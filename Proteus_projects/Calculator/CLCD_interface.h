/*
 * #################################### CLCD_interface.h #############################
 *   Author : Aya Ramadan
 *   date   : 21 march 2024
 *   Layer  :HALL
 *   SWC    :CLCD
 *   Version: 1
*/

#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_
/* mode macro*/
#define EIGHT_BITS 0x38
#define FOUR_BITS  0x28

#define LCD_LOW_NIBBLE   0
#define LCD_HIGH_NIBBLE  1


#define CLCD_ROW_1  1
#define CLCD_ROW_2  2

#define CLCD_COL_1   1 
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16
/*commands macro*/
#define LCD_HOME                  0x02 /* return curser to frist position*/
#define LCD_CLEAR                 0x01
#define LCD_DISPLAY_ON_CURSOROFF  0x0c
#define LCD_DISPLAY_ON_CURSORON   0x0e
#define LCD_DISPLAY_OFF_CURSOROFF 0x08
#define LCD_ENTRY_MODE            0x06 /* shift curser from left to right */
#define LCD_SetCurser             0x80
#define LCD_CGRAM                 0x40
#define LCD_FunctionSet           0x30




void CLCD_voidInti           (             void             );
void CLCD_voidClearScreen    (             void             );
void CLCD_voidSendData       (      u8 copy_u8Data          );
void CLCD_voidSendCommand    (      u8 copy_u8Command       );
void CLCD_voidSendNumber     (      u64 copy_u64Number      );
void CLCD_voidSendFloatNumber(      f32 Copy_f32Number      );
void CLCD_voidSendString     (  const u8 *copy_u8PtrString  );
void CLCD_voidSendExtraChar  (  u8 copy_u8Row,u8 copy_u8Col );
void CLCD_voidSetPosition    (  u8 copy_u8Row,u8 copy_u8Col );


#endif







