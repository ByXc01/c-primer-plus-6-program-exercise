/* File: n_to10.c
 * Author: ByXc
 * About: n to 10
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_input, i_i;
	
	printf("Please enter an integer:");
	scanf("%d", &i_input);
	
	i_i = i_input;
	while (i_i <= i_input + 10)
		printf("%3d ", i_i++);
	
	printf("\nDone! \n");
	
	return 0;
}