/* File: print_string.c
 * Author: ByXc
 * About: print string
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170609
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>         // 提供 strcmp() 的函數原型
#include <ctype.h>          // 提供 toupper() 和 tolower() 的函數原型

#define SIZE 40

int main(int argc, char * argv[])
{
    char cha_string[SIZE];
    int i_count;

    while (fgets(cha_string, SIZE , stdin))                         // 輸入字符串
    {
        if (argc == 1 || strcmp(*(argv + 1), "-p") == 0)            // -p 或 沒有輸入參數則原樣打印
            fputs(cha_string, stdout); 
        else if (strcmp(*(argv + 1), "-u") == 0)                    // 比較命令行參數是否是 -p
        {
            for (i_count = 0; *(cha_string + i_count); i_count++)   // 字符串結尾（即空字符）借宿
                putchar(toupper(*(cha_string + i_count)));          // 輸出大寫字符
        }
        else if (strcmp(*(argv + 1), "-l") == 0)
        {
            for (i_count = 0; *(cha_string + i_count); i_count++)
                putchar(tolower(*(cha_string + i_count)));          // 輸出小寫字符
        }
        else
            printf("Usage: %s [-p | -u | -l]! \n", *argv);
    }
    puts("Bye!");

    return 0;
}

/* 注意一下 24 行的 if(argc == 1 || strcmp(*argv + 1))
 * 邏或兩邊的條件不能互換。 因如果沒有輸入命令行參數，
 * *(argv + 1) 是不確定的， 不能解引用其值。 否則在
 * Unix 會出現"Segmentation fault"(分段錯誤)，這條信息
 * 說明該程序試圖訪問未分配的內存。（自從用了指針，這個
 * 提示經常現）。 然而 argc == 1 這條子表達式若為真，則
 * strcmp(*(argv + 1)) 不會執行， if 表達式為真。
 */
