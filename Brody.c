// Function that changes the rank integer value to a character
// representing the rank
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


// Last function reviews the final hand and determines the value of
// the hand.
int analyzeHand(int ranksinHand[], int suitsinHand[])
{
int num_consec = 0;
int i, rank, suit;
int straight = FALSE;
int flush = FALSE;
int four = FALSE;
int three = FALSE;
int pairs = 0;
for (suit = 0; suit < 4; suit++)
if (suitsinHand[suit] == 5)
flush = TRUE;
rank = 0;
while (ranksinHand[rank] == 0)
rank++;
for (; rank < 13 && ranksinHand[rank]; rank++)
num_consec++;
if (num_consec == 5) {
straight = TRUE;
}
for (rank = 0; rank < 13; rank++) {
if (ranksinHand[rank] == 4)
four = TRUE;
if (ranksinHand[rank] == 3)
three = TRUE;
if (ranksinHand[rank] == 2)
pairs++;
}
if (straight && flush) {
printf("Straight flush\n\n");
return (20);
}
else if (four) {
printf("Four of a kind\n\n");
return (10);
}
else if (three && pairs == 1) {
printf("Full house\n\n");
return (8);
}
else if (flush) {
printf("Flush\n\n");
return (5);
}
else if (straight) {
printf("Straight\n\n");
return (4);
}
else if (three) {
printf("Three of a kind\n\n");
return (3);
}
else if (pairs == 2) {
printf("Two pairs\n\n");
return (2);
}
else if (pairs == 1) {
printf("Pair\n\n");
return (1);
}
else {
printf("High Card\n\n");
return (0);
}
}
