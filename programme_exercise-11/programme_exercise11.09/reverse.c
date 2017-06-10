/* File: reverse.c
 * Author: ByXc
 * About: reverse string
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170605
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>             // 提供 strchr() 的函數原型

#define POSTSCRIPT "Please enter a string(empty line to quit)"
#define SIZE 12

char * reverse(char *);
char * s_gets(char *, int);

int main(void)
{
    char cha_string[SIZE];
    
    puts(POSTSCRIPT);
    while (s_gets(cha_string, SIZE) && *cha_string != '\0')                  // 返回值不為 NULL 且第一個字符不能是回車
    {
        if (reverse(cha_string))                                             // 返回值不為 NULL 基本上沒問題，返回類型弄著玩的
            printf("String reverse: %s \n", cha_string);

        puts(POSTSCRIPT);
    }
    puts("Bye!");

    return 0;
}

char * reverse(char * chp_string)
{
    char ch_temp;
    int i_number, i_count;

    i_number = strlen(chp_string) - 1;                                       // 最後一個位置是空字符，不進行交換
    for (i_count = 0; i_count < (i_number + 1) / 2; i_count++)              // 進行 n / 2 次交換就是倒序了
    {
       ch_temp = *(chp_string + i_count);                                    // 簡單的兩兩交換
       *(chp_string + i_count) = *(chp_string + (i_number - i_count));
       *(chp_string + (i_number  - i_count)) = ch_temp;
    }

    return chp_string;
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value, * chp_value;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)                                                   // 即 chp_return_value != NULL
    {
        chp_value = strchr(chp_string, '\n');
        if (chp_value)
            *chp_value = '\0';                                              // 找到換行符的位置替換為空字符 
        else
            while (getchar() != '\n')                                       // 丟棄剩餘的輸入
                continue;
    }

    return chp_return_value;
}
