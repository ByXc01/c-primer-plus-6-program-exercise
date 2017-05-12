/* File: overflow_underflow.c
 * Author: ByXc
 * About: overflow and underflow
 * Version: 1.0
 * Compilation: arm-linux-androideabi-clang 4.0
 * Date: 20170512
 * Github: ByXc01
 * Bolg: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
	unsigned int ui_natural = 4294967295;
	float fl_toobig = 3.402823e+38;
	float fl_subnormal = 0.123123;

	printf("ui_natural = %u, overflow: ui_natural + 1 = %u \n", ui_natural, ui_natural +1);
	printf("fl_toobig = %e, overflow: fl_toobig * 100.0 = %e \n", fl_toobig, fl_toobig * 100);
	printf("fl_subnormal = %f, unferflow: fl_subnormal - 10.0 = %f \n", fl_subnormal, fl_subnormal / 10.0);

	return 0;
}
/* 以上結果是 armv7 32 Bit 測試通過 */