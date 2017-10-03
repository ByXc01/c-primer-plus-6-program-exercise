/* File: pet_club.c
 * Author: ByXc
 * About: use binary search tree
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20171001
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>     /* 為 strchr() 提供函數原型                */
#include <ctype.h>      /* 為 toupper() 和 tolower() 提供函數原型  */
#include "tree.h"       /* 提供函數接口和 Tree、Item 類型          */

char menu(void);
void add_pet(Tree * pointer_tree);
void drop_pet(Tree * pointer_tree);
void show_pets(const Tree * pointer_tree);
void find_pet(const Tree * pt);
void print_item(Item item);
void uppercase(char * string);
char * s_gets(char * string, int number);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a': add_pet(&pets);
                      break;
            case 'l': show_pets(&pets);
                      break;
            case 'f': find_pet(&pets);
                      break;
            case 'n': printf("%d pets in club\n",
                             TreeItemCount(&pets));
                      break;
            case 'd': drop_pet(&pets);
                      break;
            default:  puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye!");

    return 0;
}

char menu(void)
{
    int character;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter correspondind to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((character = getchar()) != EOF)
    {
        while (getchar() != '\n')       /* 處理輸入行的剩餘內容 */
            continue;

        character = tolower(character);
        if (strchr("alnfdq", character) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (character == EOF)               /* 使用程序退出 */
        character = 'q';

    return character;
}

void add_pet(Tree * pointer_tree)
{
    Item temp;

    if (TreeIsFull(pointer_tree))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.pet_name, STRING_LENGTH);
        puts("Please enter pet kind:");
        s_gets(temp.pet_kind, STRING_LENGTH);

        uppercase(temp.pet_name);
        uppercase(temp.pet_kind);
        AddItem(&temp, pointer_tree);
    }
}

void show_pets(const Tree * pointer_tree)
{
    if (TreeIsEmpty(pointer_tree))
        puts("No entries!");
    else
        Traverse(pointer_tree, print_item);
}

void print_item(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.pet_name, item.pet_kind);
}

void find_pet(const Tree * pointer_tree)
{
    Item temp;

    if (TreeIsEmpty(pointer_tree))
    {
        puts("No entries!");
        return;     /* 如果樹為空，則退出函數 */
    }


    puts("Please enter name of pet you wish to find:");
    s_gets(temp.pet_name, STRING_LENGTH);
    //puts("Please enter pet kind:");
    //s_gets(temp.pet_kind, STRING_LENGTH);

    uppercase(temp.pet_name);
    //uppercase(temp.pet_kind);

    //printf("%s the %s ", temp.pet_name, temp.pet_kind);
    if (InTree(&temp, pointer_tree))
        ShowList(&temp, pointer_tree);
        //printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void drop_pet(Tree * pointer_tree)
{
    Item temp;

    if (TreeIsEmpty(pointer_tree))
    {
        puts("No entries!");
        return;     /* 如果树为空，则退出该函数 */
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.pet_name, STRING_LENGTH);
    puts("Please enter pet kind:");
    s_gets(temp.pet_kind, STRING_LENGTH);

    uppercase(temp.pet_name);
    uppercase(temp.pet_kind);

    printf("%s the %s ", temp.pet_name, temp.pet_kind);
    if (DeleteItem(&temp, pointer_tree))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char * string)
{
    while (*string)
    {
        *string = toupper(*string);
        string++;
    }
}

char * s_gets(char * string, int number)
{
    char * return_value;
    char * find;

    return_value = fgets(string, number, stdin);
    if (return_value)
    {
        find = strchr(string, '\n');        /* 查找换行符           */
        if (find)                           /* 如果地址不是 NULL    */
            *find = '\0';                   /* 再此放置一个空字符   */
        else
            while (getchar() != '\n')
                continue;                   /* 处理输入行的剩余内容 */
    }

    return return_value;
}
