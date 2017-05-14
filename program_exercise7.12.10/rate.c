/* File: rate.c
 * Author: ByXc
 * About: 本程序并沒加入既是“戶主”， 又是“已婚，離異”等等這些特殊情況，只能四選一
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>

#define PRINT "Please enter your categories:"

#define BEYOND 0.28
#define BASIC  0.15

#define BREAK1 17850.0
#define BREAK2 23900.0
#define BREAK3 29750.0
#define BREAK4 14875.0

void print(void);
double choice(int i_number);
double scan(void);

int main(void)
{
	int i_enter_number;
	double db_pay_tax;
	
	print();
	while (scanf("%d", &i_enter_number) && i_enter_number != 5)
	{
		db_pay_tax = choice(i_enter_number);
		printf("You should pay tax is %g \n", db_pay_tax);
		
		print();
	}
	printf("Bye! \n");
	
	return 0;
}

void print(void)
{
	for (int i_temp = 0; i_temp < strlen(PRINT); i_temp++)
		printf("* ");
	putchar('\n');
	
	printf("%s \n", PRINT);
	printf("\n1)single                   2)the head of the household");
	printf("\n3)married, a total of      4)married, divorced");
	printf("\n5)quit \n");
	
	for (int i_temp = 0; i_temp < strlen(PRINT); i_temp++)
		printf("* ");
	putchar('\n');
}

double choice(int i_number)
{
	double db_wage, db_tax;
	db_wage = db_tax = 0;
	
	switch (i_number)
	{
		case 1:
			db_wage = scan();
			if (db_wage <= BREAK1)
				db_tax = BASIC * db_wage;
			else
				db_tax = (BASIC * BREAK1) + ((db_wage - BREAK1) * BEYOND);
			break;
		case 2:
			db_wage = scan();
			if (db_wage <= BREAK2)
				db_tax = BASIC * db_wage;
			else
				db_tax = (BASIC * BREAK2) + ((db_wage - BREAK2) * BEYOND);
			break;
		case 3:
			db_wage = scan();
			if (db_wage <= BREAK3)
				db_tax = BASIC * db_wage;
			else
				db_tax = (BASIC * BREAK3) + ((db_wage - BREAK3) * BEYOND);
			break;
		case 4:
			db_wage = scan();
			if (db_wage <= BREAK4)
				db_tax = BASIC * db_wage;
			else
				db_tax = (BASIC * BREAK4) + ((db_wage - BREAK4) * BEYOND);
			break;
		default:
			printf("Enter Error! \n");
			printf("Enter the 1~5 number \n");
	}
	
	return db_tax;
}

double scan(void)
{
	double db_wage_temp;
	
	printf("Please your  wage:");
	scanf("%lf", &db_wage_temp);
	
	return db_wage_temp;
}