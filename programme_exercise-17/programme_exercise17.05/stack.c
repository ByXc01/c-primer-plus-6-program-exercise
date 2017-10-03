/* stack.c -- Satck 類型的實現 */

#include <stdbool.h>        // 為使用 bool、true、false
#include "stack.h"          // 提供 Item、Stack 類型定義和 MAX_STACK 宏

/* 初始化 */
void InitializeStack(Stack * pointer_stack)
{
    pointer_stack->top = MAX_STACK - 1;
}

/* 檢查棧是否已滿 */
bool FullStack(const Stack * pointer_stack)
{
    return pointer_stack->top == -1;
}

/* 價差棧是否為空 */
bool EmptyStack(const Stack * pointer_stack)
{
    return pointer_stack->top == MAX_STACK - 1;
}

/* 把項壓入棧頂 */
bool Push(Item item, Stack * pointer_stack)
{
    if (FullStack(pointer_stack))
        return false;

    pointer_stack->items[pointer_stack->top] = item;
    pointer_stack->top--;

    return true;
}

/* 從棧頂刪除項 */
bool Pop(Item * pointer_item, Stack * pointer_stack)
{
    if (EmptyStack(pointer_stack))
        return false;

    *pointer_item = pointer_stack->items[pointer_stack->top + 1];
    pointer_stack->top++;

    return true;
}
