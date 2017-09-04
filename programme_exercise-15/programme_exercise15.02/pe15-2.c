/* pe1502.c */
/* 這是參考標準答案的修改該版 */

#include <stdio.h>
#include <stdlib.h>         // for exit()、EXIT_FAILURE
#include <string.h>         // for strlen()
#include <limits.h>         // for CHAR_BIT
#include <stdbool.h>        // for bool、true、false

unsigned int bstr_to_dec(const char * string);
char * itobs(int, char *);
bool check_value(const char * string);

static const size_t LENGTH = CHAR_BIT * sizeof(unsigned int);

int main(int argc, char * argv[])
{
    int value1;
    int value2;
    char bstr[LENGTH + 1];

    if (argc != 3)          // 檢查命令行參數
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 檢查二進制字符串
    if (!check_value(argv[1]) || !check_value(argv[2]))
    {
        puts("A binary number contains just 0s and 1s.");
        exit(2);
    }

    value1 = bstr_to_dec(argv[1]);
    value2 = bstr_to_dec(argv[2]);

    printf("~%s = %s\n", argv[1], itobs(~value1, bstr));
    printf("~%s = %s\n", argv[2], itobs(~value2, bstr));
    printf("%s & %s = %s\n", argv[1], argv[2], itobs(value1 & value2, bstr));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(value1 | value2, bstr));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(value1 ^ value2, bstr));
    puts("Done!");

    return 0;
}

unsigned int bstr_to_dec(const char * string)
{
    int value = 0;

    while (*string)
        value = 2 * value + (*string++ - '0');

    return value;
}

char * itobs(int number, char * ps)
{
    int index;
    
    for (index = LENGTH - 1; index >= 0; index--, number >>= 1)
        ps[index] = (number & 01) + '0';
    ps[LENGTH] = '\0';

    return ps;
}

bool check_value(const char * string)
{
    bool valid = true;

    while (valid && *string)
    {
        if (strlen(string) > LENGTH)
            valid = false;
        if (*string != '0' && *string != '1')
            valid = false;

        string++;
    }

    return valid;
}
