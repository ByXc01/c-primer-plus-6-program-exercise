/* File: number.c
 * Author: ByXc
 * About: print number
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */

#include <stdio.h>

void one_three(void);
void two(void);

int main(void)
{
	printf("staring now: \n");
	one_three();
	printf("done! \n");

	return 0;
}

void one_three(void)
{
	printf("one \n");
	two();
	printf("three \n");
}

void two(void)
{
	printf("two \n");
}
