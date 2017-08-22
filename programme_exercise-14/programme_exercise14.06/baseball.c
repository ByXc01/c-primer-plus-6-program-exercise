/* File: baseball.c
 * Author: ByXc
 * About: baseball
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170812
 * Github: ByXc
 * Blog: http://ByXc01.github.io
 */

/* 個人覺得這道題的難點就是：文件里有很多姓名，姓名有可能出現多次，但姓名是不確定的。
 * 要累計每個相同姓名的數據。想了好久，使用了姓名排序和剔除相同姓名的方法。做的很複
 * 雜。因為標準答案沒有這一題， 我就在在百度和 google 都沒有找到符合題意得答案。我這
 * 個應該蠻接近答案的。
 */

#include <stdio.h>
#include <stdlib.h>     // 為 exit() 提供函數原型, 為 EXIT_FAILURE 提供宏
#include <string.h>     // 為 strcmp()、strcpy() 提供函數原型
#include <stdbool.h>    // 為 false、true、bool 提供宏 

#define FILE_NAME "record.dat"
#define LENGTH 12
#define MAX 18

struct data
{
    struct { char cha_first_name[LENGTH]; char cha_last_name[LENGTH]; };    // 匿名結構
    int i_go;
    int i_hit, i_walk, i_run_batted_in;
    float fl_batting_average;
};

int initialization(struct data * [], FILE *, struct data *, int);           // 從文件讀取并初始化
void sort_name(struct data * [], int);                                      // 將名字排序
int repeat(struct data * [], struct data *, int);                           // 計算參賽人員
void sum(struct data *, struct data * const[], int, int);                   // 統計數據
void show(struct data *, int);                                              // 輸出數據
void show_sorted(struct data * const [], int);                              // 將排序好的名字輸出

