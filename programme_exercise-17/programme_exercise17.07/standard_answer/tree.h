/* tree.h -- binary search tree               */
/* no dupilcate items are allowd in this tree */

#ifndef TREE_H_
#define TREE_H_

#include <stdbool.h>        /* C99 */
/* enum bool { false, true }; */   /* ptr-C99 */

#define STRING_LENGTH 81

/* redefine Item as appropriate */
typedef struct item
{
    char word[STRING_LENGTH];
    int count;
} Item;

#define MAX_ITEMS 100

typedef struct node
{
    Item item;
    struct node * left;     /* pointer to left branch  */
    struct node * right;    /* pointer to right branch */
} Node;

typedef struct tree
{
    Node * root;            /* pointer to root of tree */
    int size;               /* number of items in tree */
} Tree;

/* function prototypes */

/* operation:        initialize a tree to empty                     */
/* preconditions:    pointer_tree points to a tree                  */
/* postconditions:   the tree is initialized to empty               */
void InitializeTree(Tree * pointer_tree);

/* operation:       determine if tree is empty                      */
/* precondition:    pointer_tree points to a tree                   */
/* postcondition:   function returns true if tree is empty and      */
/*                  returns false otherwise                         */
bool TreeIsEmpty(const Tree * pointer_tree);

/* operation:       determine if tre is full                        */
/* preconditions:    pointer_tree points to a tree                  */
/* postconditions:   function returns true if tree is full and      */
/*                  returns false otherwise                         */
bool TreeIsFull(const Tree * pointer_tree);

/* operation:       determine number of items in tree               */
/* preconditions:    pointer_tree points to a tree                  */
/* postconditions:   function retruns number of items in tree       */
int TreeItemCount(const Tree * pointer_tree);

/* operation:       add an item to a tree                           */
/* preconditions:    pointer_item is address of item to be added    */
/*                  pointer_tree ponints to an initialized tree     */
/* postconditions:   if possible, function adds item to tree and    */
/*                  returns true; otherwise, the function           */ 
/*                  return false                                    */
bool AddItem(const Item * pointer_item, Tree * pointer_tree);

/* operation:       find an item in a tree                          */
/* preconditions:    pointer_item points to an item                 */
/*                  pointer_tree points to an initialied tree       */
/* postconditions:   function returns true if item is in tree and   */
/*                  returns false otherwise                         */
bool InTree(const Item * pointer_item, const Tree * pointer_tree);

/* operation:       delete an item from a tree                      */
/* preconditions：   pointer_item is address of item to be deleted  */
/*                  pointer_tree points to an initialized tree      */
/* postconditions:   if possible, function deletes item from tree   */
/*                  and return true;                                */
/*                  otherwise, the function returns false           */
bool DeleteItem(const Item * pointer_item, Tree * pointer_tree);

/* operation:       apply a function to each item in the tree       */
/* preconditions:    pointer_tree pointes to a tree                 */
/*                  pointer_function points to a function that      */
/*                  taked an Item argument and has no return value  */
/* postconditions:   the function pointed to by pfun is executed    */
/*                  once for each item in tree                      */
void Traverse(const Tree * pointer_tree, void (* pointer_function) (Item item));

/* operation:       delete everything from a tree                   */
/* preconditions:    pointer_tree points to an initialized tree     */
/* postconditions:   tree is empty                                  */
void DeleteAll(Tree * pointer_tree);

/* operation:       return address of item in a tree                */
/* preconditions:   pointer_item points to an item                  */
/*                  pointer_tree points to an initialized tree      */
/* postconditions:  function returns address if item is in tree and */
/*                  returns NULL otherwise                          */
const Item * WhereInTree(const Item * pointer_item, const Tree * ponter_tree);

#endif
