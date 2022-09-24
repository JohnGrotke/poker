#include <stdio.h>
#include "poker.h"


void init_deck(DECK deck) {
	for (int suit = 0; suit < 4; suit++) {
		for (int rank = 1; rank <= 13; rank++) {
			deck[suit * 13 + rank - 1] = suit << 4 | rank;
		}
	}
}

int find_card (DECK deck, int card)
{
    for (int i = 0; i < 52; i++)
    {
        if(deck[i] == card)
        {
            return i;
        }
    }
}

#define SPADES 3

#define ACE 1

int main() {
    srand(time(NULL));
    int counts[52] = {0};
    for (int i = 0; i < 10000000; i++)
    {
        DECK deck;
        init_deck(deck);
        shuffle(deck);

        int pos = find_card(deck, SPADES << 4 | ACE);
        counts[pos]++;
    }

    for (int i = 0; i < 52; i++)
    {
        printf("%02d: %d\n", i, counts[i]);
    }
}