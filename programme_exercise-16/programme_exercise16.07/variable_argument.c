/* File: variable_argument.c
 * Author: ByXc
 * About: variable argument
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170913
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // for malloc()、free()
#include <stdarg.h>     // for va_list、va_start、va_arg、va_end

void show_array(const double array[], int number);
double * new_d_array(int number, ...);

int main(void)
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);

    show_array(p1, 5);
    show_array(p2, 4);

    free(p1);
    free(p2);

    return 0;
}

void show_array(const double array[], int number)
{
    int index;

    for (index = 0; index < number; index++)
    {
        printf("%10.4f ", array[index]);
        if (index % 10 == 9)
            putchar('\n');
    }
    if (index % 10 != 0)
        putchar('\n');
}

double * new_d_array(int number, ...)
{
    va_list list;                                               // 聲明一個對象存參數
    int index;
    double * pointer;

    pointer = (double *) malloc(number * sizeof(double));       // 使用動態內存分配，存儲參數
    va_start(list, number);                                     // 把 list 初始化為參數列表
    
    for (index = 0; index < number; index++)
        pointer[index] = va_arg(list, double);                  // 訪問參數列表中的每一項

    va_end(list);                                               // 清理工作

    return pointer;
}
