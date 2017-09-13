/* pe16-5.c -- 以下是標準答案，本人優化了算法 */

#include <stdio.h>
#include <stdlib.h>     // for srand()、srand()
#include <time.h>       // for time()

#define SPOTS 50
#define PICKS 6 

void random_pick(int array[], int array_size, int picks);
int main(void)
{
    int lotto[SPOTS];
    int index;
    char character;

    for (index = 0; index < SPOTS; index++)
    {
        lotto[index] = index + 1;
        printf("%2d ", lotto[index]);
    }
    putchar('\n');

    do
    {
        random_pick(lotto, SPOTS, PICKS);
        printf("Again?<y/n> ");
        character = getchar();

        while (getchar() != '\n')
            continue;
    } while (character == 'y' || character == 'Y');
    puts("Done!");

    return 0;
}

void random_pick(int array[], int array_size, int picks)
{
    int i, index, temp;

    srand((unsigned int) time(0));
    if (picks > array_size)
    {
        fputs("Number of picks > array size\n", stderr);
        fputs("Setting picks = array size\n", stderr);
        picks = array_size;
    }

    for (i = 0; i < picks; i++)
    {
        index = rand() % array_size;                /* pick a random element     */
        temp = array[index];
        printf("%2d ", temp);                       /* display it                */

        if (i % 20 == 19)
            putchar('\n');
        
        array[index] = array[array_size - 1];       /* swap it with last element */
        array[array_size - 1] = temp;

        array_size--;                               /* exclude end form search   */
    }
    if (i % 20 != 0)
        putchar('\n');
}
