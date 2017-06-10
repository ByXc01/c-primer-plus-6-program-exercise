/* File: reverse.c
 * Author: ByXc
 * About: reverse
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define MAX 8
int main(void)
{
	int i_index, i_array[MAX];
	
	printf("Please enter %d integer. \n", MAX);
	for (i_index = 0; i_index < MAX; i_index++)
		scanf("%d", &i_array[i_index]);
		
	printf("Here in reverse order, are the values you entered:");
	while (--i_index >= 0)				//利用前綴自減的特性
		printf("%2d ", i_array[i_index]);
	
	return 0;
}