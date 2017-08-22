/* File: structure_a.c
 * Author: ByXc
 * About: by passing the structure address
 * Compiler: gcc 6.3.0 for msys2
 * Version: 1.0
 * Date:20170811
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <string.h>     // 為 strcmp() 提供函數原型
#define MAX_NAME 20
#define MAX 5
#define NOT "null"      // 中間名沒有的用 null 標識

struct data
{
    int i_digital;
    struct name
    {
        char cha_first_name[MAX_NAME];
        char cha_middle_name[MAX_NAME];
        char cha_last_name[MAX_NAME];
    };
};

void show(const struct data *, int);
int main(void)
{
    struct data person[MAX] =
    {
        { 302039823, { "Dribble", "Max", "Flossie" } },
        { 302039824, { "By", "Lzc", "Xc" } },
        { 302039825, { "Polly", "null", "Poetica" } },
        { 302039826, { "Dudley", "null", "Forse" } },
        { 302039827, { "Nellie", "null", "Nostrum" } }
    };

    show(person, MAX);

    return 0;
}

void show(const struct data * st_pointer, int i_number)
{
    int i_count;

    for (i_count = 0; i_count < i_number; i_count++)
    {
        printf("%s, ", st_pointer[i_count].cha_first_name);
        printf("%s ", st_pointer[i_count].cha_last_name);
        if (strcmp(st_pointer[i_count].cha_middle_name, NOT) != 0)
            printf("%c. ", st_pointer[i_count].cha_middle_name[0]);
        printf("-- %d\n", st_pointer[i_count].i_digital);
    }
}
