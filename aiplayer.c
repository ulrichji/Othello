#include "aiplayer.h"

bboard getMoveAlternatives(Board* board, int side)
{
	bboard enemies;
	bboard friends;
	bboard empty;
	bboard alternatives = 0ULL;
	
	if(side == WHITE)
	{
		enemies = board->black;
		friends = board->white;
	}
	else
	{
		enemies = board->white;
		friends = board->black;
	}
	
	empty = ~(enemies | friends);
	
	alternatives |= (enemies >> 1ULL) & (~RIGHTSIDE);
	alternatives |= (enemies << 1ULL) & (~LEFTSIDE);
	alternatives |= (enemies << 8ULL);
	alternatives |= (enemies >> 8ULL);
	alternatives |= (enemies << 7ULL) & (~RIGHTSIDE);
	alternatives |= (enemies >> 9ULL) & (~RIGHTSIDE);
	alternatives |= (enemies << 9ULL) & (~LEFTSIDE);
	alternatives |= (enemies >> 7ULL) & (~LEFTSIDE);
	
	return alternatives;
}

bboard generateMove(Board* board, int side)
{
	bboard alternatives = getMoveAlternatives(board, side);
	
	while(alternatives)
	{
		bboard move = alternatives & (~(alternatives - 1));
		printBitboard(move);
		alternatives &= ~(move);
	}
}

bboard getAiPlayerPlacement(Board* board, int side)
{
	Board boardCopy = *board;
	Board* boardCopyPointer = &boardCopy;
	
	bboard result = generateMove(boardCopyPointer, side);
	
	return result;
}

