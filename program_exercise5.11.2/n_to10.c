/* File: n_to10.c
 * Author: ByXc
 * About: n to 10
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_input, i_i;
	i_input = i_i = 0;
	
	printf("Please enter integer:");
	scanf("%d", &i_input);
	
	while (i_i <= 10)
	{
		printf("%3d", i_input++);
		i_i++;
	}
	printf("\n Done! \n");
	
	return 0;
}