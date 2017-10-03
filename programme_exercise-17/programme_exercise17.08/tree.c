//* tree.c -- 樹的支持函數 */

#include <stdio.h>
#include <stdlib.h>     /* 為 exit() 提供函數原型    */
#include <string.h>     /* for strcmp() 提供函數原型 */
#include "tree.h"

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
static void InOrder(const Tree_node * root, void(* pointer_function) (Item item));
static Pair SeekItem(const Item * pointer_item, const Tree * pointer_tree);
static void DeleteNode(Tree_node ** pointer);
static void DeleteAllNodes(Tree_node * pointer);
static Item * MakeItem(const Item * pointer_item);
static void DeleteAllItem(Item * head);
static bool AddList(Tree_node * root, const Item * pointer_item);
static bool DeleteListNode(Tree_node ** root, const Item * pointer_item);

/* 函數定義 */
void InitializeTree(Tree * pointer_tree)
{
    pointer_tree->root = NULL;
    pointer_tree->size = 0;
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
    if (pointer_tree->size == MAX_ITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * pointer_tree)
{
    return pointer_tree->size;
}

bool AddItem(const Item * pointer_item, Tree * pointer_tree)
{
    Tree_node * new_node;
    Pair look;

    if (TreeIsFull(pointer_tree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;                               /* 提前返回             */
    }

                                                    /* 查找同名的寵物       */
    if ((look = SeekItem(pointer_item, pointer_tree)).child != NULL)
    {
        if (AddList(look.child, pointer_item))      /* 把項添加到鏈錶中     */
        {
            pointer_tree->size++;
            return true;
        }
        else
        {
            fprintf(stderr, "Couldn't create list node.\n");
            return false;
        }
        //fprintf(stderr, "Attempted to add duplicate item\n");
        //return false;                             /* 提前返回             */
    }

    new_node = MakeNode(pointer_item);              /* 指向新節點           */ 
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create tree node.\n");
        return false;                               /* 提前返回             */
    }

    /* 成功創建了一個新節點 */
    pointer_tree->size++;

    if (pointer_tree->root == NULL)                 /* 情況1：樹為空         */
        pointer_tree->root = new_node;              /* 新節點為樹的根節點    */
    else                                            /* 情況2：樹不為空       */
        AddNode(new_node, pointer_tree->root);      /* 在樹中添加新節點      */

    return true;                                    /* 成功返回              */
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
    
    if (DeleteListNode(&look.child, pointer_item))  /* 刪除寵物鏈錶裡的項   */
    {
        pointer_tree->size--;
        return true;
    }

    if (look.parent == NULL)                        /* 刪除根節點項 */
        DeleteNode(&pointer_tree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    pointer_tree->size--;

    return true;
}

void Traverse(const Tree * pointer_tree, void (* pointer_function) (Item item))
{
    if (pointer_tree != NULL)
        InOrder(pointer_tree->root, pointer_function);
}

void ShowList(const Item * pointer_item, const Tree * pointer_tree)
{
      Tree_node * temp;
      Item * save;

     temp = SeekItem(pointer_item, pointer_tree).child;
     if (temp != NULL)
     {
         save = temp->head;
         while (save != NULL)                       /* 遍歷鏈錶里的同名寵物 */
         {
             printf("name: %s, kind: %s\n", save->pet_name, save->pet_kind);
             save = save->next;
         }
     }
     else
         puts("Not found!");
}

void DeleteAll(Tree * pointer_tree)
{
    if (pointer_tree != NULL)
        DeleteAllNodes(pointer_tree->root);
    pointer_tree->root = NULL;
    pointer_tree->size = 0;
}

/* 局部函數 */
static void InOrder(const Tree_node * root, void (* pointer_function) (Item item))
{
    Item * temp;

    if (root != NULL)
    {
        InOrder(root->left, pointer_function);
        temp = root->head;
        while (temp != NULL)                        /* 遍歷每個二叉樹節點中同名寵物的鏈錶 */
        {
            (*pointer_function) (*temp);
            temp = temp->next;
        }
        InOrder(root->right, pointer_function);
    }
}

static void DeleteAllNodes(Tree_node * root)
{
    Tree_node * pointer_right;

    if (root != NULL)
    {
        pointer_right = root->right;
        DeleteAllNodes(root->left);                 /* 遞歸釋放已分配二叉樹內存 */
        DeleteAllItem(root->head);                  /* 釋放已分配鏈錶內存       */
        free(root);
        DeleteAllNodes(pointer_right);
    }
}

static void AddNode(Tree_node * new_node, Tree_node * root)
{
    if (ToLeft(new_node->head, root->head))
    {
        if (root->left == NULL)                     /* 空子樹           */
            root->left = new_node;                  /* 把節點添加到此處 */
        else
            AddNode(new_node, root->left);          /* 否則處理該子樹   */
    }
    else if (ToRight(new_node->head, root->head))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                                            /* 不允許有重複項   */
    {
        /* 在本程序使用的方式可以有重複項，但這語句也不會執行。留著以便以後需要 */
        fprintf(stderr, "location error in AddNode()\n");
        exit(EXIT_FAILURE);
    }
}

static bool ToLeft(const Item * item1, const Item * item2)
{
    if (strcmp(item1->pet_name, item2->pet_name) < 0)       /* 按寵物名排序 */
        return true;
    else
        return false;
}

static bool ToRight(const Item * item1, const Item * item2)
{
    if (strcmp(item1->pet_name, item2->pet_name) > 0)
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
        new_node->head = MakeItem(pointer_item);
        new_node->end = new_node->head;
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
        if (ToLeft(pointer_item, look.child->head))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pointer_item, look.child->head))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else                    /* 如果前兩種情況都不滿足，則必定是相等的情況 */
            break;              /* look.child 目標項的節點                    */
    }

    return look;                /* 成功返回 */
}

