/* Programming Exercise 8-5 */
/* binaryguess.c -- an improved number-guess */
/* but relies upon truthfull, correct responses */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i_high = 100;
    int i_low  = 0;
    int i_guess = (i_high + i_low) / 2;
    char ch_response;

    printf("Pick an integer from 1 to 100. I will try to guess it. \n");
    printf("Respond with a y my guess is right, with a h if it is high, and with an l if it is low. \n");
    printf("Uh...is your number %d? \n", i_guess);

    while ((ch_response = getchar()) != 'y')            //get response
    {
        if ('\n' == ch_response)
            continue;

        if (ch_response != 'h' && ch_response != 'l')
        {
            printf("I don't understand that response. Please enter h for high, l of low, or y for correct. \n");
            continue;
        }

        if ('h' == ch_response)
            i_high = i_guess - 1;
        else if ('l' == ch_response)
            i_low = i_guess + 1;
        i_guess = (i_high + i_low) / 2;

        printf("Well, then is it %d? \n", i_guess);
    }
    printf("I knew I could do it! \n");

    return 0;
} 

/* 這個是抄答案的， 想了好久都沒想出來 */
