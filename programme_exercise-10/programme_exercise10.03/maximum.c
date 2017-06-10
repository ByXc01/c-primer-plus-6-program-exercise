/* File: maximum.c
 * Author: ByXc
 * About: array elements maximum
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170517
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE 5

int element_maximum(const int [], int);			// 返回數組最大值函數
void show_array(const int *, int);				// 輸出數組

int main(void)
{
	int ip_array[SIZE] = { 1, 3, 5, 7, 9 };	
	
	show_array(ip_array, SIZE);
	printf("array elements maximum is %3d \n", element_maximum(ip_array, SIZE));
	
	return 0;
}

int element_maximum(const int cip_array[], int i_line)
{
	int i_index, i_maximum;
	
	i_index = 0;
	i_maximum = cip_array[i_index];							// 假設最大值為第一個元素
	for (i_index = 1; i_index < i_line; i_index++)			// 從1開始， 因數組0已賦值給i_maximum
	{
		if (cip_array[i_index] > i_maximum)					// 遍歷元素是否比i_maximum大
			i_maximum = cip_array[i_index];					// 更新最大值
	}
	
	return i_maximum;
}

void show_array(const int * ip_array, int i_cols)
{
	int i_index;
	
	for (i_index = 0; i_index < i_cols; i_index++)
		printf("%3d ", *(ip_array + i_index));
	putchar('\n');
}
