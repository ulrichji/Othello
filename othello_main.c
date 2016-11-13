#include <stdio.h>
#include <stdlib.h>
#include "othello.h"

int main(int argc, char** argv)
{
	Board* board = (Board*)malloc(sizeof(Board));
	setupDefaultBoard(board);
	printBoard(board);
	
	int res = placeWhitePiece(board,PIECE(49));
	
	printf("res: %d\n",res);
	
	printBoard(board);
	
	free(board);
	return 0;
}
