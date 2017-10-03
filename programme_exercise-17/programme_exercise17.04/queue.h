/* queue.c -- Queue 的接口 */

#ifndef Queue_H_
#define Queue_H_

#include <stdbool.h>    /* 為了使用 bool、true、false */

// 在這插入 Item 類型的定義，例如
// typedef int Item;       // 用於 use_q.c
// 或者 typedef struct item { int gumption; int charisma; } Item;

typedef struct item
{
    long arrive;        /* 一位顧客加入隊列的時間 */
    int process_time;   /* 該顧客咨詢時花費的時間 */
} Item;

#define MAX_QUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;       /* 指向隊列首項的指針 */
    Node * rear;        /* 指向隊列尾項的執政 */
    int items;          /* 隊列中的項數       */ 
} Queue;

/* 操作：       初始化隊列                                                  */
/* 前提條件：   pointer_queue 指向一個隊列                                  */
/* 後置條件：   隊列初始化為空                                              */
void InitializeQueue(Queue * pointer_quque);

/* 操作：       檢查隊列是否已滿                                            */
/* 前提條件：   pointer_queue 指向之前被初始化的隊列                        */
/* 後置條件：   如果隊列已滿則返回 true，否則返回 false                     */
bool QueueIsFull(const Queue * pointer_queue);

/* 操作：       檢查隊列是否為空                                            */
/* 前提條件：   pointer_queue 指向之前被初始化的隊列                        */
/* 後置條件：   如果隊列為空則返回 true，否則返回 false                     */
bool QueueIsEmpty(const Queue * pointer_queue);

/* 操作：       確定隊列中的項數                                            */
/* 前提條件：   pointer_queue 指向之前被初始化的隊列                        */
/* 後置條件：   返回隊列中的項數                                            */
int QueueItemCount(const Queue * pointer_queue);

/* 操作：       在列表末尾添加項                                            */
/* 前提條件：   pointer_queue 指向之前被初始化的隊列                        */
/*              item 是要被添加在隊列末尾的項                               */
/* 後置條件：   如果隊列未滿，item 將被添加在隊列的末尾，                   */
/*              該函數返回 true；否則，隊列不改變，該函數返回 false         */
bool EnQueue(Item item, Queue * pointer_queue);

/* 操作：       從隊列的開頭刪除項                                          */
/* 前提條件：   pointer_queue 指向之前被初始化的隊列                        */
/* 後置條件：   如果隊列不為空，隊列首端的 item 將被拷貝到 *pointer_item 中 */
/*              并被刪除，且函數返回 true；                                 */
/*              如果該操作使得隊列為空，則重置隊列為空                      */
/*              如果隊列在操作前為空，該函數返回 false                      */
bool DeleteQueue(Item * pointer_item, Queue * pointer_queue);

/* 操作：       清空隊列                                                    */
/* 前提條件：   pointer_queue 指向指向被初始化的隊列                        */
/* 後置條件：   隊列被清空                                                  */
void EmptyTheQueue(Queue * pointer_queue);

#endif
