/*
 * calculator_functions.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Aya Ramadan
 */

/* variables */
/*u8 press=NOT_PRESSED,num1=NOT_PRESSED,num2=NOT_PRESSED,operator=NOT_PRESSED,count=0;
	float result=0;
 */
#include "STD_TYPES.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"

/* >>>>>>>>>>first idea for operation on two number  of one digit<<<<<<<<<<<<*/
void one_digit(void)
{
	/* variables */
	u8 press=NOT_PRESSED,num1=NOT_PRESSED,num2=NOT_PRESSED,operator=NOT_PRESSED,count=0;
	float result=0;
	while(1)
	{
		press=KPD_u8GetPressed();
		/* check clear */
		if(press=='?')
		{
			CLCD_voidClearScreen(  );
			count=0;
			num1=NOT_PRESSED;num2=NOT_PRESSED;operator=NOT_PRESSED;
			continue;
		}
		/* store data*/
		else if(press!=NOT_PRESSED)
		{
			switch(count)
			{
			case 0: num1=press;CLCD_voidSendData (num1);count++; break;
			case 1: operator=press;CLCD_voidSendData (operator); count++; break;
			case 2: num2=press;CLCD_voidSendData (num2);count++;break;
			}
		}
		/* calc result */
		if(count==3 )
		{
			switch(operator)
			{
			case '+': result=(num1-48)+(num2-48);break;
			case '-': {
				if(num1>num2)
					result=num1-num2;
				else
					result=num2-num1;
			}break;
			case '*': result=(num1-48)*(num2-48);break;
			case '/': result=(float)(num1-48)/(num2-48);break;
			}

		}
		/* display output */
		if(press == '=')
		{
			CLCD_voidSendData (press);
			/* check if operand is valid or not */
			if(num1== '+' || num1== '-' || num1== '*' || num1== '/' ||num2== '+' || num2== '-' || num2== '*' || num2== '/'
					|| (operator != '+'  && operator != '-'  && operator != '*' && operator != '/'  ))
			{
				CLCD_voidClearScreen(  );
				CLCD_voidSendString( "ERROR"  );
				count=0;
				num1=NOT_PRESSED;num2=NOT_PRESSED;operator=NOT_PRESSED;
				continue;
			}
			else
			{
				if(num2>num1 && operator == '-')
				{
					CLCD_voidSendData ('-');
				}
				CLCD_voidSendFloatNumber(result);
			}
		}
	}
}

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
