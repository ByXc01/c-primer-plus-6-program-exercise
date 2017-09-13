/* File: delay.c
 * Author: ByXc
 * About: delay.c
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170912
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <time.h>       // for clock_t、clock()、CLOCKS_PER_SEC

int main(void)
{
    double db_time = 0.0;
    clock_t ct_n1, ct_n2;

    ct_n1 = clock();
    for (auto int i_count = 0; i_count < 10000000; i_count++)   // 循環一千萬次
        continue;
    ct_n2 = clock();

    db_time = ((double) ct_n2 - ct_n1) / CLOCKS_PER_SEC;        // 計算循環一千萬次的時間
    printf("delay %f sec\n", db_time); 

    return 0;
}
