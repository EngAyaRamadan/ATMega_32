/*
 * dcmotor.h
 *
 *  Created on: Sep 13, 2023
 *      Author: dell
 */

#ifndef HAL_DCMOTOR_DCMOTOR_H_
#define HAL_DCMOTOR_DCMOTOR_H_

#define DCMOTOR_PORT DIO_PORTA
#define BLUE     DIO_PIN0
#define PINK      DIO_PIN1
#define YELLOW    DIO_PIN2
#define ORANGE    DIO_PIN3


void DCMOTOR_Init(void);
void DCMOTOR_Stop(void);
void DCMOTOR_CW(void);
void DCMOTOR_CCW(void);


#endif /* HAL_DCMOTOR_DCMOTOR_H_ */
