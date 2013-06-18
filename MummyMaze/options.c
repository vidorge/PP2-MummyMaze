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

	positionCursor(50,11);
	printf (	"   ____  _____ _______ _____ ____  _   _  _____ \n");
	positionCursor(50,12);
	printf ("  / __ \\|  __ \\__   __|_   _/ __ \\| \\ | |/ ____|\n");
	positionCursor(50,13);
	printf (" | |  | | |__) | | |    | || |  | |  \\| | (___  \n");
	positionCursor(50,14);
	printf (" | |  | |  ___/  | |    | || |  | | . ` |\\___ \\ \n");
	positionCursor(50,15);
	printf (" | |__| | |      | |   _| || |__| | |\\  |____) |\n");
	positionCursor(50,16);
	printf ("  \\____/|_|      |_|  |_____\\____/|_| \\_|_____/ ");
	positionCursor(50,17);
	printf ("                                                ");


	while(1) {
		
		if (selection==LEVELSIZE) {
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS);
			printf ("LEVEL SIZE");
			changeColor(MENUA);
			positionCursor(FIRST,TOPOPTIONS+2);
			if (settings->levelSize==SMALL)
				printf ("SMALL");
			else if (settings->levelSize==MEDIUM)
				printf ("MEDIUM");
			else
				printf ("LARGE");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS);
			printf ("LEVEL SIZE");
			changeColor(MENUC);
			positionCursor(FIRST,TOPOPTIONS+2);
			if (settings->levelSize==SMALL)
				printf ("SMALL");
			else if (settings->levelSize==MEDIUM)
				printf ("MEDIUM");
			else
				printf ("LARGE");
		}

		if (selection==WALLCOLOR) {
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS);
			printf ("WALL COLOR");
			changeColor(MENUA);
			positionCursor(FIRST,BOTTOMOPTIONS+2);
			if (settings->wallColor==LIGHT)
				printf ("LIGHT");
			else
				printf ("DARK");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS);
			printf ("WALL COLOR");
			changeColor(MENUC);
			positionCursor(FIRST,BOTTOMOPTIONS+2);
			if (settings->wallColor==LIGHT)
				printf ("LIGHT");
			else
				printf ("DARK");
		}

		if (selection==PLAYMETOD) {
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS);
			printf ("PLAY METOD");
			changeColor(MENUA);
			positionCursor(SECOND,TOPOPTIONS+2);
			if (settings->playMetod==REALTIME)
				printf ("REAL TIME");
			else 
				printf ("POSITIONAL");
		}
		else {
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS);
			printf ("PLAY METOD");
			changeColor(MENUC);
			positionCursor(SECOND,TOPOPTIONS+2);
			if (settings->playMetod==REALTIME)
				printf ("REAL TIME");
			else 
				printf ("POSITIONAL");
		}

		if (selection==MAZEALGORTIHM) {
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS);
			printf ("MAZE ALGORITHM");
			changeColor(MENUA);
			positionCursor(SECOND,BOTTOMOPTIONS+2);
			if (settings->mazeAlgorithm==PRIM)
				printf ("PRIM");
			else if (settings->mazeAlgorithm==BACKTRACK)
				printf ("BACKTRACK");
			else
				printf ("BINARY");
		}
		else {
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS);
			printf ("MAZE ALGORITHM");
			changeColor(MENUC);
			positionCursor(SECOND,BOTTOMOPTIONS+2);
			if (settings->mazeAlgorithm==PRIM)
				printf ("PRIM");
			else if (settings->mazeAlgorithm==BACKTRACK)
				printf ("BACKTRACK");
			else
				printf ("BINARY");
		}

		if (selection==BOTNUMBER) {
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

		if (selection==BOTDIFFICULTY) {
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

		if (selection==CHARACTER) {
			changeColor(MENUC);
			positionCursor(FOURTH,TOPOPTIONS);
			printf ("CHARACTER");
			changeColor(MENUA);
			positionCursor(FOURTH,TOPOPTIONS+2);
			if (settings->character==LAZY)
				printf ("LAZY");
			else
				printf ("DAZY");
		}
		else {
			changeColor(MENUC);
			positionCursor(FOURTH,TOPOPTIONS);
			printf ("CHARACTER");
			changeColor(MENUC);
			positionCursor(FOURTH,TOPOPTIONS+2);
			if (settings->character==LAZY)
				printf ("LAZY");
			else
				printf ("DAZY");
		}

		if (selection==FILTERENDS) {
			changeColor(MENUC);
			positionCursor(FOURTH,BOTTOMOPTIONS);
			printf ("FILTER DEAD ENDS");
			changeColor(MENUA);
			positionCursor(FOURTH,BOTTOMOPTIONS+2);
			if (settings->filterEnds==YES)
				printf ("YES");
			else
				printf ("NO");
		}
		else {
			changeColor(MENUC);
			positionCursor(FOURTH,BOTTOMOPTIONS);
			printf ("FILTER DEAD ENDS");
			changeColor(MENUC);
			positionCursor(FOURTH,BOTTOMOPTIONS+2);
			if (settings->filterEnds==YES)
				printf ("YES");
			else
				printf ("NO");
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
			case LEFT:	 if (selection/10 == 1) selection+=30; 
						 else selection-=10;
						 break;
			case RIGHT:	 if (selection/10 == 4) selection-=30; 
						 else selection+=10;
						 break;
			case ENTER:	 switch (selection) {
							case LEVELSIZE: 
								while (1) {
									if (settings->levelSize==SMALL) {
										changeColor(MENUA);positionCursor(FIRST+1,TOPOPTIONS+3);printf ("    SMALL     ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FIRST+1,TOPOPTIONS+3);printf ("    SMALL     ");
									}

									if (settings->levelSize==MEDIUM) {
										changeColor(MENUA);positionCursor(FIRST+1,TOPOPTIONS+4);printf ("    MEDIUM    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FIRST+1,TOPOPTIONS+4);printf ("    MEDIUM    ");
									}

									if (settings->levelSize==LARGE) {
										changeColor(MENUA);positionCursor(FIRST+1,TOPOPTIONS+5);printf ("    LARGE     ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FIRST+1,TOPOPTIONS+5);printf ("    LARGE     ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->levelSize==SMALL) settings->levelSize=LARGE; else settings->levelSize--; break;
										case DOWN:	if (settings->levelSize==LARGE) settings->levelSize=SMALL; else settings->levelSize++; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(FIRST,i);changeColor(MENUC);printf ("                   ");
								}
								break;

							case WALLCOLOR:
								while (1) {
									if (settings->wallColor==LIGHT) {
										changeColor(MENUA);positionCursor(FIRST+1,BOTTOMOPTIONS+3);printf ("    LIGHT    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FIRST+1,BOTTOMOPTIONS+3);printf ("    LIGHT    ");
									}

									if (settings->wallColor==DARK) {
										changeColor(MENUA);positionCursor(FIRST+1,BOTTOMOPTIONS+4);printf ("    DARK     ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FIRST+1,BOTTOMOPTIONS+4);printf ("    DARK     ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->wallColor==LIGHT) settings->wallColor=DARK; else settings->wallColor=LIGHT; break;
										case DOWN:	if (settings->wallColor==DARK) settings->wallColor=LIGHT; else settings->wallColor=DARK; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(FIRST,i);changeColor(MENUC);printf ("                   ");
								}
								break;								

							case PLAYMETOD: 
								while (1) {
									if (settings->playMetod==REALTIME) {
										changeColor(MENUA);positionCursor(SECOND+1,TOPOPTIONS+3);printf ("    REAL TIME    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(SECOND+1,TOPOPTIONS+3);printf ("    REAL TIME    ");
									}

									if (settings->playMetod==POSITIONAL) {
										changeColor(MENUA);positionCursor(SECOND+1,TOPOPTIONS+4);printf ("    POSITIONAL   ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(SECOND+1,TOPOPTIONS+4);printf ("    POSITIONAL   ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->playMetod==REALTIME) settings->playMetod=POSITIONAL; else settings->playMetod=REALTIME; break;
										case DOWN:	if (settings->playMetod==POSITIONAL) settings->playMetod=REALTIME; else settings->playMetod=POSITIONAL; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(SECOND,i);changeColor(MENUC);printf ("                   ");
								}
								break;

							case MAZEALGORTIHM: 
								while (1) {
									if (settings->mazeAlgorithm==PRIM) {
										changeColor(MENUA);positionCursor(SECOND+1,BOTTOMOPTIONS+3);printf ("       PRIM      ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(SECOND+1,BOTTOMOPTIONS+3);printf ("       PRIM      ");
									}

									if (settings->mazeAlgorithm==BACKTRACK) {
										changeColor(MENUA);positionCursor(SECOND+1,BOTTOMOPTIONS+4);printf ("    BACKTRACK    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(SECOND+1,BOTTOMOPTIONS+4);printf ("    BACKTRACK    ");
									}

									if (settings->mazeAlgorithm==BINARY) {
										changeColor(MENUA);positionCursor(SECOND+1,BOTTOMOPTIONS+5);printf ("      BINARY     ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(SECOND+1,BOTTOMOPTIONS+5);printf ("      BINARY     ");
									}



									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->mazeAlgorithm==PRIM) settings->mazeAlgorithm=BINARY; else settings->mazeAlgorithm--; break;
										case DOWN:	if (settings->mazeAlgorithm==BINARY) settings->mazeAlgorithm=PRIM; else settings->mazeAlgorithm++; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(SECOND,i);changeColor(MENUC);printf ("                   ");
								}
								break;

							case BOTNUMBER:
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

							case BOTDIFFICULTY: 
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

							case CHARACTER:
								while (1) {
									if (settings->character==LAZY) {
										changeColor(MENUA);positionCursor(FOURTH+1,TOPOPTIONS+3);printf ("    LAZY    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FOURTH+1,TOPOPTIONS+3);printf ("    LAZY    ");
									}

									if (settings->character==DAZY) {
										changeColor(MENUA);positionCursor(FOURTH+1,TOPOPTIONS+4);printf ("    DAZY    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FOURTH+1,TOPOPTIONS+4);printf ("    DAZY    ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->character==LAZY) settings->character=DAZY; else settings->character=LAZY; break;
										case DOWN:	if (settings->character==DAZY) settings->character=LAZY; else settings->character=DAZY; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(FOURTH,i);changeColor(MENUC);printf ("                   ");
								}
							break;

							case FILTERENDS:
								while (1) {
									if (settings->filterEnds==YES) {
										changeColor(MENUA);positionCursor(FOURTH+1,BOTTOMOPTIONS+3);printf ("    YES    ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FOURTH+1,BOTTOMOPTIONS+3);printf ("    YES    ");
									}

									if (settings->filterEnds==NO) {
										changeColor(MENUA);positionCursor(FOURTH+1,BOTTOMOPTIONS+4);printf ("    NO     ");
									}
									else {
										changeColor(DROPUNACTIVE);positionCursor(FOURTH+1,BOTTOMOPTIONS+4);printf ("    NO     ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (settings->filterEnds==NO) settings->filterEnds=YES; else settings->filterEnds=NO; break;
										case DOWN:	if (settings->filterEnds==YES) settings->filterEnds=NO; else settings->filterEnds=YES; break;
									}								
								}

								for (i=TOP+1;i<BOTTOM-1;i++) {
									positionCursor(FOURTH,i);changeColor(MENUC);printf ("                   ");
								}
							break;

						 } break; //break enter
		}


	}
}