/* pe14-5.c */

#include <stdio.h>
#include <string.h>

#define LENGTH 14
#define CSIZE 4
#define SCORES 3

struct name
{
    char first[LENGTH];
    char last[LENGTH];
};

struct student
{
    struct name person;
    float scores[SCORES];
    float mean;
};

void get_scores(struct student[], int limit);
void find_means(struct student[], int limit);
void show_class(const struct student array[], int limit);
void show_average(const struct student array[], int limit);

int main(void)
{
    struct student class[CSIZE] = 
    {
        { { "Flip", "Snide" } },
        { { "Clare", "Voyans" } },
        { {"Bingo", "Higgs" } },
        { {"Fawn", "Hunter" } } 
    };

    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_average(class, CSIZE);

    return 0;
}

void get_scores(struct student array[], int limit)
{
    int i, j;

    for (i = 0; i < limit; i++)
    {
        printf("Please enter %d scores for %s %s:\n", SCORES, array[i].person.first, array[i].person.last);
        for (j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &array[i].scores[j]) != 1)
            {
                scanf("*s");
                puts("Please use numberic input.");
            }
        }
    }
}

void find_means(struct student array[], int limit)
{
    int i, j;
    float sum;

    for (i = 0; i < limit; i++)
    {
        for (sum = 0, j = 0; j < SCORES; j++)
            sum += array[i].scores[j];
        array[i].mean = sum / SCORES;
    }
}

void show_class(const struct student array[], int limit)
{
    int i, j;
    char whole_name[2 * LENGTH];

    for (i = 0; i < limit; i++)
    {
        strcpy(whole_name, array[i].person.first);
        strcat(whole_name, " ");
        strcat(whole_name, array[i].person.last);
        
        printf("%27s: ", whole_name);
        for (j = 0; j < SCORES; j++)
            printf("%6.1f ", array[i].scores[j]);
        printf(" Average = %5.2f\n", array[i].mean);
    }
}

void show_average(const struct student array[], int limit)
{
    int i, j;
    float total;

    printf("\n%27s: ", "QUIZ AVERAGES");
    for (j = 0; j < SCORES; j++)
    {
        for (total = 0, i = 0; i < limit; i++)
            total += array[i].scores[j];
        printf("%6.2f ", total / limit);
    }

    for (total = 0, i = 0; i < limit; i++)
        total += array[i].mean;
    printf("%6.2f", total / limit);
}
