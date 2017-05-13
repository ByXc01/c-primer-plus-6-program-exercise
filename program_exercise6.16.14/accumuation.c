/* File: accumulation.c
 * Author: ByXc
 * About: accumulation
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	const short int CHD_MAX = 8;
	double db_numbers[CHD_MAX], db_sums[CHD_MAX];
	double db_temp;
	int i_count;
	
	printf("Please enter %hd numbers:", CHD_MAX);
	for (i_count = db_temp = 0; i_count < CHD_MAX; i_count++)
	{
		scanf("%lf", &db_numbers[i_count]);
		db_sums[i_count] = db_temp += db_numbers[i_count];
	}
	
	printf("Numbers: ");
	while (i_count-- > 0)
		printf("%5g ", db_numbers[CHD_MAX - i_count - 1]);
	printf("\n");
	
	printf("Sums   : ");
	while (++i_count < CHD_MAX)
		printf("%5g ", db_sums[i_count]);
	printf("\nThe all! \n"); 
	
	return 0;
}