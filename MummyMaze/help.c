#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "maze_solve.h"

void help () {
	
	int i, input, gotTheJewel=0;

	int **matrix;
	dimension_t dimension;
	position_t	playerPosition, jewelPosition;

	dimension.x = 35;
	dimension.y = 20;
	matrix = initMatrix(dimension);
	fillHelpMatrix(matrix,dimension);
	
	playerPosition.x=playerPosition.y=3;
	jewelPosition.x=6;
	jewelPosition.y=22;

	matrix[playerPosition.x][playerPosition.y]=PLAYER;
	matrix[jewelPosition.x][jewelPosition.y]=JEWEL;

	backgroundImage (TEXT);	
	
	//***************************
	//****   HEADING   **********
	//***************************

	positionCursor(63,11);
	printf ("  _    _ ______ _      _____  ");
	positionCursor(63,12);
	printf (" | |  | |  ____| |    |  __ \\ ");
	positionCursor(63,13);
	printf (" | |__| | |__  | |    | |__) |");
	positionCursor(63,14);
	printf (" |  __  |  __| | |    |  ___/ ");
	positionCursor(63,15);
	printf (" | |  | | |____| |____| |     ");
	positionCursor(63,16);
	printf (" |_|  |_|______|______|_|     ");
	positionCursor(63,17);
	printf ("                              ");

	//***********************************
	//*******    CONTAINER   ************
	//***********************************

	positionCursor(42,20);
	printf ("CONTROLS");
	positionCursor(108,20);
	printf ("How to!");
	
	//*******  CURSORS  **********
	positionCursor(23,22);
	printf ("          _______               ||");
	positionCursor(23,23);
	printf ("         ||      ||             ||");
	positionCursor(23,24);
	printf ("         ||  up  ||             || ");
	positionCursor(23,25);
	printf ("         ||      ||             ||");
	positionCursor(23,26);
	printf ("         ||______||             ||");
	positionCursor(23,27);
	printf ("         |/______\\|             ||");
	positionCursor(23,28);
	printf (" _______  _______  _______      ||");
	positionCursor(23,29);
	printf ("||      |||      |||      ||    ||");
	positionCursor(23,30);
	printf ("||      |||      |||      ||    ||");
	positionCursor(23,31);
	printf ("||left  ||| down ||| right||    ||");
	positionCursor(23,32);
	printf ("||______|||______|||______||    ||");
	positionCursor(23,33);
	printf ("|/______\\|/______\\|/______\\|    ||");

	positionCursor(23,34);
	printf ("                                ||");
	positionCursor(23,35);
	printf ("                                ||");

	positionCursor(23,36);
	printf (" ____________________           ||");
	positionCursor(23,37);
	printf ("||                   ||         ||");
	positionCursor(23,38);
	printf ("|| \33---    PAUSE     ||         ||");
	positionCursor(23,39);
	printf ("||                   ||         ||");
	positionCursor(23,40);
	printf ("||___________________||         ||");
	positionCursor(23,41);
	printf ("|/___________________\\|         ||");

	positionCursor(23,42);
	printf ("                                ||");
	positionCursor(23,43);
	printf ("                                ||");

	//*******  Description  **********
	positionCursor(58,23);
	printf ("For movement use the Arrow keys");
	positionCursor(58,24);
	printf ("and for pause/menu press");
	positionCursor(58,25);
	printf ("Backspace or Escape key.");

	positionCursor(58,30);
	printf ("Goal is to get around");
	positionCursor(58,31);
	printf ("the Labirinth collect the");
	positionCursor(58,32);
	printf ("Jewel and get out before");
	positionCursor(58,33);
	printf ("mummy catches you!");

	positionCursor(58,38);
	printf ("Try to get the Jewel on");
	positionCursor(58,39);
	printf ("how to test run!");
	
	for (i=22;i<44;i++) {
		positionCursor(90,i);
		printf ("||");
	}

	//*******  Matrix  **********

	while (1) {
		printHelpMatrix(matrix,dimension);
		
		
		if ((playerPosition.x==jewelPosition.x)&&(playerPosition.y==jewelPosition.y)) gotTheJewel=1;
		
		if (gotTheJewel) {
			positionCursor(105,33);
			changeColor(14);
			printf("YOU DID IT!");
		}

		input=controls(_getch());
		if ((input==PAUSE)||(input==EXIT)) break;
		switch (input) {
			case UP:	if (matrix[playerPosition.x-1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y);
							playerPosition.x-=1;
							break;
						}else break;
			case DOWN:	if (matrix[playerPosition.x+1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y);
							playerPosition.x+=1;
							break;
						}else break;
			case LEFT:	if (matrix[playerPosition.x][playerPosition.y-1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1);
							playerPosition.y-=1;
							break;
						}else break;
			case RIGHT:	if (matrix[playerPosition.x][playerPosition.y+1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1);
							playerPosition.y+=1;
							break;
						}else break;
		}
		
	}
	
	
	MazeDestroy(matrix, dimension);
}