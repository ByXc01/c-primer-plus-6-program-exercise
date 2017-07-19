/* File: add_word.c
 * Author: ByXc
 * About: Add a number to the number
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170717
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
/*
#include <stdio.h>
#include <stdlib.h>     // 提供 exit() 和 strtol() 原型， 和為 EXIT_FAILURE 提供原型
#include <string.h>     // 提供 strncat() 和 strlen() 原型

#define MAX 50 

int main(void)
{
    FILE * fp_file;
    char cha_words[MAX], cha_temp[MAX];
    char * chp_end; 
    long int l_temp;
    int i_length;

    if ((fp_file = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to teh file; press the #");
    puts("key at the beginning of a line to terminate.");

    rewind(fp_file);                                    // 回到文件開始處
    while (fscanf(fp_file, "%50s", cha_temp) == 1)      // 檢查文件裡的單詞編號，直到最後一行
        continue;

    if((l_temp = strtol(cha_temp, &chp_end, 10)) > 1)   // 將數字字符轉換為數字
        l_temp++;
    else                                                // 表明是新文件
        l_temp = 1;

    while ((fscanf(stdin, "%50s", cha_temp) == 1) && (*cha_temp != '#'))
    {
        sprintf(cha_words, "%lu:", l_temp);             // 格式化字符串
        i_length = MAX - strlen(cha_words);
        strncat(cha_words, cha_temp, i_length - 1);     // 將單詞連接在編號的後面

        fprintf(fp_file, "%s\n", cha_words);
        l_temp++;
    }

    puts("File content:");
    rewind(fp_file);
    while (fscanf(fp_file, "%s", cha_words) == 1)
        puts(cha_words);
    puts("Done!");

    if (ferror(fp_file) != 0)                           // 檢查讀取出錯
        fprintf(stderr, "Error in reading file \"wordy\"\n");
    if (fclose(fp_file) != 0)                           // 檢查關閉文件出錯
        fprintf(stderr, "Error closing file\n");

    return 0;
}
*/

/* 以下為標準答案， 本人人做的太複雜了。走彎路。 */
/* to simplify accounting, stores one number and word per line */

#include <stdio.h>
#include <stdlib.h>

#define MAX 47

int main(void)
{
    FILE * fp_file;
    char cha_words[MAX];
    int i_word_count = 0;

    if ((fp_file = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // determine current number of lines
    rewind(fp_file);
    while (fgets(cha_words, MAX, fp_file) != NULL)
        i_word_count++;         // 數數多少行就行了， 我當時就沒想到
    rewind(fp_file);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    
    while ((fscanf(stdin, "%40s", cha_words) == 1) && (cha_words[0] != '#'))
        fprintf(fp_file, "%3d: %s\n", ++i_word_count, cha_words);       // 這裡我也沒想到 

    puts("File content:");
    rewind(fp_file);            // go back to beginning of line
    while (fgets(cha_words, MAX, fp_file) != NULL)                      // read line including number
        fputs(cha_words, stdout);

    if (fclose(fp_file) != 0)
        fprintf(stderr, "Error closing file.\n");
    puts("Done!");

    return 0;
}
