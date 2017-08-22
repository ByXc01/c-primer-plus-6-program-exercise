/* pe14-7.c -- 這是標準答案(本人修改了一些已知 bug)， 本人覺得題目描述的不夠具體 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10      /* maximmum number of books */
#define CONTINUE 0
#define DONE     1

struct book              /* set up book template      */
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct pack
{
    struct book book;    /* different namespace for two book identifiers */
    bool delete_me;
};

/*
 * strategy: rather than rearrange array of structures every time
 * there is a deletion, combine structure with a data member indicationg
 * whether or not an item is marked for deletion. At the end of the program,
 * show and store only those items not marked for deletion. The deletion
 * information could be stored in a separate array, but storing it in a
 * structure along with the book structure keeps the information together.
 */

char * s_gets(char * string, int number);
int get_let(const char * string);
int get_book(struct pack * pb);
void update(struct pack * item);

int main(void)
{
    struct pack library[MAXBKS];        /* array of strucres */
    int count = 0;
    int deleted = 0;
    int index, file_count, open;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "rb")) != NULL)
    {
        while (count < MAXBKS && fread(&library[count].book.title, size, 1, pbooks) == 1)
        {
            library[count].delete_me = false;

            if (count == 0)
                puts("Crrent contents of book.dat:");

            printf("%s by %s: $%.2f\n", library[count].book.title, library[count].book.author, library[count].book.value);
            printf("Do you wish to change or delete this entry?<y/n> ");
            
            if (get_let("yn") == 'y')
            {
                printf("Enter c to change, d to delete entry: ");
                if (get_let("cd") == 'd')
                {
                    library[count].delete_me = true;
                    deleted++;
                    puts("Entry marked for deletion.");
                }
                else
                    update(&library[count]);
            }
            count++;
        }
        fclose(pbooks);
    }

    file_count = count - deleted;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    open = 0;
    while (file_count < MAXBKS)
    {
        if (file_count < count)
        {
            while (library[open].delete_me == false)
                open++;
            if (get_book(&library[open]) == DONE)
                break;
        }
        else if (get_book(&library[file_count]) == DONE)
            break;

        file_count++;
        if (file_count < MAXBKS)
            puts("Enter the next book title.");
    }
    puts("Here is the list of your books:");
    for (index = 0; index < file_count; index++)
        if (library[index].delete_me == false)
            printf("%s by %s: $%.2f\n", library[index].book.title, library[index].book.author, library[index].book.value);

    if ((pbooks = fopen("book.dat", "wb")) == NULL)
    {
        fputs("Can't open book.dat file for output\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    for (index = 0; index < file_count; index++)
        if (library[index].delete_me == false)
            fwrite(&library[index].book, size, 1, pbooks);

    fclose(pbooks);

    return 0;
}

int get_let(const char * string)
{
    char character;

    character = getchar();
    while (strchr(string, character) == NULL)
    {
        printf("Enter a character in the list %s\n", string);
        while (getchar() != '\n')
            continue;
        character = getchar();
    }
    while (getchar() != '\n')
        continue;

    return character;
}

int get_book(struct pack * pb)
{
    int status = CONTINUE;

    if (s_gets(pb->book.title, MAXTITL) == NULL || pb->book.title[0] == '\0')
        status = DONE;
    else
    {
        printf("Now enter the author: ");
        s_gets(pb->book.author, MAXAUTL);

        printf("Now enter the value: ");
        while (scanf("%f", &pb->book.value) != 1)
        {
            puts("Please use numeric input");
            scanf("%*s");
        }
        while (getchar() != '\n')
            continue;       /* clear input line */

        pb->delete_me = false;
    }

    return status;
}

void update(struct pack * item)
{
    struct pack copy;
    char character;

    copy = (*item);
    puts("Enter the letter that indcates your choice:");
    puts("t) modify title       a) modify author");
    puts("v) modify value       s) quit, saving changes");
    puts("q) quit, ignore changes");

    while ((character = get_let("tavsq")) != 's' && character != 'q')
    {
        switch (character)
        {
            case 't':   
                puts("Enter new title: ");
                s_gets(copy.book.title, MAXTITL);
                break;
            case 'a':
                puts("ENter new author: ");
                s_gets(copy.book.author, MAXAUTL);
                break;
            case 'v':
                puts("Enter new value: ");
                while (scanf("%f", &copy.book.value) != 1)
                {
                    puts("Enter a numeric value: ");
                    scanf("%*s");
                }
                while (getchar() != '\n')
                    continue;
                break;
        }
        puts("t) modify title       a) modify author");
        puts("v) modify value       s) qiut, saving changes");
        puts("q) quit, ignore changes");
    }

    copy.delete_me = false;
    if (character == 's')
        (*item) = copy;
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
            while (getchar() != '\n')
                continue;                   /* dispose of rest of line      */
    }

    return return_value;
}
