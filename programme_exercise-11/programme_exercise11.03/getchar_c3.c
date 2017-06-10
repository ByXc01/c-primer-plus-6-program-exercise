/* File: getchar_c3.c
 * Author: ByXc
 * About: get character
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170603
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>
#define SIZE 12                                                 // 可適當加大長度， 現在只做調試

char * getchar_c(char *);
int main(void)
{
    char cha_string[SIZE]; 
    char * chp_value;
    
    chp_value = getchar_c(cha_string);
    if (chp_value)
        puts(cha_string);
    else
        puts("Input Error!");

    return 0;
}

char * getchar_c(char * chp_pointer)
{
    char * chp_return_value = chp_pointer;
    char ch_input;

    while ((ch_input = getchar()) && isspace(ch_input))           // 跳過字符前的所有空白符
        continue;

    if (ch_input == EOF)
        chp_return_value = NULL;
    else
        *chp_pointer++ = ch_input;                               // 第一個個非空白符

    while ((ch_input = getchar()) && !isspace(ch_input))         // 讀取每一個字符， 遇到空字符結束
        *chp_pointer++ = ch_input;
    *chp_pointer = '\0';                                         // 最後一個位置設置為空字符

    while (getchar() != '\n')                                    // 丟棄剩餘的輸入
        continue;

    return chp_return_value;
}
