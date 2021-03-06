#ifndef OTHELLO_M
#define OTHELLO_M

#include <stdint.h>

#define WHITE 1
#define BLACK 2

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#define PIECE(pos) (1ULL << pos)

#define LEFTSIDE (PIECE(0) | PIECE(8) | PIECE(16) | PIECE(24) | PIECE(32) | PIECE(40) | PIECE(48) | PIECE(56))
#define RIGHTSIDE (PIECE(7) | PIECE(15) | PIECE(23) | PIECE(31) | PIECE(39) | PIECE(47) | PIECE(55) | PIECE(63))

#define LINE "+---+---+---+---+---+---+---+---+"

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


typedef uint64_t bboard;

typedef struct struct_board
{
	bboard white;
	bboard black;
}Board;

typedef struct struct_Move
{
	Board newBoard;
	Board oldBoard;
}Move;

void printBitboard(bboard board);
void printBoard(Board* board);
int placePiece(Board* board, bboard piece, int side);
void setupDefaultBoard(Board* board);

#endif

