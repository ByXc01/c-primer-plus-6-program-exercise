/* File: menutte.c
 * Author: ByXc
 * About: menutte
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */
 
#include <stdio.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
	int ch_choice;

	while ((ch_choice = get_choice()) != 'q')
		{
			switch(ch_choice)
			{
			case 'a':
				printf("Buy low, sell high. \n");
				break;
			case 'b':
				putchar('\a');		//ANSI
				break;
			case 'c':
				count();
				break;
			default:
				printf("Program error! \n");
				break;
			}
		}
	printf("Bye! \n");
	return 0;
}

void count(void)
{
	int i_n, i_i;

	printf("Count how far? Enter an integer: \n");
	i_n = get_int();

	for (i_i = 1; i_i <= i_n; i_i++)
		printf("%d \n", i_i);

	while (getchar() != '\n')
		continue;
}

char get_choice(void)
{
	int ch;

	printf("Enter the letter of your choice: \n");
	printf("a. advice                b. bell \n");
	printf("c. count                 q. quit\n");

	ch = get_first();
	while ((ch < 'a' ||  ch > 'c') && ch != 'q')
		{
			printf("Please respond with a, b, c, or q. \n");
			ch = get_first();
		}

	return ch;
}

char get_first(void)
{
	char ch;
	while (isspace((ch = getchar())))				//只能這麽做了，暫時想不出其方法
		continue;
	 while (getchar() != '\n')
		continue;
	return ch;
}

int get_int(void)
{
	int i_input;
	char ch;

	while (scanf("%d", &i_input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);                           //處理錯誤輸出
		printf(" is not an integrt. \nPlease enter an ");
		printf("integer value, such as 25, -127, or 3: ");
	}

	return i_input;
}
