/* File: ascending_order.c
 * Author: ByXc
 * About: ascending_order
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170330
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 人笨啊， 做了好久。 最後只好窮舉所有的可能 */
#include <stdio.h>

void ascending_sequence(double *, double *, double *);
void swap3(double *, double *, double*);					//此版本更簡便

int main(void)
{
    double db_number1, db_number2, db_number3;
    
    printf("Please enter three digits: ");
    while (scanf("%lf %lf %lf", &db_number1, &db_number2, &db_number3) == 3)
    {
        printf("Originally number1 = %g, number2 = %g, number3 = %g \n", db_number1, db_number2, db_number3);
        ascending_sequence(&db_number1, &db_number2, &db_number3);
		//swap3(&db_number1, &db_number2, &db_number3);
        printf("Now number1 = %g, number2 = %g, number3 = %g \n", db_number1, db_number2, db_number3);

        printf("Please continue  to enter three digits(q to quit): ");
    }
    printf("End the program, thank you! \n");

    return 0;
}

void ascending_sequence(double * pdb_x, double * pdb_y, double * pdb_z)
{
    double db_median, db_max, db_min;
    
    if (*pdb_x > *pdb_y && *pdb_x > *pdb_z)
    {
        db_max = *pdb_x;
        if (*pdb_y > *pdb_z)
        {
            db_median = *pdb_y;
            db_min    = *pdb_z;
        }
        else
        {
            db_median = *pdb_z;
            db_min    = *pdb_y;
        }
    }
    else if (*pdb_y > *pdb_x && *pdb_y > *pdb_z)
    {
        db_max = *pdb_y;
        if (*pdb_x > *pdb_z)
        {
            db_median = *pdb_x;
            db_min    = *pdb_z;
        }
        else
        {
            db_median = *pdb_z;
            db_min    = *pdb_x;
        }
    }
    else
    {
        db_max = *pdb_z;
        if (*pdb_x > *pdb_y)
        {
            db_median = *pdb_x;
            db_min    = *pdb_y;
        }
        else
            return;                     //最後一個肯定時升序， 直接返回
    }

    *pdb_x = db_min;
    *pdb_y = db_median;
    *pdb_z = db_max;
}

void swap3(double *db_x, double *db_y, double *db_z)
{
	
	if (*db_x > *db_y)
	{
		*db_x += *db_y;
		*db_y  = *db_x - *db_y;
		*db_x -= *db_y;
	}
	if (*db_x > *db_z)
	{
		*db_x += *db_z;
		*db_z  = *db_x - *db_z;
		*db_x -= *db_z;
	}
	if (*db_y > *db_z)
	{
		*db_y += *db_z;
		*db_z  = *db_y - *db_z;
		*db_y -= *db_z;
	}
}