/* diceroll.c -- 擲骰子模擬程序 */

#include <stdio.h>
#include <stdlib.h>                 /* 提供庫函數 rand() 的原型 */
#include "diceroll.h"               /* 與 manydice.c 一起編譯   */

static int rollem(int i_sides)      /* 該函數屬該文件私有       */
{
    int i_roll;

    i_roll = rand() % i_sides + 1;

    return i_roll;
}

int roll_n_dice(int i_dice, int i_sides)
{
    int i_total, i_count;

    if (i_sides < 2)
    {
        puts("Need at least 2 sides.");
        return -2;
    }
    if (i_dice < 1)
    {
        puts("Need at least 1 die.");
        return -1;
    }

    for (i_count = i_total = 0; i_count < i_dice; i_count++)
        i_total += rollem(i_sides);

    return i_total; 
}
