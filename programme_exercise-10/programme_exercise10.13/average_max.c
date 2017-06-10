/* File: average_max.c
 * Author: ByXc
 * About: 3 * 5 array average and maximum
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170521
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5

void input(double [], int);									// 輸入數組
double array_5(const double [], int);                       // 返回五個數組內元素的平均值
double array_all(const double (*)[COLS], int);              // 計算整個二維數組的的平均值
double array_max(const double (*)[COLS], int);              // 找出整個二維數組的最大值

int main(void)
{
    int i_r;
    double dba_data[ROWS][COLS];


    printf("Please enter 3 groups number, each group containing 5 \'double\' types numbers : \n");
    for (i_r = 0; i_r < ROWS; i_r++)
    {
        printf("Group %d \n", i_r + 1);
        input(*(dba_data + i_r), COLS);						// 把二維數組比喻成行和列， 把行壓棧
    }

    putchar('\n');
    for (i_r = 0; i_r < ROWS; i_r++) 
        printf("Group %d average is %3g. \n", i_r + 1, array_5(*(dba_data + i_r), COLS));      // 將每一維數組入棧
    putchar('\n');

    printf("Average of all data: %g \n", array_all(dba_data, ROWS));
    putchar('\n');

    printf("Maximum value of all data is %3g \n", array_max(dba_data, ROWS));

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

double array_all(const double (* cdbp_array)[COLS], int i_rows)
{
    int i_r, i_c;
    double db_sum;

    for (i_r = db_sum = 0; i_r < i_rows; i_r++)
        for (i_c = 0; i_c < COLS; i_c++)
            db_sum += *(*(cdbp_array + i_r) + i_c);

    return db_sum / (ROWS * COLS);                  // 返回所有元素的絕對值
}

double array_max(const double (* cdbp_array)[COLS], int i_rows)
{
    int i_r, i_c;
    double db_maximum;

    for (i_r = 0, db_maximum = **cdbp_array; i_r < ROWS; i_r++)             // 假設第一個是最大值
    {
        for (i_c = 0; i_c < COLS; i_c++)
        {
            if (db_maximum < *(*(cdbp_array + i_r) + i_c))                  // 檢測條件是否大於db_maimum
                db_maximum = *(*(cdbp_array + i_r) + i_c);                  // 更新最大值 
        }
    }

    return db_maximum;
}

void input(double * dbp_array, int i_cols)
{
	int i_index;
	
	for (i_index = 0; i_index < i_cols; i_index++)
    {
            printf("No: %d: ", i_index + 1);
            scanf("%lf", dbp_array + i_index);          // 指針表示法處理每一組數據
    }
}