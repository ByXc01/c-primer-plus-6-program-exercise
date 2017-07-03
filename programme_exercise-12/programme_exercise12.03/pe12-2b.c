/* File: pe12-2b.c
 * Author: ByXc
 * About: book
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170701
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int i_mode, i_last;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &i_mode);

    while (i_mode >= 0)
    {
        if (i_mode == 0 || i_mode == 1)
        {
            i_last = i_mode;
            set_mode(i_mode, i_last);
        }
        else
            set_mode(i_mode, i_last);

        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &i_mode);
    }
    printf("Done!\n");

    return 0;
}
