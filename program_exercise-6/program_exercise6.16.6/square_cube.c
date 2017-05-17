/* File: square_cube.c
 * Author: ByXc
 * About: square cube
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_number, i_limit;		//开始和结束
	long l_square, l_cube;		//平方和立方
	
	printf("Please enter a start and a end:");
	for (scanf("%d %d", &i_number, &i_limit); i_number <= i_limit; i_number++)
	{
		printf("number    square    cube\n");
			
		l_square = i_number * i_number;
		l_cube   = i_number * i_number * i_number;		//也可以偷懒写成l_cube = l_square * i_number;
		
		printf("%3d %10ld %9ld\n", i_number, l_square, l_cube);
	}
	printf("The all! \n");
	
	return 0;
}