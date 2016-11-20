#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "othello.h"
#include "console_player.h"

char rowValue(int row)
{
	switch(row)
	{
	case 0:
		return '1';
	case 1:
		return '2';
	case 2:
		return '3';
	case 3:
		return '4';
	case 4:
		return '5';
	case 5:
		return '6';
	case 6:
		return '7';
	case 7:
		return '8';
	}
	
	return '=';
}

char value(int col)
{
	switch(col)
	{
	case 0:
		return 'a';
	case 1:
		return 'b';
	case 2:
		return 'c';
	case 3:
		return 'd';
	case 4:
		return 'e';
	case 5:
		return 'f';
	case 6:
		return 'g';
	case 7:
		return 'h';
	}
	
	return '0';
}

void printBitboard(bboard board)
{
	printf("%s\n",LINE);
	for(int i=7;i>=0;i--)
	{
		for(int u=0;u<8;u++)
		{
			bboard index = (i*8) + u;
			bboard mask = PIECE(index);
			printf("| ");
			if(board & mask)
			{
				printf("%c",'*');
			}
			else
			{
				printf("%c",' ');
			}
			printf(" ");
		}
		printf("|\n%s\n",LINE);
	}
}

void printBoard(Board* board)
{
	printf("   %s\n",LINE);
	for(int i=7;i>=0;i--)
	{
		printf("%c  ",rowValue(i));
		for(int u=0;u<8;u++)
		{
			bboard index = (i*8) + u;
			bboard mask = PIECE(index);
			printf("| ");
			if(board->white & mask)
			{
				printf("%c",'X');
			}
			else if(board->black & mask)
			{
				printf("%c",'O');
			}
			else
			{
				printf("%c",' ');
			}
			printf(" ");
		}
		printf("|\n   %s\n",LINE);
	}
	printf("     a   b   c   d   e   f   g   h\n");
}

int placePiece(Board* board, bboard piece, int side)
{
	bboard convertedPieces = 0ULL;
	bboard tempConverted = 0ULL;
	bboard testPiece = piece;
	
	bboard enemies = 0;
	bboard empty = 0;
	bboard friends = 0;
	
	if(side == WHITE)
	{
		enemies = board->black;
		empty = ~(board->black | board->white);
		friends = board->white;
	}
	else if(side == BLACK)
	{
		enemies = board->white;
		empty = ~(board->black | board->white);
		friends = board->black;
	}
	
	int found = 0;
	
	//Find pieces west
	while(testPiece)
	{
		testPiece = (testPiece >> 1ULL) & (~RIGHTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;

	//Find pieces east
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece << 1ULL) & (~LEFTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces north
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece << 8ULL);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces south
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece >> 8ULL);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces north west
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece << 7ULL) & (~RIGHTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces south west
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece >> 9ULL) & (~RIGHTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces north east
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece << 9ULL) & (~LEFTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
	
	//Find pieces south east
	testPiece = piece;
	tempConverted = 0ULL;
	found = 0;
	
	while(testPiece)
	{
		testPiece = (testPiece >> 7ULL) & (~LEFTSIDE);
		
		if(testPiece & enemies)
			tempConverted |= testPiece;
		else if((testPiece & friends) && tempConverted != 0)
		{
			found = 1;
			break;
		}
		else
			break;
	}
	if(found)
		convertedPieces |= tempConverted;
		
	
	//the tests are done. also add the piece if the move is valid
	if(convertedPieces != 0)
		convertedPieces |= piece;
	
	if(side == WHITE)
	{
		board->white |= convertedPieces;
		board->black &= ~convertedPieces;
	}
	else if(side == BLACK)
	{
		board->white &= ~convertedPieces;
		board->black |= convertedPieces;
	}
	
	if(convertedPieces == 0)
		return 1;
	return 0;
}

void setupDefaultBoard(Board* board)
{
	board->white = 0;
	board->black = 0;
	
	board->white |= PIECE(35) | PIECE(28);// | PIECE(26) | PIECE(44) | PIECE(45);
	board->black |= PIECE(27) | PIECE(36);// | PIECE(42) | PIECE(37);
}




