
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "poker.h"
#include "score.h"


// typedef int DECK[52];

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

#define RANKOF(c) ( (c) & 0xf )
#define SUITOF(c) ( ( (c) >> 4 ) & 0xf )
bool royal_flush (int* hand )
{
	int suit = SUITOF(hand[0]);
	
	// Exit out early if the suit isn't the same
	for (int i = 1; i < 5; i++)
	{
		if ( ! ( SUITOF( hand[i] ) == suit) )
		{
			return false;
		} 
	}

	// For a royal flush to be true, the next card has to be a king
	int next_card_needed = 13;
	for (int i = 0; i < 4; i++)
	{
		int rank = RANKOF(hand[i]);
		if (rank != next_card_needed)
		{
			return false;
		}
		next_card_needed--;
	}

	// last card has to be an ACE
	if ( ! ( RANKOF(hand[4] ) == 1 ) )
	{
		return false;
	}

	return true;
}

bool straight_flush ( int* hand )
{
	int suit = SUITOF(hand[0]);
	
	// Check if everything is in the same suit
	for (int i = 1; i < 5; i++)
	{
		if ( ! ( SUITOF( hand[i] ) == suit) )
		{
			return false;
		} 
	}

	// hack to get around aces being 1. Just set it to be the next expected card
	if ( RANKOF( hand[0] ) == 13 && RANKOF( hand[4] ) == 1 )
	{
		hand[4] = 9;
	}
	
	// Since the cards are sorted in decending order the next card 
	// needs to be one less than the first card
	int next_card_needed = RANKOF(hand[0]) - 1;
	for (int i = 1; i < 5; i++)
	{
		int rank = RANKOF(hand[i]);

		
		if (rank != next_card_needed)
		{
			return false;
		}
		next_card_needed--;
	}

	return true;
}

bool four_of_a_kind (int* hand )
{
	for( int i = 0; i < 5; i++ )
	{
		int num_same = 1; 
		for(int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				continue;
			}
			
			if ( RANKOF(hand[i]) == RANKOF(hand[j]) )
			{
				num_same++;
			}
		}
		if ( num_same == 4 )
		{
			return true;
		}
	}

	return false;
}

bool full_house ( int* hand )
{
	int rank1 = RANKOF(hand[0]);
	int rank2 = -1;

	// If we find more than 2 ranks then we don't have a full house 
	bool found_2_cards = false;

	// loop through to find 2 ranks
	for( int i = 1; i < 5; i++ )
	{
		if ( (RANKOF(hand[i])) != rank1 && !found_2_cards)
		{
			found_2_cards = true;
			rank2 = (RANKOF(hand[i]));
		}
		else if ( (RANKOF(hand[i])) == rank1 || (RANKOF(hand[i])) == rank2) 
		{
			continue;
		}
		else 
		{
			return false;
		}

	}
	return true;
}

bool flush ( int* hand )
{
	int suit = SUITOF(hand[0]);
	
	// Check if everything is in the same suit
	for (int i = 1; i < 5; i++)
	{
		if ( ! ( SUITOF( hand[i] ) == suit) )
		{
			return false;
		} 
	}

	return true;
}

bool straight (int* hand )
{
	// Since the cards are sorted in decending order the next card 
	// needs to be one less than the first card
	
	// hack to get around aces being 1. Just set it to be the next expected card
	if ( RANKOF( hand[0] ) == 13 && RANKOF( hand[4] ) == 1 )
	{
		hand[4] = 9;
	}

	int next_card_needed = RANKOF(hand[0]) - 1;
	for (int i = 1; i < 5; i++)
	{
		int rank = RANKOF(hand[i]);
		if (rank != next_card_needed)
		{
			return false;
		}
		next_card_needed--;
	}

	return true;
}

bool three_of_a_kind (int* hand )
{
	for( int i = 0; i < 5; i++ )
	{
		int num_same = 1; 
		for(int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				continue;
			}
			
			if ( (RANKOF(hand[i])) == RANKOF(hand[j]) )
			{
				num_same++;
			}
		}
		if ( num_same == 3 )
		{
			return true;
		}
	}

	return false;
}

bool two_pair (int* hand )
{
	int rank1 = RANKOF(hand[0]);
	int rank2 = -1;
	int rank3 = -1;

	// If we find more than 2 ranks then we don't have a full house 
	bool found_2_cards = false;
	bool found_3_cards = false;

	// loop through to find 2 ranks
	for( int i = 1; i < 5; i++ )
	{
		if ( (RANKOF(hand[i])) != rank1 && !found_2_cards)
		{
			found_2_cards = true;
			rank2 = (RANKOF(hand[i]));
		}
		else if ( (RANKOF(hand[i])) != rank1 && 
				  (RANKOF(hand[i])) != rank2 && 
				  !found_3_cards)
		{
			found_3_cards = true;
			rank3 = (RANKOF(hand[i]));
		}
		else if ( (RANKOF(hand[i])) == rank1 || 
				  (RANKOF(hand[i])) == rank2 || 
				  (RANKOF(hand[i])) == rank3) 
		{
			continue;
		}
		else 
		{
			return false;
		}

	}
	return true;
}

bool pair (int* hand )
{
	for( int i = 0; i < 5; i++ )
	{
		int num_same = 1; 
		for(int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				continue;
			}
			
			if ( (RANKOF(hand[i])) == RANKOF(hand[j]) )
			{
				num_same++;
			}
		}
		if ( num_same == 2 )
		{
			return true;
		}
	}

	return false;
}

int high_card ( int* hand0, int* hand1 )
{
	int rank0 = RANKOF(hand0[0]);
	int suit0 = SUITOF(hand0[0]);
	int rank1 = RANKOF(hand1[0]);
	int suit1 = SUITOF(hand1[0]);

	// in this case, ace should be the highest card
	if (rank0 == 1)
	{
		rank0 = 14;
	}
	if (rank1 == 1)
	{
		rank1 = 14;
	}

	// Check ranks first
	if (rank0 != rank1)
	{
		
		if (rank0 > rank1)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
	}
	else // check suits
	{
		if ( suit0 > suit1 )
		{
			return 0;
		} 
		else 
		{
			return 1;
		}
	}
}

int compare_hands(int* hand0, int* hand1) {
	
	// sort hands from highest to lowest
	qsort( hand0, 5, sizeof(int), compare );
	qsort( hand1, 5, sizeof(int), compare );

	int hand0_score = get_score(hand0);
	int hand1_score = get_score(hand1);

	printf("human score: %d\n", hand0_score);
	printf("ai score: %d\n", hand1_score);

	
	if (hand0_score == hand1_score)
	{
		return high_card(hand0, hand1);
	}
	else if (hand0_score > hand1_score)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	//return rand() % 2;
}

int get_score(int * hand)
{
		if (royal_flush(hand))
		{
			return 10;
		} 
		else if ( straight_flush(hand) )
		{
			return 9;
		}
		else if ( four_of_a_kind(hand) )
		{
			return 8;
		}
		else if ( full_house(hand) )
		{
			return 7;
		}
		else if ( flush(hand) )
		{
			return 6;
		}
		else if ( straight(hand) )
		{
			return 5;
		}
		else if ( three_of_a_kind(hand) )
		{
			return 4;
		}
		else if ( two_pair(hand) )
		{
			return 3;
		}
		else if ( pair(hand) )
		{
			return 2;
		}
		else 
		{
			// high card
			return 1;
		}
		
}







