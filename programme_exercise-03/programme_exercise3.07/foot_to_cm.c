/* File: foot_to_cm.c
 * Author: ByXc
 * About: foot converted centimeter
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_inch_cm = 2.54;
    float fl_fool_inch = 12.0;
    float fl_input;

    printf("Please enter your height(/foot): ");
    scanf("%f", &fl_input);

    printf("Your height is %f cm \n", fl_input * fl_fool_inch * fl_inch_cm);

    return 0;
}
