#include <stdio.h>
#include <stdlib.h>
#include "othello.h"
#include "console_player.h"

int main(int argc, char** argv)
{
	Board* board = (Board*)malloc(sizeof(Board));
	setupDefaultBoard(board);
	
	int turn = WHITE;
	
	for(int i=0;i<10;i++)
	{
		printBoard(board);
		if(turn == WHITE)
			turn = BLACK;
		else
			turn = WHITE;
		
		int result = 1;
		while(result != 0)
		{
			bboard placement = getConsolePlayerPlacement();
			result = placePiece(board, placement, turn);
			if(result != 0)
			{
				printf("That move is not legal!\n");
			}
		}
	}
	
	//int res = placePiece(board,PIECE(21),BLACK);
	
	//printf("res: %d\n",res);
	
	printBoard(board);
	
	free(board);
	return 0;
}
