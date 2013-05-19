#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "start_game.h"
#include "background.h"

void mainMenu () {

	int selection=0, choice, game=FALSE;
	int i=0,end=3;

	//***************************************************************************
	//******************             FOOTER                **********************
	//***************************************************************************
	changeColor(GROUND);
	positionCursor(0,49);changeColor(MENUC);printf ("     Mummy Maze v1.0 APLHA                                                      Git Commit Team      All Rights Reserved     ");


	//***************************
	//*****   MENU ITEMS   ******
	//***************************

	while (1) {
		
		changeColor(MENUC);

		if (selection==0) {
			if (game) {
				positionCursor(54,18);printf ("----------------");
				changeColor(MENUA);positionCursor(54,19);printf ("|  Resume Game |");
				changeColor(MENUC);positionCursor(54,20);printf ("----------------");
			}

			else {
				positionCursor(54,18);printf ("----------------");
				changeColor(MENUA);positionCursor(54,19);printf ("|   New Game   |");
				changeColor(MENUC);positionCursor(54,20);printf ("----------------");
			}
		}
		else {
			if (game) {
				positionCursor(54,19);printf ("|  Resume Game |");
			}
			else {
				positionCursor(54,19);printf ("|   New Game   |");
			}
		}

		if (selection==1) {
			changeColor(MENUA);positionCursor(54,21);printf ("|  Load  Game  |");
			changeColor(MENUC);
		}
		else {
			positionCursor(54,21);printf ("|  Load  Game  |");
			positionCursor(54,22);printf ("----------------");
		}

		if (selection==2) {
			changeColor(MENUA);positionCursor(54,23);printf ("|  Save  Game  |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(54,23);printf ("|  Save  Game  |");
			positionCursor(54,24);printf ("----------------"); 
		}

		if (selection==3) { 
			changeColor(MENUA);positionCursor(54,25);printf ("|   Options    |");
			changeColor(MENUC); 
		}
		else { positionCursor(54,25);printf ("|   Options    |");
		positionCursor(54,26);printf ("----------------");
		}

		if (selection==4) { 
			changeColor(MENUA);positionCursor(54,27);printf ("| High  Scores |");
			changeColor(MENUC); 
		}
		else { 
			positionCursor(54,27);printf ("| High  Scores |");
			positionCursor(54,28);printf ("----------------"); 
		}

		if (selection==5) { 
			changeColor(MENUA);positionCursor(54,29);printf ("|     Help     |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(54,29);printf ("|     Help     |");
			positionCursor(54,30);printf ("----------------"); 
		}

		if (selection==6) { 
			changeColor(MENUA);positionCursor(54,31);printf ("|     About    |"); 
			changeColor(MENUC); 
		}
		else {
			positionCursor(54,31);printf ("|     About    |");
			positionCursor(54,32);printf ("----------------"); 
		}

		if (selection==7) {
			changeColor(MENUA);positionCursor(54,33);printf ("|     Exit     |");
			changeColor(MENUC); 
		}
		else { 
			positionCursor(54,33);printf ("|     Exit     |");
			positionCursor(54,34);printf ("----------------");
		}

		choice=controls(_getch());
		if (choice==EXIT) break;
		switch (choice){
			case UP: { if (selection>0) selection--; else selection=7; break; }
			case DOWN: { if (selection<7) selection++; else selection=0; break; }
			case ENTER: { 
				switch (selection){
					case 0: system("CLS");game=TRUE;startGame();backgroundImage(2);break;
					case 1: break;
					case 2: break;
					case 3: break;
					case 4: break;
					case 5: break;
					case 6: break;
					case 7: exit (0);
				}			
			}
		}
		changeColor(GROUND);
	}
}