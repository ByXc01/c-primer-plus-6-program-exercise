/* list.h -- 簡單鏈錶類型的頭文件 */
#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>        /* C99 特性             */

/* 特定的聲明 */

#define TITLE_SIZE 45       /* 儲存電影名的數組大小 */
#define MAX_SIZE 10         /* 項目最大值           */

struct film
{
    char title[TITLE_SIZE];
    int rating;
};

/* 一般類型定義 */

typedef struct film Item;

typedef struct list
{
    Item entries[MAX_SIZE];
    int items;
} List;

/* 函數原型 */

/* 操作：       初始化一個鏈錶                                                              */
/* 前提條件：   pointer_list 指向一個鏈錶                                                   */
/* 後置條件：   鏈錶初始化為空                                                              */
void InitializeList(List * pointer_list);

/* 操作：       確定鏈錶是否為空，                                                          */ 
/* 前提條件：   pointer_list 指向一個已初始化的鏈錶                                         */
/* 後置條件：   如果鏈錶為空，該函數返回 true，否則返回 false                               */
bool ListIsEmpty(const List * pointer_list);

/* 操作：       確定鏈錶是否已滿                                                            */
/* 前提條件：   pointer_list 指向一個已初始化的鏈錶                                         */
/* 後置條件：   如果鏈錶已滿，該函數返回 true，否則返回 false                               */
bool ListIsFull(const List * pointer_list);

/* 操作：       確定鏈錶中的項數                                                            */
/* 前提條件：   pointer_list 指向已過已初始化的鏈錶                                         */
/* 後置條件：   該函數返回鏈錶中的項數                                                      */
int ListItemCount(const List * pointer_list);

/* 操作：       在鏈錶的末尾添加項                                                          */
/* 前提條件：   Item 是一個待添加至鏈錶的項，pointer_list 指向一個已初始化的鏈錶            */
/* 後置條件：   如果可以，該函數在鏈錶末尾添加一個項，且返回 true，否則返回 false           */
bool AddItem(Item item, List * pointer_list);

/* 操作：       把函數作用於鏈錶中的每一項                                                  */ 
/* 前提條件：   pointer_list 指向一個已初始化的鏈錶                                         */
/*              pointer_function 指向一個函數，該函數接受一個 Item 類型的參數，且無返回值   */
/* 後置條件：   pointer_function 指向的函數作用于鏈錶中的每一項一次                         */
void Traverse(const List * pointer_list, void (* pointer_functiong) (Item item));

/* 操作：       將項目數設置為 0                                                            */
/* 前提條件：   pointer_list 指向一個已初始化的鏈錶                                         */
/* 后置條件：   項目數為 0                                                                  */ 
void EmptyTheList(List * pointer_list);

#endif
