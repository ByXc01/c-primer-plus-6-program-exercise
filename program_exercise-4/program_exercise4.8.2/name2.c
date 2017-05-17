/* File: name2.c
 * Author: ByXc
 * About: name
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char c_name[10];
    char c_last_name[5];
    int i_length1, i_length2;

    printf("Please enter your name: ");
    scanf("%s", c_name);

    printf("Please continue enter your last name: ");
    scanf("%s", c_last_name);

    printf("\"%s, %s\" \n", c_name, c_last_name);
    printf("\"%20s, %20s\" \n", c_name, c_last_name);
    printf("\"%-20s, %-20s\" \n", c_name, c_last_name);

    i_length1 = strlen(c_name) + 3;
    i_length2 = strlen(c_last_name) + 3;

    printf("%*s, %*s \n", i_length1, c_name, i_length2, c_last_name);

    return 0;
}
