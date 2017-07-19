/* File: copy.c
 * Author: ByXc
 * About: copy file content
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 的原型

int main(int argc, char * argv[])
{
    FILE * fp_input, * fp_output;       // 聲明兩個指向 FILE 的指針
    int i_character;

    // 檢查命令行參數
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s [source filename] [target filename]", *argv);
        exit(EXIT_FAILURE);
    }

    // 設置輸入
    if ((fp_input = fopen(*(argv + 1), "rb")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", *(argv + 1));
        exit(EXIT_FAILURE);
    }

    // 設置輸出
    if ((fp_output = fopen(*(argv + 2), "wb")) == NULL)
    {
        fprintf(stderr, "Can't create ooutput file.\n");
        exit(3);
    }

    // 拷貝數據
    while ((i_character = getc(fp_input)) != EOF)
        putc(i_character, fp_output);

    // 收尾工作
    if (fclose(fp_input) != 0)
        fprintf(stderr, "Could not close file \"%s\"\n", *(argv + 1));
    if (flocse(fp_output) != 0)
        fprintf(stderr, "Could not close file \"%s\"\n", *(argv + 2));

    return 0;
}
