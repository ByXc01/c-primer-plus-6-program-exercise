// 要與 main.c 一起編譯

#include <stdio.h>
#include <string.h>     // for strcmp()
#include "name_st.h"    // for Name

void show_name(const Name cN_name[], int i_limits)
{
    int i_index;

    for (i_index = 0; i_index < i_limits; i_index++)
        printf("%s %s\n", cN_name[i_index].first_name, cN_name[i_index].last_name);
    putchar('\n');
}

int comp(const void * name1, const void * name2)
{
    // 得到正確類型的指針
    const Name * cN_n1 = (const Name *) name1;
    const Name * cN_n2 = (const Name *) name2;

    int i_flag;

    i_flag = strcmp(cN_n1->last_name, cN_n2->last_name);        // 比較姓
    if (i_flag != 0)
        return i_flag;
    else                                                        // 如果同姓，則比較名
        return strcmp(cN_n1->first_name, cN_n2->first_name);
}
