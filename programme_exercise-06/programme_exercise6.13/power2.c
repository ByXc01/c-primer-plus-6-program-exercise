/* File: powe2.c
 * Author: ByXc
 * About: power 2
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define MAX 8

int main(void)
{
	const short int MAX = 8;
	int i_power, i_count, i_temp;
	int numbers[MAX];
	
	//初始化變量可以放在for循環外， 像我這樣就略顯臃腫了，
	for (i_count = i_temp = 1, numbers[i_count - 1] = 1, i_power = 2; i_count < MAX; i_count++)
		numbers[i_count] = i_temp *= i_power;		//賦值運算符是從右往左的
	
	i_count = 0;
	do
		printf("%d power to %d is %d \n", i_power, i_count, numbers[i_count]);
	while (++i_count < MAX);		//用i++會迭代n+1次， 謹記前後綴自增的區別
	printf("The all! \n");

	return 0;
}