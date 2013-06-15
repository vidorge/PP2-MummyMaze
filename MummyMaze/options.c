#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"
#include "options.h"

void options (settings_t *settings) {
	int i, choice, selection=11, subselection=1;

	backgroundImage(TEXT);

	while(1) {
		
		if (selection==11) {                //11
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS);
			printf ("LEVEL SIZE");
			changeColor(MENUA);
			positionCursor(FIRST,TOPOPTIONS+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS);
			printf ("LEVEL SIZE");
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS+2);
			printf ("K");
		}

		if (selection==12) {                //12
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS);
			printf ("WALL COLOR");
			changeColor(MENUA);
			positionCursor(FIRST,BOTTOMOPTIONS+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS);
			printf ("WALL COLOR");
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS+2);
			printf ("K");
		}

		if (selection==21) {                //21
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS);
			printf ("PLAYER");
			changeColor(MENUA);
			positionCursor(SECOND,TOPOPTIONS+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS);
			printf ("PLAYER");
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS+2);
			printf ("K");
		}

		if (selection==22) {                //22
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS);
			printf ("MAZE ALGORITHM");
			changeColor(MENUA);
			positionCursor(SECOND,BOTTOMOPTIONS+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS);
			printf ("MAZE ALGORITHM");
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS+2);
			printf ("K");
		}

		if (selection==31) {                //31
			changeColor(MENUC);
			positionCursor(THIRD,TOPOPTIONS);
			printf ("BOT NUMBER");
			changeColor(MENUA);
			positionCursor(THIRD,TOPOPTIONS+2);
			printf ("%d",settings->botNumber);
		}
		else {
			changeColor(MENUC);
			positionCursor(THIRD,TOPOPTIONS);
			printf ("BOT NUMBER");
			changeColor(MENUC);
			positionCursor(THIRD,TOPOPTIONS+2);
			printf ("%d",settings->botNumber);
		}

		if (selection==32) {                //32
			changeColor(MENUC);
			positionCursor(THIRD,BOTTOMOPTIONS);
			printf ("BOT DIFFICULTY");
			changeColor(MENUA);
			positionCursor(THIRD,BOTTOMOPTIONS+2);
			if (settings->botDifficuly==EASY)
				printf ("EASY");
			else
				printf ("HARD");
		}
		else {
			changeColor(MENUC);
			positionCursor(THIRD,BOTTOMOPTIONS);
			printf ("BOT DIFFICULTY");
			changeColor(MENUC);
			positionCursor(THIRD,BOTTOMOPTIONS+2);
			if (settings->botDifficuly==EASY)
				printf ("EASY");
			else
				printf ("HARD");
		}
		
		choice=controls(_getch());
		if ((choice==EXIT)||(choice==PAUSE)) break;

		switch (choice)	{
			case UP:	 if (selection%10 == 2) selection--; 
						 else selection++; 
						 break;
			case DOWN:	 if (selection%10 == 1) selection++; 
						 else if (selection%10 == 2) selection--;
						 break;
			case LEFT:	 if (selection/10 == 1) selection+=20; 
						 else selection-=10;
						 break;
			case RIGHT:	 if (selection/10 == 3) selection-=20; 
						 else selection+=10;
						 break;
			case ENTER:	 switch (selection) {
							case 11: break;

							case 12: break;

							case 21: break;

							case 31:
								while (1) {
									if (settings->botNumber==1) {
										changeColor(MENUA);positionCursor(THIRD+1,TOPOPTIONS+3);printf ("    1    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(THIRD+1,TOPOPTIONS+3);printf ("    1    ");
									}

									if (settings->botNumber==2) {
										changeColor(MENUA);positionCursor(THIRD+1,TOPOPTIONS+4);printf ("    2    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(THIRD+1,TOPOPTIONS+4);printf ("    2    ");
									}

									if (settings->botNumber==3) {
										changeColor(MENUA);positionCursor(THIRD+1,TOPOPTIONS+5);printf ("    3    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(THIRD+1,TOPOPTIONS+5);printf ("    3    ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->botNumber>1) settings->botNumber--; else settings->botNumber=3; break;
										case DOWN:	if (settings->botNumber<3) settings->botNumber++; else settings->botNumber=1; break;
									}								
								}
								
								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(THIRD,i);changeColor(MENUC);printf ("                   ");
								}
							break;

							case 32: 
								while (1) {
									if (settings->botDifficuly==EASY) {
										changeColor(MENUA);positionCursor(THIRD+1,BOTTOMOPTIONS+3);printf ("    EASY    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(THIRD+1,BOTTOMOPTIONS+3);printf ("    EASY    ");
									}

									if (settings->botDifficuly==HARD) {
										changeColor(MENUA);positionCursor(THIRD+1,BOTTOMOPTIONS+4);printf ("    HARD    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(THIRD+1,BOTTOMOPTIONS+4);printf ("    HARD    ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->botDifficuly==EASY) settings->botDifficuly=HARD; else settings->botDifficuly=EASY; break;
										case DOWN:	if (settings->botDifficuly==HARD) settings->botDifficuly=EASY; else settings->botDifficuly=HARD; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(THIRD,i);changeColor(MENUC);printf ("                   ");
								}
							break;

						 } break; //break enter
		}


	}
}