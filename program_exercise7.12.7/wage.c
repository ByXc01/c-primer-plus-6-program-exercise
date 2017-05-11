/* File: wage.c
 * Author: ByXc
 * About: wage
 * Version: 2.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */
 
#include <stdio.h>

#define RATE1 0.15                  // <= 300 的稅率
#define RATE2 0.20                  // <= 450 的稅率
#define RATE3 0.25                  // >  450 的稅率

#define BREAK1 300.0                // 稅率的第一個分界
#define BREAK2 450.0                // 稅率的第二個分界

#define OVERTIME_PAY 1.5            // 1.5 倍的加班時間
#define BASIC_SALARY 10.0           // 基本工資/h
#define BASIC_WEEK_HOUR 40          // 基本工作時間

#define BASE1 (BREAK1 * RATE1)      // 總工資為 300 
#define BASE2 (BREAK2 * RATE2)      // 總工資為 450 

int main(void)
{
    double db_total, db_tax, db_wage;                     // 分別是總工資， 稅金和淨收入 
    double db_input_hour;                                 // 輸入時間``

    printf("Please enter the number of hours a week: ");
    scanf("%lf", &db_input_hour);
    
    if (db_input_hour <= BASIC_WEEK_HOUR)
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
        db_total = ((db_input_hour - BASIC_WEEK_HOUR) * OVERTIME_PAY + BASIC_WEEK_HOUR) * BASIC_SALARY;
        db_tax   = (BREAK1 * RATE1) + ((BREAK2 - BREAK1) * RATE2) + ((db_total - BREAK2) * RATE3);
    }

    db_wage = db_total - db_tax;

    printf("Gross salary = %g, tax = %g, income = %g \n", db_total, db_tax, db_wage);

    return 0;
}
