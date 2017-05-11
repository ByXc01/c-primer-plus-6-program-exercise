/* File: double_and_square.c
 * Author: ByXc
 * About: double and square
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170511
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	int i_toes, i_double, i_square;

	i_toes = 10;
	i_double = i_toes * 2;
	i_square = i_toes * i_toes;

	printf("number: %d; double = %d, square = %d \n", i_toes, i_double, i_square);

	return 0;
}
