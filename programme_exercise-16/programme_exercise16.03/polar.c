/* File: polar.c
 * Author: ByXc
 * About: polar coordinate to coordinate
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170908
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>
#include <math.h>                           // for cos()、sin()、atan()

#define DEG_TO_RAD ((4 * atan(1)) / 180)    // 角度轉弧度，其實可以直接用 3.1415926535 / 180

typedef struct polar_v
{
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v
{
    double x;
    double y;
} Rect_V;

Rect_V polar_to_rect(Polar_V);

int main(void)
{
    Polar_V input;
    Rect_V result;

    puts("Please ente polar coordinates a vector in terms of magnitude and the\
countterclokwise angle.");
    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("x = %.2f, y = %.2f\n", result.x, result.y);
    }
    puts("Bye!");

    return 0;
}

Rect_V polar_to_rect(Polar_V pv)
{
    Rect_V rv;

    // 因本人數學水平還停留在小學階段，也不懂三角函數，以下是按公式調用函數
    rv.x = pv.magnitude * cos(pv.angle * DEG_TO_RAD);
    rv.y = pv.magnitude * sin(pv.angle * DEG_TO_RAD);

    return rv;
}
