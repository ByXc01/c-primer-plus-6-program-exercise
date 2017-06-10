/* File: format.c
 * Author: ByXc01
 * About: format output
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_input;

    scanf("%f", &fl_input);
    printf("%f, %e \n", fl_input, fl_input);

    return 0;
}
