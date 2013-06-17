#include "maze_gui.h"


void printFormattedMatrix(int **matrix, dimension_t dimension,settings_t settings) {
	int i,j;
	int temp, column=MAZECOLUMN;

	
	system ("CLS");
	if (settings.wallColor==LIGHT)
		changeColor(LIGHTBACK);	
	else
		changeColor(DARKBACK);
	
	for (i=0;i<HEIGHT;i++)	{
		for (j=0;j<WIDTH;j++)
			printf ("\261");
	}


	for (i=0;i<dimension.x;i++) {
		temp=MAZEROW;
		for (j=0;j<dimension.y;j++) {

			if(matrix[j][i]==BLANK) {
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTBLANK);
				else
					changeColor(DARKBLANK);

				positionCursor(column,temp++);
				printf ("   ");
				positionCursor(column,temp++);
				printf ("   ");
				positionCursor(column,temp++);
				printf ("   ");
				changeColor(119);

			} else if (matrix[j][i]==PLAYER) {
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTPLAYER);
				else
					changeColor(DARKPLAYER);

				positionCursor(column,temp++);
				printf (" \225 "); //225
				positionCursor(column,temp++);
				printf ("/|\\");
				positionCursor(column,temp++);
				printf ("/ \\");
				changeColor(119);
			}

			else if (matrix[j][i]==MUMMY) {
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTMUMMY);
				else
					changeColor(DARKMUMMY);

				positionCursor(column,temp++);
				printf ("\\@/");
				positionCursor(column,temp++);
				printf (" | ");
				positionCursor(column,temp++);
				printf ("/ \\");
				changeColor(119);
			}
			else if (matrix[j][i]==JEWEL) {
				if (settings.wallColor==LIGHT)
					changeColor(188);
				else
					changeColor(108);

				positionCursor(column,temp++);
				printf ("\4\4\4");
				positionCursor(column,temp++);
				printf ("\4\4\4");
				positionCursor(column,temp++);
				printf ("\4\4\4");
				changeColor(119);
			}
			else if (matrix[j][i]==EXIT) {
				if (settings.wallColor==LIGHT)
					changeColor(108);
				else
					changeColor(60);

				positionCursor(column,temp++);
				printf ("\260\260\262");
				positionCursor(column,temp++);
				printf ("\260\260\262");
				positionCursor(column,temp++);
				printf ("\260\260\262");
				changeColor(119);
			}
			else {
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTWALL);
				else
					changeColor(DARKWALL);


				positionCursor(column,temp++);
				printf ("\260\260\260");
				positionCursor(column,temp++);
				printf ("\261\261\261");
				positionCursor(column,temp++);
				printf ("\262\262\262");
			}

		}
		column+=3;
	}
}

void printMovement (int beforeRow, int beforeColumn, int afterRow, int afterColumn, int whatToPrint, int *wave, settings_t settings) {
	int i, row;
	
	if (settings.wallColor==LIGHT)
		changeColor(LIGHTBLANK);
	else
		changeColor(DARKBLANK);

	row=beforeRow*3;
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row++);printf("   ");
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row++);printf("   ");
	positionCursor(MAZECOLUMN+(beforeColumn*3),MAZEROW+row);printf("   ");

	if (whatToPrint==PLAYER) {
		if (settings.wallColor==LIGHT)
			changeColor(LIGHTPLAYER);
		else
			changeColor(DARKPLAYER);

		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" \225 ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("/|\\");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
	}
	else if (*wave==0) {
		if (settings.wallColor==LIGHT)
			changeColor(LIGHTMUMMY);
		else
			changeColor(DARKMUMMY);

		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("_\@_");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" | ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
		*wave=1;
	}
	else if (*wave==1){
		if (settings.wallColor==LIGHT)
			changeColor(LIGHTMUMMY);
		else
			changeColor(DARKMUMMY);
		row=afterRow*3;
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf(" \@ ");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row++);printf("/|\\");
		positionCursor(MAZECOLUMN+(afterColumn*3),MAZEROW+row);printf("/ \\");
		*wave=2;
	}
	else {
		if (settings.wallColor==LIGHT)
			changeColor(LIGHTMUMMY);
		else
			changeColor(DARKMUMMY);
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
				changeColor(LIGHTBLANK);
				printf(" ");

			} else if (matrix[i][j]==PLAYER) {
				changeColor(LIGHTPLAYER);
				printf ("\225");
			}

			else if (matrix[i][j]==JEWEL) {
				changeColor(108);
				printf ("\4");
			}
			else {	
				changeColor(LIGHTWALL);
				printf(" ");
			}

		}
	}
}