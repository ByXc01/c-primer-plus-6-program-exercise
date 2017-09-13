// #pragma once 為了兼容所有的編譯器，不用這條編譯指示。

#ifndef NAMES_H_    // 作用為了不重複包含
#define NAMES_H_
#define LENGTH 14

typedef struct name // 類型定義
{
    char first_name[LENGTH];
    char last_name[LENGTH];
} Name;

// 函數原型
void show_name(const Name[], int);
int comp(const void *, const void *);

#endif
