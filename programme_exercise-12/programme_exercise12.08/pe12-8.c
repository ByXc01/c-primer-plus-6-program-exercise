/* File: pe12-8.c
 * Author: ByXc
 * About: function definition
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170702
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 為 malloc()、free() 和 exit() 提供函數原型， 為 EXIT_FAILURE 提供宏定義

int * make_array(int, int);
void show_array(const int *, int);

int main(void)
{
    int * ip_array;
    int i_size;
    int i_value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &i_size) == 1 && i_size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &i_value);
        ip_array = make_array(i_size, i_value);

        if (ip_array)
        {
            show_array(ip_array, i_size);
            free(ip_array);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.");

    return 0;
}

int * make_array(int i_element, int i_value)
{
    int i_count;
    int * ip_dynamic = (int *) malloc(i_element * sizeof(int));

    if (ip_dynamic == NULL)     // 預防動態內存分配失敗
    {
        puts("Dynamic allocation failed!");
        exit(EXIT_FAILURE);
    }

    for (i_count = 0; i_count < i_element; i_count++)
        *(ip_dynamic + i_count) = i_value;

    return ip_dynamic;
}

void show_array(const int * cip_array, int i_n)
{
    int i_count;

    for (i_count = 0; i_count < i_n; i_count++)
    {
        printf("%3d ", *(cip_array + i_count));

        if (i_count % 8 == 7)
            putchar('\n');
    }
    if (i_count % 8 != 0)
        putchar('\n');
}
