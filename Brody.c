// Function that changes the rank integer value to a character
// representing the rank

#define FALSE 0
#define TRUE 1


char getRank(int rank)
{
switch (rank)
{
case 0:
return('A');
case 1:
return('2');
case 2:
return('3');
case 3:
return('4');
case 4:
return('5');
case 5:
return('6');
case 6:
return('7');
case 7:
return('8');
case 8:
return('9');
case 9:
return('T');
case 10:
return('J');
case 11:
return('Q');
case 12:
return('K');
}
}


// Function to deal the first five cards
void getFirstHand(int cardRank[], int cardSuit[])
{
int i,j;
int cardDup;
for (i=0; i < 5; i++)
{
cardDup = 0;
do {
// Card rank is one of 13 (2-10, J, Q, K, A)
cardRank[i] = (rand() % 13);
// Card suit is one of 4
// (club, diamond, heart, spade)
cardSuit[i] = (rand() % 4);
// Loop that ensures each card is unique
for (j=0; j < i; j++)
{
if ((cardRank[i] == cardRank[j]) &&
(cardSuit[i] == cardSuit[j]))
{
cardDup = 1;
}
}
} while (cardDup == 1);
}
}
