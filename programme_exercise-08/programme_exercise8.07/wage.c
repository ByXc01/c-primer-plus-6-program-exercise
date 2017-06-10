/* File: wage_plus.c
 * Author: ByXc
 * About: wage plus
 * Version: 1.0
 * Compiler: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Blog: http://ByXc01.io
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RATE1 0.15                  // <= 300 的稅率
#define RATE2 0.20                  // <= 450 的稅率
#define RATE3 0.25                  // >  450 的稅率

#define WAGE1 8.75
#define WAGE2 9.33
#define WAGE3 10.0
#define WAGE4 11.20

#define BREAK1 300.0                // 稅率的第一個分界
#define BREAK2 450.0                // 稅率的第二個分界

#define OVERTIME_PAY 1.5            // 1.5 倍的加班時間
#define BASIC_SALARY 10.0           // 基本工資/h
#define BASIC_WORK_HOUR 40          // 基本工作時間

#define BASE1 (BREAK1 * RATE1)      // 總工資為 300
#define BASE2 (BREAK2 * RATE2)      // 總工資為 450

#define PRINT "Enter the number corresponding to the desired pay rate or action:"

void display(void);                      // 輸出菜單函數
void choice(char);                       // 選擇函數
void compute (double, double);					 // 計算函數
double scan (void);

int main(void)
{
	char ch_type;

	display ();
	while ((ch_type = getchar()) && (ch_type != 'q' || ch_type != 'Q'))
	{
						
		while (getchar() != '\n')
			continue;
		
		ch_type = toupper(ch_type);
		if (ch_type < 'A'  || ch_type > 'D')
			{
				printf ("Enter erroe, try again \n");
				continue;
			}
			choice (ch_type);

			display ();
	}
		
	return 0;
}

double scan(void)
{
	double db_week_hour;
	printf ("Please enter week hour: ");
	while (scanf ("%lf", &db_week_hour) == 0)
	{
		while (getchar () != '\n')
			continue;
		printf ("Enter error, try again! \n");
		printf ("Please enter week hour: ");
		continue;
	}
	return db_week_hour;
}
void choice (char ch_type)
{
	double db_hour;

	switch (ch_type)
	{
		case 'A':
			db_hour = scan ();
			compute (db_hour, WAGE1);
			break;
		case 'B':
			db_hour = scan ();
			compute (db_hour, WAGE2);
			break;
		case 'C':
			db_hour = scan ();
			compute (db_hour, WAGE3);
			break;
		case 'D':
			db_hour = scan ();
			compute (db_hour, WAGE4);
			break;
		default:
			printf (" Program error! \n");
			break;
		}
}

void compute (double db_hour, double db_week)
{
	double db_total, db_tax, db_wage;
	
	if (db_hour <= BASIC_WORK_HOUR)
		{
			db_total = db_hour * BASIC_SALARY;

			if (db_total <= BREAK1)
				db_tax = db_total * RATE1;
			else
				db_tax = (BREAK1 * RATE1) + ((db_total - BREAK1) * RATE2);

			db_wage = db_total - db_tax;
		}
	else
		{
			db_total = ((db_hour - BASIC_WORK_HOUR) * OVERTIME_PAY + BASIC_WORK_HOUR) * BASIC_SALARY;
			db_tax = (BREAK1 * RATE1) + ((BREAK2 - BREAK1) * RATE2) + ((db_total - BREAK2) * RATE3);
		}

	db_wage = db_total - db_tax;
	printf ("Gross salary = %g, tax = %g, income = %g \n", db_total, db_tax, db_wage);
	}

	void display (void)
	{
		int i_temp;

		for (i_temp = 0; i_temp < strlen (PRINT); i_temp++)
			putchar ('*');
		putchar ('\n');

		printf ("%s \n", PRINT);
		printf ("A) $8.75/hr                B) $9.33/hr \n");
		printf ("C) $10.10/hr               D) $11.20/hr \n");
		printf ("5) quit \n");

		for (i_temp = 0; i_temp < strlen (PRINT); i_temp++)
			putchar ('*');
		putchar ('\n');
	}
