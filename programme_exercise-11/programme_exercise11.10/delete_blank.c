/* File: delete.c
 * Author: ByXc
 * About: delete string blank
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170605
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>                 // 提供了 strchr() 的函數原型

#define POSTSCRIPT "Please enter a string(empty line to quit):"
#define SIZE 12

void delete_blank(char *);        // 刪除字符串中的空格
void drop_space(char *);          // 標準答案的算法像不一個整體向前移動， 效率可能不太高
char * s_gets(char *, int);       // 不保存換行符和丟棄剩餘輸入

int main(void)
{
    char cha_string[SIZE];
    
    puts(POSTSCRIPT);
    while (s_gets(cha_string, SIZE) && *cha_string != '\0')  // 返回值不為 NULL 且第一個字符不能為回車
    {
        delete_blank(cha_string);
        //drop_space(cha_string);
        puts(cha_string);
        
        puts(POSTSCRIPT);
    }
    puts("Bye!");

    return 0;
}

void delete_blank(char * chp_string)
{
    char * chp_value;

    while (*chp_string)                                     // 即 chp_string != '\0'
    {
        if (*chp_string == 32)                              // 32 是 ASCII 碼表空格標號
        {
            chp_value = chp_string;                         // 記錄第一次出現空格的位置
            while (*++chp_value == 32 && *chp_value)        // 跳過非空格字符且 *chp_value != '\0'
                continue;

            if (*chp_value)                                 // 如果不是空字符即交換
            {
                *chp_string = *chp_value;
                *chp_value = 32;
            }
            else                                            // 說明沒有非空格字符了
                break;                                      // 直接退出
        }
        chp_string++;
    }
    chp_value = strchr(chp_value, 32);                      // 查找交換后的第一個空格地址
    if (chp_value)                                          // 即 chp_value != NULL
        *chp_value = '\0';                                  // 第一個空格設置為空字符, 因為我也不曉得怎麼刪除
}

void drop_space(char * s)
{
    char * pos;

    while (*s)                                              // or while (*s != '\0')
    {
        if (*s == ' ')
        {
            pos = s;
            do
            {
                *pos = *(pos + 1);
                pos++;
            } while (*pos);
        }
        else
            s++;
    }
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value, * chp_value;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)                                   // 即 chp_return_value != NULL
    {
       chp_value = strchr(chp_string, '\n');                // 查找第換行符 
       if (chp_value)                                       // chp_value != NULL
           *chp_value = '\0';                               // 把第一個換行出現的位置替換為空字符
       else                                                 // 沒有找到換行符
           while (getchar() != '\n')                        // 丟棄多餘的輸入
               continue;
    }

    return chp_return_value;
}
