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

	setConsoleSize(WIDTH,HEIGHT);

	matrix = initMatrix(23);
	printFormattedMatrix(matrix, 23);
	
	system ("pause");
	return 0;
}