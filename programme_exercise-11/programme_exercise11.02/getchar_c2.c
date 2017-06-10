/* File: getchar_c2.c
 * Author: ByXc
 * About: get character, blank to quit
 * Version: 2.0
 * Compiler: gcc 6.3.0 for msys2
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
    char chp_string[SIZE], * chp_value;

    chp_value = getchar_c(chp_string, SIZE - 1);
    if (chp_value)                                  // chp_value != NULL
        printf("string: \"%s\" \n", chp_string);
    else
        puts("Not input!");

    return 0;
}


char * getchar_c(char * chp_string, int i_number)
{
    char ch_input;
    char * chp_return_value;
    int i_index;

    for (i_index = 0; i_index < i_number; i_index++)
    {
        ch_input = getchar();
        if (ch_input != EOF && !isspace(ch_input))  // 輸入的字符不能等於 EOF 或空白字符
            *(chp_string + i_index) = ch_input;
        else
        {
            if (ch_input == EOF && i_index == 0)    // 第一位不能是 EOF
                *chp_string = EOF;
            break;
        }
    }
    if (*chp_string == EOF) 
        chp_return_value = NULL;
    else
    {
        *(chp_string + i_index) = '\0';             // 最後一個字符設置為空字符
        chp_return_value = chp_string;
    }
    
    return chp_return_value;
}
