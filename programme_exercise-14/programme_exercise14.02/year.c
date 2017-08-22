/* File: year.c
 * Author: ByXc
 * About: days nubmer 
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170809
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

/* 我寫的代碼有臭又長， 最好把三大塊寫進函數 */
#include <stdio.h>
#include <string.h>     // 為 strcmp() 提供函數原型
#include <ctype.h>      // 為 toupper() 和 tolower() 提供函數原型

#define MONTHS 12

struct year
{
    int i_year;
    char cha_month[10];   // 為了加深記憶 使用了月份名全稱
    int i_day;
};

struct month
{
    char cha_name[10];
    int i_days;
    int i_month_number;
};

void clean(void);

int main(void)
{
    struct month months[12] = 
    {
        { "January", 31, 1 },
        { "February", 28, 2 },
        { "March", 31, 3 },
        { "April", 30, 4 },
        { "May", 31, 5 },
        { "June",30, 6 },
        { "July", 31, 7 },
        { "August", 31, 8 },
        { "September", 30, 9 },
        { "October", 31, 10 },
        { "November", 30, 11 },
        { "December", 31, 12 }
    };
    struct year date;

    int i_index, i_line, i_sum;
    
    puts("Please enter days:");
    while (scanf("%d", &date.i_day) == 1)
    {
        if (date.i_day < 0 || date.i_day > 31)
        {
            puts("Enter error! (1 ~ 31)");
            puts("Try Again!");
            continue;
        }

        puts("Now Enter the name of a month:");
        while (scanf("%9s", date.cha_month) == 1)
        {
            *date.cha_month = toupper(*date.cha_month);             // 第一個字符轉為大寫
            for (i_line = 1; i_line < MONTHS; i_line++)             // 轉為小寫
                date.cha_month[i_line] = tolower(date.cha_month[i_line]);

            for (i_line = 1; i_line < MONTHS; i_line++)
                if (strcmp(date.cha_month, months[i_line].cha_name) == 0)
                {
                    i_index = months[i_line].i_month_number;        // 記錄月份號
                    break;
                }

            if (i_line == MONTHS)
            {
                puts("Enter error, try again!");
                continue;
            }
            else
                break;
        }

        puts("Now enter the year: ");
        while (scanf("%d", &date.i_year) == 1)
        {
            if (date.i_year > 0)
            {
                if ((date.i_year % 4 == 0 && date.i_year % 100 != 0) || date.i_year % 400 == 0)
                    months[1].i_days = 29;                          // 閏年， 雖然題目沒要求
                
                i_sum = 0;
                for (i_line = 1; i_line < i_index; i_line++)
                    i_sum += months[i_line - 1].i_days;             // 累加 i_line - 1 次
                i_sum += date.i_day;                                // 另算的 i_lilne 月的累加
                break;
            } 
            else
                puts("Enter error, try again!");
        }

        printf("There are %d days through %s.\n", i_sum, date.cha_month);

        puts("Next days (q to quit):");
        clean();
    }
    puts("Bye!");

    return 0;
}

void clean(void)
{
    while (getchar() != '\n')
        continue;
}
