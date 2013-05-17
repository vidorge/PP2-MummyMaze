#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"


int main()
{
	int **matrix;
	
	//i'm a sad sad main :(

	matrix = initMatrix(23);
	printFormattedMatrix(matrix, 23);
	
	return 0;
}