/* pe17-5a.c */

#include <stdio.h>
#include <string.h>
#include "pe17-5.h"

#define STRING_LENGTH 81

char * s_gets(char *, int);
int main(void)
{
    Stack st_character;
    char temp[STRING_LENGTH];
    int index;
    char character;

    InitializeStack(&st_character);
    printf("Eenter a line (an empty line to quit):\n");
    while (s_gets(temp, STRING_LENGTH) && temp[0] != '\0')
    {
        index = 0;
        while (temp[index] != '\0' && !FullStack(&st_character))
            Push(temp[index++], &st_character);

        while (!EmptyStack(&st_character))
        {
            Pop(&character, &st_character);
            putchar(character);
        }
        putchar('\n');
        printf("Enter next line (empty line to quit):\n");
    }
    puts("Done!");

    return 0;
}

char * s_gets(char * string, int number)
{
    char * return_value;
    char * find;

    return_value = fgets(string, number, stdin);
    if (return_value)
    {
        find = strchr(string, '\n');        // look for newline
        if (find)                           // if the address is not NULL,
            *find = '\0';                   // place a null character there
        else
            while (getchar() != '\n')
                continue;                   // dispose of rest of line
    }

    return return_value;
}