static void DeleteNode(Tree_node ** pointer)
{
    Tree_node * temp;

    DeleteAllItem((*pointer)->head);        /* 把二叉樹節點中的鏈錶釋放 */
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
    else                                    /* 被刪除的節點有兩個子節點 */
    {
        /* 找到重新連接的右子樹的位置 */
        for (temp = (*pointer)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*pointer)->right;

        temp = *pointer;
        *pointer = (*pointer)->left;
        free(temp);
    }
}

static void DeleteAllItem(Item * head)
{
    Item * temp = head;

    while (temp != NULL)
    {
        head = temp->next;
        free(temp);
        temp = head;
    }
}

static Item * MakeItem(const Item * pointer_item)
{
    Item * temp;

    temp = (Item *) malloc(sizeof (Item));
    if (temp != NULL)
    {
        *temp = *pointer_item;
        temp->next = NULL;
    }

    return temp;
}

static bool AddList(Tree_node * root, const Item * pointer_item)
{
    Item * new;

    new = MakeItem(pointer_item);
    if (new == NULL)
        return false;
     
    if (root->head == NULL)         /* 鏈錶是空的       */
        root->head = new;           /* 設置頭指針       */
    else                            /* 鏈錶不為空       */
        root->end->next = new;      /* 添加到鏈錶末尾   */
    root->end = new;

    return true;
}

static bool DeleteListNode(Tree_node ** root, const Item * pointer_item)
{
    Item * temp, * previous;
    Item ** current;

    current = &(*root)->head;
    while (*current != NULL)        /* 遍歷鏈錶 */
    {
        /* 找到要刪除的項 */
        if (strcmp(pointer_item->pet_name, (*current)->pet_name) == 0 &&
            strcmp(pointer_item->pet_kind, (*current)->pet_kind) == 0)
        {
            temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
        previous = *current;
        current = &(*current)->next;
    }

    if ((*root)->head == NULL)      /* 只有一項，返回 false，以便於把二叉樹也釋放了 */
        return false; 
    if (*current == NULL)
        (*root)->end = previous;    /* 當刪除的項是最后項時，重新設置尾指針         */

    return true;
}
