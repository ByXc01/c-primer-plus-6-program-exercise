/* File: rotate.c
 * Author: ByXc
 * About: rotate bit
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170902
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <limits.h>     // for CHAR_BIT
#include <stdbool.h>    // for bool、true、false

unsigned int rotate(unsigned int, unsigned int);
void show_binary(unsigned int);

static const unsigned int LENGTH = CHAR_BIT * sizeof(unsigned int);

int main(void)
{
    int i_number, i_bit;
    unsigned int ui_value;
    bool b_flag;

    printf("Please enter a integer(negative to quit): "); 
    while (scanf("%d", &i_number) == 1 && i_number > 0)
    {
        do
        {
            b_flag = false;
            printf("Now enter bit(s) (0 ~ %u): ", LENGTH - 1);
            while (scanf("%d", &i_bit) != 1)
            {
                scanf("%*s");
                puts("Please use numerice input!!");
                printf("Now enter bit(s) (0 ~ %u): ", LENGTH - 1);
            }

            if (i_bit < 0 || i_bit > LENGTH - 1)
            {
                puts("Over range!!");
                b_flag = true;
            }

            while (getchar() != '\n')
                continue;

        } while (b_flag);

        ui_value = rotate(i_number, i_bit); 
        printf("%u rotated is %u.\n", i_number, ui_value);

        show_binary(i_number);
        puts("rotated is ");
        show_binary(ui_value);
        printf("Please enter next integer(negative to quit): ");
    }
    puts("Bye!");

    return 0;
}

unsigned int rotate(unsigned int i_number, unsigned int i_bit)
{
    int i_count;
    bool b_temp = 0;                // 节约内存

    for (i_count = 0; i_count < i_bit; i_count++)
    {
        b_temp = i_number >> (LENGTH - 1);
        i_number <<= 1;
        i_number |= b_temp;         // ^= 和 |= 都可以
    }

    return i_number;
}

void show_binary(unsigned int i_number)
{
    int i_count = 1;

    //我是一位一位追加的，效率低、可讀性也差。建議看標準答案
    while (i_count <= LENGTH)
    {
        printf("%d", (i_number >> (LENGTH - i_count)) & 01);
        if (i_count++ % 4 == 0)     // 四位一组
            putchar(' ');
    }
    putchar('\n');
}
