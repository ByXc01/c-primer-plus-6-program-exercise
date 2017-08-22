/* 此文件定義了結構變量供 months.c 引用, 要與 months.c 一起編譯 */

#include "mode.h"       // 提供結構聲明

#define MONTHS 12
struct month months[MONTHS] = 
{
    { "January", "jan", 31, 1 },
    { "February", "feb", 28, 2 },
    { "March", "mar", 31, 3 },
    { "April", "apr", 30, 4 },
    { "May", "may", 31, 5 },
    { "June", "jun", 30, 6 },
    { "July", "jul", 31, 7 },
    { "August", "Aug", 31, 8 },
    { "Setember", "set", 30, 9 },
    { "October", "oct", 31, 10 },
    { "November", "nov", 30, 11 },
    { "December", "dec", 31, 12 }
};
