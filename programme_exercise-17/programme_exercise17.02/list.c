/* list.c -- 支持鏈錶操作的函數 */

#include <stdio.h>
#include <stdlib.h>     /* 提供 molloc() 和 free() 函數原型 */
#include <stdbool.h>    /* 提供 bool、true 和 false         */
#include "list.h"       /* 提供 Item、Node 和 List 的定義   */

/* 局部函數原型 */
static void CopyToNode(Item item, Node * pointer_node);

/* 函數接口 */

/* 把鏈錶設置為空 */
void InitializeList(List * pointer_list)
{
    pointer_list->head = pointer_list->end = NULL;
}

/* 如果鏈錶為空，返回 true */
bool ListIsEmpty(const List * pointer_list)
{
    if (pointer_list->head == NULL)
        return true;
    else
        return false;
}

/* 如果鏈錶已滿，返回 true */
bool ListIsFull(const List * pointer_list)
{
    Node * pointer_node;
    bool full;

    pointer_node = (Node *) malloc(sizeof (Node));
    if (pointer_node == NULL)
        full = true;
    else
        full = false;

    return full;
}

/* 返回節點的數量 */
unsigned int ListItemCount(const List * pointer_list)
{
    unsigned int count = 0;
    Node * pointer_node = pointer_list->head;       /* 設置鏈錶的開始 */

    while (pointer_node != NULL)
    {
        count++;
        pointer_node = pointer_node->next;          /* 設置下一個節點 */
    }
    
    return count;
}

/* 創建儲存項的節點，并將其添加至由 pointer_list 指向的鏈錶末尾（較快的實現:) */
bool AddItem(Item item, List * pointer_list)
{
    Node * pointer_new;

    pointer_new = (Node *) malloc(sizeof (Node));
    if (pointer_new == NULL)
        return false;           /* 提前返回 */

    CopyToNode(item, pointer_new);
    pointer_new->next = NULL;

    if (pointer_list->head == NULL)                 /* 空鏈錶                                    */
        pointer_list->head = pointer_new;           /* 把 pointer_new 放在鏈錶的開頭             */
    else
        pointer_list->end->next = pointer_new;      /* 把 pointer_new 放在鏈錶的末尾             */
    pointer_list->end = pointer_new;                /* 每添加一個新節點， 將尾指針指向當前新節點 */

    return true;
}

/* 訪問每個節點并執行 pointer_function 指向的函數 */
void Traverse(const List * pointer_list, void (* pointer_function) (Item item))
{
    Node * pointer_node = pointer_list->head;       /* 設置鏈錶的開始                            */

    while (pointer_node != NULL)
    {
        (*pointer_function) (pointer_node->item);   /* 把函數應用於鏈錶中的項                    */
        pointer_node = pointer_node->next;          /* 前進到下一項                              */
    }
}

/* 釋放由 malloc() 分配的內存 */
/* 設置鏈錶指針為 NULL        */
void EmptyTheList(List * pointer_list)
{
    Node * pointer_save = pointer_list->head;       /* 設置鏈錶的開始                            */
    Node * pointer_temp;

    while (pointer_save != NULL)
    {
        pointer_temp = pointer_save->next;          /* 保存下一個節點的指針                      */     
        free(pointer_save);                         /* 釋放當前節點                              */
        pointer_save = pointer_temp;                /* 前進下一節點                              */
    }

    pointer_list->head = NULL;                      /* 設置鏈錶為空                              */
    pointer_list->end = NULL;
}

/* 局部函數定義 */

/* 把一個項拷貝到節點中 */
void CopyToNode(Item item, Node * pointer_node)
{
    pointer_node->item = item;      /* 拷貝結構 */
}
