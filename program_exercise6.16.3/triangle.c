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
	int i_row, i_col;
	char ch_letter;
	for (i_row = 1; i_row <= 6; i_row++)
	{
		for (i_col = 0, ch_letter = 70; i_col < i_row; i_col++, ch_letter--)		//ch_letter初始化为70或'F'，前者要求系统使用ASCII编码
			printf("%c", ch_letter);
		printf("\n");
	}
	//printf("Bye! \n");
	return 0;
}

/*
如果你的系統不是使用ASCII或其他數字順序編碼的代碼，可以使用此版本
#include <stdio.h>
#define D_MAX 26
int main(void)
{
	int i_row, i_col;
	char ch_letter[D_MAX + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (i_row = 1; i_row <= 6; i_row++)
	{
		for (i_col = 0; i_col < i_row; i_col++)
			printf("%c", ch_letter[5 - i_col]);
		printf("\n");
	}
	
	return 0;
}
*/