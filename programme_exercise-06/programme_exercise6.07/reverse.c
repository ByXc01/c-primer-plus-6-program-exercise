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
#include <string.h>

int main(void)
{
	int i_count;
	char ch_string[40];
	
	printf("Please enter a string:");
	scanf("%s", ch_string);
	
	for (i_count = strlen(ch_string); i_count >= 0; i_count--)
		printf("%c", ch_string[i_count - 1]);        //i_count - 1, 是因为字符串后有一個空字符 \0 (ASCII = 0)
	printf("\nThe all! ");
	
	return 0;
}

/*關於空字符的問題：在minGW,codeblocks, visual studio 2015。輸出的是一個像空格一樣的字符，
在手機c4droid, cide, aide, c4droid toolchain 的gcc5.2.0輸出空字符都是不可見得。。
其他其他編譯器就不清楚了。。  so， 看情況是否使用i_count - 1
*/