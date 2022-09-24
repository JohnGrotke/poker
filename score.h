#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int get_score (int* hand0);

void print_card(int card);
int compare (const void * a, const void * b);
bool royal_flush (int* hand );
bool test_royal_flush ( );
bool straight_flush ( int* hand );
bool test_straight_flush ( );
bool four_of_a_kind (int* hand );
bool test_four_of_a_kind ( );
bool full_house ( int* hand );
bool test_full_house ( );
bool flush ( int* hand );
bool test_flush ( );
bool straight (int* hand );
bool test_straight ( );
bool three_of_a_kind (int* hand );
bool test_three_of_a_kind ( );
bool two_pair (int* hand );
bool test_two_pair ( );
bool pair (int* hand );
bool test_pair ( );
int high_card ( int* hand0, int* hand1 );
bool test_high_card ( );


bool test_all ();