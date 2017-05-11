/* File: smile.c
 * Author: ByXc
 * About: smile
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

void display(void);
int main(void)
{
	display();
	display();
	display();
	printf("\n");

	display();
	display();
	printf("\n");

	display();
	printf("\n");

	return 0;
}

void display(void)
{
	printf("Smile!");
}
