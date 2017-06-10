/* File: cube.c
 * Author: ByXc
 * About: cube
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

void cube(double db_number);
int main(void)
{
	double db_input;
	
	printf("Please enter a number of type double:");
	scanf("%lf", &db_input);
	
	while (db_input > 0)
	{
		cube(db_input);
		printf("Please continue enter a number of type double:");
		scanf("%lf", &db_input);
	}
	printf("Bey! \n");
	
	return 0;
}

void cube(double db_number)
{
	printf("TThe cube of %f is %f", db_number, db_number * db_number * db_number);
}