/* File: function_pointer_array.c
 * Auhor: ByXc
 * About: function pointer array
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Data: 20170820
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 這道題做是做出了，但沒有什麼實際意義 */
#include <stdio.h>
#include <string.h>     // 為 strchr() 提供函數原型
#include <ctype.h>      // 為 tolower() 提供函數原型

void menu(void);
char get_let(const char *);
void print1(void);
void print2(void);

int main(void)
{
    char ch_character;
    void (* fp_print[]) (void) = { print1, print2 };

    menu();
    while ((ch_character = get_let("abq")) != 'q')
    {
        switch (ch_character)
        {
            case 'a':
                fp_print[0]();
                break;
            case 'b':
                fp_print[1]();
                break;
        }
        menu();
    }
    puts("Bye!");

    return 0;
}

void menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) How do you look like?");
    puts("b) How handsome are you?");
    puts("q) Quit.");
}

char get_let(const char * cchp_string)
{
    char ch_character;

    ch_character = tolower(getchar());
    while (strchr(cchp_string, ch_character) == NULL)
    {
        printf("Enter a character in the list %s\n", cchp_string);
        while (getchar() != '\n')
            continue;

        ch_character = tolower(getchar());
    }
    while (getchar() != '\n')
        continue;

    return ch_character;
}

void print1(void)
{
    puts("I am handsome!");
}

void print2(void)
{
    puts("Don't you think so?");
}
