/* tree.c -- 樹的支持函數 */

#include <stdio.h>
#include <stdlib.h>     /* 為 malloc()、free() 和 exit() 提供函數原型, EXIT_FAILURE 宏 */
#include <stdbool.h>    /* 為使用 bool、true、false                                    */
#include <string.h>     /* 為 strmpy() 提供函數原型                                    */
#include "tree.h"       /* 提供 Item、Tree_node、Tree 類型定義                         */

/* 局部數據類型 */
typedef struct pair
{
    Tree_node * parent;
    Tree_node * child;
} Pair;

/* 局部函數的原型 */
static Tree_node * MakeNode(const Item * pointer_item);
static bool ToLeft(const Item * item1, const Item * item2);
static bool ToRight(const Item * item1, const Item * item2);
static void AddNode(Tree_node * new_node, Tree_node * root);
static void InOrder(const Tree_node * root, void (* pointer_function) (Item item));
static Pair SeekItem(const Item * pointer_item, const Tree * pointer_tree);
static void DeleteNode(Tree_node ** pointer);
static void DeleteAllNodes(Tree_node * pointer);

/* 函數定義 */
void InitializeTree(Tree * pointer_tree)
{
    pointer_tree->root = NULL;
    pointer_tree->items = 0;
}

bool TreeIsEmpty(const Tree * pointer_tree)
{
    if (pointer_tree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * pointer_tree)
{
    Tree_node * pointer_temp;
    bool full;

    pointer_temp = (Tree_node *) malloc(sizeof (Tree_node));
    if (pointer_temp == NULL)
        full = true;
    else
    {
        full = false;
        free(pointer_temp);
    }

    return full;
}

unsigned int TreeItemCount(const Tree * pointer_tree)
{
    return pointer_tree->items;
}

bool AddItem(Item * pointer_item, Tree * pointer_tree)
{
    Tree_node * new_node;
    Tree_node * duplicate;

    if (TreeIsFull(pointer_tree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if ((duplicate = SeekItem(pointer_item, pointer_tree).child) != NULL)
    {
        duplicate->item.count++;       /* 找到相同單項，項目數加一 */
        return true;
    }

    pointer_item->count = 1;
    new_node = MakeNode(pointer_item);  /* 指向新節點               */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    /* 成功創建了一個新節點 */
    pointer_tree->items++;
    
    if (pointer_tree->root == NULL)             /* 情況 1：樹為空     */
        pointer_tree->root = new_node;          /* 新節點為樹的根節點 */
    else                                        /* 情況 2：樹不為空   */
        AddNode(new_node, pointer_tree->root);  /* 在樹中添加新節點   */

    return true;
}

bool InTree(const Item * pointer_item, const Tree * pointer_tree)
{
    return (SeekItem(pointer_item, pointer_tree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pointer_item, Tree * pointer_tree)
{
    Pair look;

    look = SeekItem(pointer_item, pointer_tree);
    if (look.child == NULL)
        return false;

    if (look.child->item.count > 0)
        look.child->item.count--;
    else
    {
        if (look.parent == NULL)                /* 刪除根節點 */
            DeleteNode(&pointer_tree->root);
        else if (look.parent->left == look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
        pointer_tree->items--;
    }

    return true;
}

void Traverse(const Tree * pointer_tree, void (* pointer_function) (Item item))
{
    if (pointer_tree != NULL)
        InOrder(pointer_tree->root, pointer_function);
}

void DeleteAll(Tree * pointer_tree)
{
    if (pointer_tree != NULL)
        DeleteAllNodes(pointer_tree->root);
    pointer_tree->root = NULL;
    pointer_tree->items = 0;
}

/* 局部函數定義 */
static void InOrder(const Tree_node * root, void (* pointer_function) (Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pointer_function);
        (*pointer_function) (root->item);
        InOrder(root->right, pointer_function);
    }
}

static void DeleteAllNodes(Tree_node * root)
{
    Tree_node * pointer_right;

    if (root != NULL)
    {
        pointer_right = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pointer_right); 
    }
}

static void AddNode(Tree_node * new_node, Tree_node * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)                 /* 空子樹           */
            root->left = new_node;              /* 把節點添加到此處 */
        else
            AddNode(new_node, root->left);      /* 否則處理該子樹   */
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                                        /* 不允許有重複項  */
    {
        /* 可以暫時忽略此次結果，因為在本程序需要將重複項的項數記錄 */
        /* 所以這條語句就不會執行                                   */
        fprintf(stderr, "location error in AddNode()\n");
        exit(EXIT_FAILURE);
    }
}

static bool ToLeft(const Item * item1, const Item * item2)
{
    if (strcmp(item1->word, item2->word) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * item1, const Item * item2)
{
    if (strcmp(item1->word, item2->word) > 0)
        return true;
    else
        return false;
}

static Tree_node * MakeNode(const Item * pointer_item)
{
    Tree_node * new_node;

    new_node = (Tree_node *) malloc(sizeof (Tree_node));
    if (new_node != NULL)
    {
        new_node->item = *pointer_item;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekItem(const Item * pointer_item, const Tree * pointer_tree)
{
    Pair look;
    look.parent = NULL;
    look.child = pointer_tree->root;

    if (look.child == NULL)
        return look;            /* 提前返回 */
    
    while (look.child != NULL)
    {
        if (ToLeft(pointer_item, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pointer_item, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else                    /* 如果前兩種情況都不滿足，則必定是相等的情況 */
            break;              /* look.child 目標項的節點                    */
    }

    return look;                /* 成功返回                                   */
}

/* pointer 是指向目標節點的父節點指針成員的地址 */
static void DeleteNode(Tree_node ** pointer)
{
    Tree_node * temp;

    if ((*pointer)->left == NULL)
    {
        temp = *pointer;
        *pointer = (*pointer)->right;
        free(temp);
    }
    else if ((*pointer)->right == NULL)
    {
        temp = *pointer;
        *pointer = (*pointer)->left;
        free(temp);
    }
    else                        /* 被刪除的節點有兩個子節點 */ 
    {
        /* 找到重新連接右子樹的位置 */
        for (temp = (*pointer)->left; temp->right != NULL; temp = temp->right)
            continue;

        temp->right = (*pointer)->right;
        temp = (*pointer);
        *pointer = (*pointer)->left;
        free(temp);
    }
}
