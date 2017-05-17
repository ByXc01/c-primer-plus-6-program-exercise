/* File: print_eof.c
 * Author: ByXc
 * About: print eof, 現在有一個問題是每次回車確認都會當做一個字符輸入
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */


#include <stdio.h>
#include <ctype.h>

#define SPECIAL '\\'
#define CONTROL '^'

int main(void)
{
	int ch_character;
	const short CHD_NUM = 64;

	for (int i_count = 0; (ch_character = getchar()) != EOF ; i_count++)		//如果輸ctrl + d(windows是 ctrl + z)就會直接退出，不顯示字符和編號
	{
		if (iscntrl(ch_character))
			{
				printf("%c%c-%d ", CONTROL, ch_character + CHD_NUM, ch_character);
			}
		else if (isblank(ch_character))				/*本來我是想用isspace()函數的， 不過題目沒要求且我又懶。不過很簡單*/
				{
					if ('\n' == ch_character)
						{
							putchar(SPECIAL);
							putchar('n');
							
						}
					else if ('\t' == ch_character)
						{
							putchar(SPECIAL);
							putchar('t');
						}
					else
							putchar(ch_character);
							
					printf("-%d ", ch_character);
				}
		else 
			printf("%c-%d ", ch_character, ch_character);

		if (10 == i_count % 10)
			putchar('\n');
	}

	return 0;
}
