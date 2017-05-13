/* File: max.c
 * Author: ByXc
 * About: max
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
void larger_of(double *, double *);
int main(void)
{
	double db_number1, db_number2;
	db_number1 = 10.0;
	db_number2 = 20.0;
	
	printf("Originally number1 = %f and number2 = %f \n", db_number1, db_number2);
	larger_of(&db_number1, &db_number2);
	printf("Now number1 = %f and number2 = %f \n", db_number1, db_number2);
	
	return 0;
}
void larger_of(double *pdb_x, double *pdb_y)
{
  *pdb_x = *pdb_x < *pdb_y ? *pdb_y : (*pdb_y = *pdb_x);		//如果覺得難于理解的話可拆分兩個三元運算符
}