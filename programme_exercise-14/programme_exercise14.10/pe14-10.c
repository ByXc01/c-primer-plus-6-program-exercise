/* 以下是標準答案 */
/* the tricky part is declaring an array of pointer to function */

#include <stdio.h>
#include <math.h>       // for sqrt()

#define NUM 4

double twice(double x);
double half(double x);
double thrice(double x);
void show_menu(void);

int main(void)
{
    double (* pointer_function_array[NUM])(double) = { twice, half, thrice, sqrt };
    double value;
    double answer;
    int select;

    printf("Enter a number (negative to quit): ");
    while (scanf("%lf", &value) && value >= 0)
    {
        show_menu();
        while (scanf("%d", &select) && select >= 0 && select <= 3)
        {
            answer = (*pointer_function_array[select])(value);      // first notation
            printf("answer = %f\n", answer);
            answer = pointer_function_array[select](value);         // alternative notation
            printf("to repeat, answer = %f\n", answer);
            show_menu();
        }
        printf("Enter next number (negative to quit): "); 
    }
    puts("Bye.");

    return 0;
}

void show_menu(void)
{
    puts("Enter one of the following choices: ");
    puts("0) double the value       1) halve the value");
    puts("2) triple the value       3) square root the value");
    puts("4) next number");
}

double twice(double x) { return 2.0 * x; }
double half(double x)  { return x / 2.0; }
double thrice(double x) { return 3.0 * x; }
