/* File: balance.c
 * Author: ByXc
 * About: balance
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	const float CFL_PRINCIPAL = 100.0;				//本金
	double single_interest, compound_interest;		//單利息和復合利息
	int i_count_year;								//年數
	
	single_interest = compound_interest = CFL_PRINCIPAL;
	i_count_year = 0;
	do
	{
		++i_count_year;
		single_interest += CFL_PRINCIPAL * (1 + 0.1) - CFL_PRINCIPAL;							//單利息投資：原本金 += 原本金 * 利息
		compound_interest *= 1 + 0.05;															//復合利息投資：餘額本金 += 餘額本金* 利息
		
	}while (single_interest >= compound_interest);
	printf("%d years Deirdre balance = %g beyond Daphne balance = %g \n",
	i_count_year, compound_interest, single_interest);
	return 0;
}

/*推薦此版本， 簡單明了。
  剛開始以為是錯的。
  後來對結果不太滿意，
  一直摸索才做出
  來。此版本有幾個地方做
  很巧妙。（註明：轉載）
 
#include <stdio.h>
#define NUM 100.0
#define SIG 0.1
#define DOU 0.05
int main(void)
{
	double dap = NUM;
	double dei = NUM;
	int list = 0;
	
	do
	{
		dap += NUM * SIG;
		dei += dei * DOU;
		list++;
	}while (dap >= dei);
	printf("%d年 Daphe 投资有%.f, Deirdre 投资有%.2f", list, dap, dei);
	
	return 0;
}
*/