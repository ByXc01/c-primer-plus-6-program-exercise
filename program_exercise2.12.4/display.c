/* File: diaplay.c
 * Author: ByXc
 * About: display
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Bolg: http://ByXc01.io
 */

#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();

    return 0;
}

void jolly(void)
{
    printf("For he's a jolly good fellow! \n");
}

void deny(void)
{
    printf("Which nobody can deny! \n");
}
