/* File: years_to_days.c
 * Author: ByXc
 * About: years to days
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    int i_age;
    int i_days;

    i_age = 17;
    i_days = 17 * 365;

    printf("%d years = %d days \n", i_age, i_days);    // 這裡是不考慮閏年的

    return 0;
}
