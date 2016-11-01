#include <stdio.h>
#include <stdlib.h>
#include "othello.h"

int main(int argc, char** argv)
{
	Board* board = (Board*)malloc(sizeof(Board));
	setupDefaultBoard(board);
	printBoard(board);
	generateWhiteMoves(board);
	free(board);
	return 0;
}
