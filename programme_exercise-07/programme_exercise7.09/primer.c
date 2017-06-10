/* File: prime.c
 * Author: ByXc
 * About: prime
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int i_prime, i_number;
	int i_count, i_index;
	bool B_true;
	
loop:
	printf("Please enter a number (number <=2 , q to quit):");
	while (scanf("%d", &i_number))
	{
		if (i_number >= 2)
		{
			printf("Primer: ");
				for (i_count = 2; i_count <= i_number; i_count++)
				{
					for (i_index = 2, B_true = true; (i_index * i_index) <= i_count; i_index++)
					{
						if (i_count % i_index == 0)
						{
							B_true = false;
							break;
						}
					}
					if (B_true)
					{
						i_prime = i_count;
						printf("%2d ", i_prime);
					}
				}
				printf("\nThe all. \n");
				
			printf("Please enter nexet a number (number <= 2, q to quit):");
		}
		else
		{
			printf("Enter Error! \n");
			goto loop;
		}
	}
	printf("Bye! \n");
	
	return 0;
}