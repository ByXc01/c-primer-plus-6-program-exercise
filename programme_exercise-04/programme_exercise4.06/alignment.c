/* File: alignment.c
 * Author: ByXc
 * About: number name alignment
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char c_name[10], c_last_name[5];
    int i_name_number, i_last_name_number;

    printf("Please enter your name: ");
    scanf("%s", c_name);
    
    printf("Please contion enter your last name: ");
    scanf("%s", c_last_name);

    i_name_number = strlen(c_name);
    i_last_name_number   = strlen(c_last_name);

    printf("%s, %s \n", c_name, c_last_name);
    printf("%*d, %*d \n", i_name_number, i_name_number, i_last_name_number, i_last_name_number);
    printf("%s, %s \n", c_name, c_last_name);
    printf("%-*d, %-*d \n", i_name_number, i_name_number, i_last_name_number, i_last_name_number);

    return 0;
}
