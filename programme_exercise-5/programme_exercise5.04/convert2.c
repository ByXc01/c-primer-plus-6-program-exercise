/* File: 5.1142.c
 * Author: ByXc
 * About: convert
 * Version: 1.0
 * Compiler: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
const float CFL_FEET = 0.032808399;						//一釐米 = 0.032808399英呎
const float CFL_INCHES = 0.3937007874;					//一釐米 = 0.3937007874英吋
int main(void)
{
	float fl_feet, fl_inches;							//轉換的英呎和英吋
	float fl_cm;						            	//用戶輸入的釐米數
	
	printf("Enter a height in centimeters: ");
	scanf("%f", &fl_cm);
	while (fl_cm > 0)
	{
		fl_feet = fl_cm * CFL_FEET;						//轉換英呎
		fl_inches = fl_cm * CFL_INCHES;					//轉換英吋
		printf("%3.1f cm, %3.2f feet, %3.2f inches. \n", fl_cm, fl_feet, fl_inches);
		
		printf("Enter a height in centimeters (<= 0 to quit):");
		scanf("%f", &fl_cm);
	}
	printf("Bey! \n");
	
	return 0;
}