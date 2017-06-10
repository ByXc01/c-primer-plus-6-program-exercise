/* File: strchr_c.c
 * Author: ByXc
 * About: find character
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170604
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define POSTSCRIPT "Enter a string, please.(empty line to quit):"
#define SIZE 12

char * strchr_c(const char *, int);
char * s_gets(char *, int);

int main(void)
{
    char cha_source[SIZE], * chp_value;
    char ch_target;

    puts(POSTSCRIPT);
    while (s_gets(cha_source, SIZE) && *cha_source != '\0')             // 空行結束
    {
        puts("Please enter a character you want to find:");
        ch_target = getchar();
        
        while (getchar() != '\n')                                       // 跳過多餘的輸入
            continue;

        chp_value = strchr_c(cha_source, ch_target);
        if (chp_value)                                                  // 返回值不為空指針
            printf("first character address: %p first target character: %p \n", cha_source,  chp_value);
        else
            puts("Not found!");

        puts(POSTSCRIPT);
    }
    puts("Bye!");

    return 0;
}

char * strchr_c(const char * cchp_string, int i_character)
{
    char * chp_return_value;

    while (*cchp_string)
    {
        if (*cchp_string == i_character)
        {
            chp_return_value = (char *) cchp_string;    // 首次出出現的位置, 要用強制轉換，不然會有警告
            break;
        }
        cchp_string++;                                  // 指向下一個字符
    }

    if (!*cchp_string)                                  // 如果此時 chp_string 指向空字符說明沒有找到
        return NULL;                                    // 返回空指針

    return chp_return_value;
}

char * s_gets(char * chp_pointer, int i_number)
{
    char * chp_return_value;
    char * chp_value;

    chp_return_value = fgets(chp_pointer, i_number, stdin);
    if (chp_return_value)                               // 等價于 chp_value != NULL
    {
       chp_value = strchr_c(chp_pointer, '\n');         // 要善於用函數
       if (chp_value)
           *chp_value = '\0';
       else
           while (getchar() != '\n')                    // 跳過超出輸入的字符 
               continue;
    }

    return chp_return_value;
}
