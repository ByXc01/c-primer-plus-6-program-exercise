/* File: convert.c
 * Author: ByXc
 * About: convert
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define TEMPCM 0.0328083			//一釐米 = 0.032808399 英呎
#define TEMPINCH 0.083333			//一英呎 = 0.083333333 英吋

int main(void)
{
	int feet;
	float cm, inch;
	
	printf("Enter a height in cedtimeters :");
	scanf("%f", &cm);
	while (cm > 0)
	{
		feet = (int) cm * TEMPCM;
		inch = (cm * TEMPCM - feet) / TEMPINCH;
		printf("%.1f cm = %d feet, %.1f iches\n", cm, feet, inch);
		printf("Enter a height in cedtimeters :");
		scanf("%f", &cm);
	}
	printf("Bey, your num < 0 \n");
	
	return 0;
}