/* File: invert.c
 * Author: ByXc01
 * About: binary string to decimal
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Data: 20170901
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 推薦使用標準答案， 本人寫的轉換函數相對來說較複雜 */
/*
#include <stdio.h>
#include <string.h>         // 為 strlen() 提供函數原型

int bstod(const char *);

int main(void)
{
    const char * cha_binary = "10101001";
    int i_count = 0;
    
    puts("Binary:");
    while (*(cha_binary + i_count))
    {
        printf("%c", *(cha_binary + i_count));
        if (++i_count % 4 == 0 && *(cha_binary + i_count))      // 四位一組
            printf(" ");
    }
    printf("\nDecimal: %d", bstod(cha_binary));

    return 0;
}

int bstod(const char * chp_string)
{
    int i_index, i_power;
    int i_answer;

    i_power = 1;
    i_answer = 0;

    for (i_index = strlen(chp_string) - 1; i_index >= 0; i_index--)
    {
        i_answer += (i_power * (*(chp_string + i_index) - '0'));        // 利用字符0、1在 ACSII 的順序
        i_power *= 2;
    }

    return i_answer;
}
*/

/* pe-15.c */

#include <stdio.h>
#include <stdbool.h>      // c99 -- otherwise use int
#include <limits.h>       // for CHAR_BIT
#include <string.h>       // for strchr()

int bstr_to_dec(const char * string);
bool check_value(const char * string);
char * s_gets(char * string, int number);

int main(void)
{
    const size_t STRING_LENGTH = CHAR_BIT * sizeof(int) + 1;
    char value[STRING_LENGTH];

    printf("Enter a binary number with up to %zu digits: ", STRING_LENGTH - 1);

    while (s_gets(value, STRING_LENGTH) && value[0] != '\0')
    {
        if (!check_value(value))
            puts("A binary number contains just 0s and 1s.");
        else
            printf("%s is %d\n", value, bstr_to_dec(value));
        puts("ENter next value (empty line to quit):");
    }
    puts("Done!");

    return 0;
}

int bstr_to_dec(const char * string)
{
    int value = 0;

    while (*string)
        value = 2 * value + (*string++ - '0');

    return value;
}

bool check_value(const char * string)
{
    bool valid = true;

    while (valid && *string != '\0')
    {
        if (*string != '0' && *string != '1')
            valid = false;
        ++string;
    }        

    return valid;
}

char * s_gets(char * string, int number)
{
    char * return_value;
    char * find;

    return_value = fgets(string, number, stdin);
    if (return_value)
    {
        find = strchr(string, '\n');        // look for new line
        if (find)                           // if the address is not NULL
            *find = '\0';                   // place a null character there
        else
            while (getchar() != '\n')
                continue;                   // dispose  of rest of line
    }

    return return_value;
}
