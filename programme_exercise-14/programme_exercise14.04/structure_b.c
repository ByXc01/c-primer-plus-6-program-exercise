/* File: structure_b.c
 * Author: ByXc
 * About: by passing the structure value instead of the address
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

void show(const struct data);
int main(void)
{
    int i_count;
    struct data person[MAX] =
    {
        { 302039823, { "Dribble", "Max", "Flossie" } },
        { 302039824, { "By", "Lzc", "Xc" } },
        { 302039825, { "Polly", "null", "Poetica" } },
        { 302039826, { "Dudley", "null", "Forse" } },
        { 302039827, { "Nellie", "null", "Nostrum" } }
    };

    for (i_count = 0; i_count < MAX; i_count++)
        show(person[i_count]);

    return 0;
}

void show(const struct data structure)
{
        printf("%s, ", structure.cha_first_name);
        printf("%s ", structure.cha_last_name);
        if (strcmp(structure.cha_middle_name, NOT) != 0)
            printf("%c. ", structure.cha_middle_name[0]);
        printf("-- %d\n", structure.i_digital);
}
