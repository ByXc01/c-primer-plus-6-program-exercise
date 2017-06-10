/* File: getchar_c4.c
 * Author: ByXc
 * About: get characters
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170603
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>
#define SIZE 10

char * getchar_c(char *, int);
int main(void)
{
    char cha_string[SIZE];                           // 字符串, 為了輸出方便
    char * chp_value;

    chp_value = getchar_c(cha_string, SIZE - 1);     // 最後一個為空字符
    if (chp_value)                                   // 等價 chp_value != NULL
        printf("string: \"%s\" \n", cha_string);
    else
        puts("Input Error!");

    return 0;
}

char * getchar_c(char * chp_string, int i_number)
{
    char * chp_return_value;
    char ch_input;
    int i_index = 0; 

    while ((ch_input = getchar()) && isspace(ch_input))     		// 跳過第一個非空白字符之前的空白字符 
        continue;
    *(chp_string + i_index) = ch_input;

    while (++i_index < i_number)
    {
        if (ch_input != EOF && i_number != 0)       				// 第一個不能是 EOF
        {
            if ((ch_input = getchar()) && !isspace(ch_input))       // 存入非空白符
                *(chp_string + i_index) = ch_input;
            else                                                    // 空白符直接退出
                break;
            
        }
        else
            return NULL;                            // 直接返回空指針
    }
    *(chp_string + i_index) = '\0';                 // 添加空字符
    chp_return_value = chp_string;

    return chp_return_value;                        // 返回字符串首地址
}
