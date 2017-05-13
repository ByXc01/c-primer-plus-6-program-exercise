/* File: 5.1141.c
 * Author: ByXc
 * About: convert
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
const float CFL_FEET = 0.032808399;						//一釐米 = 0.032808399英呎
const float CFL_INCHES = 11.999999981712;				//一英呎= 11.999999981712英吋
int main(void)
{
	int i_feet;											//存儲轉換的英呎
	float fl_inches;						   			//存儲轉換剩餘的英吋
	float fl_cm;										//用戶輸入的釐米數
	
	printf("Enter a height in centimeters:");
	scanf("%f", &fl_cm);
	
	while (fl_cm > 0)
	{
		i_feet = fl_cm * CFL_FEET;
		fl_inches = (fl_cm * CFL_FEET - i_feet) * CFL_INCHES;
		printf("%3.1f cm, %3d feet, %3.1f inches. \n", fl_cm, i_feet, fl_inches);
		
		printf("Enter a height in centimeters (<= 0 to quit):");
		scanf("%f", &fl_cm);
	}
	printf("Bey! \n");
	
	return 0;
}