/* stack.h -- 棧的接口                                      */
/* 下面是以數組形式實現棧，但這些信息只影響定義結構和函數   */
/* 定義的細節，不會影響函數原型的接口                       */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>            /* 為使用 bool、true、false */

/* 在這插入 Item 類型 */
/* 例如： typedef int Item; */

typedef char Item;

#define MAX_STACK  100

typedef struct stack
{
    Item items[MAX_STACK];      /* 儲存星系         */
    int top;                    /* 第一個空位的索引 */
} Stack;

/* 操作：       初始化棧                                            */
/* 前提條件：   pointer_stack 指向一個棧                            */
/* 後置條件：   該棧被初始化為空                                    */
void InitializeStack(Stack * pointer_stack);

/* 操作：       檢查棧是否已滿                                      */
/* 前提條件：   pointer_stack 指向之前已被初始化的棧                */
/* 後置條件：   如果棧已滿，該函數返回 true；否則，返回 false       */
bool FullStack(const Stack * pointer_stack);

/* 操作：       檢查棧是否為空                                      */
/* 前提條件：   pointer_stack 指向之前已被初始化的棧                */
/* 後置條件：   如果棧為空，該函數返回 true；否則，返回 false       */
bool EmptyStack(const Stack * pointer_stack);

/* 操作：       把項壓入棧頂                                        */
/* 前提條件：   pointer_stack 指向之前已被初始化的指針              */
/*              item 是待壓入棧頂的項                               */
/* 後置條件：   如果棧 未滿，把 item 放在棧頂，該函數返回 true      */
/*              否則，棧不變，該函數返回 false                      */
bool Push(Item item, Stack * pointer_stack);

/* 操作：       從棧頂刪除項                                        */
/* 前提條件：   pointer_stack 指向之前已被初始化的棧                */
/* 後置條件：   如果棧不為空，吧棧頂的 item 拷貝到 *pointer_stack   */
/*              刪除棧頂的 item，該函數返回 ture；                  */
/*              如果該操作后棧中沒有項，則重置該棧為空。            */
/*              如果刪除之前棧為空，棧不變，該函數返回 false        */
bool Pop(Item * pointer_item, Stack * pointer_stack);

#endif
