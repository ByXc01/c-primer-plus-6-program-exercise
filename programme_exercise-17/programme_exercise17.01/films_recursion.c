/* File: films_recursion.c
 * Author: ByXc01
 * About: It displays the movie list both in the original order and in reverse order.
 * Version: recursion 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170925
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     /* 提供 malloc() 和 free() 的函數原型   */
#include <string.h>     /* 提供 strcpy() 和 strchr() 的函數原型 */

#define TITLE_SIZE 45   /* 儲存片名的數組大小                   */

typedef struct film
{
    char title[TITLE_SIZE];
    int rating;
    struct film * next; /* 儲存鏈接中的下一個結構               */
} Film;

char * s_gets(char *, int);
void original_show(const Film *);
void reverse_show(const Film *);
static inline void eat_line(void);

int main(void)
{
    Film * head = NULL;
    Film * prev, * current;
    char ch_input[TITLE_SIZE];

    /* 收集并儲存信息 */
    puts("Enter first movie title:");
    while (s_gets(ch_input, TITLE_SIZE) && *ch_input != '\0')
    {
        current = (Film *) malloc(sizeof (Film));
        if (head == NULL)        /* 第一個結構 */
            head = current;
        else                     /* 後續的結構 */
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, ch_input);

        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        eat_line();

        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    if (head == NULL)
        printf("No data entered.");
    else
        printf("Here is the movie list:\n");

    /* 順序顯示電影列表 */
    puts("Original show:");
    original_show(head);

    putchar('\n');

    /* 逆序顯示電影列表 */
    puts("Reverse show:");
    reverse_show(head);


    /* 完成任務，釋放已分配的內存 */
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    printf("Bye!");

    return 0;
}


void original_show(const Film * head)
{
    if (head != NULL)
    {
        printf("Movies: %s Rating: %d\n", head->title, head->rating);
        original_show(head->next);      /* 我這也用遞歸，沒考慮效率和內存問題 */
    }
}

void reverse_show(const Film * head)
{
    if (head != NULL)
    {
        reverse_show(head->next);
        printf("Movie: %s Rating: %d\n", head->title, head->rating);
    }
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value;
    char * chp_find;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)
    {
        chp_find = strchr(chp_string, '\n');    /* 查找換行符         */
        if (chp_find)                           /* 如果地址不是 NULL  */
            *chp_find = '\0';                   /* 在此處放一個空字符 */
        else
            eat_line();                         /* 處理剩餘的輸入行   */
    }

    return chp_return_value;
}
