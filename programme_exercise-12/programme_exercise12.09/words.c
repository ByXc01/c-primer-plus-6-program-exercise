/* File: words.c
 * Author: ByXc
 * About: Dynamic mollocation
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 為 malloc()、free() 和 exit() 提供函數原型， 為 EXIT_FAILURE 提供宏定義
#include <stdbool.h>    // 為 bool、true 和 false 提供宏定義
#define MAX 180         // 最大單詞字符量

void function(void);    // 題目要求編寫一個函數， 但描述的不詳細
int main(void)
{
    function();         // 只好這麼做了。。

    return 0;
}

void function(void)
{
    bool b_one = true;  // 看了一天的題目都不明白， 只好這樣做
    int i_count, i_number;
    char * chp_temp, ** chpp_pointer;

    printf("How many words do you wish to enter? ");
    scanf("%d", &i_number);
    printf("Enter %d words now:\n", i_number);

    chp_temp = (char *) malloc(MAX * sizeof(char));
    chpp_pointer = (char **) malloc(i_number * sizeof(char *));

    if (!chp_temp || !chpp_pointer) // 預防動態內存分配失敗
    {
        puts("Dynamic allocation failed!");
        exit(EXIT_FAILURE);
    }

    for (i_count = 0; i_count < i_number; i_count++)
    {
        scanf("%s", chp_temp);      // 這種情況下最好用 scanf() 因跳過空白符和遇到空白符結束讀取
        if (b_one)
        {
            puts("Here are your words:");
            b_one = false;
        }

        *(chpp_pointer + i_count) = chp_temp;
        puts(*(chpp_pointer + i_count));
    }

    free(chp_temp);
    free(chpp_pointer);
}
