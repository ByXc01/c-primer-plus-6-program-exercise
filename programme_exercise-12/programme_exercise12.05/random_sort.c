/* File: random_sort.c
 * Author: ByXc
 * About: random number sort
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170701
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 rand()、srand()、calloc()、free() 和 exit 的函數原型
#include <time.h>       // 提供 time() 的函數原型

#define ARRAY_MAX 100
#define NUMBER_MAX 10

void selection_sort(short int *);
void initialization(short int *);
void show_array(short int *);

int main(void)
{
    short int * sip_rand_num = (short int *) calloc(ARRAY_MAX, sizeof(short int));

    if (sip_rand_num == NULL)           // 如分配動態內存失敗
        exit(EXIT_FAILURE);

    srand((unsigned) time(0));
    initialization(sip_rand_num);
    show_array(sip_rand_num);

    selection_sort(sip_rand_num);
    show_array(sip_rand_num);
    free(sip_rand_num);

    return 0;
}

void show_array(short int * sip_array)
{
    int i_count;

    for (i_count = 0; i_count < ARRAY_MAX; i_count++)
    {
        printf("%2d ", *(sip_array + i_count));
        if (i_count % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}

void initialization(short int * sip_array)
{
    int i_count;
    for (i_count = 0; i_count < ARRAY_MAX; i_count++)
        *(sip_array + i_count) = rand() % NUMBER_MAX + 1;
}

void selection_sort(short int * sip_array)
{
    int i_index, i_count;
    short int si_temp;

    for (i_index = 0; i_index < ARRAY_MAX - 1; i_index++)
        for (i_count = i_index + 1; i_count < ARRAY_MAX; i_count++)
            if (*(sip_array + i_index) < *(sip_array + i_count))
            {
                si_temp = *(sip_array + i_count);
                *(sip_array + i_count) = *(sip_array + i_index);
                *(sip_array + i_index) = si_temp;
            }
}
