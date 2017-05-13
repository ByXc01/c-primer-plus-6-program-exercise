/* File: odd_and_even.c
 * Author: ByXc
 * About: odd and even
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_odd, i_even	;					//分别代表奇數和偶數
	int i_input, i_count;					//分別代表用戶輸入的數和輸入次數
	float fl_odd_average, fl_even_average;		//奇數平均值和偶數平均值
	
	i_odd = i_even = i_input = 0;
	
	printf("Please enter number.(0 to quit): ");
	scanf("%d", &i_input);
	while (i_input > 0)
	{
		i_count++;
		if (i_input % 2 == 0)
			i_odd++;
		else
			i_even++;
		scanf("%d", &i_input);
	}
	fl_odd_average = (float) i_odd / i_count * 100;
	fl_even_average = (float) i_even / i_count * 100;
	
	printf("%d odd number and everage %2.2f%%. \n", i_odd, fl_odd_average);
	printf("%d even number and everage %2.2f%%. \n", i_even, fl_even_average);
	printf("Done! \n");
	
	return 0;
}