/* list.c -- 支持鏈錶操作的函數 */

#include <stdbool.h>    /* 提供 bool、true 和 false         */
#include "list.h"       /* 提供 Item 和 List 的定義   */


/* 函數接口 */

/* 把鏈錶設置為空 */
void InitializeList(List * pointer_list)
{
    pointer_list->items = 0;
}

/* 如果鏈錶為空，返回 true */
bool ListIsEmpty(const List * pointer_list)
{
    if (pointer_list->items == 0)
        return true;
    else
        return false;
}

/* 如果鏈錶已滿，返回 true */
bool ListIsFull(const List * pointer_list)
{
    if (pointer_list->items == MAX_SIZE)
        return true;
    else
        return false;
}

/* 返回節點的數量 */
 int ListItemCount(const List * pointer_list)
{
    return pointer_list->items;
}

/* 創建儲存項的節點，并將其添加至由 pointer_list 指向的鏈錶末尾（較快的實現:) */
bool AddItem(Item item, List * pointer_list)
{
    int index;

    if (pointer_list->items == MAX_SIZE)
        return false;                       /* 提前返回                   */

    index = pointer_list->items;            /* 項數就是待添加的數組的索引 */ 
    pointer_list->entries[index] = item;    /* 添加至數組                 */
    pointer_list->items++;                  /* 項數加一                   */

    return true;
}

/* 訪問每個節點并執行 pointer_function 指向的函數 */
void Traverse(const List * pointer_list, void (* pointer_function) (Item item))
{
    int index;

    for (index = 0; index < pointer_list->items; index++)
        (*pointer_function) (pointer_list->entries[index]);   /* 把函數應用於鏈錶中的項 */
}

/* malloc() not used, nothing need be deallocated */
/* set items member to 0                          */
void EmptyTheList(List * pointer_list)
{
    pointer_list->items = 0;
}
