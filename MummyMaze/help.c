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

	positionCursor(50,11);
	printf ("  _    _ ______ _      _____  ");
	positionCursor(50,12);
	printf (" | |  | |  ____| |    |  __ \\ ");
	positionCursor(50,13);
	printf (" | |__| | |__  | |    | |__) |");
	positionCursor(50,14);
	printf (" |  __  |  __| | |    |  ___/ ");
	positionCursor(50,15);
	printf (" | |  | | |____| |____| |     ");
	positionCursor(50,16);
	printf (" |_|  |_|______|______|_|     ");
	positionCursor(50,17);
	printf ("                              ");

	//***********************************
	//*******    CONTAINER   ************
	//***********************************

	positionCursor(39,20);
	printf ("CONTROLS");
	positionCursor(95,20);
	printf ("How to!");
	
	//*******  CURSORS  **********
	positionCursor(10,22);
	printf ("          _______               ||");
	positionCursor(10,23);
	printf ("         ||      ||             ||");
	positionCursor(10,24);
	printf ("         ||  up  ||             || ");
	positionCursor(10,25);
	printf ("         ||      ||             ||");
	positionCursor(10,26);
	printf ("         ||______||             ||");
	positionCursor(10,27);
	printf ("         |/______\\|             ||");
	positionCursor(10,28);
	printf (" _______  _______  _______      ||");
	positionCursor(10,29);
	printf ("||      |||      |||      ||    ||");
	positionCursor(10,30);
	printf ("||      |||      |||      ||    ||");
	positionCursor(10,31);
	printf ("||left  ||| down ||| right||    ||");
	positionCursor(10,32);
	printf ("||______|||______|||______||    ||");
	positionCursor(10,33);
	printf ("|/______\\|/______\\|/______\\|    ||");

	positionCursor(10,34);
	printf ("                                ||");
	positionCursor(10,35);
	printf ("                                ||");

	positionCursor(10,36);
	printf (" ____________________           ||");
	positionCursor(10,37);
	printf ("||                   ||         ||");
	positionCursor(10,38);
	printf ("|| \33---    PAUSE     ||         ||");
	positionCursor(10,39);
	printf ("||                   ||         ||");
	positionCursor(10,40);
	printf ("||___________________||         ||");
	positionCursor(10,41);
	printf ("|/___________________\\|         ||");

	positionCursor(10,42);
	printf ("                                ||");
	positionCursor(10,43);
	printf ("                                ||");

	//*******  Description  **********
	positionCursor(45,23);
	printf ("For movement use the Arrow keys");
	positionCursor(45,24);
	printf ("and for pause/menu press");
	positionCursor(45,25);
	printf ("Backspace or Escape key.");

	positionCursor(45,30);
	printf ("Goal is to get around");
	positionCursor(45,31);
	printf ("the Labirinth collect the");
	positionCursor(45,32);
	printf ("Jewel and get out before");
	positionCursor(45,33);
	printf ("mummy catches you!");

	positionCursor(45,38);
	printf ("Try to get the Jewel on");
	positionCursor(45,39);
	printf ("how to test run!");
	
	for (i=22;i<44;i++) {
		positionCursor(77,i);
		printf ("||");
	}

	//*******  Matrix  **********

	while (1) {
		printHelpMatrix(matrix,dimension,80,23);
		
		
		if ((playerPosition.x==jewelPosition.x)&&(playerPosition.y==jewelPosition.y)) gotTheJewel=1;
		
		if (gotTheJewel) {
			positionCursor(92,33);
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