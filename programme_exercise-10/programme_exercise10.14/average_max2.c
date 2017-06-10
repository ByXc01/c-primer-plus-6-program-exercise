/* File: average_max2.c
 * Author: ByXc
 * About: 3 * 5 array average and maximum, variable length array version
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170521
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

void input(int, int, double (*)[*]);						  // 輸入函數
double array_5(const double [], int);                         // 返回五個數組內元素的平均值
double array_all(int, int, const double (*)[*]);              // 計算整個二維數組的的平均值
double array_max(int, int, const double (*)[*]);              // 找出整個二維數組的最大值

int main(void)
{
    int i_rows = 3, i_cols = 5;
    int i_r;
    double dba_data[i_rows][i_cols];

	input(i_rows, i_cols, dba_data);						   // 調用輸入函數
	
    for (i_r = 0; i_r < i_rows; i_r++) 
        printf("Group %d average is %3g. \n", i_r + 1, array_5(*(dba_data + i_r), i_cols));      // 將每一維數組入棧
    putchar('\n');

    printf("Average of all data: %g \n", array_all(i_rows, i_cols, dba_data));
    putchar('\n');

    printf("Maximum value of all data is %3g \n", array_max(i_rows, i_cols, dba_data));

    return 0;
}

double array_5(const double * cdbp_array, int i_cols)
{
    int i_index;
    double db_sum;

    for (i_index = db_sum = 0; i_index < i_cols; i_index++)
        db_sum += *(cdbp_array + i_index);
   
    return db_sum / i_cols;                          // 返回平均值
}

double array_all(int i_rows, int i_cols, const double (* cdbp_array)[i_cols])
{
    int i_r, i_c;
    double db_sum;

    for (i_r = db_sum = 0; i_r < i_rows; i_r++)
        for (i_c = 0; i_c < i_cols; i_c++)
            db_sum += *(*(cdbp_array + i_r) + i_c);

    return db_sum / (i_rows * i_cols);                  // 返回所有元素的絕對值
}

double array_max(int i_rows, int i_cols, const double (* cdbp_array)[i_cols])
{
    int i_r, i_c;
    double db_maximum;

    for (i_r = 0, db_maximum = **cdbp_array; i_r < i_rows; i_r++)             // 假設第一個是最大值
    {
        for (i_c = 0; i_c < i_cols; i_c++)
        {
            if (db_maximum < *(*(cdbp_array + i_r) + i_c))                  // 檢測條件是否大於db_maimum
                db_maximum = *(*(cdbp_array + i_r) + i_c);                  // 更新最大值 
        }
    }

    return db_maximum;
}

void input(int i_rows, int i_cols, double (* dbpa_array)[i_cols])
{
	int i_r, i_c;
		
    printf("Please enter 3 groups number, each group containing 5 \'double\' types numbers : \n");
    for (i_r = 0; i_r < i_rows; i_r++)
    {
        printf("Group %d \n", i_r + 1);
        for (i_c = 0; i_c < i_cols; i_c++)
        {
            printf("No: %d: ", i_c + 1);
            scanf("%lf", *(dbpa_array + i_r) + i_c);          // 指針表示法
        }
    }

}