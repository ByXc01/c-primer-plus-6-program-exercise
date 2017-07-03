/* File: called_count.c
 * Author: ByXc
 * About: called function count
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170701
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

unsigned int * called(void);
int main(void)
{

    unsigned int * ui_static_blok = called();

    for (int i_index = 0; i_index < 7; i_index++)
        called();
    printf("The called() function was called %d times.\n", *ui_static_blok);

    return 0;
}

unsigned int * called(void)
{
    static unsigned int ui_count;     // 自動初始化為0
    
    ui_count++;
    return &ui_count;
}
