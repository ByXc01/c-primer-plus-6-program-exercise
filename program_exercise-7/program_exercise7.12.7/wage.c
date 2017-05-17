/* File: wage.c
 * Author: ByXc
 * About: wage
 * Version: 2.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define RATE1 0.15                  // <= 300 的稅率
#define RATE2 0.20                  // <= 450 的稅率
#define RATE3 0.25                  // >  450 的稅率

#define BREAK1 300.0                // 稅率的第一個分界
#define BREAK2 450.0                // 稅率的第二個分界

#define OVERTIME_PAY 1.5            // 1.5 倍的加班時間
#define BASIC_SALARY 10.0           // 基本工資/h
#define BASIC_WORK_HOUR 40          // 基本工作時間

#define BASE1 (BREAK1 * RATE1)      // 總工資為 300 
#define BASE2 (BREAK2 * RATE2)      // 總工資為 450 

int main(void)
{
    double db_total, db_tax, db_wage;                     // 分別是總工資， 稅金和淨收入 
    double db_input_hour;                                 // 輸入時間``

    printf("Please enter the number of hours a week: ");
    scanf("%lf", &db_input_hour);
    
    if (db_input_hour <= BASIC_WORK_HOUR)
    {
        db_total = db_input_hour * BASIC_SALARY;

        if (db_total <= BREAK1)
            db_tax  = db_total * RATE1;
        else 
            db_tax  = (BREAK1 * RATE1) + ((db_total - BREAK1) * RATE2);

        db_wage = db_total - db_tax;
    }
    else
    {
        db_total = ((db_input_hour - BASIC_WORK_HOUR) * OVERTIME_PAY + BASIC_WORK_HOUR) * BASIC_SALARY;
        db_tax   = (BREAK1 * RATE1) + ((BREAK2 - BREAK1) * RATE2) + ((db_total - BREAK2) * RATE3);
    }

    db_wage = db_total - db_tax;

    printf("Gross salary = %g, tax = %g, income = %g \n", db_total, db_tax, db_wage);

    return 0;
}

/* 推薦標準答案， 本人做的太複雜的 */
// Programming Exercise 7-7
/*
#include <stdio.h>

#define BASEPAY 10 		// $10 per hour
#define BASEHRS 40  	// hours at basepay
#define OVERTIME 1.5 	// 1.5 time

#define AMT1 300 		// 1st rate tier
#define AMT2 150 		// 2st rate tier

#define RATE1 0.15 		// rate for 1st tier
#define RATE2 0.20 		// rate for 2nd tier
#define RATE3 0.25 		// rate for 3rd tier

int main(void)
{
	double hours;
	double gross;
	double net;
	double taxes;
	
	printf("Enter the number of hours worked this week: ");
	scanf("%lf", &hours);
	
	if (hours <= BASEHRS)
		gross = hours * BASEPAY;
	else
		gross = BASEHRS * BASEPAY + (hours - BASEHRS) * BASEPAY * OVERTIME;
	
	if (gross <= AMT1)
		taxes = gross * RATE1;
	else if (gross <= AMT1 + AMT2)
		taxes = AMT1 * RATE1 + (gross - AMT1) * RATE2;
	else
		taxes = AMT1 * RATE1 + AMT2 * RATE2 + (gross - AMT1 - AMT2) * RATE3;
	net = gross - taxes;
	
	printf("gross: $%.2f; taxes: $%.2f; net: $%.2f\n", gross, taxes, net);
	
	return 0;
}
*/