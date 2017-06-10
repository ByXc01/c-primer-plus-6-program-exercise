/* File: moduli.c
 * Author: ByXc
 * About: mod
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_modulus, i_number, i_sum;						//用戶輸入的模,求模數，餘數
	
	printf("This program computes moduli. \n");
	printf("Enter an integer to  serve as the second operand:");
	scanf("%d", &i_modulus);
	
	printf("Now enter the first operand:");
	scanf("%d", &i_number);
	
	while (i_number != 0)
	{
		i_sum = i_number % i_modulus;
		printf("%d %% %d is %d. \n", i_number, i_modulus, i_sum);
		
		printf("Enter next number for first operand (= 0 to quit):");
		scanf("%d", &i_number);
	}
	printf("Done! \n");
	
	return 0;
}