#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"


int startGame()
{
	int **matrix;
	dimension_t dimension;

	dimension.x = 80;
	dimension.y = 23;
	
	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN??? I <3 DORVI
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	DfsInit(matrix, dimension);

	RemoveRandomWalls(matrix, dimension, 4);
	printFormattedMatrix(matrix, dimension);

	printf("\n\n");

	RemoveAloneWalls(matrix, dimension);



	printFormattedMatrix(matrix, dimension);
	MazeDestroy(matrix, dimension);

	//DEBUGING
	system ("pause"); 

	return 0;
}