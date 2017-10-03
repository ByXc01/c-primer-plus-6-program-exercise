/* File: films.c
 * Author: ByXc
 * About: using an ADT-style linked list, compile with list.c
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170926
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     /* 提供 EXIT_FAILUE 宏 和 exit() 函數原型 */
#include <string.h>     /* 提供 strchr() 函數原型                 */
#include "list.h"       /* 定義 List、Item 和一系列接口函數原型   */

void show_movies(Item item);
char * s_gets(char *, int);
static inline void eat_line(void);

int main(void)
{
    List movies;
    Item temp;

    /* 初始化 */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available! Bye!");
        exit(EXIT_FAILURE);
    }

    /* 獲取用戶輸入并儲存 */
    puts("Enter first movies title:");
    while (s_gets(temp.title, TITLE_SIZE) && *temp.title != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        eat_line();
        
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }

        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        
        puts("Enter next movie title (empty line to stop):");
    }

    /* 顯示 */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, show_movies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    /* 設置項目數為 0 */
    EmptyTheList(&movies);
    printf("Bye!");

    return 0;
}

void show_movies(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value;
    char * chp_find;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)
    {
        chp_find = strchr(chp_string, '\n');        /* 查找換行符           */
        if (chp_find)                               /* 如果地址不是 NULL，  */
            *chp_find = '\0';                       /* 在此處放置一個空字符 */
        else
            eat_line();                             /* 處理輸入行的剩餘內容 */
    }

    return chp_return_value;
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
