/* File: pe12-2b.c
 * Author: ByXc
 * About: book
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170627
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int i_mode;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &i_mode);

    while (i_mode >= 0)
    {
        set_mode(i_mode);
        get_info();
        show_info();

        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &i_mode);
    }
    printf("Done!\n");

    return 0;
}
