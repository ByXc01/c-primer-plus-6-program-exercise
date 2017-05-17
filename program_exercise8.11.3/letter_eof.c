/* File: letter_eof.c
 * Author: ByXc
 * About: letter eof
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 2017051
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch_character;
    int i_capital_letter, i_lowercase_letter;

    i_capital_letter = i_lowercase_letter = 0;

    while ((ch_character = getchar()) != EOF)
    {
        if (isalpha(ch_character))
        {

            if (isupper(ch_character))
                i_capital_letter++;

            if (islower(ch_character))
                i_lowercase_letter++;
        }
        else 										// 在標準答案中其它字符也納入計算了， 因題目沒要求我就沒添加
        {
            if (getchar() != '\n')
               continue;
        }
    }
    printf("capital letter number is %d, lowercase letter number is %d. \n", i_capital_letter, i_lowercase_letter);

    return 0;
}
