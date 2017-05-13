/* File: min.c
 * Author: ByXc
 * About: min
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

/* 程序很簡單，也可以設置用戶輸入來判斷 */
#include <stdio.h>
double min(double db_x, double db_y);
int main(void)
 {
  printf("%g \n", min(3.0, 2.0)); 			//簡單的驅動程序測試成功，
  return 0;
}
double min(double db_x, double db_y) 
{ 
	return db_x < db_y ? db_x : db_y; 
}
