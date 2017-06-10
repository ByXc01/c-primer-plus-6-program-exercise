/* File: reverse.c
 * Author: ByXc
 * About: reverse
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>
#define SIZE 255

int main(void)
{
	char ch_string[SIZE];
	int i_index;
	
	printf("Please enter string:");
	scanf("%s", ch_string);
	i_index = strlen(ch_string);
	
	while (--i_index >= 0)				//無語， 又是空字符的問題
		printf("%c", ch_string[i_index]);
	printf("\n");
	
	return 0;
}