int main(void)
{
    struct data baseball[MAX];                          // 存儲文件內容
    struct data * pointer[MAX];                         // 結構數組，用作排序
    struct data total[MAX] =                            // 累計數據
    {
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
        { { "\0", "\0" }, 0, 0, 0, 0, 0.0  },
    };
    int i_max;                                          // 參賽人員
    int i_person;                                       // 實際參賽人員
    FILE * fp_file;                                     // 文件指針

    if ((fp_file = fopen(FILE_NAME, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    i_max = initialization(pointer, fp_file, baseball, MAX);
    sort_name(pointer, i_max); 
    show_sorted(pointer, i_max);

    i_person = repeat(pointer, total, i_max);
    sum(total, pointer, i_person, i_max);
    show(total, i_person);

    if (ferror(fp_file) != 0)
        fputs("Error in reading file.\n", stderr);

    if (fclose(fp_file) != 0)
        fprintf(stderr, "Error in closeing file.\n");

    return 0;
}

int initialization(struct data * sta_data[], FILE * fp_file, struct data * st_pointer, int i_number)
{
    int i_count = 0;

    // 從文件讀取姓名
    while (i_count < i_number && fscanf(fp_file, "%s %s", st_pointer[i_count].cha_first_name, st_pointer[i_count].cha_last_name) == 2)
    {
        // 從文件讀取其餘數據
        if (fscanf(fp_file, "%d %d %d %d", &st_pointer[i_count].i_go, &st_pointer[i_count].i_hit, &st_pointer[i_count].i_walk, &st_pointer[i_count].i_run_batted_in) == 4)
        {
            // 計算RBI(run batted in)
            st_pointer[i_count].fl_batting_average = (float) st_pointer[i_count].i_hit / st_pointer[i_count].i_go;
            sta_data[i_count] = &st_pointer[i_count];       // 儲存結構指針，以便排序
            i_count++;
        }
    }

    return i_count;                                         // 返回參賽球員
}

void sort_name(struct data * sta_pointer[], int i_number)
{
    int i_count, i_index;
    int i_temp_index;           // 記錄首次出現不同姓名的下標
    bool b_flag;
    struct data * st_temp;

    for (i_count = 0; i_count < i_number - 1; i_count++)
    {
        b_flag = true;
        for (i_index = i_count + 1; i_index < i_number; i_index++)
        {
            // 兩個姓名比較, 如果都不是同一姓名
            if (strcmp(sta_pointer[i_count]->cha_first_name, sta_pointer[i_index]->cha_first_name) != 0 && strcmp(sta_pointer[i_count]->cha_last_name, sta_pointer[i_index]->cha_last_name) != 0 && b_flag)
            {
                i_temp_index = i_index;
                b_flag = false;
            }
            // 如果找到相同的姓名，則退出循環
            else if (strcmp(sta_pointer[i_count]->cha_first_name, sta_pointer[i_index]->cha_first_name) == 0 && strcmp(sta_pointer[i_count]->cha_last_name, sta_pointer[i_index]->cha_last_name) == 0)
                break;
        }

        // 判斷是否標記到了首次出現不同姓名下標，如果 i_index == i_number 說明遍歷一遍沒有找到
        if (!b_flag && i_index != i_number)
        {
            // 將姓名互換，實現排序
            st_temp = sta_pointer[i_temp_index];
            sta_pointer[i_temp_index] = sta_pointer[i_index];
            sta_pointer[i_index] = st_temp;
        }
    }
}

int repeat(struct data * sta_pointer[], struct data * sta_name, int i_number)
{
    int i_count, i_index;
    int i_temp;

    for (i_count = i_index = 0; i_count < i_number - 1; i_count++)
    {
        // 兩個姓名比較
        if (strcmp(sta_pointer[i_count]->cha_first_name, sta_pointer[i_count + 1]->cha_first_name) != 0 && strcmp(sta_pointer[i_count]->cha_last_name, sta_pointer[i_count + 1]->cha_last_name) != 0)
        {
            // 如果不同則拷貝第一個姓名
            strcpy(sta_name[i_index].cha_first_name, sta_pointer[i_count]->cha_first_name);
            strcpy(sta_name[i_index].cha_last_name, sta_pointer[i_count]->cha_last_name);

            // 記錄拷貝的下標
            i_temp = i_count;
            i_index++;
        }
    }

    // 如果拷貝的下標和最後一個元素下標的姓名不相同
    if (strcmp(sta_pointer[i_temp]->cha_first_name, sta_pointer[i_number - 1]->cha_first_name) != 0 && strcmp(sta_pointer[i_temp]->cha_last_name, sta_pointer[i_number - 1]->cha_last_name) != 0)
    {
        // 則拷貝最後一個姓名
        strcpy(sta_name[i_index].cha_first_name, sta_pointer[i_number - 1]->cha_first_name);
        strcpy(sta_name[i_index].cha_last_name, sta_pointer[i_number - 1]->cha_last_name);
    }

    return ++i_index;
}

void sum(struct data * stp_total, struct data * const sta_pointer[], int i_row, int i_col)
{
    int i_count , i_index;

    for (i_count = 0; i_count < i_row; i_count++)
    {
        for (i_index = 0; i_index < i_col; i_index++)
        {
            // 如果姓名相同，說明是同一個人
            if (strcmp(stp_total[i_count].cha_first_name, sta_pointer[i_index]->cha_first_name) == 0 && strcmp(stp_total[i_count].cha_last_name, sta_pointer[i_index]->cha_last_name) == 0)
            {
                // 累計數據 
                stp_total[i_count].i_go += sta_pointer[i_index]->i_go;
                stp_total[i_count].i_hit += sta_pointer[i_index]->i_hit;
                stp_total[i_count].i_walk += sta_pointer[i_index]->i_walk;
                stp_total[i_count].i_run_batted_in += sta_pointer[i_index]->i_run_batted_in;
                stp_total[i_count].fl_batting_average += sta_pointer[i_index]->fl_batting_average;
            }
        }
    }
}

void show(struct data * stp_total, int i_number)
{
    int i_count;
    
    puts("Entire team:");
    for (i_count = 0; i_count < i_number; i_count++)
    {
        printf("%s %s ", stp_total[i_count].cha_first_name, stp_total[i_count].cha_last_name);
        printf("%d %d %d %d %f\n", stp_total[i_count].i_go, stp_total[i_count].i_hit, stp_total[i_count].i_walk, stp_total[i_count].i_run_batted_in, stp_total[i_count].fl_batting_average);
    }
}

void show_sorted(struct data * const sta_pointer[], int i_number)
{
    int i_count;

    puts("Sorted content:");
    for (i_count = 0; i_count < i_number; i_count++)
    {
        printf("%d %s %s ", i_count, sta_pointer[i_count]->cha_first_name, sta_pointer[i_count]->cha_last_name);
        printf("%d %d %d %d ", sta_pointer[i_count]->i_go, sta_pointer[i_count]->i_hit, sta_pointer[i_count]->i_walk, sta_pointer[i_count]->i_run_batted_in);
        printf("%f\n", sta_pointer[i_count]->fl_batting_average);
    }
    putchar('\n');
}
