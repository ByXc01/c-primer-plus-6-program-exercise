/* File: name.c
 * Author: ByXc
 * About: print name
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    char c_name[10];
    char c_last_name[5];

    printf("Please enter your name: ");
    scanf("%s", c_name);
    
    printf("Please continue enter your last name: ");
    scanf("%s", c_last_name);

    printf("%s, %s \n", c_name, c_last_name);

    return 0;
}
