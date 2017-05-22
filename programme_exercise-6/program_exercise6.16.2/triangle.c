/* File: triangle.c
 * Author: ByXc
 * About: triangle
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_row, i_col;
	
	for (i_row = 0; i_row = 5; i_row++)
	{
		for (i_col = 0; i_col < i_row; i_col++)
			printf("$");
		printf("\n");
	}
	
	return 0;
}