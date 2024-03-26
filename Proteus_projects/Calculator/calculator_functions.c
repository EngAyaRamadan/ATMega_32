/*
 * calculator_functions.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Aya Ramadan
 */


#include "STD_TYPES.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"


/*>>>>>>>>>>>>> calculator function for operation on two number of any number of digit<<<<<<<<< */
void calculator(void)
{
	/* variables */
	u8 press=NOT_PRESSED,operator=NOT_PRESSED,count=0;
	u32 num1=0,num2=0;
	float result=0;
	while(1)
	{
		press=KPD_u8GetPressed();
		/* check clear button is pressed or not */
		if(press=='?')
		{
			CLCD_voidClearScreen(  );
			count=0;
			press=NOT_PRESSED;
			num1=0;num2=0;result=0;
			continue;
		}
		/* store data of two numbers */
		else if(press!=NOT_PRESSED)
		{
			switch(count)
			{
			/* store data of first number */
			case 0:
			{
				while(press!=NOT_PRESSED)
				{
					if( press != '+' && press != '-' && press != '*' && press != '/')
					{
						CLCD_voidSendData (press);
						num1=(num1*10)+(press-48);
						press=KPD_u8GetPressed();//123
						continue;
					}
					if(press == '+' || press == '-' || press == '*' || press == '/')
					{
						operator=press;
						CLCD_voidSendData (press);
						count++;
						break;
					}
				}
			}break;
			/* store data of second number */
			case 1:
			{
				while(press!=NOT_PRESSED )
				{
					if( press != '+' && press != '-' && press != '*' && press != '/' && press != '=')
					{
						CLCD_voidSendData (press);
						num2=(num2*10)+(press-48);
						press=KPD_u8GetPressed();//123
						continue;
					}
					if(press == '=')
					{
						count++;
						break;
					}
				}
			}break;
			}
		}
		/* calculate result of operation */
		if(count==2 )
		{
			switch(operator)
			{
			case '+': result=num1+num2;break;
			case '-':
			{
				if(num1>num2)
					result=num1-num2;
				else
					result=num2-num1;
			}break;
			case '*': result=num1*num2;break;
			case '/': result=(float)num1/num2;break;
			}
		}
		/* display output of operation */
		if(press == '=')
		{
			CLCD_voidSendData (press);
			if(num2>num1 && operator == '-')
			{
				CLCD_voidSendData ('-');
			}
			CLCD_voidSendFloatNumber(result);
			num1=0;num2=0;result=0;
		}
	}
}
