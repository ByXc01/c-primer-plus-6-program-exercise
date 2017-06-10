/* File: bubble_sort.c
 * Author: ByXc
 * About: bubble sort
 * Version: 2.0
 * Compiler: arg-linux-androideabi-gcc 6.1.0
 * Date: 20170517
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
 
#include<stdio.h>
#include <stdbool.h>
#define SIZE 5

void sort (double *, int);									// 冒泡排序
void read_array (const double *, int);					    // 輸出數組

int main(void)
{
	double dbp_array[SIZE] = { 3.0, 2.0, 1.0, 5.0, 4.0 };

	printf("Not sorted: \n");
	read_array(dbp_array, SIZE);
	putchar('\n');
	
	printf("After sorting: \n");
	sort (dbp_array, SIZE);
	read_array (dbp_array, SIZE);

	return 0;
}

void sort(double * dbp_array, int i_line)
{
	int i_index, i_count;			// 外層和內層循環數
	double db_max;					// 存儲最大值
	bool b_change = false;

	for (i_index = 0; i_index < i_line - 1; i_index++)				 // 外層循環數i_line - 1
		{
			for (i_count = i_index + 1; i_count < i_line; i_count++) // 內層循環從i_index - 1 ~ i_line, i_index - 1假設最大值或已排好
			{
				if (dbp_array[i_index] < dbp_array[i_count])		 // 如當前數組元素的下一個元素比當前數組元素大
				{
					db_max = dbp_array[i_count];					 // 交換兩元素的值，確保dbp_array是最大值
					dbp_array[i_count] = dbp_array[i_index];
					dbp_array[i_index] = db_max;
					b_change = true;
				}
			}
			if (!b_change)							//  有序數組元素直接退出
				break;
		}
}

void read_array(const double * cdbp_array, int i_line)
{
	int i_index;

	for (i_index = 0; i_index < i_line; i_index++)
		printf ("%3g ", *(cdbp_array + i_index));
	putchar ('\n');
}
