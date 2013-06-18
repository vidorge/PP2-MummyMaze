#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "start_game.h"
#include "background.h"
#include "main_menu.h"
#include "out_animation.h"

#include "options.h"
#include "help.h"
#include "about.h"
#include "screen_resolution.h"

void mainMenu () {

	int selection=NEWGAME, choice, game=FALSE;
	int i=0,end=3;

	settings_t settings;

	settings.botNumber=1;
	settings.botDifficuly=HARD;
	settings.character=LAZY;
	settings.levelSize=LARGE;
	settings.mazeAlgorithm=BINARY;
	settings.wallColor=DARK;
	settings.playMetod=REALTIME;
	settings.filterEnds=YES;

	_getch();

	//***************************************************************************
	//******************             FOOTER                **********************
	//***************************************************************************
	changeColor(GROUND);
	positionCursor(0,HEIGHT-1);changeColor(MENUC);printf ("     Mummy Maze v1.2 BETA                                                       Git Commit Team      All Rights Reserved     ");


	//***************************
	//*****   MENU ITEMS   ******
	//***************************

	while (1) {
		
		changeColor(MENUC);

		if (selection==NEWGAME) {
			if (game) {
				positionCursor(66,18);printf ("----------------");
				changeColor(MENUA);positionCursor(66,19);printf ("|  Resume Game |");
				changeColor(MENUC);positionCursor(66,20);printf ("----------------");
			}

			else {
				positionCursor(66,18);printf ("----------------");
				changeColor(MENUA);positionCursor(66,19);printf ("|   New Game   |");
				changeColor(MENUC);positionCursor(66,20);printf ("----------------");
			}
		}
		else {
			if (game) {
				positionCursor(66,19);printf ("|  Resume Game |");
			}
			else {
				positionCursor(66,19);printf ("|   New Game   |");
			}
		}

		if (selection==LOADGAME) {
			changeColor(MENUA);positionCursor(66,21);printf ("|  Load  Game  |");
			changeColor(MENUC);
		}
		else {
			positionCursor(66,21);printf ("|  Load  Game  |");
			positionCursor(66,22);printf ("----------------");
		}

		if (selection==SAVEGAME) {
			changeColor(MENUA);positionCursor(66,23);printf ("|  Save  Game  |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(66,23);printf ("|  Save  Game  |");
			positionCursor(66,24);printf ("----------------"); 
		}

		if (selection==OPTIONS) { 
			changeColor(MENUA);positionCursor(66,25);printf ("|   Options    |");
			changeColor(MENUC); 
		}
		else { positionCursor(66,25);printf ("|   Options    |");
		positionCursor(66,26);printf ("----------------");
		}

		if (selection==HIGHSCORES) { 
			changeColor(MENUA);positionCursor(66,27);printf ("| High  Scores |");
			changeColor(MENUC); 
		}
		else { 
			positionCursor(66,27);printf ("| High  Scores |");
			positionCursor(66,28);printf ("----------------"); 
		}

		if (selection==HELP) { 
			changeColor(MENUA);positionCursor(66,29);printf ("|     Help     |");
			changeColor(MENUC);
		}
		else { 
			positionCursor(66,29);printf ("|     Help     |");
			positionCursor(66,30);printf ("----------------"); 
		}

		if (selection==ABOUT) { 
			changeColor(MENUA);positionCursor(66,31);printf ("|     About    |"); 
			changeColor(MENUC); 
		}
		else {
			positionCursor(66,31);printf ("|     About    |");
			positionCursor(66,32);printf ("----------------"); 
		}

		if (selection==EXIT) {
			changeColor(MENUA);positionCursor(66,33);printf ("|     Exit     |");
			changeColor(MENUC); 
		}
		else { 
			positionCursor(66,33);printf ("|     Exit     |");
			positionCursor(66,34);printf ("----------------");
		}		
		
		choice=controls(_getch());
		if (choice==EXIT) exit (0);
		switch (choice){
			case UP: { if (selection>NEWGAME) selection--; else selection=EXIT; break; }
			case DOWN: { if (selection<EXIT) selection++; else selection=NEWGAME; break; }
			case ENTER: { 
				switch (selection){
					case NEWGAME:		system("CLS");game=TRUE;startGame(settings, 0);backgroundImage(MENU);break;
					case LOADGAME:		break;
					case SAVEGAME:		break;
					case OPTIONS:		system ("CLS");options(&settings);backgroundImage(MENU);selection=(NEWGAME);break;
					case HIGHSCORES:	break;
					case HELP:			system("CLS");help();backgroundImage(MENU);selection=(NEWGAME);break;
					case ABOUT:			system("CLS");about();backgroundImage(MENU);selection=(NEWGAME);break;
					case EXIT:			outAnimation();exit (1);
				}			
			}
		}
		changeColor(GROUND);
	}
}