/* File: money.c
 * Author: ByXc
 * About: money
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

const float CFL_YEAR_MONEY = 1.0E5;								//每年取走十萬
const float CFL_ANNUAL_INTEREST_RATE = 0.08;					//年利率

int main(void)
{
	double db_money = 1.0E6;									//總餘額
	int i_year;													//年數
	
	for (i_year = 1; db_money > 0; i_year++)
	{
		db_money += db_money * CFL_ANNUAL_INTEREST_RATE;		//餘額 * 年利率 == 利息 + 餘額
		db_money -= CFL_YEAR_MONEY;								//每年餘額-10萬
		//printf("%d %g\n", i_year, db_money);
	}
	printf("\nAfter %d year Chuckie later to take all the money!", --i_year);	//若db_money == 0 则i_year - 2
	
	return 0;
}