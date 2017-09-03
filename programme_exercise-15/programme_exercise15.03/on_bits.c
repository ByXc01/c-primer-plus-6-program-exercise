/* File: no_bits.c
 * Author: ByXc
 * About: number "no" bits
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170902
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 右移對於無符號類型，用零填充空出的位置;
 * 對於有符號類型，起結果取決于機器。所以
 * 盡量用 unsigned。但題目多次要求用 int。
 * 那說明一個問題可能是指有符號的值。如-1。
 */
#include <stdio.h>
#include <limits.h>     // for CHAR_BIT

int on_bits(int);
void show_binary(int);

int main(void)
{
    int i_input;

    puts("Please enter a integer(negative to quit):");
    while (scanf("%d", &i_input) == 1 && i_input >= 0)
    {
        show_binary(i_input);
        printf("%d has %d bit(s) on.\n", i_input, on_bits(i_input));
        puts("Please enter next integer(negative to quit):");
    }
    puts("Bye!");

    return 0;
}

int on_bits(int i_number)
{
    int sum = 0;

    while (i_number)
    {
        if (i_number & 01)
            sum++;
        i_number >>= 1;
    }

    return sum;
}

void show_binary(int i_number)
{
    int i_count = 1;
    static const size_t LENGTH = CHAR_BIT * sizeof(int);

    while (i_count <= LENGTH)
    {
        printf("%d", (i_number >> (LENGTH - i_count)) & 01);
        if (i_count++ % 4 == 0)
            putchar(' ');
    }
    putchar('\n');
}

