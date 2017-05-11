/* 20170511 -- ByXc */
/* compilation compile: gcc 6.3.0 for msys2 */

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
