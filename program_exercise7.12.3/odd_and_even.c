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
	int i_odd, i_even;	    				    // 分别代表奇數和偶數的個數
	int i_input;        					    // 代表用戶輸入數
	int i_odd_sum, i_even_sum;					// 奇偶數總和
	
	i_odd = i_even = 0;
	i_odd_sum = i_even_sum = 0;
	
	printf("Please enter number.(0 to quit): ");
	while (scanf("%d", &i_input) && i_input != 0)
	{
		if (i_input % 2 == 0)
		{
			i_even_sum += i_input;
			i_even++;
		}
		else                                     // i_input % 2 is either 1 or -1
		{
			i_odd_sum += i_input;
			i_odd++;
		}
	}
	
	printf("Number of evens: %d ", i_even);
	if (i_even > 0)
		printf("average: %g ", (double) i_even_sum / i_even);
	putchar('\n');
	
	printf("Number of odds: %d ", i_odd);
	if (i_odd > 0)
		printf("average: %g ", (double) i_odd_sum / i_odd);
	putchar('\n');
	
	printf("Done! \n");
	
	return 0;
}