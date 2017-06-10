/* File: triangle.c
 * Author: ByXc
 * About: triangle
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	char ch_input,ch_letter;
	int i_row, i_col, i_temp, i_bey;
	
	scanf("%c", &ch_input);
	for (i_row = 0, ch_letter = 'A'; i_row <= ch_input - 'A'; i_row++, ch_letter++)
	{
		for (i_col = ch_input - 'A' - i_row; i_col > 0; i_col--)
			printf(" ");
		
		for (i_temp = i_row; i_temp >= 0; i_temp--)
			printf("%c", ch_letter - i_temp);
		
		for (i_bey = i_row - 1; i_bey >= 0; i_bey--, i_temp--)
			printf("%c", ch_letter + i_temp);
		printf("\n");
	}
	printf("So beautiful! \n");
	
	return 0;
}

/*
//Byxc -- 如果你的系統不支持ASCII或其他以數字順序編碼的代碼，可以使用此版本
#include <stdio.h>
int main(void)
{
	int i_row, i_col, i_temp, i_bye, i_count;
	char ch_input, ch_letter[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	_Bool B_true;
	
	for (i_count = 0,B_true = scanf("%c", &ch_input); ch_input != ch_letter[i_count] && B_true; i_count++)
		;		//也可以使用continue,因做第六章的練習我用空語句
	for (i_row = 0; i_row <= i_count; i_row++)
	{
		for (i_col = 0; i_col < i_count - i_row; i_col++)
			printf(" ");
		
		for (i_temp = 0; i_temp <= i_row; i_temp++)
			printf("%c", ch_letter[i_temp]);
		
		for (i_bye = i_temp - 2; i_bye >= 0; i_bye--)
			printf("%c", ch_letter[i_bye]);
		printf("\n");
	}
	printf("So beautiful! \n");
	
	return 0;
}
*/