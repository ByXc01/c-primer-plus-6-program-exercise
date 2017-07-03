/* File: test_random.c
 * Author: ByXc
 * About: test random number
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170702
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 srand() 和 rand() 的函數原型

#define MAX 100
#define RANGE 10

static short int sia_number[RANGE];     // 自動初始化為0
static void count(unsigned int);
int main(void)
{
    int i_count, i_index;

    for (i_count = 0; i_count < RANGE; i_count++)
    {
        for (i_index = 0; i_index < MAX; i_index++)
        {
            srand((unsigned int) i_count);
            count(rand() % RANGE + 1);
        }
    }

    puts("number count\n");
    for (i_index = 0; i_index < RANGE; i_index++)
        printf("%3d %7d\n", i_index + 1, *(sia_number + i_index));

    return 0;
}

static void count(unsigned int ui_number)
{
   switch (ui_number)
   {
        case 1:
            ++*sia_number;
            break;
        case 2:
            ++*(sia_number + 1);
            break;
        case 3:
            ++*(sia_number + 2);
            break;
        case 4:
            ++*(sia_number + 3);
            break;
        case 5: 
            ++*(sia_number + 4);
            break;
        case 6:
            ++*(sia_number + 5);
            break;
        case 7:
            ++*(sia_number + 6);
            break;
        case 8: 
            ++*(sia_number + 7);
            break;
        case 9:
            ++*(sia_number + 8);
            break;
        case 10:
            ++*(sia_number + 9);
            break;
        default:
            puts("Program Error!");
   }
}
