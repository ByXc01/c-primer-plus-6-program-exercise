/* File: manydice.c
 * Author: ByXC
 * About: 與 diceroll.c 一起編譯
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170702
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* manydice.c -- 多次擲骰子模擬程序 */
#include <stdio.h>
#include <stdlib.h>     /* 為庫函數 srand() 提供函數原型*/
#include <time.h>       /* 為 time() 提供函數原型       */
#include "diceroll.h"   /* 為 roll_n_dice() 提供原型 */

int main(void)
{
    int i_dice, i_roll;
    int i_sides, i_status;
    int i_sets, i_count;

    srand((unsigned int) time(0));      /* 隨機種子 */
    puts("Enter the number of sets; enter q to stop.");
    while (scanf("%d", &i_sets) == 1)
    {
        if (i_sets < 1)
        {
            puts("Enter error, try again!(>=1).");
            puts("How many sets? Enter q to stop.");
            continue;
        }

        puts("How many sides and how many dice?");
        if ((i_status = scanf("%d %d", &i_sides, &i_dice)) != 2)
        {
            if (i_status == EOF)
                break;                  /* 退出循環 */
            else
            {
                puts("You should have entered an integer. Let's begin again.");
                while (getchar() != '\n')
                    continue;           /* 處理錯誤的輸入 */
                puts("How many sets? Enter q to stop.");
                continue;               /* 進入循環的下一輪迭代 */
            }
        }

        printf("Here are %2d sets of %2d %2d-sided throws.\n", i_sets, i_dice, i_sides);
        for (i_count = 0; i_count < i_sets; i_count++)
        {
            i_roll = roll_n_dice(i_dice, i_sides);
            printf("%-2d ", i_roll);

            if (i_count % 15 == 14) 
                putchar('\n');
        }
        if (i_count % 15 != 0)
            putchar('\n');
        puts("How many sets? Enter q to stop.");
    }

    return 0;
}
