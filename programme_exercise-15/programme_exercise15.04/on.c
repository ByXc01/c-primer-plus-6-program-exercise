/* File: on.c
 * Author: ByXc
 * About: look bit
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170902
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <limits.h>     // for CHAR_BIT
#include <stdbool.h>    // for bool、false、true

bool look_bit(unsigned int, unsigned int);
void show_binary(unsigned int);

static const unsigned int LENGTH = CHAR_BIT * sizeof(unsigned int);

int main(void)
{

    int i_number, i_bit;
    bool b_flag;

    printf("Please enter a integer(negative to quit): ");
    while (scanf("%d", &i_number) == 1 && i_number >= 0)
    {
        do
        {
            b_flag = false;
            printf("Now enter bit(s) (0 ~ %u): ", LENGTH - 1);
            while (scanf("%d", &i_bit) != 1)
            {
                scanf("%*s");
                puts("Please use numeric input!!");
                printf("Now enter bit(s) (0 ~ %u): ", LENGTH - 1);
            }

            if (i_bit < 0 || i_bit > LENGTH - 1)
            {
                printf("Over range!");
                b_flag = true;
            }

            while (getchar() != '\n')
                continue;

        } while (b_flag);

        printf("%d >> %d is %u\n", i_number, i_bit, look_bit(i_number, i_bit));
        show_binary(i_number);
        printf("Please enter next integer(negative to quit): ");
    }
    puts("Bye!");

    return 0;
}

bool look_bit(unsigned int ui_number, unsigned int ui_bit)
{
    unsigned int ui_mask = 01 << ui_bit;

    if ((ui_number & ui_mask) == ui_mask)
        return true;
    else
        return false;
}

void show_binary(unsigned int ui_number)
{
    int i_count = 1;

    while (i_count <= LENGTH)
    {
        printf("%d", (ui_number >> (LENGTH - i_count)) & 01);
        if (i_count++ % 4 == 0)     // 四位一組
            putchar(' ');
    }
    putchar('\n'); 
}
