/* File: double_squares.c
 * Author: ByXc
 * About: double squares
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

void squares(double dbl_number);
int main(void)
{
	double dbl_input;
	printf("Please enter a number of type double:");
	scanf("%lf", &dbl_input);
	
	while (dbl_input > 0)
	{
		squares(dbl_input);
		printf("Please continue enter a number of type double:");
		scanf("%lf", &dbl_input);
	}
	printf("Bey! \n");
	
	return 0;
}

void squares(double dbl_number)
{
	printf("The number of the square is %3.2f", dbl_number * dbl_number);
}