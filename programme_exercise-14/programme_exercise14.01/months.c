/* File: months.c
 * Author: ByXc
 * About: Total number of days in month
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170808
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>                                                 // 提供了 strcmp() 的函數原型
#include <ctype.h>                                                  // 提供了 toupper() 和 tolower() 的函數原型
#include "mode.h"                                                   // 提供結構聲明

#define MAX 10
#define MONTHS 12

extern struct month months[];                                       // 引用外部定義的結構數組

int days(char *, int);

int main(void)
{
    char cha_month[MAX];                                            // namespace 特性， 跟結構的不衝突，但不推薦
    int i_day_total;

    puts("Enter the name of a month: ");
    while (scanf("%9s", cha_month) == 1 && *cha_month != 'q')
    {
        i_day_total = days(cha_month, MONTHS);
        if (i_day_total > 0)
            printf("There are %d days through %s.\n", i_day_total, cha_month);
        else
            fprintf(stderr, "%s is not valid input.\n", cha_month);
        puts("Next month (q to quit): "); 
    }
    puts("Bye!");

    return 0;
}

int days(char * chp_string, int i_number)
{
    int i_index, i_line, i_sum;

    *(chp_string) = toupper(*(chp_string));                         // 開頭第一個字符大寫
    for (i_line = 1; *(chp_string + i_line) != '\0'; i_line++)      // 將字符轉為小寫
        *(chp_string + i_line) = tolower(*(chp_string + i_line));

    for (i_line = 0; i_line < i_number; i_line++)
        if (strcmp(chp_string, months[i_line].cha_name) == 0)       // 比較月份名, 要求全稱
        {
            i_index = months[i_line].i_month_number;
            break;            
        }
    if (i_line == i_number)                                         // 沒有正確輸入月份
        return -1;
    else
    {
        i_sum = 0;
        for (i_line = 0; i_line < i_index; i_line++)                // 計算月份天數
            i_sum += months[i_line].i_days;
    }

    return i_sum;
}
