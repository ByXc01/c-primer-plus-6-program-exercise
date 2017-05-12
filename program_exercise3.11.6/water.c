/* File: water.c
 * Author: ByXc
 * About: quart conversion water
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_water_k = 3.0E-23;
    float fl_quart_k = 950.0;
    float fl_input;
    double db_total;

    printf("Please enter quart: ");
    scanf("%f", &fl_input);

    db_total = fl_input * fl_quart_k * fl_water_k;
    printf("%f quart = %e k water \n", fl_input, db_total);
}
