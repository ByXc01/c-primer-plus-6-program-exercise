/* pe15-3.c */

#include <stdio.h>
#include <limits.h>     // for CHAR_BIT

char * itobs(int number, char * pointer_string);
int on_bits(int);

static const int LENGTH = CHAR_BIT * sizeof(int);

int main(void)
{
    int value;

    char bstr[LENGTH + 1];

    // 此程序有個 bug 但用戶輸入負數的時候，本人做的就沒這個問題
    printf("Enter an integer (q to quit):");
    while (scanf("%d", &value) == 1)
    {
        printf("%d (%s) has %d bit(s) on.\n", value, itobs(value, bstr), on_bits(value));
        printf("Next value: ");
    }
    puts("Done!");

    return 0;
}

char * itobs(int number, char * pointer_string)
{
    int index;
    
    for (index = LENGTH - 1; index >= 0; index--, number >>= 1)
        pointer_string[index] = (01 & number) + '0';
    pointer_string[LENGTH] = '\0';

    return pointer_string;
}

int on_bits(int number)
{
    int count = 0;
    int index;

    for (index = 0; index < LENGTH; index++, number >>= 1)
        if ((1 & number) == 1)
            count++;

    return count;
}
