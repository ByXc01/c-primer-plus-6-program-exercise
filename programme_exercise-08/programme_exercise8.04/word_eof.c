/* File: print_eof.c
 * Author: ByXc
 * About: print eof
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    int i_input;                // 輸入字符
    int i_letter_number = 0;    // 統計單詞字母數
    int i_word_number = 0;      // 統計單詞數
	bool B_true = false;

    while ((i_input = getchar()) != EOF)
    {
        if (!B_true && !(isspace(i_input) || ispunct(i_input)) && isalpha(i_input))
        {
			i_word_number++;
            B_true = true;
        }
		
        if (isalpha(i_input))
            i_letter_number++;
		
		if (B_true && (isspace(i_input) || ispunct(i_input)))
            B_true = false;

    }
    printf("word: %d, letter number: %d \n", i_word_number, i_letter_number);
	printf("The average letter word: %g \n", (double) i_letter_number / i_word_number);

    return 0;
}
