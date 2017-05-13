/* File: triangle.c
 * Author: ByXc
 * About: triangle
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_letter;
	int i_row, i_col;
	
	for (i_row = 1, ch_letter = 'A'; i_row <= 6; i_row++) 
	{
		for (i_col = 0; i_col < i_row; i_col++, ch_letter++)		//其实ch_letter++也可以放在第一个printf()
			printf("%c", ch_letter);
		printf("\n");
	}
	
	return 0;
}

/*
ByXc
如果你的系統不是使用ASCII或其他數字順序編碼的代碼，可以使用此版本
#include <stdio.h>
int main(void)
{
	int i_row, i_col, i_temp;
	char ch_letter[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	i_temp = 0;
	for (i_row = 1; i_row < 7; i_row++)
	{
		for (i_col = 0; i_col < i_row; i_col++)
			printf("%c", ch_letter[i_temp + i_col]);
		i_temp += i_col;
		printf("\n");	
	}
	
	return 0;
}
*/