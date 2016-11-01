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

void placeWhitePiece(Board* board, bboard piece)
{	
	
}

void setupDefaultBoard(Board* board)
{
	board->white = 0;
	board->black = 0;
	
	board->white |= PIECE(35) | PIECE(28);
	board->black |= PIECE(27) | PIECE(36);
}



