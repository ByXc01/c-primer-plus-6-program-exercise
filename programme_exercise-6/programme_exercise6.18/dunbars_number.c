/* File: dunbars_number.c
 * Author: ByXc
 * About: dunbar's number
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define DUNBARS_NUMBER 150						//鄧巴數

int main(void)
{
	int i_friends, i_week, i_double;			//分別是朋友， 周數和雙倍數
	
	for (i_friends = 5, i_week = 1, i_double = 2; i_friends < DUNBARS_NUMBER; i_week++)
	{
		i_friends -= i_week;
		i_friends *= i_double;
		
		printf("After %d week, Rabnud have %d frienfs. \n", i_week, i_friends);
	}
	printf("The all! \n");
	
	return 0;
}