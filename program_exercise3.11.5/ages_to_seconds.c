/* File: ages_to_seconds.c
 * Author: ByXc
 * About: Age conversion seconds
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_age_seconds = 3.156E+7;
    int i_age;

    printf("Please enter your age: ");
    scanf("%d", &i_age);

    printf("Your age is %d, converted to seconds, about %e seconds. \n", i_age, fl_age_seconds * i_age);

    return 0;
}
