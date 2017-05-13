/* File: compute.c
 * Author: ByXc
 * About: compute
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	float fl_number, fl_value;
	double db_sum;
	
	printf("Enter a pari of numbers:");
	while (scanf("%f %f", &fl_number, &fl_value) == 2)
	{
		db_sum = (fl_number - fl_value) / (fl_number * fl_value);
		printf("(%g - %g) / (%g * %g) = %g\n", fl_number, fl_value,
		fl_number, fl_value, db_sum);

		printf("Enter next pari(non nnumberic to quit):");
	}
	printf("Bye! \n");
	
	return 0;
}