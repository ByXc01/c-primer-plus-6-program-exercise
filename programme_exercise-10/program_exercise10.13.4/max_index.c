/* File: max_index.c
 * Author: ByXc
 * About: elements maximum index
 * Version: 1.0
 * Compilation: gcc 5.1.0 for MinGw
 * Date: 20170517
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE 5

void show_array(const double [], int);			// 輸出數組
int max_index(const double [], int);			// 返回元素最大值的下標

int main(void)
{
	double dbp_array[SIZE] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
	
	show_array(dbp_array, SIZE);
	printf("array maximum elements index is %3d \n", max_index(dbp_array, SIZE));
	
	return 0;
}

int max_index(const double cdbp_array[], int i_line)
{
	int i_index, i_col, i_max;

	i_index = 0;
	i_max = cdbp_array[i_index];							// 假設數組第一個元素是最大值

	for (i_col = 1; i_col < i_line; i_col++)			 	// 從1開始， 因0已賦值給i_max
	{
		if (cdbp_array[i_col] > i_max)						// 遍歷元素是否比i_max大
			{
				i_max = cdbp_array[i_col];					  // 更新最大值
				i_index = i_col;										 // 更新最大值的下標
			}
	}

	return i_index;
}

void show_array(const double cdbp_array[], int i_cols)
{
	int i_index;
	
	for (i_index = 0; i_index < i_cols; i_index++)
		printf("%3g ", *(cdbp_array + i_index));
	putchar('\n');
}