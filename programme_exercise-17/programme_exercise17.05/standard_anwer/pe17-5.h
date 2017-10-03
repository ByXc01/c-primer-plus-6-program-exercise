/* pe17-5.h -- head file for a stack type */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>        /* C99 */
/* enum bool { false, true }; */    /* pre-C99 */

/* inser item type here          */
/* for example, typedef int Item */

typedef char Item;

#define MAX_STACK 100

typedef struct stack
{
    Item items[MAX_STACK];      /* holds info                */
    int top;                    /* index of first empty slot */
} Stack;

/* operation:       initialize the stack                                 */
/* precondition:    pointer_stack points to a stack                      */
/* postcondition:   stack is initialized to being empty                  */
void InitializeStack(Stack * pointer_stack);

/* operation:       check if stack is full                               */
/* precondition:    pointer_stack points to previously initialized stack */
/* postcondition:   returns True if stack is full, else False            */
bool FullStack(const Stack * pointer_stack);

/* operation:       check if stack is empty                              */
/* precondition:    pointer_stack points to previously initialized stack */
/* postcondition:   returns True is stack is empty, else False           */
bool EmptyStack(const Stack * pointer_stack);

/* operation:       push item onto of stack                              */
/* precondition:    pointer_stack points to previously initialized stack */
/*                  item is to be placed on toop of stack                */
/* postcondition:   if stack is no full, item is placed at             */
/*                  top of stack and function returns                    */
/*                  True; otherwise, stack is unchanged and              */
/*                  function returns False                               */
bool Push(Item item, Stack * pointer_stack);

/* operation:       remove item from top of stack                        */
/* precondition:    pointer_stack points to previously initialized stack */
/* postcondition:   if stack is not empty, item at top of                */
/*                  stack is copied to *pointer_item and deleted form    */
/*                  stack, and function returns True; if the             */
/*                  operation empties the stack, the stack is            */
/*                  reset to empty. If the stack is empty to             */
/*                  begin with, stack is unchanged and the               */
/*                  function returns False                               */
bool Pop(Item * pointer_item, Stack * pointer_stack);

#endif
