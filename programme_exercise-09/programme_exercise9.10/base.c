/* File: base.c
 * Author: ByXc
 * About: base
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

int input(void);				//判斷操作數
void to_base_n(int, int);		//進制轉換

int main(void)
{
	int i_number, i_base;

	printf("Please enter a numer to convert and a radix number to convert. \n");

	while (scanf("%d", &i_number))
	{
		i_base = input();
		
		printf("Radix equivalent:");
		to_base_n(i_number, i_base);

		printf("\nPlease enter the number to be converted and the number of radix to be converted. (q to quit): ");
	}
	printf("Hope you will like this program, goodbye! \n");

	return 0;
}

int input(void)
{
	int i_try_input;
	_Bool B_judge;
	char ch_error_input;

	while ((B_judge = scanf("%d", &i_try_input)) != 1 || (i_try_input > 10 || i_try_input < 2))
	{
		if (!B_judge)						//處理錯誤輸入
		{	
			while ((ch_error_input = getchar()) != '\n')
			       putchar(ch_error_input);
		       printf(" is not an integer. \nPlease enter an integer value, such as 2, 3, 5 or 7 \n");
		}
		else							//處理過大或過小的數
			printf("Please enter the number 2 to 10. \n");
	}

	return i_try_input;
}


void to_base_n(int i_decimal, int i_radix)
{
	int i_results;

	i_results = i_decimal % i_radix;
	if (i_decimal >= i_radix)
		to_base_n(i_decimal / i_radix, i_radix);

	printf("%d", i_results);
	//putchar('0' + i_results);				// 字符0和數字運算， 是把i_results轉換為數字字符

	return;
}	
