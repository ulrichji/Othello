#include <stdint.h>

#define PIECE(pos) (1ULL << pos)

#define LEFTSIDE (PIECE(0) | PIECE(8) | PIECE(16) | PIECE(24) | PIECE(32) | PIECE(40) | PIECE(48) | PIECE(56))
#define RIGHTSIDE (PIECE(7) | PIECE(15) | PIECE(23) | PIECE(31) | PIECE(39) | PIECE(47) | PIECE(55) | PIECE(63))

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

void printBitboard(bboard board);
void printBoard(Board* board);
void generateBlackMoves(Board* board);
void generateWhiteMoves(Board* board);
void setupDefaultBoard(Board* board);

