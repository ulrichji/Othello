#include "console_player.h"
#include <stdio.h>

int getIndex(char character)
{	
	switch(character)
	{
		case 'a': case '1':
			return 0;
		case 'b': case '2':
			return 1;
		case 'c': case '3':
			return 2;
		case 'd': case '4':
			return 3;
		case 'e': case '5':
			return 4;
		case 'f': case '6':
			return 5;
		case 'g': case '7':
			return 6;
		case 'h': case '8':
			return 7;
	}
	
	//error indicating a mistake
	return -1;
}

bboard getConsolePlayerPlacement(void)
{
	bboard placement = 0ULL;
	
	int validPlacement = 1;
	
	char line [100];
	
	while(validPlacement != 0)
	{
		printf("Place piece: ");
		scanf("%s",line);
		printf("%s\n",line);
		
		char currentChar = '=';
		int counter = 0;
		int col = -1;
		int row = -1;
		while(currentChar != 0)
		{
			currentChar = line[counter];
			
			int indexVal = getIndex(currentChar);
			
			if(indexVal >= 0)
			{
				if(col >= 0)
					row = indexVal;
				else
					col = indexVal;
			}
			
			if(counter >= 100)
			{
				printf("Input is invalid. Can not be longer than 100 characters!\n");
				break;
			}
			counter++;
		}
		
		if(row < 0 || col < 0)
		{
			printf("Input is invalid. No valid rows or columns found\n");
		}
		else
		{
			validPlacement = 0;
			placement = (1ULL << (bboard)((row * BOARD_WIDTH) + col));
		}
		printf("Move to %d,%d\n", row, col);
	}
	
	return placement;
}
