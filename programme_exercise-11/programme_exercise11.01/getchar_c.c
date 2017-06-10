/* File: getchar_c.c
 * Author: ByXc
 * About: get character
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170603
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE 10

char * getchar_c(char *, int);                              // 因題目講的不詳細， 我就隨便做了
int main(void)
{
    char chp_string[SIZE], * chp_value;

    chp_value = getchar_c(chp_string, SIZE - 1);            // 最多儲存 9 個字符， 最後一個為空字符
    if (chp_value)                                          // 等價于 chp_value != NULL
        printf("string: \"%s\" \n", chp_string);
    else
        puts("Not input!");

    return 0; 
}

char * getchar_c(char * chp_string, int i_number)
{
    char * chp_return_value, ch_input;
    int i_index;
    
    for (i_index = 0; i_index < i_number; i_index++)
    {
        ch_input = getchar();
        if (ch_input != EOF)                                // 文件結尾即結束
            *(chp_string + i_index) = ch_input;
        else
        {
            if (i_index == 0)                               // 第一位不能是 EOF
                *chp_string = ch_input;
            break;
        }
    }
    if (ch_input == EOF && i_index == 0)
        chp_return_value = NULL;
    else
    {
        *(chp_string + i_index) = '\0';                     // 最後一個設置為空字符
        chp_return_value = chp_string;
    }
    
    return chp_return_value;
}
