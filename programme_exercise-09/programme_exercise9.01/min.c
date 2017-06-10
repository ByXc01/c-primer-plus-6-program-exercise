/* File: min.c
 * Author: ByXc
 * About: min
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 程序很簡單，因我直接是調用函數測試的。所以參考標準答案的方法 */
#include <stdio.h>

double min(double db_x, double db_y);
int main(void)
{
    double db_number1, db_number2;
	
	printf("Enter two numbers (q to quit): ");
	while (scanf("%lf %lf", &db_number1, &db_number2) == 2)
	{
		printf("The smaller number is %g. \n", min(db_number1, db_number2)); 			//簡單的驅動程序測試成功，
		printf("Next two value (q to quit): ");
	}
	
	return 0;
}
double min(double db_x, double db_y) 
{ 
	return db_x < db_y ? db_x : db_y; 
}
