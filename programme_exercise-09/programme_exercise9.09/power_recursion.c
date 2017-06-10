/* File: power_recursion.c
 * Author: ByXc
 * About: power recursion
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 求正負整數（遞歸版）
 * 感覺學編程吧，是把編程， 數學， 英語一起學。。
 * a^-n = 1 / (a^n)     上網找的公式，算法即出來了
 */

#include <stdio.h>

double judge(double, int);                                  //判斷操作數
double power(double, int);                                  //計算

int main(void)
{
    double db_input, db_results;
    int i_num;
    
    printf("Enter a number and the positive integer power to which \n"
           "the number will be raised. Enter q to quit. \n");
    while (scanf("%lf %d", &db_input, &i_num) == 2)
    {
        db_results = power(db_input, i_num);

        if (0 == db_results)
            printf("Zero zero power undefined! \n");
        else
            printf("%.3g to the power %d is %.5g. \n", db_input, i_num, judge(db_input, i_num));

        printf("Enter next a pair of numbers or q to quit. \n");
    }
    printf("Hope you enjoyed this power trip -- bye! \n");

    return 0;
}

double judge(double db_number, int i_index)
{
    double db_xpower;
    int i_absolut_value;

    if (0 == db_number && 0 == i_index)                             //返回0好判斷， 0的0次冪沒定義
        return 0;
    else if (0 == i_index)                                          //任何數的0次冪都爲1
        return 1;
    else
    {
        i_absolut_value = i_index > 0 ? i_index : -i_index;         //求絕對值
        db_xpower = power(db_number, i_absolut_value);
    }

    if (i_index < 0)
        return 1.0 / db_xpower;                                     //負整數，根據公式進行計算

    return db_xpower;                                               //普通正整數直接返回
}

double power(double db_base, int i_exponted)
{
    double db_power;

    if (i_exponted > 1)                                             //操作次數
        db_power = db_base * power(db_base, i_exponted - 1);
        //return db_base * power(db_base, i_exponted - 1);
    else
        db_power = db_base;
        //return db_base;

    return db_power;
}

/* 對遞歸真的很難理解， 這個power()函數的遞歸我還是
 * 參考程序清單9.7的。 照c primer plus對尾遞歸的定義
 * 我這也算尾遞歸呢。 其實直接return的效率更高
 */
