/* File: strings_tool.c
 * Author: ByXc
 * About: strings output
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170608
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>                                         // 提供 strlen() 和 strchr() 的函數原型
#include <ctype.h>                                          // 提供 toupper() 的函數原型

#define SIZE 10
#define LENGTH 40
#define POSTSCRIPT "Please enter your choose:"

void menu (void);				            			    // 菜單
void initialize(char * [], char (*) [LENGTH], int);         // 初始化指針數組
void choose(char (*) [LENGTH], int, char);                  // 選擇
void display_string (char * [], int);	                    // 輸出字符串
void stsrt_sort (char *  [], int);			                // 照 ASCII 碼排序(每個字符串首元素)
void length (char * [], int);					            // 字符串長度
void first_length (char *[], int);							// 第一個字符串的第一個單詞長度
char *s_gets (char *, int);                                 // 丟棄換行符和緩衝區的輸入

int main(void)
{
    char chp_source[SIZE][LENGTH];
    char ch_choose;
    int i_count;

    printf("Please Enter up to %d lines(or end of fine(EOF) to quit): \n", SIZE);
    for (i_count = 0; i_count < SIZE; i_count++)            // 讀取十個字符串
    {
        if (s_gets(*(chp_source + i_count), LENGTH) == NULL)// 遇到 EOF 結束
            break;
    }

	menu();
    puts(POSTSCRIPT);
	ch_choose = getchar();
	ch_choose = toupper(ch_choose);		                    // 轉換為大寫字母

	while (ch_choose != 'Q')
	{
		while (getchar() != '\n')		                    // 丟棄多餘的輸入
			continue;

		if (ch_choose > 'D' || ch_choose < 'A')             // 處理非正確輸入
			puts ("Input Error!");
		else
			choose (chp_source, i_count, ch_choose);

		menu ();
        puts(POSTSCRIPT);
		ch_choose = getchar();
		ch_choose = toupper(ch_choose);
    }
    puts("Bye!");

	return 0;
}

void menu(void)
{
	puts("A): print the origin list of string.");
	puts("B): print the strings in ASCII collating sequence.");
	puts("C): print strings in order of increasing length.");
	puts("D): print the strings in order of the first wrod in the string.");
	puts("Q): quit.");
}

void display_string(char * cchpa_string[], int i_number)
{
	int i_count;

	for (i_count = 0; i_count < i_number; i_count++)
		puts(*(cchpa_string + i_count));                // cchpa_string 是一個存著 const char * 類型指針的數組
}

void choose(char (* chpa_pointer)[LENGTH], int i_number, char ch_letter)        // chpa_strings 是一個指向 char 數組的指針
{
    char * chap_origin[SIZE];                           // chap_origin 是一個存著 char * 類型的指針
    char * chap_stsrt_sort[SIZE];
    char * chap_length[SIZE];
    char * chap_first_length[SIZE];

    switch (ch_letter)
    {
        case 'A':
            initialize(chap_origin, chpa_pointer, i_number);                   // 將源數組指向 char * 的指針賦值給目標指針數組
            display_string(chap_origin, i_number);                             // 直接把原數組的字符串數組
            break;

        case 'B':
			initialize(chap_stsrt_sort, chpa_pointer, i_number);
			stsrt_sort(chap_stsrt_sort, i_number);                            // 需要處理的目標指針數組， 調用對應的函數即可
			display_string(chap_stsrt_sort, i_number);
            break;

        case 'C':
			initialize(chap_length, chpa_pointer, i_number);
			length(chap_length, i_number);
			display_string(chap_length, i_number);
            break;

        case 'D':
			initialize(chap_first_length, chpa_pointer, i_number);
			first_length(chap_first_length, i_number);
			display_string(chap_first_length, i_number);
            break;

        default:
            puts("Program Error!");
            break;
    }

}

void initialize(char * chpa_target[], char (* chap_source)[LENGTH], int i_number)
{
    int i_count;

    for (i_count = 0; i_count < i_number; i_count++)
       *(chpa_target + i_count) = *(chap_source + i_count);         // 將數組指針指向的值賦給指針數組
}


void stsrt_sort(char * chpa_string[], int i_number)
{
    char * chp_value;
    int i_count, i_index;

    for (i_count = 0; i_count < i_number - 1; i_count++)
    {
        for (i_index = i_count + 1; i_index < i_number; i_index++)
        if (strcmp(*(chpa_string + i_count), *(chpa_string + i_index)) > 0)         // 採用選擇排序法，比較字符串中的首字符
        {
            chp_value = *(chpa_string + i_count);
            *(chpa_string + i_count) = *(chpa_string + i_index);
            *(chpa_string + i_index) = chp_value;
        }
    }
}

void length(char * chp_pointer [], int i_number)
{
	int i_count, i_index;
	char *chp_value;

	for (i_count = 0; i_count < i_number - 1; i_count++)
	{
		for (i_index = i_count + 1; i_index < i_number; i_index++)
		{
			if (strlen(*(chp_pointer + i_count)) < strlen(*(chp_pointer + i_index)))    // 也是選擇排序法， 比較字符串的長度。
			{
				chp_value = *(chp_pointer + i_index);                                   // 較長的在前面
				*(chp_pointer + i_index) = *(chp_pointer + i_count);
				*(chp_pointer + i_count) = chp_value;
			}
		}
	}
}

void first_length(char * chp_pointer[],int i_number)
{
	char * chp_value;
	int i_row, i_line;
	int i_count1, i_count2;

	for (i_row = 0; i_row < i_number - 1; i_row++)
	{
		for (i_line = i_row + 1; i_line < i_number; i_line++)
		{
			for (i_count1 = 0; *(*(chp_pointer + i_row) + i_count1); i_count1++)        // 指針數組的指針指向的值(字符)
				if (*(*(chp_pointer + i_row) + i_count1) == 32)                         // 32(ASCII) 表示空格
					break;                                                              // 遇到空格或字符串結尾（空字符）即結束

			for (i_count2 = 0; *(*(chp_pointer + i_line) + i_count2); i_count2++)
				if (*(*(chp_pointer + i_line) + i_count2) == 32)
					break;
			
			if (i_count1 < i_count2)                                                    // 兩個字符串首個單詞（非空格或空字符之前的字符)的長度
			{
				chp_value = *(chp_pointer + i_row);                                     // 交換指針數組的值（char *)， 較長的在前面
				*(chp_pointer + i_row) = *(chp_pointer + i_line);
				*(chp_pointer + i_line) = chp_value;
			}
		}
	}
}

char * s_gets(char * chp_string, int i_number)
{
	char * chp_return_value, * chp_value;

	chp_return_value = fgets(chp_string, i_number, stdin);                             // 返回值是 chp_string 或遇到 EOF 是空指針(NULL)
	if (chp_return_value)                                                                     // 非空指針, chp_string != NULL
	{
		chp_value = strchr(chp_string, '\n');                                      // 查找字符串中首次出現的換行符
		if (chp_value)                                                              // chp_value 不為 NULL 即找到出現的位置
			*chp_value = '\0';                                                      // 將換行符替換為空字符
		else
			while (getchar() != '\n')                                              // 丟棄換行符后的面的輸入
				continue;
	}

	return chp_return_value;
}
