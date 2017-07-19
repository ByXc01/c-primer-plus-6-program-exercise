/* File: find_string.c
 * Author: ByXc
 * About: find string, print line
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 原型，為 EXIT_FAILURE 提供宏
#include <string.h>     // 提供 strstr() 原型

#define LINE_MAX 255

int main(int argc, char * argv[])
{
    FILE * fp_file;
    char cha_line[LINE_MAX];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [string] [filename]\n", *argv);
        exit(EXIT_FAILURE);
    }

    if ((fp_file = fopen(*(argv + 2), "r")) == NULL)
    {
        fprintf(stderr, "Could not open file \"%s\".\n", *(argv + 2));
        exit(2);
    }

    while (fgets(cha_line, LINE_MAX, fp_file))  // 等價 != NULL
        if (strstr(cha_line, *(argv + 1)))
            fputs(cha_line, stdout);

    if (ferror(fp_file) != 0)                   // 檢查讀取錯誤
        fprintf(stderr, "Error in reading file \"%s\"\n", *(argv + 2));
    if (fclose(fp_file) != 0)                   // 檢查關閉錯誤
        fprintf(stderr, "Error closing file \"%s\"\n", *(argv + 2));

    return 0;
}
