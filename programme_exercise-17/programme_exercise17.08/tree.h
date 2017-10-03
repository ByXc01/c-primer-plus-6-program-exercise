/* tree.h -- 二叉查找樹         */
/*           樹中不允許有重複項 */

#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

/* 根據具體情況重新定義 Item */
#define STRING_LENGTH 10            /* 字符串長度       */

typedef struct item
{
    char pet_name[STRING_LENGTH];
    char pet_kind[STRING_LENGTH];
    struct item * next;             /* 使用鏈錶方式     */
} Item;

#define MAX_ITEMS 10

typedef struct tree_node
{
    Item * head;                    /* 指向鏈錶的開頭   */
    Item * end;                     /* 指向鏈錶的末尾   */
    struct tree_node * left;        /* 指向左分支的指針 */
    struct tree_node * right;       /* 指向右分支的指針 */
} Tree_node;

typedef struct tree
{
    Tree_node * root;               /* 指向根節點的指針 */
    int size;                       /* 樹的項數         */
} Tree;

/* 函數原型 */

/* 操作：       把樹初始化為空                                                          */
/* 前提條件：   pointer_tree 指向一個樹                                                 */
/* 後置條件：   樹被初始化                                                              */
void InitializeTree(Tree * pointer_tree);

/* 操作：       確定樹是否為空                                                          */
/* 前提條件：   pointer_tree 指向一個樹                                                 */
/* 後置條件：   如果樹為空，該函數返回 true                                             */
/*                  否則返回 false                                                      */
bool TreeIsEmpty(const Tree * pointer_tree);

/* 操作：       確定樹是否已滿                                                          */
/* 前提條件：   pointer_tree 指向一個樹                                                 */
/* 後置條件：   如果樹已滿，該函數返回 true                                             */
/*                  否則，返回 false                                                    */
bool TreeIsFull(const Tree * pointer_tree);

/* 操作：       確定樹的項數                                                            */
/* 前提條件：   pointer_tree 指向一個樹                                                 */
/* 後置條件：   返回樹的項數                                                            */
int TreeItemCount(const Tree * pointer_tree);

/* 操作：       在樹中添加一個項                                                        */
/* 前提條件：   pointer_item 是待添加項的地址                                           */
/*                  pointer_tree 指向一個已初始化的樹                                   */
/* 後置條件：   如果可以添加，該函數將在樹中添加一個項                                  */
/*                  并返回 true； 否則，返回 false                                      */
bool AddItem(const Item * pointer_item, Tree * pointer_tree);

/* 操作：       在樹中查找一個項                                                        */
/* 前提條件：   pointer_item 指向一個項                                                 */
/*                  pointer_tree 指向一個已初始化樹                                     */
/* 後置條件：   如果該項在樹中，該函數返回 true                                         */
/*                  否則，返回 false                                                    */
bool InTree(const Item * pointer_item, const Tree * pointer_tree);

/* 操作：       從樹中刪除一個項                                                        */
/* 前提條件：   pointer_item 是刪除項的地址                                             */
/* 後置條件：   如果從樹中成功刪除一個項，該函數返回 true                               */
/*                  否則，返回 false                                                    */
bool DeleteItem(const Item * pointer_item, Tree * pointer_tree);

/* 操作：       把函數應用于樹中的每一項                                                */
/* 前提條件：   pointer_tree 指向一個樹                                                 */
/*                  pointer_function 指向一個函數，                                     */
/*                  該函數接受一個 Item 類型的參數，並無返回值                          */
/* 後置條件：   pointer_function 指向的這個函數為樹中的每一項執行一次                   */
void Traverse(const Tree * pointer_tree, void (* pointer_functiong) (Item item));

/* 操作：       刪除樹中的所有內容                                                      */
/* 前提條件：   pointer_tree 指向一個已初始化的樹                                       */
/* 後置條件：   樹為空                                                                  */
void DeleteAll(Tree * pointer_tree);

/* 操作：       輸出所在鏈錶的同名寵物                                                  */
/* 前提操作：   pointer_item 指向項                                                     */
/*                  pointer_tree 指向一個已初始化的樹                                   */
/* 後置條件：   如果樹中有同名寵物，輸出整個鏈錶的同名寵物                              */
void ShowList(const Item * pointer_item, const Tree * pointer_tree);

#endif
