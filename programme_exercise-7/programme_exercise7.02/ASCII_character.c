/* File: ASCII_character.c
 * Author: ByXc
 * About: ASCII character and number
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_character;
	int i_count = 0;
	
	while ((ch_character = getchar()) != '#')
	{
		i_count++;
		printf("(%2c %2d) ", ch_character, ch_character);
		
		if (i_count % 8 == 0)
			putchar('\n');
	}
	printf("\nDone! \n");
	
	return 0;
}