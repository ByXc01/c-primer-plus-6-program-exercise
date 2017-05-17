/* File: replacement.c
 * Author: ByXc
 * About: replacement . and !
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_character;
	int i_replace_number1, i_replace_number2;
	
	i_replace_number1 = i_replace_number2 = 0;
	
	while ((ch_character = getchar()) != '#')
	{
		switch (ch_character)
		{
			case '.':
				putchar('!');
				i_replace_number1++;
				break;
			case '!':
				printf("!!");
				i_replace_number2++;
				break;
			default:
				putchar(ch_character);
		}
	}
	printf("%d replacement(s) of . with ! \n", i_replace_number1);
	printf("%d replacement(s) of ! with !! \n", i_replace_number2);
	
	return 0;
}	