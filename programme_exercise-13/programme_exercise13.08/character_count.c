/* File: character_count.c
 * Author: ByXc
 * About: character statistics in files
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170717
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 原型和 EXIT_FAILURE 宏

#define NAME_MAX 40     // 文件名的最大长度

unsigned long int count(FILE *, char);
int main(int argc, char * argv[])
{
    FILE * fp_file;
    unsigned long int ul_count;
    int i_index;
    char cha_filename[NAME_MAX];

    // 檢查參數 
    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s [character] [filename]...\n", *argv);
        exit(EXIT_FAILURE);
    }

    // 檢查字符後面參數，若沒有則從新輸入
    if (argc < 3)
    {
        puts("Please enter filename:");
        while (scanf("%40s", cha_filename) == 1)
        {
            if ((fp_file = fopen(cha_filename, "r")) == NULL)       // 如果打開失敗則跳過
            {
                fprintf(stderr, "Could not open file \"%s\"\n", cha_filename);
                puts("Please enter next finemae(EOF to quit):");

                continue;
            }

            ul_count = count(fp_file, **(argv + 1));

            if (ferror(fp_file) != 0)                             // 檢查讀取錯誤
                fprintf(stderr, "Error in reading file \"%s\"\n", cha_filename);

            printf("There are %lu \'%c\' characters in the \"%s\" file.\n", ul_count, **(argv + 1), cha_filename);

            if (fclose(fp_file) != 0)                               // 檢查關閉是否成功
                fprintf(stderr, "Could not close file \"%s\"\n", cha_filename);

            puts("Please enter next filename(EOF to quit):");
        }
    }
    else
    {
        // 直接從命令行參數中獲取文件名
        for (i_index = 2; i_index < argc; i_index++)
        {
            if ((fp_file = fopen(*(argv + i_index), "r")) == NULL)
            {
                fprintf(stderr, "Could not open file \"%s\"\n", *(argv + i_index));
                continue;
            }

            ul_count = count(fp_file, **(argv + 1));

            if (ferror(fp_file) != 0)
                fprintf(stderr, "Error in reading file \"%s\"\n", *(argv + i_index));

            printf("There are %lu \'%c\' character in the \"%s\" file.\n", ul_count, **(argv + 1), *(argv + i_index));

            if (fclose(fp_file) != 0)
                fprintf(stderr, "Could not close file \"%s\"\n", *(argv + i_index));
        }
    }
    puts("Done!");

    return 0;
}

unsigned long int count(FILE * fp_path, char ch_source)
{
    int i_character;
    unsigned long int ul_count = 0;

    while ((i_character = getc(fp_path)) != EOF)        // 從文件讀取字符
    {
        if (i_character == ch_source)
            ul_count++;
    }
    
    return ul_count;
}
