/* File: echo_eof.c
 * Author: ByXc
 * About: echo eof
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int ch_character, i_character_number = 0;
	
	while ((ch_character = getchar()) != EOF)
		{
			i_character_number++;
			putchar(ch_character);
		}
	printf("Character number is: %d \n", i_character_number);

	return 0;
}