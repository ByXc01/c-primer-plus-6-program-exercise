/* File: addemup.c
 * Author: ByXc
 * About: addemup
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_count, i_days, i_sum;		        	// 聲明
	char ch_judge;
	do
	{
		i_sum = i_count = 0;					// 表達式語句
		
		printf("Please input the number of business days you want to query:");
		scanf("%d", &i_days);
		while (i_count++ < i_days)
			i_sum += i_count
		printf("The nuer of days you work for %d days, salary of $ %d .", i_days, i_sum);
		
		printf("Whether to continue? (input Y continue)):\n");
		scanf(" %c", &ch_judge);
	}while (ch_judge == 'y' || ch_judge == 'Y');
	printf("Bey!");
	
	return 0;
}