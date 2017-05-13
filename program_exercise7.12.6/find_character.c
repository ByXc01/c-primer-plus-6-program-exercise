/* File: find_character.c
 * Author: ByXc
 * About: find character
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_character, ch_prev;
	int i_number = 0;
	
	ch_prev = 0;				//ASCII code 的0是NULL
	printf("Please enter string. (# to quit): ");
	while ((ch_character = getchar()) != '#')
	{	
		if ('e'== ch_prev && 'i' == ch_character)
			i_number++;
		ch_prev = ch_character;	//保存上一個字符,參考了程序清單7.7
	}
	printf("\'ei\' The character %d times. \n", i_number);
	printf("The end! \n");
	
	return 0;
}