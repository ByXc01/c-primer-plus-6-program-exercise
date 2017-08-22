/* 这是标准答案 */

#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100     /* maximun number of books */

struct book             /* set up book template    */
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * string, int number);
void sortt(struct book * pb[], int number);
void sortv(struct book * pb[], int number);

int main(void)
{
    struct book library[MAXBKS];        /* array of book structures */
    struct book * pbk[MAXBKS];          /* pointers for sorting     */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);

        pbk[count] = &library[count];   /* 結構數組，只需對結構數組排序即可。比我在原來的結構數組上排序強多了 */
        count++;

        while (getchar() != '\n')
            continue;                   /* clear input line */

        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

    sortt(pbk, count);
    printf("Here is the list of your books sorted by title:\n");
    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", pbk[index]->title, pbk[index]->author, pbk[index]->value);

    sortv(pbk, count);
    printf("Here is the list of your books sorted by value:\n");
    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", pbk[index]->title, pbk[index]->author, pbk[index]->value);

    return 0;
}

void sortt(struct book * pb[], int number)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < number - 1; top++)
        for (search = top + 1; search < number; search++)
            if (strcmp(pb[search]->title, pb[top]->title) < 0)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
}

void sortv(struct book * pb[], int number)
{
    int top, search;
    struct book * temp;

    for (top = 0; top < number - 1; top++)
        for (search = top + 1; search < number; search++)
            if (pb[search]->value < pb[top]->value)
            {
                temp = pb[search];
                pb[search] = pb[top];
                pb[top] = temp;
            }
}

char * s_gets(char * string, int number)
{
    char * return_value, * find;

    return_value = fgets(string, number, stdin);
    if (return_value)
    {
        find = strchr(string, '\n');    /* look for newline */
        if (find)                       /* if the address is not NULL */
            *find = '\0';               /* place a null character there */
        else
            while (getchar() != '\n')
                continue;               /* dispose of rest of line */
    }

    return return_value;
}
