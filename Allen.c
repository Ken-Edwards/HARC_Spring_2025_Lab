#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getBet(void)
{
    int bet;
    do
    {
        printf("How much do you want to bet? (Enter a number ");
        printf("1 to 5, or 0 to quit the game): ");
        scanf(" %d", &bet);
        if (bet >= 1 && bet <= 5)
        {
            return(bet);
        }
        else if (bet == 0)
        {
            exit(1);
        }
        else
        {
            printf("\n\nPlease enter a bet from 1-5 or ");
            printf("0 to quit the game.\n");
        }
    } while ((bet < 0) || (bet > 5));
    return bet;
}

char getSuit(int suit)
{
    switch (suit)
    {
    case 0:
        return('c');
    case 1:
        return('d');
    case 2:
        return('h');
    case 3:
        return('s');
    default:
        return('?');
    }
}
