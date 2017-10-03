/* File: binary_search.c
 * Author: ByXc
 * About: binary search
 * Version: 1.0
 * Compile: gcc 6.3.0 for msys2
 * Date: 20170928
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // 提供 rand()、srand()、qsort() 的函原型
#include <stdbool.h>    // 为了是用 bool、true、false
#include <time.h>       // 提供 time() 的函數原型

#define ARRAY_MAX 10
#define ELEMENT_MAX 1000

void random_initialize(int [] , int);                       // 隨機初始化數組
void show_array(const int [], int);                         // 輸出數組
bool binary_search(const int [], int, int);                 // 使用二分查找
int comp(const void *, const void *);                       // 比較函數
static inline void clean_line(void);                        // 使用內聯函數

int main(void)
{
    int i_array[ARRAY_MAX];
    int i_input;
    bool b_flag;

    srand((unsigned int) time(0));                          // 初始化隨機種子

    
    puts("Randomized:");
    random_initialize(i_array, ARRAY_MAX);
    show_array(i_array, ARRAY_MAX);

    puts("Sorted:");
    qsort(i_array, ARRAY_MAX, sizeof (int), comp);
    show_array(i_array, ARRAY_MAX);

    printf("Please enter an search integer (1~%d): ", ELEMENT_MAX);
    while (scanf("%d", &i_input) == 1)
    {
        clean_line();                                       // 丟棄 scanf() 留在緩衝區的換行符
        b_flag = binary_search(i_array, ARRAY_MAX, i_input);
        printf("%d %s in array.\n", i_input, b_flag ? "is" : "isn't");
        printf("Please enter next search integer (1~%d) (q to quit): ", ELEMENT_MAX);
    }
    puts("Bye!");

    return 0;
}

void random_initialize(int ip_data[], int i_limit)
{
    int i_count;

    for (i_count = 0; i_count < i_limit; i_count++)
        *(ip_data + i_count) = rand() % ELEMENT_MAX + 1;    // 隨機的範圍是 1~ELEMENT_MAX
}

void show_array(const int ip_data[], int i_limit)
{
    int i_count;

    for (i_count = 0; i_count < i_limit; i_count++)
    {
        printf("%3d ", *(ip_data + i_count));
        if (i_count % 20 == 19)
            putchar('\n');
    }
    if (i_count % 20 != 0)
        putchar('\n');
}

int comp(const void * pointer1, const void * pointer2)
{
    const int * ip_element1 = (const int *) pointer1;
    const int * ip_element2 = (const int *) pointer2;

    if (*ip_element1 > *ip_element2)
        return 1;
    else if(*ip_element1 == *ip_element2)
        return 0;
    else
        return -1;
}

bool binary_search(const int ip_source[], int i_limit, int i_target)
{
    int i_high, i_low, i_middle;
    bool b_found = false;

    i_low = 0;
    i_high = i_limit - 1;

    while (i_low <= i_high)
    {
        i_middle = (i_high + i_low) / 2;                    // 求出中間索引
        if (i_target > ip_source[i_middle])                 // 在中間索引（不包括中間索引，所以要加一）的后半部分查找
            i_low = i_middle + 1;
        else if (i_target < ip_source[i_middle])
            i_high = i_middle - 1;                          // 在中間索引（不包括中間索引，所以要減一）的前半部分查找
        else                                                // 找到目標
        {
            b_found = true;
            break;
        }
    }

    return b_found;
}

static inline void clean_line(void)
{
    while (getchar() != '\n')
        continue;
}
