/* File: word_count.c
 * Author: ByXc
 * About: word count
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170608
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define POSTSCRIPT "Enter text to be analyzed(EOF to terminate):"

int main(void)
{
	int ch_input;		/* 為消除 warning: comparison of constant -1 with type 'char' is always true [-W tautological-constant-of-rage-compare] */
	int i_word_number, i_uppercase_letter, i_lowercase_letter;
	int i_punctuation, i_digit_number;
	bool b_is_word;
	
	i_word_number = i_uppercase_letter = i_lowercase_letter = 0;
	i_punctuation = i_digit_number = 0;
	b_is_word = false;

	puts (POSTSCRIPT);
	while ((ch_input = getchar()) != EOF)
		{
			if (isalpha (ch_input)) 				 // 字母
			{
				if (isupper (ch_input)) 			 // 大寫字母
					i_uppercase_letter++;
				else 								 // 小寫字母
						i_lowercase_letter++;
			}
			else if (ispunct (ch_input)) 			  // 標點符號
				i_punctuation++;
			else if (isdigit (ch_input)) 			  // 數字字符
				i_digit_number++;

			if (!b_is_word && !isspace (ch_input))    // 單詞
			{
				i_word_number++;
				b_is_word = true;
			}
			else if (b_is_word && isspace (ch_input)) // 空白符
				b_is_word = false;
	}
	printf ("word: %d, uppercase letter: %d, lowercase letter: %d, punction character: %d, digit character: %d \n", 
	i_word_number, i_uppercase_letter, i_lowercase_letter, i_punctuation, i_digit_number);

	return 0;
}
