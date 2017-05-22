/* File: unit_conversion.c
 * Author: ByXc
 * About: unit conversion
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_pint, fl_ounce, fl_cup, fl_spoon, fl_teaspoon;
    
    printf("Please enter the number of cups: ");
    scanf("%f", &fl_cup);

    fl_pint     = fl_cup   / 2.0;
    fl_ounce    = fl_cup   * 8.0; 
    fl_spoon    = fl_ounce * 2.0;
    fl_teaspoon = fl_spoon * 3.0;

    printf("%g cup = %g pint = %g ounce = %g spoon = %g teaspoon \n", fl_cup, fl_pint, fl_ounce, fl_spoon, fl_teaspoon);
}

/* 因為單位可以用小數作精確表示， 如用整形的話結果很容易被截斷 */
