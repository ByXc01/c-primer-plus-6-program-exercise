/* File: temperatures.c
 * Author: ByXc
 * About: temperatures convert
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

void Temperatures(double db_fahrenheit);
int main(void)
{
	double db_fahrenheit_input;		//輸入的華氏溫度
	
	printf("Please enter the fahrenheit:\n");
	while (scanf("%lf", &db_fahrenheit_input) == 1)
	{
		Temperatures(db_fahrenheit_input);
		printf("Please next enter the fahrenheit (q to quit):");
	}
	printf("Bey! \n");
	
	return 0;
}

void Temperatures(double db_fahrenheit)
{
	const float CFL_CELSIUS = 5.0 / 9.0 * (db_fahrenheit - 32.0);
	const float CFL_KELVIN   = CFL_CELSIUS + 273.16;
	
	printf("Fahrenheit is %3.2f, Celsius is %3.2f, Kelvin temperature is %3.2f. \n",
	db_fahrenheit, CFL_CELSIUS, CFL_KELVIN);
}