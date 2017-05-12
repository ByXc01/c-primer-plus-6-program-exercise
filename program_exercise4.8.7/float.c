/*File: float.c
 * Author: ByXc
 * About: double and float
 * Version: 1.0
 * Compilpation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc
 * Blog: httP://ByXc01.github.io
 */

#include <stdio.h>
#include <float.h>

int main(void)
{
    double db_number = 1.0 / 3.0;
    float fl_number = 1.0 / 3.0;

    printf("double 1.0 / 3.0 results: %f, %.12f, %.16f \n", db_number, db_number, db_number);
    printf("float 1.0 / 3.0 results: %f, %.12f, %.16f \n", fl_number, fl_number, fl_number);

    printf("FLT_DIG = %d, BDL_DIG = %d \n", FLT_DIG, DBL_DIG);

    return 0;
}

/* 在 x64 下測試， FLT_DIG = 6， DBL_DIB = 15。 精度問題.
 * 本人也不是很了解， 可看 IEEE 60559:2011.
 */
