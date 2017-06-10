/* File: sequence.c
 * Author: ByXc
 * About: infinite sequence
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

//c primer plus 中文第六版
#include <stdio.h>
const double CDB_ONE = 1.0;
const double CDB_ONE2 = -1.0;
int main(void)
{
	int i_input;
	double db_sum1, db_sum2;
	double db_number, db_temp;
	
	printf("Please enter a number:");
	scanf("%d", &i_input);
	
	while (i_input > 0)
	{
		db_sum1 = db_sum2 = 1.0;
		db_temp = -1.0;
		//printf("%g + ", CDB_ONE);
		for (db_number = 2.0; db_number <= i_input; db_number++)
		{
			db_sum1 += CDB_ONE / db_number;
			//printf("%g / %g +  ", CDB_ONE, db_number);
			db_sum2 += db_temp / db_number;
			db_temp *= CDB_ONE2;
		}
			printf("= %g \n", db_sum1);
		
	
		//printf("%g ", CDB_ONE);
		/*for (db_number2 = 2.0; db_number2 <= i_input; db_number2++)
		{
			db_sum2 += db_temp / db_number2;
			//printf(" %+2g / %g ", db_temp, db_number2);
			db_temp *= CDB_ONE2;
		}*/
		printf("= %g \n", db_sum2);

		printf("The all! \n");
		printf("Please enter next a number:");
		scanf("%d",&i_input);
	}
	printf("Bye! \n");
	
	return 0;
}

/*方法二			c primer plus中文五版
#include <stdio.h>
int main(void)
{
	double i, sum1, sum2;
	int sign, count;
	
	printf("Enter the count:");
	scanf("%d", &count);
	
	for (i = 1.0, sign = 1, sum1 = sum2 = 0; i <= count; i++, sign *= -1)
	{
		sum1 += 1.0 / i;
		sum2 += sign * 1.0 / i;
		//利用sign的變化規律， 使運算符在正負間交替變化
	}
	printf("%d terms = %lf \n", count, sum1);
	printf("%d terms = %lf \n", count, sum2);
	printf("sign = %d \n", sign);
	
	return 0;
}
*/


/*方法三			c printf plus中文第五版
#include <stdio.h>
#define NUM 1.0
int main(void)
{
	int time;
	double a_all = 0, b_all = 0;
	int index, list;
	int temp = 1;
	
	scanf("%d", &time);
		for (index = 1; index <= time; index++)
			a_all += NUM / index;
	
		for (list = 1; list <= time; list++)
		{
			b_all += NUM / list * temp;
			temp *= -1;
		}
	    printf("A is %g, B is %g \n", a_all, b_all);
	
	return 0;
}
*/