/* File: reverse.c
 * Author: ByXc
 * About: command-line argument reverse output
 * Version: 1.0
 * Compiler: arm-linux-androideabi-gcc 6.1.0
 * Date: 20170609
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(int argc, char * argv[])
{
	int i_count;

	for (i_count = argc - 1; i_count > 0; i_count--)	// 設置下標
		printf ("%s ", *(argv + i_count));				// 從最後一個命令行參數輸出
	putchar ('\n');

	return 0;
}