/* File: rain_pointer.c
 * Author: ByXc
 * About: rain pointer
 * Version: 1.0
 * Compiler: arm-linux-androideabi-gcc 6.1.0
 * Date: 20170515
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

/* rain_pointer.c -- 計算每年的總降水量、年平均降水量和5年中每月的平均降水量 */
#include <stdio.h>

#define YEARS 5				// 一年中的月份
#define MONTHS 12		 // 年數

int main(void)
{
	// 用 2010~2014 年的降水量初始化數組
	const float cflp_rain[YEARS][MONTHS] = 
	{
		{ 4.2, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};

	int i_year, i_month;
	float fl_subtot, fl_total;

	printf (" YEAR         RAINFALL (inches) \n");
	for (i_year = 0; i_year < YEARS; i_year++)
	{
		// 每一年， 個月的降水量總和
		for (i_month = 0, fl_subtot = 0; i_month < MONTHS; i_month++)
			fl_subtot += *(*(cflp_rain + i_year) + i_month);
			
		printf ("%5d %15.1f \n", 2010 + i_year, fl_subtot);
		fl_total += fl_subtot;		// 五年的總降水量
	}
	printf ("\nThe yearly average is %.1f inches. \n\n", fl_total / YEARS);
	printf ("MONTHLY AVERAGES: \n\n");
	printf (" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec \n");

	for (i_month = 0; i_month < MONTHS; i_month++)
	{								// 每個月， 五年的總降水量
		for (i_year = 0, fl_subtot = 0; i_year < YEARS; i_year++)
			fl_subtot += *(*(cflp_rain + i_year) + i_month);
		printf ("%4.1f ", fl_subtot / YEARS);
	}
	printf ("\n");

	return 0;
}
