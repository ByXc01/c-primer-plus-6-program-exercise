/* File: height.c
 * Author: ByXc
 * About: height
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_height;
    char c_name[10];

    printf("Please input your height(Unit: foot): ");
    scanf("%f", &fl_height);

    printf("Please input your name: ");
    scanf("%s", c_name);

    printf("%s, your are %.3f feet tall \n", c_name, fl_height / 12.0);        // 把英吋轉換英呎

    return 0;
}
