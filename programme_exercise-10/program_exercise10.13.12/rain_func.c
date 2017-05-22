/* File: rain_func.c
 * Author: ByXc
 * About: rain function version
 * Version: 1.0
 * Compilation： gcc 6.3.0 for msys2
 * Date: 20170519
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* rain_func.c -- 計算每年的總降水量、年平均降水量個5年中每月的平均降水量 */
#include <stdio.h>

#define MONTHS 12           // 一年的月份數
#define YEARS  5            // 年數

float year(const float (*)[MONTHS], int);            //  統計每年各月的降水量總和。和五年的總降水量
void month(const float (*)[MONTHS], int);            // 統計每個月， 五年的總降水量

int main(void)
{
    // 用 2010 ~ 2014 年的降水量數據初始化數組
    const float cfla_rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };

    float fl_total;

    printf(" YEARS          RAINFALL (inches) \n");
    fl_total = year(cfla_rain, YEARS);

    printf("The yearly average is %.1f inches. \n\n", fl_total / YEARS);
    printf("MONTHLY AVERAGES: \n\n");

    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec \n");
    month(cfla_rain, YEARS);

    return 0;
}

float year(const float (* cdbp_rain)[MONTHS], int i_years)
{
    int i_row, i_col;
    float fl_subtot, fl_total;

    for (i_row = fl_total = 0; i_row < i_years; i_row++)
    {
        // 每一年， 各月的降水量和
        for (i_col = fl_subtot = 0; i_col < MONTHS; i_col++)
            fl_subtot += *(*(cdbp_rain + i_row) + i_col);

        printf("%5d %15.1f \n", 2010 + i_row, fl_subtot);
        fl_total += fl_subtot;                                          // 五年的總降水量 
    }

    return fl_total;
}


void month(const float (* cdbp_array)[MONTHS], int i_years)
{
    int i_row, i_col;
    float fl_subtot;

    for (i_col = 0; i_col < MONTHS ; i_col++)
    {       // 每個月，五年的降水量
        for (i_row = fl_subtot = 0; i_row < i_years; i_row++)
            fl_subtot += *(*(cdbp_array + i_row) + i_col);

        printf("%4.1f ", fl_subtot / YEARS);
    }
    putchar('\n');
}
