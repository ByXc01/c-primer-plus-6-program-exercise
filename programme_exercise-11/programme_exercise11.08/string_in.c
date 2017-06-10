/* File: string_in.c
 * Author: ByXc
 * About: string in
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170605
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>		    // 提供 strchr() 的原型
#include <stdbool.h>	    // 為了使用 bool

#define POSTSCRIPT "Please enter a source string(empty line to quit):"
#define SIZE 12

char * string_in(const char *, const char *);
//char * string_in(const char *, const char *);           // 標準答案在處理源數組長度比目標長度要短即結束， 效率較高
char * s_gets(char *, int);

int main(void)
{
	char cha_source[SIZE], cha_target[SIZE];
	char * chp_value;

    puts(POSTSCRIPT);
	while (s_gets (cha_source, SIZE) && *cha_source != '\0')
	{
        puts("Please enter a target string:");
		if (s_gets (cha_target, SIZE))
		{
				chp_value = string_in(cha_source, cha_target);
				if (chp_value) // chp_value != NULL
					printf("first source string addressv %p first target string address: %p \n", cha_source, chp_value);
				else
					puts ("Not found!");
		}

        puts(POSTSCRIPT);
	}
	puts ("Bye! \n");
	
	return 0;
}

char * string_in(const char * cchp_source, const char * cchp_target)
{
	const char * chp_return_value;
	bool b_first = true;

	while (*cchp_source && *cchp_target)			// 都要檢測到字符串結尾（空字符）
	{
		if (*cchp_source == *cchp_target)
		{
			if (b_first)
			{
				chp_return_value = cchp_source;     // 第一次出現相同字符的位置
				b_first = false;				    // 非第一次出現相同字符就不會重複賦值
			}
			cchp_target++;                          // 相同繼續比較下一字符(指向下一字符地址）
		}
		cchp_source++;
	}

	if (*cchp_target)	                            // 如果目標字符沒有比較到字符結尾，說明還有不同之處
		chp_return_value = NULL;

	return (char *) chp_return_value;
	// 強制類型轉換，const 表示在此函數不會更改其指向的指，若在調用函數嘗試修改該指針指向的值，結果是未定義的
}

/*
char * string_in(const char * s1, const char * s2)
{
    int l2 = strlen(s2);
    int tries;                                // maximum number of comparisons
    int nomatch = 1;                          // set to 0 if match is found

    tries = strlen(s1) + 1 + l2;
    if (tries > 0)
        while ((nomatch = strncmp(s1, s2, l2)) && tries--)
            s1++;
    
    if (nomatch)
        return NULL;
    else
        return (char *) s1;                   // cast const away
}
*/

char * s_gets(char * chp_string, int i_number)
{
	char * chp_return_value;
	char * chp_value;

	chp_return_value = fgets(chp_string, i_number, stdin);
	if (chp_return_value)			// 即 chp_return_value != NULL
	{
		chp_value = strchr(chp_string, '\n');   // 找到換行符出現的位置
		if (chp_value)						    // 即 chp_value != NULL
			*chp_value = '\0';				    // 第一個出現換行符的位置替換為空字符
		else								    // 沒有找到換行符
			while (getchar () != '\n')		    // 丟棄剩餘的字符
				continue;
	}

	return chp_return_value;
}
