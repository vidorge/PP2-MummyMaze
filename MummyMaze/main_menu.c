#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "start_game.h"
#include "background.h"
#include "main_menu.h"

#include "help.h"

void mainMenu () {

	int selection=NEWGAME, choice, game=FALSE;
	int i=0,end=3;

	_getch();

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

		if (selection==NEWGAME) {
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

		if (selection==LOADGAME) {
			changeColor(MENUA);positionCursor(54,21);printf ("|  Load  Game  |");
			changeColor(MENUC);
		}
		else {
			positionCursor(54,21);printf ("|  Load  Game  |");
			positionCursor(54,22);printf ("----------------");
		}

		if (selection==SAVEGAME) {
			changeColor(MENUA);positionCursor(54,23);printf ("|  Save  Game  |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(54,23);printf ("|  Save  Game  |");
			positionCursor(54,24);printf ("----------------"); 
		}

		if (selection==OPTIONS) { 
			changeColor(MENUA);positionCursor(54,25);printf ("|   Options    |");
			changeColor(MENUC); 
		}
		else { positionCursor(54,25);printf ("|   Options    |");
		positionCursor(54,26);printf ("----------------");
		}

		if (selection==HIGHSCORES) { 
			changeColor(MENUA);positionCursor(54,27);printf ("| High  Scores |");
			changeColor(MENUC); 
		}
		else { 
			positionCursor(54,27);printf ("| High  Scores |");
			positionCursor(54,28);printf ("----------------"); 
		}

		if (selection==HELP) { 
			changeColor(MENUA);positionCursor(54,29);printf ("|     Help     |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(54,29);printf ("|     Help     |");
			positionCursor(54,30);printf ("----------------"); 
		}

		if (selection==ABOUT) { 
			changeColor(MENUA);positionCursor(54,31);printf ("|     About    |"); 
			changeColor(MENUC); 
		}
		else {
			positionCursor(54,31);printf ("|     About    |");
			positionCursor(54,32);printf ("----------------"); 
		}

		if (selection==EXIT) {
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
			case UP: { if (selection>NEWGAME) selection--; else selection=EXIT; break; }
			case DOWN: { if (selection<EXIT) selection++; else selection=NEWGAME; break; }
			case ENTER: { 
				switch (selection){
					case NEWGAME:		system("CLS");game=TRUE;startGame();backgroundImage(2);break;
					case LOADGAME:		break;
					case SAVEGAME:		break;
					case OPTIONS:		break;
					case HIGHSCORES:	break;
					case HELP:			system("CLS");help();backgroundImage(2);selection=(NEWGAME);break;
					case ABOUT:			break;
					case EXIT:			exit (0);
				}			
			}
		}
		changeColor(GROUND);
	}
}