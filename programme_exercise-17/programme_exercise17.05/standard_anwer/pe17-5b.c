/* pe17-5b.c -- stack operations */

#include <stdio.h>
#include "pe17-5.h"

void InitializeStack(Stack * pointer_stack)
{
    pointer_stack->top = 0;
}

bool FullStack(const Stack * pointer_stack)
{
    return pointer_stack->top == MAX_STACK;
}

bool EmptyStack(const Stack * pointer_stack)
{
    return pointer_stack->top == 0;
}

bool Push(Item item, Stack * pointer_stack)
{
    if (pointer_stack->top == MAX_STACK)
        return false;
    else
    {
        pointer_stack->items[pointer_stack->top++] = item;
        return true;
    }
}

bool Pop(Item * pointer_item, Stack * pointer_stack)
{
    if (pointer_stack->top == 0)
        return false;
    else
    {
        pointer_stack->top--;
        *pointer_item = pointer_stack->items[pointer_stack->top];
        return true;
    }
}
