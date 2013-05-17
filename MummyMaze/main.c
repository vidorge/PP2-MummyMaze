#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "screen_resolution.h"


int main()
{
	int **matrix;
	
	//i'm a sad sad main :(

	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN???
	srand( (unsigned) time(NULL) );

	setConsoleSize(WIDTH,HEIGHT);

	matrix = initMatrix(23);

	DfsInit(matrix, 23);

	RemoveRandomWalls(matrix, 23, 7);

	printFormattedMatrix(matrix, 23);

	system ("pause");
	return 0;
}