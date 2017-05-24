/* File: copy.c
 * Author: ByXc
 * About: copy source to target
 * Version: 1.0
 * Compilation: gcc 6.1.0 for cide
 * Date: 20170516
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
 
#include <stdio.h>
#define SIZE 5

void copy_array (double[], const double[], int);						// 帶數組表示法拷貝
void copy_pointer (double *, const double *, int);				   // 帶指針表示法拷貝
void copy_pointers (double *, const double *, double *);		   // 帶指針表示法拷貝且傳遞數組最後一個元素的下一個指針
void read_array (const double *, int);

int main(void)
{
	double dbp_source[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };		   // 源數據
	double dbp_target1[SIZE];
	double dbp_target2[SIZE];
	double dbp_target3[SIZE];

	copy_array (dbp_target1, dbp_source, SIZE);
	copy_pointer (dbp_target2, dbp_source, SIZE);
	copy_pointers (dbp_target3, dbp_source, dbp_source + SIZE);

	read_array (dbp_source, SIZE);
	read_array (dbp_target1, SIZE);
	read_array (dbp_target2, SIZE);
	read_array (dbp_target3, SIZE);
	
	return 0;
}

void copy_array(double dbp_target[], const double cdbp_source[], int i_index)
{
	int i_col;

	for (i_col = 0; i_col < i_index; i_col++)
		dbp_target[i_col] = cdbp_source[i_col];				// 數組表示法
}

void copy_pointer (double * dbp_target, const double * cdbp_source, int i_index)
{
	int i_col;

	for (i_col = 0; i_col < i_index; i_col++)
		*(dbp_target + i_col) = *(cdbp_source + i_col);	// 指針表示法
}

void copy_pointers(double * dbp_target, const double * cdbp_source, double * dbp_max)
{
	const double *cdbp_pointer = cdbp_source;
	
	while (cdbp_pointer < dbp_max)
	{
		// 利用幾個 * sizeof (double) 的差進行計算
		*(dbp_target + (int)(cdbp_pointer - cdbp_source)) = *cdbp_pointer;    // 這裡不可用*cdbp_pointer++,未定義序列點問題
		cdbp_pointer++;
	}
}

void read_array(const double * cdbp_array, int i_max)
{
	int i_col;

	for (i_col = 0; i_col < i_max; i_col++)
		printf ("%3.1f ", *(cdbp_array + i_col));						// 學過指針和數組的都應該知道是等價的
	putchar ('\n');
}
