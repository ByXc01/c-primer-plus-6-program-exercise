/* File: copy_3_to_5.c
 * Author: ByXc
 * About: copy 3 ~ 5 elements
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170518
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define SIZE 7
#define MAX  3

void copy(double *, const double *, int );                  // 拷貝下標為 3 ~ 5 的元素給另一個元素
void display_array(const double *, int );                   // 輸出數組元素

int main(void)
{
    double dbp_source[SIZE] = { 1.0, 7.0, 14.0, 21.0, 28.0, 35.0, 49.0 };
    double dbp_target[MAX] = { 0 };
   
	printf("This is the source array: \n");
	display_array(dbp_source, SIZE);						 //	輸出源數組
	putchar("\n");
   
	printf("This is the tarage array: \n");
    copy(dbp_target, dbp_source + (MAX - 1), MAX);           // 將數組第三個元素的地址入棧
    display_array(dbp_target, MAX);

    return 0;
}

void copy(double * dbp_array, const double * cdbp_source, int i_cols)
{
    int i_index;

    for (i_index = 0; i_index < i_cols; i_index++)
        *(dbp_array + i_index) = *(cdbp_source + i_index);  // 使用指針表示法
}

void display_array(const double * cdbp_array, int i_cols)
{
    int i_index;

    for (i_index = 0; i_index < i_cols; i_index++)
        printf("%2g ", *(cdbp_array + i_index));
    putchar('\n');
}
