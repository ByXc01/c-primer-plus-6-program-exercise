/* File: fibonacci.c
 * Author: ByXc
 * About: fibonacci
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 遞歸做的太爛了， 不好意思發出來，
 * 還是自己看看就算了吧。個人感覺
 * 斐波那契數列這樣才好看， 直接給
 * 結果， 沒有過程感覺很乏味. 要是
 * 覺得我的顯示不好， 微改一下就好
 */

#include <stdio.h>

void loop_version(int);	                                				//循環的版本
void recursion_version(unsigned long, unsigned long, int);				//遞歸的版本

int main(void)
{
	int i_number;

	printf("Please enter a number, the program will display the number of the Fibonacci sequence. \n");	
	while (scanf("%d", &i_number))
	{
		if (i_number < 1)
		{
			printf("The number of inputs must be greater than one, otherwise meaningless! \n");
			continue;
		}

		else
		{
			printf("Cycle version recults: \n");
			loop_version(i_number);
			putchar('\n');

			printf("\nrecursion version recults: \n");
			recursion_version(1, 1, i_number);
			putchar('\n');
		}
		printf("Please enter next integer. (Enter a non number program will be quit!) \n");
	}

	printf("Hope you will like this program, goodbye! \n");

	return 0;
}

void loop_version(int i_digit)
{
	unsigned long lu_fl1, lu_fl2, lu_sum;
	int i_count;

	lu_fl1 = lu_fl2 = lu_sum = 1;

	if (1 == i_digit)
	       putchar('1');
	else
	{
		printf("%lu %lu ", lu_fl1, lu_fl2);
		for (i_count = 2; i_count < i_digit; i_count++)				// 大於2開始循環
		{

			lu_sum = lu_fl1 + lu_fl2;
			lu_fl1 = lu_fl2;
			lu_fl2 = lu_sum;

			printf("%lu ", lu_sum);
		}
	}

	return;
}

void recursion_version(unsigned long lu_fl1, unsigned long lu_fl2, int i_digit)
{
	unsigned long lu_sum;						// 遞歸的太爛了，對遞歸還是不太了解，有空我再做一遍。 此版本大家笑話一下就好了 -_-!!

	if (1 == i_digit)
		putchar('1');
	else if (2 == i_digit && 1 == lu_fl1)
		printf("1 1");	
	else if (i_digit > 2)
	{
		if (1 == lu_fl1 && 1 == lu_fl2)
			printf("1 1 ");

		lu_sum = lu_fl1 + lu_fl2;
		lu_fl1 = lu_fl2;
		lu_fl2 = lu_sum;
		
		printf("%lu ", lu_sum);

		if (3 != i_digit)
			recursion_version(lu_fl1, lu_fl2, i_digit - 1);
	}
}
