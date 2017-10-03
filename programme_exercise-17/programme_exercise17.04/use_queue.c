/* use_queue.c -- 驅動程序測試 Queue 接口 */
/* 與 queue.c 一起編譯 */

#include <stdio.h>
#include "queue.h"      /* 定義 Queue、Item 和一系列接口函數 */

int main(void)
{
    Queue line;
    Item temp;
    char character;

    InitializeQueue(&line);
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((character = getchar()) != 'q')
    {
        if (character != 'a' && character != 'd')       /* 忽略其他輸入 */
            continue;
        if (character == 'a')
        {
            printf("Integer to add:");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeleteQueue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        printf("Type a to add, d to delete, q to quit:");
    }
    EmptyTheQueue(&line);
    puts("Bye!");

    return 0;
}
