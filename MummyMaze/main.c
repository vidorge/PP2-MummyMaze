#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "screen_resolution.h"


int main()
{
	int **matrix;
	dimension_t dimension;

	dimension.x = 80;
	dimension.y = 23;
	
	//i'm a sad sad main :(

	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN???
	srand( (unsigned) time(NULL) );

	setConsoleSize(WIDTH,HEIGHT);

	matrix = initMatrix(dimension);

	DfsInit(matrix, dimension);

	RemoveRandomWalls(matrix, dimension, 3);
	RemoveAloneWalls(matrix, dimension);


	printFormattedMatrix(matrix, dimension);

	MazeDestroy(matrix, dimension);

	system ("pause");
	return 0;
}