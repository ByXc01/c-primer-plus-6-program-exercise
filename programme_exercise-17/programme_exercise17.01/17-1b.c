/* pe17-1b.c -- double-link solution */
/* 標準答案雙向鏈錶，本人修改了一個  */
/* bug 以及加入個人的風格            */

#include <stdio.h>
#include <stdlib.h>             /* has the malloc prototype            */
#include <string.h>             /* has the strcpy and strchr prototype */

#define TITLE_SIZE 45           /* size of tarray to hold title        */

struct film
{
    char title[TITLE_SIZE];
    int rating;
    struct film * next;         /* points to next struct in list       */
    struct film * previous;     /* points to previous struct           */
};

char * s_gets(char * string, int number);
static inline void eat_line(void);

int main(void)
{
    struct film * head = NULL;
    struct film * previous, * current;
    char input[TITLE_SIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TITLE_SIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof (struct film));
        if (head == NULL)        /* first structure                     */
        {
            head = current;
            head->previous = NULL;
        }
        else                    /* subsequent structures               */
        {
            previous->next = current;
            current->previous = previous;
        }
        current->next = NULL;
        strcpy(current->title, input);

        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        eat_line();

        puts("Enter next movie title (empty line to stop):");
        previous = current;
    }

    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movis list:\n");
    
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        previous = current;
        current = current->next;
    }

    if (head != NULL)
    {
        printf("\nHere is the list in reverse order:\n");
        current = previous;
        while (current != NULL)
        {
            printf("Movie: %s Rating: %d\n", current->title, current->rating);
            current = current->previous;
        }
    }

    /* deallocated */
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    printf("Bye!\n");

    return 0;
}

static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
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
