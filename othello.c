#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "othello.h"

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
	printf("%s\n",LINE);
	for(int i=7;i>=0;i--)
	{
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
		printf("|\n%s\n",LINE);
	}
}

void generateBlackMoves(Board* board)
{

}

void generateWhiteMoves(Board* board)
{
	Board oldBoard = *board;
	for(int i=0;i<64;i++)
	{
		Board newBoard = oldBoard;
		bboard addedPiece = PIECE(i);
		bboard convertedPieces = 0;
		int found = 0;
		
		//Test west direction
		while(addedPiece)
		{
			//Shift piece one step west
			addedPiece = addedPiece >> 1;
			if(addedPiece & oldBoard.white)
			{
				addedPiece = 0;
				if(convertedPieces != 0)
					found = 1;
			}
			addedPiece &= oldBoard.black & (~RIGHTSIDE);
			convertedPieces |= addedPiece;
		}
		if(found)
		{
			newBoard.black &= ~convertedPieces;
			newBoard.white |= convertedPieces | PIECE(i);
			printBoard(&newBoard);
		}
	}
}

int placeWhitePiece(Board* board, bboard piece)
{
	bboard convertedPieces = 0ULL;
	bboard tempConverted = 0ULL;
	bboard testPiece = piece;
	//Special case
	bboard enemies = board->black;
	bboard empty = ~(board->black | board->white);
	bboard friends = board->white;
	//end special case
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
	
	//Special case
	board->white |= convertedPieces;
	board->black &= ~convertedPieces;
	//end special case
	
	if(convertedPieces == 0)
		return 1;
	return 0;
}

void setupDefaultBoard(Board* board)
{
	board->white = 0;
	board->black = 0;
	
	board->white |= PIECE(35) | PIECE(28) | PIECE(26) | PIECE(44) | PIECE(45);
	board->black |= PIECE(27) | PIECE(36) | PIECE(42) | PIECE(37);
}




