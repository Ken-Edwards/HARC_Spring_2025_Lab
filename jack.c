#include "Jack.h"
#include <stdio.h>
#include <stdlib.h>

// Function to finalize the player's hand
void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksinHand[], int suitsinHand[]) {
    // Copy the original hand to the final hand
    for (int i = 0; i < 5; i++) {
        finalRank[i] = cardRank[i];
        finalSuit[i] = cardSuit[i];

        // Update rank and suit counts for analysis
        ranksinHand[cardRank[i]]++;
        suitsinHand[cardSuit[i]]++;
    }
}

// Function to analyze the final hand and return the hand's value (as a multiplier for winnings)
int analyzeHand(int ranksinHand[], int suitsinHand[]) {
    int i, numPairs = 0, threeOfAKind = 0, fourOfAKind = 0;
    int flush = 0, straight = 0;

    // Check for flush (all suits are the same)
    for (i = 0; i < 4; i++) {
        if (suitsinHand[i] == 5) {
            flush = 1;
        }
    }

    // Check for straight (5 consecutive ranks)
    int consecutiveRanks = 0;
    for (i = 0; i < 13; i++) {
        if (ranksinHand[i] > 0) {
            consecutiveRanks++;
        } else {
            consecutiveRanks = 0;
        }
        if (consecutiveRanks == 5) {
            straight = 1;
            break;
        }
    }

    // Analyze pairs, three of a kind, and four of a kind
    for (i = 0; i < 13; i++) {
        if (ranksinHand[i] == 2) {
            numPairs++;
        } else if (ranksinHand[i] == 3) {
            threeOfAKind = 1;
        } else if (ranksinHand[i] == 4) {
            fourOfAKind = 1;
        }
    }

    // Check the best hand (using hand rankings)
    if (flush && straight) {
        return 20;  // Straight Flush
    }
    if (fourOfAKind) {
        return 10;  // Four of a Kind
    }
    if (numPairs == 1 && threeOfAKind) {
        return 8;   // Full House
    }
    if (flush) {
        return 5;   // Flush
    }
    if (straight) {
        return 4;   // Straight
    }
    if (threeOfAKind) {
        return 3;   // Three of a Kind
    }
    if (numPairs == 2) {
        return 2;   // Two Pairs
    }
    if (numPairs == 1) {
        return 1;   // One Pair
    }

    return 0;  // No winning hand
}

