/* File: balance.c
 * Author: ByXc
 * About: balance
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
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
 * 標準答案。
 */
 
/* per6-16c */
/*
#include <stdio.h>

#define RATE_SIMP 0.10
#define RATE_COMP 0.05
#define INIT_AMT 100.0
 
int main(void)
{
	double daphne = INIT_AMT;
	double deidre = INIT_AMT;
	int years = 0;
	 
	while (deidre <= daphne)
	{
		daphne += RATE_SIMP * INIT_AMT;
		deidre += RATE_COMP * deidre;
		++years;
	}
	printf("Inverstment values after %d years: \n", years);
	printf("Daphne: $%.2f \n", daphne);
	printf("Deidre: $%.2f \n", deidre);
	 
	return 0;
}
*/