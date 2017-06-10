/* File: copy_vla.c
 * Author: ByXc
 * About: copy variable length array
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170518
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy_vla(int, int, double (*)[*], const double (*)[COLS]);  // 支持變長數組的拷貝函數
void display_array(int, int, const double (*)[*]);                // 支持變長數組的輸出函數

int main(void)
{
    int i_r, i_c;
    i_r = ROWS;
    i_c = COLS;

    double dba_source[ROWS][COLS];                                // 傳統數組
    double dba_target[i_r][i_c];                                  // variable-length array

    for (int i_row = 0; i_row < ROWS; i_row++)                    // 給源數組初始化
        for (int i_col = 0; i_col < COLS; i_col++)
            *(*(dba_source + i_row) + i_col) = i_row * i_col + i_col;

   printf("source arary: \n");
   display_array(ROWS, COLS, dba_source);
   putchar('\n');

   printf("target array: \n");
   copy_vla(ROWS, COLS, dba_target, dba_source);
   display_array(i_r, i_c, dba_target);

   return 0;
}

void copy_vla(int i_rows, int i_cols, double dbp_array[i_rows][i_cols], const double (* cdbp_source)[COLS])
{
    int i_r, i_c;

    for (i_r = 0; i_r < i_rows; i_r++)
        for (i_c = 0; i_c < i_cols; i_c++)
            *(*(dbp_array + i_r) + i_c) = *(*(cdbp_source + i_r) + i_c);            // 進行拷貝
}

void display_array(int i_rows, int i_cols, const double cdbp_array[i_rows][i_cols])
{
    int i_r, i_c;

    for (i_r = 0; i_r < i_rows; i_r++)
    {
        for (i_c = 0; i_c < i_cols; i_c++)
            printf("%2g ", *(*(cdbp_array + i_r) + i_c));                           // 輸出元素
        putchar('\n');
    }
}
