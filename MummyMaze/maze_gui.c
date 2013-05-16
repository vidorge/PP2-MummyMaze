#include <stdio.h>
#include <Windows.h>

#include "maze_gui.h"




void printFormattedMatrix(int **matrix, int dimension)
{
	int i, j;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	SetConsoleTextAttribute(consoleHandle, 215);

	for (i=0; i<dimension; i++, printf("\n") )
		for(j=0; j<dimension; j++)
		{
			printf("%d", matrix[i][j]);

		}

}