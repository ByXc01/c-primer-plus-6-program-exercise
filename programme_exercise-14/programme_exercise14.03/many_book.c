/* File: many_book.c
 * Author: ByXc
 * About: sort
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170809
 * Github: ByXc01
 * Blog: http:\\ByXc01.github.io
 */

/* multiple book inventory */
#include <stdio.h>
#include <string.h>     // 提供 strchr() 和 strcmp() 函數原型

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100     // 書籍的最大數量

struct book             // 建立 book 模版
{
    char cha_title[MAXTITL];
    char cha_author[MAXAUTL];
    float fl_value;
};

char * s_gets(char *, int);
void value_sort(struct book *, int);   // 本程序使用結構指針
void title_sort(struct book *, int);
void show(const struct book *, int);

int main(void)
{
    struct book library[MAXBKS];      // 要求較大的棧空間，如果發生棧溢出請把 MAXBKS 改小一點
    int i_count = 0;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (i_count < MAXBKS && s_gets(library[i_count].cha_title, MAXTITL) != NULL && library[i_count].cha_title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[i_count].cha_author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[i_count++].fl_value);

        while (getchar() != '\n')
            continue;

        if (i_count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (i_count > 0)
    {
        show(library, i_count);
        putchar('\n');

        title_sort(library, i_count);       // 以 ASCII 編碼升序排序
        show(library, i_count);
        putchar('\n');

        value_sort(library, i_count);       // 以 價錢升序排序
        show(library, i_count);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

void value_sort(struct book * pointer, int i_number)
{
    int i_index, i_count;
    struct book temp;

    for (i_index = 0; i_count < i_number - 1; i_count++)
        for (i_count = i_index + 1; i_count < i_number; i_count++)
            if (pointer[i_index].fl_value > pointer[i_count].fl_value)     // 升序排序
            {
                temp = pointer[i_index];
                pointer[i_index] = pointer[i_count];
                pointer[i_count] = temp;
            }
}

void title_sort(struct book * pointer, int i_number)
{
    int i_index, i_count;
    struct book temp;

    for (i_index = 0; i_index < i_number - 1; i_index++)
        for (i_count = i_index + 1; i_count < i_number; i_count++)
            if (strcmp(pointer[i_index].cha_title, pointer[i_count].cha_title) > 0)     // 升序排序
            {
                temp = pointer[i_index];
                pointer[i_index] = pointer[i_count];
                pointer[i_count] = temp;
            }
}

void show(const struct book * pointer, int i_number)
{
    int i_index;

    printf("Here is the list of your books:\n");
    for (i_index = 0; i_index < i_number; i_index++)
        printf("%s by %s: $%.2f\n", pointer[i_index].cha_title, pointer[i_index].cha_author, pointer[i_index].fl_value);
}

char * s_gets(char * chp_string, int i_number)
{
    char * chp_return_value, * chp_find;

    chp_return_value = fgets(chp_string, i_number, stdin);
    if (chp_return_value)
    {
        chp_find = strchr(chp_string, '\n');    // 查找換行符
        if (chp_find)                           // 如果地址不是 NULL
            *chp_find = '\0';                   // 在此處放置一個空字符
        else
            while (getchar() != '\n')           // 處理輸入行中剩餘的字符
                continue;
    }

    return chp_return_value;
}
