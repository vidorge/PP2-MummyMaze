#include <stdio.h>
#include <Windows.h>

#include "maze_gui.h"
#include "maze_create.h"
#include "colors.h"
#include "position_cursor.h"


void printFormattedMatrix(int **matrix, dimension_t dimension) {
	int i,j;
	int temp, column=MAZECOLUMN;

	for (i=0;i<dimension.x;i++) {
		temp=MAZEROW;
		for (j=0;j<dimension.y;j++) {

			if(matrix[j][i]==0) {
				changeColor(102);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
				changeColor(119);

			} else if (matrix[j][i]==PLAYER) {
				changeColor(111);
				positionCursor(column,temp++);
				printf (" \225 ",matrix[j][i],matrix[j][i],matrix[j][i]); //225
				positionCursor(column,temp++);
				printf ("/|\\",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("/ \\",matrix[j][i],matrix[j][i],matrix[j][i]);
				changeColor(119);
			}

			else if (matrix[j][i]==MUMMY) {
				changeColor(110);
				positionCursor(column,temp++);
				printf ("\\@/",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf (" | ",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("/ \\",matrix[j][i],matrix[j][i],matrix[j][i]);
				changeColor(119);
			}
			else if (matrix[j][i]==JEWEL) {
				changeColor(108);
				positionCursor(column,temp++);
				printf ("\4\4\4",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("\4\4\4",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("\4\4\4",matrix[j][i],matrix[j][i],matrix[j][i]);
				changeColor(119);
			}
			else {	
				changeColor(119);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
				positionCursor(column,temp++);
				printf ("%d%d%d",matrix[j][i],matrix[j][i],matrix[j][i]);
			}

		}
		column+=3;
	}
}

void printMovement (int beforeRow, int beforeColumn, int afterRow, int afterColumn, int whatToPrint, int *wave) {
	int i, row;
	
	changeColor(102);
	row=beforeRow*3;
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row++);printf("111");
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row++);printf("111");
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row);printf("111");

	if (whatToPrint==PLAYER) {
		changeColor(111);
		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" \225 ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("/|\\");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
	}
	else if (*wave==0) {
		changeColor(110);
		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("_\@_");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" | ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
		*wave=1;
	}
	else if (*wave==1){
		changeColor(110);
		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" \@ ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("/|\\");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
		*wave=2;
	}
	else {
		changeColor(110);
		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("\\@/");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" | ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
		*wave=0;
	}



}

void printHelpMatrix(int **matrix, dimension_t dimension) {
	int i, j;
	int column=80, row=23;

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