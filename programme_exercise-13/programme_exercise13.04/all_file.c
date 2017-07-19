/* File: all_file.c
 * Author: ByXc
 * About command line argument all file
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 為 eixt() 提供原型，為 EXIT_FAILURE 提供宏

int main(int argc, char * argv[])
{
    FILE * fp_file;
    int i_character;
    int i_count;

    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s filename[s]\n", *argv);
        exit(EXIT_FAILURE);
    }

    for (i_count = 1; i_count < argc; i_count++)
    {
        if ((fp_file = fopen(*(argv + i_count), "r")) == NULL)
        {
            fprintf(stderr, "Could noe open file %s for input.\n", *(argv + i_count));
            continue;   // 繼續嘗試打開下一個文件
        }
        
        printf("%s file content:\n", *(argv + i_count));
        while ((i_character = getc(fp_file)) != EOF)
            putc(i_character, stdout);
        
        if (fclose(fp_file) != 0)
            fprintf(stderr, "Can't close file %s.\n", *(argv + i_count));
    }
    puts("Done!");

    return 0;
}
