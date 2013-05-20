#include <stdio.h>
#include <Windows.h>

#include "maze_gui.h"
#include "maze_create.h"
#include "colors.h"




void printFormattedMatrix(int **matrix, dimension_t dimension)
{
	int i, j;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 

	SetConsoleTextAttribute(consoleHandle, 215);

	for (i=0; i<dimension.y; i++, printf("\n") )
		for(j=0; j<dimension.x; j++)
		{

			if(matrix[i][j] == 0)
			{
				changeColor(102);
				printf("%d", matrix[i][j]);
				changeColor(119);

			} else if (matrix[i][j] == 3) {
				changeColor(110);
				printf ("@",matrix[i][j]);
				changeColor(119);
			}

			else if (matrix[i][j] == 4) {
				changeColor(108);
				printf ("\4",matrix[i][j]);
				changeColor(119);
			}
			else {	
				changeColor(119);
				printf("%d", matrix[i][j]);
			}

		}





}