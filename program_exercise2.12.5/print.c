/* File: print.c
 * Author: ByXc
 * About: print
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */

#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
    br();
    printf(", ");
    ic();

    printf("\n");
    ic();

    printf(",\n");
    br();

    return 0;
}

void br(void)
{
    printf("Brazil, Russia");
}

void ic(void)
{
    printf("India, China");
}
