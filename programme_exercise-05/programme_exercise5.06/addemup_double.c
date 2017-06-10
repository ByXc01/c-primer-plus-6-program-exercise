/* File: addemup_double.c
 * Author: ByXc
 * About: addemup double
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_days, i_sum, i_count;
	char ch_judge;
	do
	{
		i_count = i_sum = 0;
		printf("Please input the number of business days you want to query:");
		
		scanf("%d", &i_days);
		while (i_count++ < i_days)
			i_sum += i_days * i_days;
		printf("The number of days you work for %d days, salary of $ %d .", i_days, i_sum);	
		
		printf("Whether to continue? (input Y continue)):\n");
		scanf(" %c", &ch_judge);
	}while (ch_judge == 'y' || ch_judge == 'Y');
	printf("Bey!");
	
	return 0;
}