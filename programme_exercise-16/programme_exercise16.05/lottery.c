/* File: lottery.c
 * Author: ByXc
 * About: lottery draw
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170912
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdlib.h>     // for malloc()、free()、srand()、rand()
#include <time.h>       // for time()

#define SIZE 10

void lottery(const int [], int, int);
int main(void)
{
    int i_array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i_input;

    srand((unsigned int) time(0));                          // 初始化隨機數種子
    printf("Please enter an positive number(1 to %d) (q to quit): ", SIZE);
    while (scanf("%d", &i_input) == 1)
    {
        if (i_input < 0 || i_input > SIZE)
        {
            printf("%d overflow\n", i_input);
            continue;
        }

        lottery(i_array, SIZE, i_input);
        printf("Please enter an positive number(1 to %d) (q to quit): ", SIZE);
    }
    puts("Bye!");

    return 0;
}

void lottery(const int i_data[], int i_limits, int i_count)
{
    int * ip_draw = (int *) malloc(i_count * sizeof(int));     // 使用動態內存分配，用來存放不重複的索引
    int i_index;
    int i, j;

    for (i = 0; i < i_count; i++)                              // 抽獎次數
    {
        i_index = rand() % i_limits;                           // 隨機索引 0 ~ i_limits - 1

        j = 0;
        while (i != 0 && j <= i)
        {
            if (ip_draw[j] == i_index)                         // 檢測索引是否重複
            {
                i_index = rand() % i_limits;                   // 若重複，則重新隨機
                j = 0;                                         // 設置為 0， 從新檢索
            }
            else                                               // 若沒被抽過
                j++;
        }
        ip_draw[i] = i_index;                                  // 將不重複的索引賦值給數組

        printf("%2d ", i_data[i_index]);
    }
    putchar('\n');

    free(ip_draw);
}
