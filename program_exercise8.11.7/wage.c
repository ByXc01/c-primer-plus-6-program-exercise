#include <stdio.h>
#include <string.h>

#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

#define BREAK1 300.0
#define BREAK2 450.0

#define BASE1 ((1.0 - RATE1) * BREAK1)
#define BASE2 (BASE1 + ((1.0 - RATE2) * (BASIC_WAGE - BREAK1)))

#define BASE3 (BASE1 + (1.0 - RATE2) * (BREAK2 - BREAK1))
#define BASE4 (BASE3 + (1.0 - RATE3) * ((db_week_hour - CI_OVERTIME) * CFL_OVERTIME_PAY * db_hour_wage))
#define BASE5 ((BREAK1 + (BREAK2 - BREAK1)) + ((db_week_hour - CI_OVERTIME) * db_hour_wage * CFL_OVERTIME_PAY))
#define BASE6 (BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2)

#define BASIC_WAGE (db_week_hour * db_hour_wage)
#define OVERTIME_PAY ((db_week_hour - CI_OVERTIME) * db_hour_wage * CFL_OVERTIME_PAY)

#define PRINT "Enter the number corresponding to the pay rate or acrion: "

#define HOUR_WAGE1 8.75
#define HOUR_WAGE2 9.33
#define HOUR_WAGE3 10.00
#define HOUR_WAGE4 11.20

const float CFL_OVERTIME_PAY = 1.5;
const float CFL_BASIC_SALARY = 10.0;
const int CI_OVERTIME = 40;
char ch_character;

void choice(char ch_letter);
void compute(double db_week_hour, double db_hour_wage);
void print(void);
int main(void)
{
    print();
    while ((ch_character = getchar()) != 'q')
    {
        choice(ch_character);

        while (getchar() != '\n')
            continue;
        print();
    }
    printf("Done! \n");

    return 0;
}

void print(void)
{
    for (int i_temp = 0; i_temp < strlen(PRINT); i_temp++)
        putchar('*');

    printf("\n%s\n", PRINT);
    printf("a) $8.75/hr           b) $9.33/hr \n");
    printf("c) $10.00/hr          d) $11.20/hr \n");
    printf("q) quit \n");

    for (int i_temp = 0; i_temp < strlen(PRINT); i_temp++)
        putchar('*');
    putchar('\n');
}

void choice(char ch_letter)
{
    double db_temp;
    
loop:
    if (ch_letter <= 'd' && ch_letter >= 'a')
    {
        switch (ch_letter)
        {
            case 'a':
                printf("Please enter week hour: \n");
                scanf("%lf", &db_temp);
                compute(db_temp, HOUR_WAGE1);
                break;

            case 'b':
                printf("Please enter week hour: \n");
                scanf("%lf", &db_temp);
                compute(db_temp, HOUR_WAGE2);
                break;

            case 'c':
                printf("Please enter week hour: \n");
                scanf("%lf", &db_temp);
                compute(db_temp, HOUR_WAGE3);
                break;

            case 'd':
                printf("please enter week hour: \n");
                scanf("%lf", &db_temp);
                compute(db_temp, HOUR_WAGE4);
                break;

            default:
                printf("Error! \n");
        }
    }
    else
    {
        printf("Please enter a~b lettere:");

        ch_character = getchar();
        while (getchar != '\n')
            continue;

        goto loop;
    }
}

void compute(double db_week_hour, double db_hour_wage)
{
    double db_week_wage;
    double db_tax, db_total_wage;

    if (db_week_hour <= CI_OVERTIME)
    {
        if (BASIC_WAGE <= BREAK1)
        {
            db_total_wage = BASIC_WAGE;
            db_week_wage = BASIC_WAGE * (1.0 - RATE1);
            db_tax = BASIC_WAGE * RATE1;
        }

        else if (BASIC_WAGE <= BREAK2)
        {
            db_total_wage = BASIC_WAGE;
            db_week_wage = BASE2;
            db_tax = db_total_wage - db_week_wage;
        }
    }
    else
    {
        db_total_wage = BASE5;
        db_week_wage = BASE4;
        db_tax = OVERTIME_PAY + BASE6;
    }

    printf("Total wage is %3.2f, tax is %3.2f, tax is %3.2f. \n", db_total_wage, db_tax, db_week_wage);
}
