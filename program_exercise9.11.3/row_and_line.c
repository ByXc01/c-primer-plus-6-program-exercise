/* File: row_and_line.c
 * Author: ByXc
 * About: row and line
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
void chline(char, int, int);
int main(void)
{
	chline('@', 6, 2);
	
	return 0;
}

void chline(char ch_character, int i_line, int i_row)
{
	int i_index, i_count;
	
    for (i_count = 0; i_count < i_row; i_count++)
    {
    	for (i_index = 0; i_index < i_line; i_index++)
          putchar(ch_character);
        putchar('\n');
     }
}