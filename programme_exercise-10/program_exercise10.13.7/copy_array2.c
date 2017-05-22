/* File: copy.c
 * Author: ByXc
 * About: copy Two-dimensional array
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170518
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define ROWS 2
#define COLS 3

void copy_array2(double (*)[COLS], const double (*)[COLS], int );               // 把源數組元素拷貝給目標
void read_array(const double (*)[COLS], int );                                  // 輸出數據

int main(void)
{
    double dbp_source[ROWS][COLS] = 
    { 
        { 1.0, 3.0, 5.0 },
        { 2.0, 4.0, 5.0 }
    };
    double dbp_target[ROWS][COLS];

    printf("This is the source array: \n"); 
    read_array(dbp_source, ROWS);
    putchar('\n');

    printf("This is the target array: \n");
	copy_array2(dbp_target, dbp_source, ROWS);                              // 進行拷貝
    read_array(dbp_target, ROWS);

    return 0;
}

void copy_array2(double (* dbp_array)[COLS], const double (* cdbp_target)[COLS], int i_rows)
{
    int i_row, i_col;

    for (i_row = 0; i_row < i_rows; i_row++)
        for (i_col = 0; i_col < COLS; i_col++)
            *(*(dbp_array + i_row) + i_col) = *(*(cdbp_target + i_row) + i_col);                // 此處本人用的時指針表示法，覺得複雜可自行更改
}

void read_array(const double (* cdbp_array)[COLS], int i_rows)
{
    int i_row, i_col;

    for (i_row = 0; i_row < i_rows; i_row++)
    {
        for (i_col = 0; i_col < COLS; i_col++)
            printf("%2g ", *(*(cdbp_array + i_row) + i_col));                                   // 想要學好指針就得多練，至少本人是這樣認為的。
        putchar('\n');
    }
}
