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

/*void printFormattedMatrix(int **matrix, dimension_t dimension, int column ,int row) {
	int i,j;
	int temp=row;

	for (i=0;i<dimension.x;i++) {
		temp=row;
		for (j=0;j<dimension.y;j++) {

			if(matrix[j][i]==0) {
				changeColor(102);
				positionCursor(column,temp++);
				printf ("%d%d",matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d",matrix[j][i],matrix[j][i]);
				changeColor(119);

			} else if (matrix[j][i]==PLAYER) {
				changeColor(111);
				positionCursor(column,temp++);
				printf ("\225\225",matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("\225\225",matrix[j][i],matrix[j][i]);
				changeColor(119);
			}

			else if (matrix[j][i]==MUMMY) {
				changeColor(110);
				positionCursor(column,temp++);
				printf (" @",matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("||",matrix[j][i],matrix[j][i]);
				changeColor(119);
			}
			else if (matrix[j][i]==JEWEL) {
				changeColor(108);
				positionCursor(column,temp++);
				printf ("\4\4",matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("\4\4",matrix[j][i],matrix[j][i]);
				changeColor(119);
			}
			else {	
				changeColor(119);
				positionCursor(column,temp++);
				printf ("%d%d",matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d",matrix[j][i],matrix[j][i]);
			}

		}
		column+=2;
	}
}*/