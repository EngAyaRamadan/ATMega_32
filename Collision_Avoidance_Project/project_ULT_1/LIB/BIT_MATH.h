/*
 *################################  BIT_MATH.h  ######################
 *   Author : Aya Ramadan
 *   Layer :LIB
 *   date : 7/2/2023
*/

#ifndef  BIT_MATH_H_
#define  BIT_MATH_H_

#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=~(1<<bit)
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define GET_BIT(reg,bit)  ((reg>>bit)&1)
#endif
