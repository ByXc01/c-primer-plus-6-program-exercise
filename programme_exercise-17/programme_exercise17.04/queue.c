/* queue.c -- Queue 類型的事項 */

#include <stdio.h>
#include <stdlib.h>     /* 為 mallo()、free() 和 free() 提供函數原型，為 EXIT_FAILURE 提供宏 */
#include <stdbool.h>    /* 為使用 bool、true、false                                          */
#include "queue.h"      /* 為 Item、Node、Queue 提供類型定義                                 */

/* 局部函數聲明 */
static void CopyToNode(Item item, Node * pointer_node);
static void CopyToItem(Node * pointer_node, Item * pointer_item);

void InitializeQueue(Queue * pointer_queue)
{
    pointer_queue->front = pointer_queue->rear = NULL;
    pointer_queue->items = 0;
}

bool QueueIsFull(const Queue * pointer_queue)
{
    return pointer_queue->items == MAX_QUEUE;
}

bool QueueIsEmpty(const Queue * pointer_queue)
{
    return pointer_queue->items == 0;
}

int QueueItemCount(const Queue * pointer_queue)
{
    return pointer_queue->items;
}

bool EnQueue(Item item, Queue * pointer_queue)
{
    Node * pointer_new;

    if (QueueIsFull(pointer_queue))
        return false;

    pointer_new = (Node * ) malloc (sizeof (Node));
    if (pointer_new == NULL)
    {
        fprintf(stderr, "Unable to allocate memoty!\n");
        exit(EXIT_FAILURE);
    }

    CopyToNode(item, pointer_new);
    pointer_new->next = NULL;
    if (QueueIsEmpty(pointer_queue))
        pointer_queue->front = pointer_new;         /* 項位於隊列的首端   */
    else
        pointer_queue->rear->next = pointer_new;    /* 鏈接到隊列的尾端   */

    pointer_queue->rear = pointer_new;              /* 記錄隊列尾端的位置 */
    pointer_queue->items++;                         /* 隊列項數加 1       */

    return true;
}

bool DeleteQueue(Item * pointer_item, Queue * pointer_queue)
{
    Node * pointer_temp;

    if (QueueIsEmpty(pointer_queue))
        return false;
    
    CopyToItem(pointer_queue->front, pointer_item);
    pointer_temp = pointer_queue->front;
    pointer_queue->front = pointer_queue->front->next;
    free(pointer_temp);
    pointer_queue->items--;

    if (pointer_queue->items == 0)
        pointer_queue->rear = NULL;

    return true;
}

/* 清空隊列 */
void EmptyTheQueue(Queue * pointer_queue)
{
    Item dummy;

    while (!QueueIsEmpty(pointer_queue))
        DeleteQueue(&dummy, pointer_queue);
}

/* 局部函數定義 */

static void CopyToNode(Item item, Node * pointer_node)
{
    pointer_node->item = item;
}

static void CopyToItem(Node * pointer_node, Item * pointer_item)
{
    *pointer_item = pointer_node->item; 
}
