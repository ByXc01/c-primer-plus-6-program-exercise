/* File: convert.c
 * Author: ByXc
 * About: convert hour and minute
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	const unsigned short CUH_MINUTE = 60;
	int i_hour, i_minute;	    		//存放轉換的小時和分鐘
	int i_input_minute;					//用戶輸入的分鐘數
	
	printf("Please enter the number of minutes you want to convert(<= 1)：");
	scanf("%d", &i_sec2);
	
	while (i_sec2 >= 1)
	{
		i_hour = i_sec2 / CUH_SEC;
		i_sec  = i_sec2 % CUH_SEC;
		printf("%4d minute, %4d hour %4d minutes \n", i_sec2, i_hour, i_sec);
		
		printf("Please enter the next number to be relaced: \n");
		scanf("%d", &i_sec2);
	}
	printf("Done! \n");
	
	return 0;
}