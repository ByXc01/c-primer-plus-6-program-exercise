/* tree.c -- tree support functions */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

/* local data type */
typedef struct pair
{
    Node * parent;
    Node * child;
} Pair;

/* prototypes for local functions */
static Node * MakeNode(const Item * pointer_item);
static bool ToLeft(const Item * item1, const Item * item2);
static bool ToRight(const Item * item1, const Item * item2);
static void AddNode(Node * new_node, Node * root);
static void InOrder(const Node * root, void (* pointer_function) (Item item));
static Pair SeekItem(const Item * pointer_item, const Tree * pointer_tree);
static void DeleteNode(Node ** pointer);
static void DeleteAllNodes(Node * pointer);

/* function definitions */
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
    Node * new;
    Pair seek;

    if (TreeIsFull(pointer_tree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;               /* early return             */
    }

    if ((seek = SeekItem(pointer_item, pointer_tree)).child != NULL)
    {
        seek.child->item.count++;
        return true;                /* new points to new node   */
    }

    new = MakeNode(pointer_item);   /* new points to new node   */
    if (new == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;               /* early return             */
    }
    /* succeeded in creating a new node */
    pointer_tree->size++;

    if (pointer_tree->root == NULL)         /* case 1: tree is empty    */
        pointer_tree->root = new;           /* new node is tree root    */
    else                                    /* case 2: not empty        */ 
        AddNode(new, pointer_tree->root);   /* case 2: not emtpy        */

    return true;
}

bool InTree(const Item * pointer_item, const Tree * pointer_tree)
{
    return (SeekItem(pointer_item, pointer_tree).child == NULL) ? false : true;
}

const Item * WhereInTree(const Item * pointer_item, const Tree * pointer_tree)
{
    Node * pointer_node;

    pointer_node = SeekItem(pointer_item, pointer_tree).child;
    if (pointer_node != NULL)
        return &(pointer_node->item);
    else
        return NULL;
}

bool DeleteItem(const Item * pointer_item, Tree * pointer_tree)
{
    Pair look;
    look = SeekItem(pointer_item, pointer_tree);

    if (look.child == NULL)
        return false;

    if (look.parent->item.count > 0)
        look.parent->item.count--;
    else
    {
        if (look.parent == NULL)        /* delete root item */
            DeleteNode(&pointer_tree->root);
        else if (look.parent->left == look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
        pointer_tree->size--;
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
    pointer_tree->size = 0;
}

/* local functions */
static void InOrder(const Node * root, void (* pointer_function) (Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pointer_function);
        (*pointer_function) (root->item);
        InOrder(root->right, pointer_function);
    }
}

static void DeleteAllNodes(Node * root)
{
    Node * pointer_right;

    if (root != NULL)
    {
        pointer_right = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pointer_right);
    }
}

static void AddNode(Node * new_node, Node * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)                     /* empty subtree          */
            root->left = new_node;                  /* so add node here       */
        else
            AddNode(new_node, root->left);          /* else process subtree   */
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                                            /* should be no duplicate */
    {
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

static Node * MakeNode(const Item * pointer_item)
{
    Node * new_node;

    new_node = (Node *) malloc(sizeof (Node));
    if (new_node != NULL)
    {
        new_node->item = *pointer_item;
        new_node->item.count = 1;
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
        return look;            /* early return     */

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
        else                    /* must be same if not to left or right     */
            break;              /* look.child is address of node witch item */
    }

    return look;                /* successful return                        */
}

/* pointer is address of parent member pointing to target node */
static void DeleteNode(Node ** pointer)
{
    Node * temp;

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
    }
    else    /* deleted node has tow children */
    {
        /* find where to reattach right subtree */
        for (temp = (*pointer)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*pointer)->right;
        temp = *pointer;
        *pointer = (*pointer)->left;
        free(temp);
    }
}
