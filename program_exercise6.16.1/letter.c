/* File: letter.c
 * Author: ByXc
 * About: letter
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE

int main(void)
{
	char ch_letter[SIZE]; 
	int i_index;
	
	for (i_index = 0; i_index < SIZE; i_index++)
	{
		ch_letter[i_index] = 97 + i_index;
		printf("%2c", ch_letter[i_index]);
	}
	printf("\nBye! \n");
	
	return 0;
}