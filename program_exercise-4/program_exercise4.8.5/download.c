/* File: download.c
 * Author: ByXc01
 * About: Calulates the download time of Mbit / sec files
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    float fl_megabit, fl_download_time, fl_file_size;

    printf("Please input your download speed(Unit: Mb/s): ");
    scanf("%f", &fl_megabit);

    printf("Please input your file size(Unit: MB): ");
    scanf("%f", &fl_file_size);

    fl_download_time = fl_file_size / (fl_megabit / 8.0);             //除以8 是因為它是以兆比特每秒算的。 
    printf("At %.2f megabits per second, a file of %.2f megabypes download in %.2f. \n", fl_megabit, fl_file_size, fl_download_time);

    return 0;
}
