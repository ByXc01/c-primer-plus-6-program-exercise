/* File: reverse.c
 * Author: ByXc
 * About: reverse
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	const unsigned short CHU_MAX = 8;
	int i_index, i_array[CHU_MAX];
	
	printf("Please enter %d integer. \n", CHU_MAX);
	for (i_index = 0; i_index < CHU_MAX; i_index++)
		scanf("%d", &i_array[i_index]);
		
	printf("Here in reverse order, are the values you entered:");
	while (--i_index >= 0)				//利用前綴自減的特性
		printf("%d", i_array[i_index]);
	
	return 0;
}