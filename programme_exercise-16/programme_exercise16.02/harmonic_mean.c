/* File: harmonic_mean.c
 * Author: ByXc
 * About: Harmonic mean
 * Version: 1.0
 * Compiler: gcc 6.3.0 for msys2
 * Date: 20170912
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

#define HARMEAN(X, Y) (1.0 / ((1.0 / (X) + 1.0 / (Y)) / 2.0))   // 本人寫的，見笑了
#define HMEAN(X, Y) (2.0 * (X) * (Y) / ((X) + (Y)))             // 標準答案，很簡潔

int main(void)
{
    double x, y, answer;

    puts("Enter a pair of numbers (q to quit):");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        answer = HMEAN(x, y);
        printf("%g = harmonic mean of %g %g.\n", answer, x, y);
        
        // see if works arithmetic expressions
        answer = HMEAN(x + y, x * y);
        printf("%g = harmonic mean of %g %g.\n", answer, x + y, x * y);

        puts("Enter a pair of numbers (q to quit): ");
    }
    puts("Bye!");

    return 0;
}
