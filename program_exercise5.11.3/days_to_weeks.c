/* File: days_to_weeks.c
 * Author: ByXc
 * About: 天數轉周數和天數
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	const unsigned short CUH_WEEKS = 7;
	int i_weeks, i_days;			//存儲轉換的周數和天數
	int i_days_input;				//用戶輸入的天數
	
	
	printf("Please enter number of days:");
	scanf("%d", &i_days_input);
	while (i_days_input > 0)
	{	
		i_weeks = i_days_input / SUH_WEEKS;
		i_days  = i_days_input % SUH_WEEKS;
	
		printf("%4d days are 4d weeks, %4d days. \n", i_days_input, i_weeks, i_days);
		printf("Please continue to enter the number of days(q to quit): ");
		scanf("%d", &i_days_input);
	}
	printf("Bey! \n");
	return 0;
}