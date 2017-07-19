/* File: print_lline_a.c
 * Author: ByXc
 * About: print file line
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 為 exit() 提供原型, 為 EXIT_FAILURE 提供宏

int main(int argc, char * argv[])
{
    FILE * fp_file1, * fp_file2;
    int i_character1, i_character2;

    // 處理參數
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [filename] [filename]\n", *argv);
        exit(EXIT_FAILURE);
    }

    // 嘗試打開文件
    if ((fp_file1 = fopen(*(argv + 1), "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", *(argv + 1));
        exit(2);
    }

    if ((fp_file2 = fopen(*(argv + 2), "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", *(argv + 2));
        exit(2);
    }

    i_character1 = getc(fp_file1);
    i_character2 = getc(fp_file2);

    while (i_character1 != EOF || i_character2 != EOF)
    {
        while (i_character1 != EOF && i_character1 != '\n')      // 讀取字符
        {
            putc(i_character1, stdout);
            i_character1 = getc(fp_file1);
        }
        if (i_character1 != EOF)
        {
            putchar('\n');
            i_character1 = getc(fp_file1); 
        }

        while (i_character2 != EOF && i_character2 != '\n')
        {
            putc(i_character2, stdout);
            i_character2 = getc(fp_file2);
        }
        if (i_character2 != EOF)
        {
            putchar('\n');
            i_character2 = getc(fp_file2);
        }
    }
    puts("Done!");

    if (fclose(fp_file1) != 0)
        fprintf(stderr, "Could not close file %s.\n", *(argv + 1));
    if (fclose(fp_file2) != 0)
        fprintf(stderr, "Could not close file %s.\n", *(argv + 2));

    return 0;
}
