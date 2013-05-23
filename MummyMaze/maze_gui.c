#include <stdio.h>
#include <Windows.h>

#include "maze_gui.h"
#include "maze_create.h"
#include "colors.h"
#include "position_cursor.h"


void printFormattedMatrix(int **matrix, dimension_t dimension, int column ,int row) {
	int i, j;

	for (i=0; i<dimension.y; i++) {
		positionCursor(column,row++);
		for(j=0; j<dimension.x; j++) {

			if(matrix[i][j]==0) {
				changeColor(102);
				printf("%d", matrix[i][j]);
				changeColor(119);

			} else if (matrix[i][j]==PLAYER) {
				changeColor(111);
				printf ("\225",matrix[i][j]);
				changeColor(119);
			}

			else if (matrix[i][j]==MUMMY) {
				changeColor(110);
				printf ("@",matrix[i][j]);
				changeColor(119);
			}
			else if (matrix[i][j]==JEWEL) {
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
}