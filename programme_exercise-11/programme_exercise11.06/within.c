/* File: within.c
 * Author: ByXc
 * About: find character
 * Version: 1.0
 * Compiler: arm-linux-androideabi-gcc 6.1.0
 * Date: 20170604
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdbool.h>                                            // 為使用 bool
#include <string.h>                                             // 提供 strchr() 的函數原型

#define POSTSCRIPT "Please enter a source string(empty line to quit):"
#define SIZE 12

bool is_within(const char *, int);                             // 用了 bool 而沒有用 _Bool 為了兼容 c++
//bool is_within(const char *, char);                           // 這是標準答案的， 很簡潔
char * s_gets(char *, int);

int main (void)
{
    char cha_source[SIZE];
    char ch_target;

    puts(POSTSCRIPT);
    while (s_gets(cha_source, SIZE) && *cha_source != '\0')     // 返回地址不能是空指針且第一個字符不能是換行符
    {
        puts("Please enter a target character:");
        ch_target = getchar();
        
        while (getchar() != '\n')                               // 丟棄多餘的字符
            continue;

        if (is_within(cha_source, ch_target))                   // 若找到字符
            puts("Is within!");
        else
            puts("Not found!");

        puts(POSTSCRIPT);
    }
    puts("Bye!");

	return 0;
}

bool is_within(const char *cchp_string, int ch_character)
{
	bool b_return_value;

	while (*cchp_string)                        // 即 *cchp_string != '\0'
	{
			if (*cchp_string == ch_character)    // 若找到第一個目標字符立即退出循環
			{
				b_return_value = true;
				break;
			}
			else
				b_return_value = false;
				
			cchp_string++;
	}

	return b_return_value;
}

/*
bool is_within(const char * str, char ch)
{
    while (*str != ch && *str != '\0')
        str++; 
    return *str;                            // = 0 if \0 reached, non-zero otherwise
}
*/

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value, * chp_value;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)                   // 即 chp_return_value != NULL
    {
        chp_value = strchr(chp_string, '\n');
        if (chp_value)
            *chp_value = '\0';              // 找到換行符的位置替換為空字符
        else
            while (getchar() != '\n')
                continue;
    }

    return chp_return_value;
}
