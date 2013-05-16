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

			if(matrix[i][j] == 0)
			{
				SetConsoleTextAttribute(consoleHandle, 255);
				printf("%d", matrix[i][j]);
				SetConsoleTextAttribute(consoleHandle, 215);

			} else printf("%d", matrix[i][j]);

		}





}