/* File: character.c
 * Author: ByXc
 * About: character
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_character;									//用戶輸入的字符
	int i_space, i_newlin, i_other_character;			//分别是空格、回車和其它字符的計數
	i_space = i_newlin = i_other_character = 0;
	
	printf("Please enter string.(# to quit): \n");
	while ((ch_character = getchar()) != '#')
	{
		if (' ' == ch_character)
			i_space++;
		else if ('\n' == ch_character)
			i_newlin++;
		else
			i_other_character++;
	}
	printf("%d space, %d enter, %d character. \n",
			i_space, i_newlin, i_other_character);
	printf("Done! \n");
	
	return 0;
}