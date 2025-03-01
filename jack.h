#ifndef JACK_H
#define JACK_H

// Function prototypes for Jack's functions
void getFinalHand(int cardRank[], int cardSuit[], int finalRank[],
                  int finalSuit[], int ranksinHand[], int suitsinHand[]);
int analyzeHand(int ranksinHand[], int suitsinHand[]);

#endif
