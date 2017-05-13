/* File: compute_function.c
 * Author: ByXc
 * About: compute function
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
double results(float fl_n, float fl_v);		//ANSI原型
int main(void)
{
	float fl_number, fl_value;
	double db_sum;
	
	printf("Please input a pari numbers:");
	while (scanf("%f %f", &fl_number, &fl_value) == 2)			//利用scanf()函數的返回值
	{
		db_sum = results(fl_number, fl_value);
		printf("(%g - %g) / (%g * %g) = %g \n", fl_number, fl_value,
		fl_number, fl_value, db_sum);
		
		printf("Please input next pari(non numberic to quit):");
	}
	printf("Bye! \n");
	
	return 0;
}

double results(float fl_n, float fl_v)			//函數定義
{
	return (fl_n - fl_v) / (fl_n * fl_v);		//直接返回一個表達式的值
}