#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIECE(pos) (1ULL << pos)

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

const char* line = "+---+---+---+---+---+---+---+---+";

typedef uint64_t bboard;

typedef struct struct_board
{
	bboard white;
	bboard black;
}Board;

typedef struct struct_Move
{
	Board new;
	Board old;
}Move;

void printBitboard(bboard board)
{
	printf("%s\n",line);
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
		printf("|\n%s\n",line);
	}
}

void printBoard(Board* board)
{
	printf("%s\n",line);
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
		printf("|\n%s\n",line);
	}
}

void generateBlackMoves(Board* board)
{

}

void generateWhiteMoves(Board* board)
{
	
}

void setupDefaultBoard(Board* board)
{
	board->white = 0;
	board->black = 0;
	
	board->white |= PIECE(35) | PIECE(28);
	board->black |= PIECE(27) | PIECE(36);
}

int main(int argc, char** argv)
{
	Board* board = (Board*)malloc(sizeof(Board));
	setupDefaultBoard(board);
	printBoard(board);
	free(board);
}

