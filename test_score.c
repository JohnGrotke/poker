
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "poker.h"
#include "score.h"

bool test_royal_flush ( )
{

	printf("=====================\n");
    printf("test_royal_flush\n");
	bool status = true;
	int test_hand1[5] = { 13, 12, 11, 10, 1 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !royal_flush( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 

	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( royal_flush( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 
	
	if (status)
    {
        printf("test_royal_flush tests passed\n");
    } 
    else 
    {
        printf("test_royal_flush tests failed\n");
    }
	printf("=====================\n");
	return status;
}

bool test_straight_flush ( )
{

	printf("=====================\n");
    printf("test_straight_flush\n");
	bool status = true;
	int test_hand1[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !straight_flush( test_hand1 ) )
	{
		printf("positive test 1 failed\n");
		status =  false;
	} 

	int test_hand2[5] = { 1, 13, 12, 11, 10 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}
	
	if ( !straight_flush( test_hand2 ) )
	{
		printf("positive test 2 failed\n");
		status =  false;
	} 

	int test_hand3[5] = { 1, 2, 3, 4, 7 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand3[i]);
	}

	if ( straight_flush( test_hand3 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 

	if (status)
    {
        printf("test_four_of_a_kind tests passed\n");
    } 
    else 
    {
        printf("test_four_of_a_kind tests failed\n");
    }

	printf("=====================\n");
	return status;
}

bool test_four_of_a_kind ( )
{

	printf("=====================\n");
    printf("test_four_of_a_kind\n");
	bool status = true;
	int test_hand1[5] = { 1, 17, 33, 49, 2 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !four_of_a_kind( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 


	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( four_of_a_kind( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 
	
	if (status)
    {
        printf("test_four_of_a_kind tests passed\n");
    } 
    else 
    {
        printf("test_four_of_a_kind tests failed\n");
    }

	printf("=====================\n");
	return status;
}

bool test_full_house ( )
{
	printf("=====================\n");
    printf("test_full_house\n");
	bool status = true;
	int test_hand1[5] = { 1, 17, 33, 2, 18 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !full_house( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 


	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( full_house( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 

	if (status)
    {
        printf("test_full_house tests passed\n");
    } 
    else 
    {
        printf("test_full_house tests failed\n");
    }
	
	printf("=====================\n");
	return status;
}

bool test_flush ( )
{
	printf("=====================\n");
    printf("test_flush\n");
	bool status = true;
	int test_hand1[5] = { 1, 2, 5, 6, 7 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !flush( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 


	int test_hand2[5] = { 1, 2, 3, 23, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( flush( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 
	
    if (status)
    {
        printf("test_flush tests passed\n");
    } 
    else 
    {
        printf("test_flush tests failed\n");
    }
	
	printf("=====================\n");
	return status;
}

bool test_straight ( )
{
	printf("=====================\n");
    printf("test_straight\n");
	bool status = true;
	int test_hand1[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !straight( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 

	int test_hand2[5] = { 1, 13, 12, 11, 10 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}
	
	if ( !straight_flush( test_hand2 ) )
	{
		printf("positive test 2 failed\n");
		status =  false;
	} 

	int test_hand3[5] = { 1, 2, 3, 23, 5 };
	qsort( test_hand3, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand3[i]);
	}

	if ( straight( test_hand3 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 

	if (status)
    {
        printf("test_straight tests passed\n");
    } 
    else 
    {
        printf("test_straight tests failed\n");
    }
	
	printf("=====================\n");
	return status;
}

bool test_three_of_a_kind ( )
{

	printf("=====================\n");
    printf("test_three_of_a_kind\n");
	bool status = true;
	int test_hand1[5] = { 1, 17, 33, 50, 2 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !three_of_a_kind( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 

	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( three_of_a_kind( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 
	
    if (status)
    {
        printf("test_three_of_a_kind tests passed\n");
    } 
    else 
    {
        printf("test_three_of_a_kind tests failed\n");
    }
	
	printf("=====================\n");
	return status;
}

bool test_two_pair ( )
{
	printf("=====================\n");
    printf("test_two_pair\n");
	bool status = true;
	int test_hand1[5] = { 1, 17, 2, 18, 20 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !two_pair( test_hand1 ) )
	{
		printf("positive test failed\n");
		status =  false;
	} 

	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( two_pair( test_hand2 ) )
	{
		printf("negative test failed\n");
		status =  false;
	} 

    if (status)
    {
        printf("test_two_pair tests passed\n");
    } 
    else 
    {
        printf("test_two_pair tests failed\n");
    }
	
	printf("=====================\n");
	return status;
}

bool test_pair ( )
{

	printf("=====================\n");
    printf("test_pair\n");
	bool status = true;
	int test_hand1[5] = { 1, 17, 35, 50, 2 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}
	
	if ( !pair( test_hand1 ) )
	{
		printf("Test 1 failed\n");
		status =  false;
	} 

	printf("Test 1 passed\n");


	int test_hand2[5] = { 1, 2, 3, 4, 5 };
	
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	if ( pair( test_hand2 ) )
	{
		printf("Test 2 failed\n");
		status =  false;
	} 
	printf("Test 2 passed\n");
	
	printf("=====================\n");
	return status;
}

bool test_high_card( )
{
	printf("=====================\n");
    printf("test_high_card\n");
	bool status = true;
	int test_hand0[5] = { 1, 2, 3, 4, 5 };
	int test_hand1[5] = { 2, 3, 4, 5, 6 };
	qsort( test_hand1, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand0[i]);
	}

	printf(" vs \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand1[i]);
	}

	
	if ( high_card( test_hand0, test_hand1 ) != 0 )
	{
		printf("Test 1 failed\n");
		status =  false;
	} 

	printf("Test 1 passed\n");


	int test_hand2[5] = { 10, 11, 12, 13, 1 };
	int test_hand3[5] = { 9, 10, 11, 12, 13 };
	
	qsort( test_hand2, 5, sizeof(int), compare );
	printf("Testing hand: \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand2[i]);
	}

	printf(" vs \n");

	for (int i = 0; i < 5; i++) {
		print_card(test_hand3[i]);
	}

	if ( high_card( test_hand2, test_hand3 ) != 0 )
	{
		printf("Test 2 failed\n");
		status =  false;
	} 
	printf("Test 2 passed\n");
	
	printf("=====================\n");
	return status;
}

bool test_all ()
{
    bool status = true;
	// Check for Royal Flush
	status &= test_royal_flush();

	// Check for Straight Flush
	status &= test_straight_flush();

	// Check for Four of a Kind
	status &= test_four_of_a_kind();

	// Check for Full House
	status &= test_full_house();

	// Check for Flush
	status &= test_flush();

	// Check for Straight
	status &= test_straight();

	// Check for Three of a kind
	status &= test_three_of_a_kind();

	// Check for Two Pair
	status &= test_two_pair();

	// Check for Pair
	status &= test_pair();

	// Check for High Card
	status &= (test_high_card());

    if (status)
    {
        printf("All tests passed\n");
    }
    else 
    {
        printf("All tests failed\n");
    }
    return status;
}