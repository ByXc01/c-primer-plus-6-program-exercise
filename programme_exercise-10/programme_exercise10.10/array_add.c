/* File: array_add.c
 * Author: ByXc
 * About: array addition
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170519
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE 4

void array_add(const int *, const int *, int *, int);                    // 數組加法函數
void show_array(const int *, int);                                       // 輸出數組

int main(void)
{
    int ia_array1[SIZE] = { 2, 4, 5, 8 };
    int ia_array2[SIZE] = { 1, 0, 4, 6 };
    int ia_target[SIZE];

	printf("Array1: \n");
	show_array(ia_array1, SIZE);
	
	printf("Array2: \n");
	show_array(ia_array2, SIZE);

    printf("result: \n");
	array_add(ia_array1, ia_array2, ia_target, SIZE);
    show_array(ia_target, SIZE);

    return 0;
}

void array_add(const int * cip_array1, const int * cip_array2, int * ip_target, int i_cols)
{
    int i_index;

    for (i_index = 0; i_index < i_cols; i_index++)
        *(ip_target + i_index) = *(cip_array1 + i_index) + *(cip_array2 + i_index);             // 指針表示法
}

void show_array(const int * cip_array, int i_cols)
{
    int i_index;
     
    for (i_index = 0; i_index < i_cols; i_index++)
        printf("%3d ", *(cip_array + i_index));
    putchar('\n');
}
