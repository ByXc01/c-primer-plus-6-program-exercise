/* File: square_sums.c
 * Author: ByXc
 * About: squate sums
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
long square(int i_low, int i_upp);		//ANSI原型
int main(void)
{
	int i_lower, i_upper;
	long l_square_low, l_square_upp;
	
	printf("Enter lower and upper integer limits:");
	while (scanf("%d %d", &i_lower, &i_upper) == 2, i_lower < i_upper)	//因考慮你們還沒學到邏輯運算符&&，這裡我使用了逗號表達式，但輸入類型要符合，否則死循環
	{																	//可是嵌套多一個while loop 用于判斷i_lower!= i_upper使用break 或if,但你們還沒學到。你們要是有更好的方法可以提出來
		l_square_low = i_lower * i_lower;				//本來想在printf()函數直接i_lower * i_lower;
		l_square_upp = i_upper * i_upper;				//可為了程序的可讀性更高使用兩個變量分別存儲兩數的平方
		
		printf("The sums of the suqares from %ld to %ld is %ld \n", l_square_low, 
		l_square_upp, square(i_lower, i_upper));		//函數調用最好賦值給一個long類型變量， 我為讀者演示了另一種直接方法
		
		printf("Enter next set of limit:");
	}
	printf("Done! \n");
	return 0;
}

long square(int i_low, int i_upp)						//函數定義
{
	long l_sum;
	
	for (l_sum = 0L; i_low <= i_upp; i_low++)
		l_sum += ((long) i_low) * i_low;					//把i_low的類型強制轉換成long類型, 確保計數使用的是long類型而不是int類型
	return l_sum;
}

/*
	強制轉換說明
	在int為16位的系統中，兩個int類型值得乘積在返回之前會被截斷
	為一個int類型的值， 這可能丟失數據。
*/

/*也可以这样
	scanf("%d %d", &i_lower, &i_upper);
	
	while (i_lower < i_upper)
	{
		...
		...
		scanf("%d %d", &i_lower, &i_upper);
		...
	}
*/