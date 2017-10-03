/* pe17-7a.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define STRING_LENGTH 81

void print_item(Item item);
char menu(void);
void show_words(const Tree * pointer_tree);
void find_word(const Tree * pointer_tree);
char * s_gets(char * string, int number);
static inline void eat_line(void);

int main(void)
{
    Tree word_count;
    FILE * file_pointer;
    char file_name[STRING_LENGTH];
    char word[STRING_LENGTH];
    Item entry;
    char choice;

    printf("Enter name of file to be processed:\n");
    s_gets(file_name, STRING_LENGTH);

    if ((file_pointer = fopen(file_name, "r")) == 0)
    {
        printf("Can't open file %s. Bye.\n", file_name);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&word_count);

    while (fscanf(file_pointer, "%s", word) == 1 && !TreeIsFull(&word_count))
    {
        strcpy(entry.word, word);
        AddItem(&entry, &word_count);
    }

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 's':   show_words(&word_count);
                        break;
            case 'f':   find_word(&word_count);
                        break;
            default:    puts("Switching error");
        }
    }
    fclose(file_pointer);
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
        find = strchr(string, '\n');        /* look for newline             */
        if (find)                           /* if the address is not NULL   */
            *find = '\0';                   /* place a null character there */
        else
            eat_line();                     /* dispose of rest of line      */
    }


    return return_value;
}

char menu(void)
{
    int character;

    puts("Word counting program");
    puts("Enter the letter corresponding to your choice:");
    puts("s) show word list     f) find a word");
    puts("q) quit");

    while ((character = getchar()) != EOF)
    {
        eat_line();                         /* discard rest of lline          */
        character = tolower(character);
        if (strchr("sfq", character) == NULL)
            puts("Please enter an s, f, or q:");
        else
            break;
    }
    if (character == EOF)                   /* make EOf cause program to quit */
        character = 'q';

    return character;
}

void show_words(const Tree * pointer_tree)
{
    if (TreeIsEmpty(pointer_tree))
        puts("No entries!");
    else
        Traverse(pointer_tree, print_item);
}

void find_word(const Tree * pointer_tree)
{
    char word[STRING_LENGTH];
    Item entry;
    const Item * pointer_item;

    if (TreeIsEmpty(pointer_tree))
    {
        puts("Noe entries!");
        return;         /* quit function if tree is empty */
    }

    printf("Enter the word to find: ");
    scanf("%s", word);
    eat_line();

    strcpy(entry.word, word);
    pointer_item = WhereInTree(&entry, pointer_tree);
    if (pointer_item == NULL)
        printf("%s is not in the list.\n", word);
    else
        printf("%s appears %d times.\n", word, pointer_item->count);
}

void print_item(Item item)
{
    printf("%3d:    %s\n", item.count, item.word);
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
