/* FIle: bitwise.c
 * Author: ByXc
 * About: bitwise
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170901
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 此程序按位運算后的二進制直接輸出 */
#include <stdio.h>
#include <stdlib.h>     // for exit()、EXIT_FAILURE
#include <stdbool.h>    // for bool、false、true
#include <limits.h>     // for CHAR_BIT
#include <string.h>     // for strlen()

void show_binary(unsigned int);
unsigned int bstr_to_dec(const char *);
bool check_value(const char *);

static const size_t LENGTH = CHAR_BIT * sizeof(unsigned int);

int main(int argc, char * argv[])
{
    unsigned int ui_number1, ui_number2;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [binary] [binary]\n", *argv);
        exit(EXIT_FAILURE);
    }

    if (check_value(*(argv + 1)) && check_value(*(argv + 2)))
    {
        ui_number1 = bstr_to_dec(*(argv + 1));
        ui_number2 = bstr_to_dec(*(argv + 2));

        
        printf("decimal1: %u, decimal2： %u\n", ui_number1, ui_number2);
        puts("decimal1 binary:");
        show_binary(ui_number1);
        puts("decimal2 binary:");
        show_binary(ui_number2);

        puts("\n~decimal1:");
        show_binary(~ui_number1);
        puts("~decimal2:");
        show_binary(~ui_number2);

        puts("\ndecimal1 & decimal2:");
        show_binary(ui_number1 & ui_number2);

        puts("\ndecimal1 | decimal2:");
        show_binary(ui_number1 | ui_number2);

        puts("\ndecimal1 ^ decimal2:");
        show_binary(ui_number1 ^ ui_number2);
    }
    else
    {
        fputs("A binary number contains just 0s and 1s.\n", stderr);
        exit(2);
    }

    return 0;
}

bool check_value(const char * chp_string)
{
    bool valid = true;

    while (valid && *chp_string)
    {
        if (strlen(chp_string) > LENGTH)                // 檢查範圍
            valid = false;
        if (*chp_string != '0' && *chp_string != '1')   // 檢查費0、1字符
            valid = false;

        chp_string++;
    }

    return valid;
}

unsigned int bstr_to_dec(const char * chp_string)
{
    unsigned int ui_value = 0;

    while (*chp_string)
        ui_value = 2 * ui_value + (*(chp_string++) - '0');

    return ui_value;
}

void show_binary(unsigned int ui_binary)
{
    int i_count = 0;

    while (++i_count <= LENGTH) 
    {
        // 從高階位往低階位右移， 右移最好是用無符號，否則結果是未定義。
        putchar((ui_binary >> (LENGTH - i_count) & 01) == 1 ? '1' : '0');
        if (i_count % 4 == 0)         // 四位一組
            putchar(' ');
    }
    putchar('\n');
}
