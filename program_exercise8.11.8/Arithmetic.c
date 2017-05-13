/* File: Arithmetic.c
 * Author: ByXc
 * About: Arithmetic
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513 	
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */


#include <stdio.h>
#include <ctype.h>

void binary_operation(char ch_choice, float fl_are_operand, float fl_operand);
void display(void);
void input(char i_choice);

int main(void)
{
    char ch_letter;

    display();
    while ((ch_letter = getchar()) != 'q')
    {
        while (getchar() != '\n')
            continue;

        if (ch_letter == 'a' || ch_letter == 's' || ch_letter == 'm' || ch_letter == 'd')
            input(ch_letter);
        else
        {
            printf("Please enter error! Please enter a, s, m, d or q. \n");
            continue;
        }
        display();
    }
    printf("Wlelcome to use. goodbye. \n");
    
    return 0;
}

void display(void)
{
    printf("Enter the operation of your choice: \n");
    printf("a. add           s. subtract \n");
    printf("m. multiply      d. divide \n");
    printf("q. quit \n");
}

void input(char ch_choice)
{
    float fl_first_number, fl_second_number;
    char ch_error;
    _Bool B_brue;

    printf("Enter first number:");
    while ((B_brue = (scanf("%f", &fl_first_number) != 1)))
    {
        while ((ch_error = getchar()) != '\n')
            putchar(ch_error);
        printf(" is not an number. \n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
    }

loop:
    printf("Enter second number:");
    if (!B_brue)
    {
        while (scanf("%f", &fl_second_number) != 1)
         {
             while ((ch_error = getchar()) != '\n')
                 putchar(ch_error);
             printf(" is not an number. \n");
             printf("Please enter a nubmer, such as 2.5, -1.7E8, or 3:");
         }

        if (ch_choice == 'd' && fl_second_number == 0)
        {
            printf("Zoro divisor cannot do. Please enter again try. \n");
            goto loop;
        }
        else
            binary_operation(ch_choice, fl_first_number, fl_second_number);

        while (getchar() != '\n')
            continue;
    }
}

void binary_operation(char ch_select, float fl_are_operand, float fl_operand)
{
    float fl_sum;

    switch(ch_select)
    {
        case 'a':
            fl_sum = fl_are_operand + fl_operand;
            printf("%g + %g = %g \n", fl_are_operand, fl_operand, fl_sum);
            break;

        case 's':
            fl_sum = fl_are_operand - fl_operand;
            printf("%g - %g = %g \n", fl_are_operand, fl_operand, fl_sum);
            break;

        case 'm':
            fl_sum = fl_are_operand * fl_operand;
            printf("%g * %g = %g \n", fl_are_operand, fl_operand, fl_sum);
            break;

        case 'd':
            fl_sum = fl_are_operand / fl_operand;
            printf("%g / %g = %g \n", fl_are_operand, fl_operand, fl_sum);
            break;

        default:
            printf("Enter error! \n");
            break;
    }
}
