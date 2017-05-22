/* File: fuel_consumption.c 
 * * Author: ByXc
 * About: fuel consumption
 * Version: 1.0
 * Compilation: gcc 6.3.0 for msys2
 * Date: 20170512
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
int main(void)
{
    const float FL_MILE_KM = 1.608;
    const float FL_GALLON = 3.785;

    float fl_mile, fl_fuel_gallon;         // 輸入的里程和消耗的汽油量
    double db_results;
    
    printf("Please enter your mileage(unit: mile): ");
    scanf("%f", &fl_mile);

    printf("Please enter your the amount of gasoline you consume: ");
    scanf("%f", &fl_fuel_gallon);

    db_results = (fl_fuel_gallon / FL_GALLON * 100.0) / FL_MILE_KM;

    printf("Your mileage per gallon is %.1f \n", db_results);

    return 0;
}
