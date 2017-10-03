/* File: word_count.c
 * Author: ByXc
 * About: Records how many times each word occurs in the file.
 * Version: 1.0
 * Compile: gcc 6.3.0 for msys2
 * Date: 20170929
 * Github: ByXc01;
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     /* 為 exit() 提供函數, EXIT_FAILURE 宏 */
#include <ctype.h>      /* 為 tolower() 提供函數原型           */
#include <string.h>     /* 為 strchr() 提供函數原型            */
#include "tree.h"       /* 提供 Item、Tree 類型定義            */

void show_word(Item);
void find_word(const Item *, const Tree *);
char get_let(const char *);
static inline void eat_line(void);

int main(void)
{
    FILE  * fp_file;
    Tree tree;
    Item item;
    char ch_letter;

    if ((fp_file = fopen("name.dat", "r")) == NULL)
    {
        fputs("Open file error!", stderr);
        exit(EXIT_FAILURE);
    }

    InitializeTree(&tree);
    while (fscanf(fp_file, "%s", item.word) != EOF)
    {
        if (TreeIsFull(&tree))
        {
            fputs("Tree is full!!\n", stderr);
            break;
        }

        AddItem(&item, &tree);
    }

    if (TreeIsEmpty(&tree))
    {
        fputs("No data entered!!\n", stderr);
        exit(EXIT_FAILURE);
    }


    puts("Type s to show all word, f to find word, q to quit:");
    while ((ch_letter = get_let("sfq")) != 'q')
    {
        if (ch_letter == 's')
            Traverse(&tree, show_word);
        else
        {
            puts("Please enter an word to search for:");
            fscanf(stdin, "%19s", item.word);               // 也可用 s_gets()，我是懶得定義 :)
            eat_line();
            find_word(&item, &tree);
        }
        putchar('\n');
        puts("Type s to show all word, f to find word, q to quit:");
    }
    puts("Bye!");

    fclose(fp_file);
    DeleteAll(&tree);
    
    return 0;
}

void show_word(Item item)
{
    printf("name: %s number: %d\n", item.word, item.count);
}

void find_word(const Item * pointer_item, const Tree * pointer_tree)
{
    if (InTree(pointer_item, pointer_tree))
        printf("name: %s number: %d\n", pointer_item->word, pointer_item->count);
    else
        puts("Not foud!!");
}

char get_let(const char * chp_string)
{
    char ch_character;

    ch_character = tolower(getchar());      // 為了更好的比較，轉換為小寫
    while (strchr(chp_string, ch_character) == NULL)
    {
        printf("Please enter an s, f or q: ");
        eat_line();
        ch_character = tolower(getchar());
    }
    eat_line();

    return ch_character;
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
