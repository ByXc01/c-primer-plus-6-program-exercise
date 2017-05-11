/* 20170511 -- ByXc */
/* compilaton: gcc 6.3.0 for msys2 */

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
