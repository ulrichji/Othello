#include <stdio.h>
#include <stdlib.h>
#include "othello.h"
#include <stdarg.h>

//  +---+---+---+---+---+---+---+---+
//8 | 56| 57| 58| 59| 60| 61| 62| 63|
//  +---+---+---+---+---+---+---+---+
//7 | 48| 49| 50| 51| 52| 53| 54| 55|
//  +---+---+---+---+---+---+---+---+
//6 | 40| 41| 42| 43| 44| 45| 46| 47|
//  +---+---+---+---+---+---+---+---+
//5 | 32| 33| 34| 35| 36| 37| 38| 39|
//  +---+---+---+---+---+---+---+---+
//4 | 24| 25| 26| 27| 28| 29| 30| 31|
//  +---+---+---+---+---+---+---+---+
//3 | 16| 17| 18| 19| 20| 21| 22| 23|
//  +---+---+---+---+---+---+---+---+
//2 | 8 | 9 | 10| 11| 12| 13| 14| 15|
//  +---+---+---+---+---+---+---+---+
//1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
//  +---+---+---+---+---+---+---+---+
//    1   2   3   4   5   6   7   8

Board constructBoard(int white_count,int total_count,...)
{
	va_list ap;
	Board b;
	b.white = 0ULL;
	b.black = 0ULL;
	va_start(ap,total_count);
	for(int i=0;i<white_count;i++)
	{
		b.white |= PIECE(va_arg(ap,int));
	}
	for(int i=0;i<total_count - white_count;i++)
	{
		b.black |= PIECE(va_arg(ap,int));
	}
	
	va_end(ap);
	
	return b;
}

int compareBoards(Board b1, Board b2)
{
	bboard wDiff = b1.white - b2.white;
	bboard bDiff = b1.black - b2.black;
	if(wDiff != 0)
	{
		return -1;
	}
	else if(bDiff != 0)
	{
		return -1;
	}
	return 0;
}

int test_place_white_piece_left_legal()
{
	int result = 0;
	Board b1 = constructBoard(2,4,35,28,27,36);
	
	placeWhitePiece(&b1,PIECE(26));
	result |= compareBoards(b1,constructBoard(4,5,26,27,28,35));
	
	Board b2 = constructBoard(1,7,7,1,2,3,4,5,6);
	result |= compareBoards(b2,constructBoard(8,8,0,1,2,3,4,5,6,7));
	
	return result;
}

int test_setup_default_board()
{
	Board b1;
	b1.white = 12845578ULL;
	b1.black = 12485821ULL;
	
	setupDefaultBoard(&b1);
	
	return compareBoards(b1,constructBoard(2,4,35,28,27,36));
}

int mainTest()
{
	int failCount = 0;
	int passCount = 0;
	int result = 0;
	
	result = test_setup_default_board();
	if(result == 0){printf("[PASS]\t");passCount++;}
	else{printf("[FAIL]\t");failCount++;}
	printf("test_setup_default_board()\n");
	
	result = test_place_white_piece_left_legal();
	if(result == 0){printf("[PASS]\t");passCount++;}
	else{printf("[FAIL]\t");failCount++;}
	printf("test_place_white_piece_left_legal()\n");
	
	printf("%d of %d tests passed\n",passCount,passCount+failCount);
	
	if(failCount > 0)
		return -1;
	return 0;
}

int main(int argc, char** argv)
{
	int result = mainTest();
	if(result != 0)
	{
		printf("FAIL!\n");
	}
	else
	{
		printf("PASS!\n");
	}
	return 0;
}

