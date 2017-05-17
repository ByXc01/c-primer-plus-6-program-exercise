/* File: notation.c
 * Author: ByXc
 * About: floation notation
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_input;

    printf("Enter a floating-point value: ");
    scanf("%f", &fl_input);

    printf("fixed-point notation: %f \n", fl_input);
    printf("exponential notation: %e \n", fl_input);
    printf("p notation: %a \n", fl_input);

    return 0;
}
