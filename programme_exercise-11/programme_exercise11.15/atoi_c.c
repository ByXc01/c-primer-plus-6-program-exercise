/* File: atio_c.c
 * Athor: ByXc
 * About: atio function
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys
 * Date: 20170609
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>          									// 提供 isdigit() 的函數原型

int atoi_c(const char *);   									// 自定義一個 atoi() 函數
int main(int argc, char * argv[])
{
    int i_count, i_temps;   									// 用程序清單 11.32 的程序測試

    if (argc < 2 || (i_temps = atoi_c(*(argv + 1))) < 1)        // 命令行參數不能小於2, 且 i_temps 是正數
        printf("Usage: %s postitive-number \n", *argv);
    else
        for (i_count = 0; i_count < i_temps; i_count++)
            puts("Hello ByXc!");
    puts("Bye!");

    return 0;
}

int atoi_c(const char * chp_string)
{
    int i_number = 0;
    
    while (*chp_string)                                         // *chp_strings != '\0'
    {
        if (isdigit(*chp_string))                               // 檢查是否數字字符
            i_number = i_number * 10 + (*chp_string - 48);      // 乘十小數點右移，數字與字符混合計算，48 是字符零的 ASCII 碼， 非 ASCII 碼不可用
        else                                                    // 非數字字符
        {
            i_number = 0;                                       // 返回值為零 
            break;                                              // 結束
        }
        chp_string++;                                           // 指向下一個字符
    }

    return i_number;
}
