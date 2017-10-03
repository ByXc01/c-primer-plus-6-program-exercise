/* tree.h -- 二叉查找樹 */

#ifndef TREE_H_
#define TREE_H_

#include <stdbool.h>

/* 根據具體情況重新定義 Item */
#define STRING_LENGTH 20        /* 假設每個單詞最大長度為 20 */
typedef struct item
{
    char word[STRING_LENGTH];   /* 單詞                      */
    int count;                  /* 單詞出現的次數            */
} Item;

typedef struct tree_node
{
    Item item;
    struct tree_node * left;    /* 指向左分支的指針          */
    struct tree_node * right;   /* 指向右分支的指針          */
} Tree_node;

typedef struct tree
{
    Tree_node * root;           /* 指向根節點的指針          */
    unsigned int items;         /* 數的項數                  */
} Tree;

/* 函數原型 */
/* 題目沒要求寫這麼多函數，我還是寫了 */

/* 操作：       把樹初始化為空                                          */
/* 前提條件：   pointer_tree 指向一個樹                                 */
/* 後置條件：   樹被初始化為空                                          */
void InitializeTree(Tree * pointer_tree);

/* 操作：       確定樹中是否為空                                        */
/* 前提條件：   pointer_tree 指向一個已初始化的樹                       */
/* 後置條件：   如果樹為空，該函數返回 true                             */
/*                  否則，返回 false                                    */
bool TreeIsEmpty(const Tree * pointer_tree);

/* 操作：       確定樹是否已滿                                          */
/* 前提條件：   pointer_tree 指向一個已初始化的樹                       */
/* 後置條件：   如果樹已滿，該函數返回 true                             */
bool TreeIsFull(const Tree * pointer_tree);

/* 操作：       確定樹的項數                                            */
/* 前提條件：   pointer_tree 指向一個樹                                 */
/* 後置條件：   返回樹的項數                                            */
unsigned int TreeItemCount(const Tree * pointer_tree);

/* 操作：       在樹中添加一個項                                        */
/* 前提條件：   pointer_item 是待添加項的地址                           */
/*                  pointer_tree 指向一個已初始化的樹                   */
/* 後置條件：   如果可以添加，該函數將在樹中添加一個項                  */
/*                  并返回 true；否則，返回 false                       */
bool AddItem(Item * pointer_item, Tree * pointer_tree);

/* 操作：       在樹中查找一個項                                        */
/* 前提條件：   pointer_item 指向一個項                                 */
/*                  pointer_tree 指向一個已初始化的樹                   */
/* 後置條件：   如果該項在樹中，該函數返回 true                         */
/*                  否則，返回 false                                    */
bool InTree(const Item * pointer_item, const Tree * pointer_tree);

/* 操作：       從樹中刪除一個項                                        */
/* 前提條件：   pointer_item 是刪除項的地址                             */
/*                  pointer_tree 指向一個已初始化的樹                   */
/* 後置條件：   如果從樹中成功刪除成功刪除一個項，該函數返回 true       */
/*                  否則，返回 false                                    */
bool DeleteItem(const Item * pointer_item, Tree * pointer_tree);

/* 操作：       把函數應用與樹中的每一項                                */
/* 前提條件：   pointer_tree 指向一個樹                                 */
/*                  pointer_function 指向一個函數                       */
/*                  該函數接受一個 Item 類型的參數，并無返回值          */
/* 後置條件：   pointer_function 指向的這個函數為樹中的每一項執行一次   */
void Traverse(const Tree * pointer_tree, void (* pointer_function) (Item item));

/* 操作：       刪除樹中的所有內容                                      */
/* 前提條件：   pointer_tree 指向一個已初始化的樹                       */
/* 後置條件：   樹為空                                                  */
void DeleteAll(Tree * pointer_tree);

#endif
