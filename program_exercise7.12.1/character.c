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
	char ch_characters;									//用戶輸入的字符
	int i_spaces, i_newlines, i_other_characters;			//分别是空格、回車和其它字符的計數
	i_spaces = i_newlines = i_other_characters = 0;
	
	printf("Please enter string.(# to quit): \n");
	while ((ch_characters = getchar()) != '#')
	{
		if (' ' == ch_characters)
			i_spaces++;
		else if ('\n' == ch_characters)
			i_newlines++;
		else
			i_other_characters++;
	}
	printf("%d space, %d newlin, %d other characters. \n",
			i_spaces, i_newlines, i_other_characters);
	printf("Done! \n");
	
	return 0;
}