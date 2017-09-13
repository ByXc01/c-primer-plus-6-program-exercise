/* pe160-3.c -- 因標準答案有誤，本人已更正*/

#include <stdio.h>
#include <math.h>

struct polar
{
    double r;
    double theta;       /* angle in degrees */
};

struct rect
{
    double x;
    double y;
};

struct rect p_to_r(const struct polar *);

int main(void)
{
    struct polar input;
    struct rect answer;

    printf("Enter magnitude and angle in degrees: ");
    while (scanf("%lf %lf", &input.r, &input.theta) == 2)
    {
        answer = p_to_r(&input);
        printf("polar coord: %g %f\n", input.r, input.theta);
        printf("rectangular coord: %g %f\n", answer.x, answer.y);
        printf("Enter magnitude and angle in degrees (q to quit): ");
    }
    puts("Bye!");

    return 0;
}

struct rect p_to_r(const struct polar * ppolar)
{
    static const double deg_rad = 3.1415926535 / 180.0;
    struct rect res;
    double angle = deg_rad * ppolar->theta;     /* convert degrees to radians */

    // 以下是修改后，因作者弄反了
    res.x = ppolar->r * cos(angle);
    res.y = ppolar->r * sin(angle);

    return res;
}
