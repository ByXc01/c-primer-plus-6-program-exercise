/* File: array_double.c
 * Aother: ByXc
 * About: array elements double
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170519
 * Github: ByXc01
 * Blog: htpp://ByXc01.giuhub.io
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5

void array_double(int (*)[COLS], int);                        // 數組元素翻倍
void show_array(const int (*)[COLS], int);                    // 輸出數組

int main(void)
{
    int ia_array[ROWS][COLS];

    for (int i_r = 0; i_r < ROWS; i_r++)
        for (int i_c = 0; i_c < COLS; i_c++)
            *(*(ia_array + i_r) + i_c) = i_r * i_c + 1;   	   // 初始化數組

    printf("Origial: \n");
    show_array(ia_array, ROWS);
    putchar('\n');

    printf("Now \n");
    array_double(ia_array, ROWS);
    show_array(ia_array, ROWS);

    return 0;
}

void array_double(int (* ip_array)[COLS], int i_rows)
{
    int i_r, i_c;

    for (i_r = 0; i_r < i_rows; i_r++)
        for (i_c = 0; i_c < COLS; i_c++)
            *(*(ip_array + i_r) + i_c) *= 2;                // 雙倍
}

void show_array(const int (* ip_array)[COLS], int i_rows)
{
    int i_r, i_c;

    for (i_r = 0; i_r < i_rows; i_r++)
    {
        for (i_c = 0; i_c < COLS; i_c++)
            printf("%2d ", *(*(ip_array + i_r) + i_c));
        putchar('\n');
    }
}
