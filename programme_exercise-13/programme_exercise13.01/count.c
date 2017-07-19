/* File: count.c
 * Author: ByXc
 * About: read file
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 的原型 
#define SIZE 40         //文件名最大長度 

int main(void)
{
    int i_character;    // 讀取文件時，儲存每個字符的地方
    FILE * fp_file;     // 文件指針 
    char cha_filename[SIZE];
    unsigned long ul_count = 0;

    puts("Please enter filename.");
    scanf("%40s", cha_filename);

    if ((fp_file = fopen(cha_filename, "r")) == NULL)
    {
        printf("Can't open %s.\n", cha_filename);
        exit(EXIT_FAILURE);
    }

    while ((i_character = getc(fp_file)) != EOF)
    {
        putc(i_character, stdout);      // 與 putchar(i_character) 相同
        ul_count++;
    }
    fclose(fp_file);
    printf("File %s has %lu characters\n", cha_filename, ul_count);

    return 0;
}
