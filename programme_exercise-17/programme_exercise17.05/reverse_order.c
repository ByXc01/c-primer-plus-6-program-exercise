/* File: reverse_order.c
 * Author: ByXc
 * About: reverse order
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170928
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 和 stack.c 一起编译 */
#include <stdio.h>
#include "stack.h"      // 提供 Item、Stack 類型定義和一系列接口函數聲明

static inline void show_item(Stack *);
int main(void)
{
    Item temp;
    Stack reverse;

    InitializeStack(&reverse);

    puts("Please enter an string:");
    while ((temp = getchar()) != EOF && !FullStack(&reverse))
        Push(temp, &reverse);

    if (!EmptyStack(&reverse))
    {
        puts("Show reverse order:");
        show_item(&reverse);
    }

    return 0;
}

static inline void show_item(Stack * pointer_stack)
{
    Item temp;

    while (Pop(&temp, pointer_stack))
        putchar(temp);
}
