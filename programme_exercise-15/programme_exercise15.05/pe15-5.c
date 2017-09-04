/* pe15-5.c */

#include <stdio.h>
#include <limits.h>

unsigned int rotate_l(unsigned int, unsigned int);
char * itobs(int, char *);

int main(void)
{
    unsigned int value;
    unsigned int rotate;
    unsigned int places;
    char bstr1[CHAR_BIT * sizeof(unsigned int) + 1];
    char bstr2[CHAR_BIT * sizeof(unsigned int) + 1];

    printf("Enter an integer (q to quit): ");
    while (scanf("%u", &value) == 1)
    {
        printf("Enter the number of bits to be rotate:\n");
        if (scanf("%u", &places) != 1)
            break;

        rotate = rotate_l(value, places);
        itobs(value, bstr1);
        itobs(rotate,  bstr2);
        
        printf("%u rotated is %u.\n", value, rotate);
        printf("%s rotated is %s.\n", bstr1, bstr2);
        printf("Next value: ");
    }
    puts("Done!");

    return 0;
}

unsigned int rotate_l(unsigned int n, unsigned int b)
{
    static const int size = CHAR_BIT * sizeof(unsigned int);
    unsigned int overflow;

    b %= size;                  // keep b a valid value
    overflow = n >> (size - b); // save bit that are shifed out

    return (n << b) | overflow;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
