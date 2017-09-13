/* FIle: main.c
 * Author: ByXc
 * About: 因不想做一個無意義的程序來應付題目，此程序將按姓排序，如果同姓則按名排序。
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170912
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

// ps: 記得要鏈接 name.c
#include <stdio.h>
#include <stdlib.h>         // qsort()
#include "name_st.h"        // for Name、comp()、show_name()

#define SIZE 5 

int main(void)
{
    Name N_names[SIZE] = 
    {
        { "By", "Xc" },
        { "L", "zc" },
        { "By", "zc" },
        { "L", "Xc" },
        { "Xc", "L" }
    };

    puts("Original:");
    show_name(N_names, SIZE);

    qsort(N_names, SIZE, sizeof(Name), comp);
    puts("Sorted:");
    show_name(N_names, SIZE);

    return 0;
}
