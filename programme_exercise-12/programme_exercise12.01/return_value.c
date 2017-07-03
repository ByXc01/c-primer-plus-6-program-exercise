/* File: return_value.c
 * Author: ByXc
 * About: return value
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170626
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

int critic(void);       // 用函數的返回值替換外部變量
int main(void)
{
    int i_input;

    puts("How many pounds to a firkin of butter?");
    scanf("%d", &i_input);

    while (i_input != 56)
        i_input = critic();
    puts("You must have looked it up!");

    return 0;
}

int critic(void)
{
    int i_temp;

    puts("No luck, my friend. Try again.");
    scanf("%d", &i_temp);

    return i_temp;
}
