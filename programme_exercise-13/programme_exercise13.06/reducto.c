/* File: reducto.c
 * Author: ByXc
 * About: interactive interface
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170716
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */ 

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 的原型
#include <string.h>     // 提供 strcpy()、strcat() 的原型

#define LENGTH 40

int main(void)
{
    FILE * fp_input, * fp_output;       // 聲明兩個指向 FILE 的指針
    int i_character;
    char cha_target[LENGTH], cha_source[LENGTH];
    int i_count = 0;

    puts("Please enter filename.");
    scanf("%40s", cha_source);

    // 設置輸入
    if ((fp_input = fopen(cha_source, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", cha_source);
        exit(EXIT_FAILURE);
    }

    // 設置輸出
    strncpy(cha_target, cha_source, LENGTH - 5);        // 拷貝文件名
    cha_target[LENGTH - 5] = '\0';
    strcat(cha_target, ".red");                         // 在文件名后添加.red

    if ((fp_output = fopen(cha_target, "w")) == NULL)   // 以寫模式打開文件
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // 拷貝數據
    while ((i_character = getc(fp_input)) != EOF)
    {
        if (i_count++ % 3 == 0)
            putc(i_character, fp_output);               // 打印3個字符的第一個字符
    }

    // 收尾工作
    if (fclose(fp_input) != 0)
        fprintf(stderr, "Could not close file %s.\n", cha_source);
    if (fclose(fp_output) != 0)
        fprintf(stderr, "Could not close file %s.\n", cha_target);

    return 0;
}
