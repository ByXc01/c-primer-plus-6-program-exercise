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
	char ch_character;
	int i_rows, i_cols;
	
	printf("Please enter character, rows, and columns, respectively. Spaces separate: ");
	while (scanf(" %c %d %d", &ch_character, &i_rows, &i_cols) == 3)
	{
		chline(ch_character, i_rows, i_cols);
		printf("Please enter next character, rows, and columns, respectively. Spaces separate:");
	}
	
	return 0;
}

void chline(char ch_character, int i_row, int i_col)
{
	int i_index, i_count;
	
    for (i_count = 0; i_count < i_row; i_count++)
    {
    	for (i_index = 0; i_index < i_col; i_index++)
          putchar(ch_character);
        putchar('\n');
     }
}