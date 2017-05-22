/* File: max_sub_min.c
 * Author: ByXc
 * About: maximum subraction minimum
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170517
 * Github: ByXc01
 * Blog: htpp://ByXc01.github.io
 */

#include <stdio.h>
#define SIZE 5

double subraction(const double [], int);
void show_array(const double [], int);

int main(void)
{
    double dbp_array[SIZE] = { 1.0, 2.0, 3.0, 5.0, 8.0 };

	show_array(dbp_array, SIZE);
    printf("array element max - element min is %f \n", subraction(dbp_array, SIZE));

    return 0;
}

double subraction(const double cdbp_array[], int i_col)
{
    int i_index;
    double db_maximum, db_minimum;

    i_index = 0;
    db_maximum = *(cdbp_array + i_index);                        // 假設數組第一個元素是最大值
    db_minimum = *(cdbp_array + i_index);                        // 同上相反

    while (++i_index < i_col)                               	 // 前綴自增
    {
        if (*(cdbp_array + i_index) > db_maximum)                // 遍歷元素是否比i_max大
            db_maximum = *(cdbp_array + i_index);                // 更新i_max的值

        if (*(cdbp_array + i_index) < db_minimum)                // 同上相反
            db_minimum = *(cdbp_array + i_index);
    }

    return db_maximum - db_minimum;
}

void show_array(const double cdbp_array[], int i_cols)
{
	int i_index;
	
	for (i_index = 0; i_index < i_cols; i_index++)
		printf("%3g ", *(cdbp_array + i_index));
	putchar('\n');
}