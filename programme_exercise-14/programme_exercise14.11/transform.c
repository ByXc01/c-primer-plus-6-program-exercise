/* File: transform.c
 * Author: ByXc
 * About: mathematics
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Data: 20170821
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <math.h>                       // 為 cos()、sin() 和 tan() 提供函數原型

#define PI 3.1415926535                 // π
#define MAX 5                           // 題目要求使用 math.h 的兩個函數和自定義兩個函數。我使用了三個 math.h 的函數
#define NUMBER 10                       // 數組的元素個數

// 想了好久都不不知道寫什麼函數好。Ps:小學的英語、數學水平。
double circle_area(double);             // 參數(圓的半徑)，返回圓的面積
double circumference(double);           // 參數(原的半徑)，返回圓的周長
void transform(const double *, double *, int, double (*)(double));
void show(const double *, int);

int main(void)
{
    int i_count;
    double dba_source[NUMBER];
    double dba_target[NUMBER];

    for (i_count = 0; i_count < NUMBER; i_count++)
        dba_source[i_count] = i_count;  // 初始化

    puts("source array:");
    show(dba_source, NUMBER);
    
    // 調用 transform() 四次， 以測試每個函數
    puts("target array, cos:");
    transform(dba_source, dba_target, NUMBER, cos);
    show(dba_target, NUMBER);

    puts("target array, sin:");
    transform(dba_source, dba_target, NUMBER, sin);
    show(dba_target, NUMBER);

    puts("target array, tan:");
    transform(dba_source, dba_target, NUMBER, tan);
    show(dba_target, NUMBER);

    puts("target array, circle area:");
    transform(dba_source, dba_target, NUMBER, circle_area);
    show(dba_target, NUMBER);

    puts("target array, circumference:");
    transform(dba_source, dba_target, NUMBER, circumference);
    show(dba_target, NUMBER);

    puts("The All");
    
    return 0;
}

double circle_area(double db_radius)
{
    return PI * db_radius * db_radius;
}

double circumference(double db_radius)
{
    return PI * db_radius * 2;
}

void transform(const double * cdbp_source, double * dbp_target, int i_limit, double (* fp_function_pointer)(double))
{
    int i_count;

    for (i_count = 0; i_count < i_limit; i_count++)
        dbp_target[i_count] = fp_function_pointer(cdbp_source[i_count]);
}

void show(const double * cdbp_data, int i_limit)
{
    int i_count;

    for (i_count = 0; i_count < i_limit; i_count++)
        printf("%12f ", cdbp_data[i_count]);
    printf("\n\n");
}
