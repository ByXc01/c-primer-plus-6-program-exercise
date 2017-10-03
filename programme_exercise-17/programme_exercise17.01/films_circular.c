/* File: films_circular.c
 * Author: ByXc
 * About: It displays the movie list both in the original order and in reverse order.
 * Version: circular linked list 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170925
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 使用雙向循環列表 (double circular linked list)      */
/* double linked list 是雙向列表，circular linked list */
/* 或 cycle chain 是循環列表。我也不知到哪個才是正確   */

#include <stdio.h>
#include <stdlib.h>     /* 為 malloc() 和 free() 提供函數原型   */
#include <string.h>     /* 為 strcpy() 和 strchr() 提供函數原型 */

#define TITLE_SIZE 45   /* 儲存片名的數組大小                   */

typedef struct film
{
    char title[TITLE_SIZE];
    int rating;
} Film;

typedef struct circular_node
{
    Film item;
    struct circular_node * prev;        /* 前驅指針 */
    struct circular_node * next;        /* 後繼指針 */
} Node;

typedef Node * Circular;

char * s_gets(char *, int);
void original_show(const Circular);
void reverse_show(const Circular);
static inline void eat_line(void);

int main(void)
{
    Circular head = NULL;
    Circular current, prior;
    char cha_input[TITLE_SIZE];

    /* 收集并存儲信息 */
    puts("Enter first movie title:");
    while (s_gets(cha_input, TITLE_SIZE) && *cha_input != '\0')
    {
        current = (Circular) malloc(sizeof (Node));
        if (head == NULL)               /* 第一個節點 */
            head = current;
        else                            /* 後續的節點 */
        {
            prior->next = current;
            current->prev = prior;

        }
        head->prev = current;           /* 頭指針的前驅指針總是指向最後節點 */
        current->next = head;           /* 尾指針的後繼指針總是指向第一節點 */
        prior = current;                /* 保存上一個節點                   */
        
        strcpy(current->item.title, cha_input);
        puts("Enter your rating <0-10):");
        scanf("%d", &current->item.rating);
        eat_line();

        puts("Enter next movie title (empty line to stop):");
    }

    if (head == NULL)
        printf("No data entered. ");
    else
    {
        printf("Here is the movie title\n");

        /* 順序顯示電影列表 */
        puts("Original show:");
        original_show(head);

        putchar('\n');

        /* 逆序顯示電影列表 */
        puts("Reverse show:");
        reverse_show(head);

        /* 完成任務，釋放已分配的內存 */
        current = head;
        do
        {
            prior = current->next;
            free(current);
            current = prior;
        } while (current != head);
    }
    puts("Bye!");

    return 0;
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value;
    char * chp_find;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)
    {
        chp_find = strchr(chp_string, '\n');        /* 查找換行符           */
        if (chp_find)                               /* 如果地址不是 NULL    */
            *chp_find = '\0';                       /* 在此處放置一個空字符 */
        else
            eat_line();                             /* 處理剩餘輸入行       */
    }

    return chp_return_value;
}

void original_show(const Circular head)
{
    Circular temp = head;

    do
    {
        /* 順序遍歷雙向循環鏈錶 */
        printf("Movie: %s Rating: %d\n", temp->item.title, temp->item.rating);
        temp = temp->next;
    } while (head != temp);
}

void reverse_show(const Circular head)
{
    Circular temp = head->prev;

    do
    {
        /* 逆序遍歷雙向循環鏈錶 */
        printf("Movie: %s Rating: %d\n", temp->item.title, temp->item.rating);
        temp = temp->prev;
    } while (head->prev != temp);
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
