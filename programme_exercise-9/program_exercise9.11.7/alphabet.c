/* File: alphabet.c
 * Author: ByXc
 * About: alphabet
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 此程序能在使用ASCII碼的機器上運行,
 * 如不能正常運行，可用數組進行比較和
 * 計算
*/

#include <stdio.h>
#include <ctype.h>

const short int CHD_UPPCODE = 65;                       //大寫字母在ASCII編碼開始的位置
const short int CHD_LOWCODE = 97;                       //小寫字母在ASCII編碼開始的位置

int letter_number(char);
int main(void)
{
   char ch_character;

   while ((ch_character = getchar()) != EOF)
   {
       while (getchar() != '\n')
           continue;

       printf("%d \n", letter_number(ch_character));
   }
   printf("\nEnd of the program, thank you! \n");

   return 0;
}

int letter_number(char ch_character)
{
    if (isalpha(ch_character))
    {
        if (isupper(ch_character))
            return ch_character - CHD_UPPCODE + 1;      //開始是65所以要加1
        if (islower(ch_character))                      //其實可以直接else
            return ch_character - CHD_LOWCODE + 1;      //開始是97所以要加1
    }

    return -1;                                          //最後處理非字母
}
