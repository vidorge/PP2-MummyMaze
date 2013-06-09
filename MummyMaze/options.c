#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"
#include "options.h"

void options () {
	int i, choice, selection=11, subselection=1;

	backgroundImage(TEXT);

	while(1) {
		
		if (selection==11) {                //11
			changeColor(MENUC);
			positionCursor(FIRST,TOP);
			printf ("LEVEL SIZE");
			changeColor(MENUA);
			positionCursor(FIRST,TOP+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,TOP);
			printf ("LEVEL SIZE");
			changeColor(MENUC);
			positionCursor(FIRST,TOP+2);
			printf ("K");
		}

		if (selection==12) {                //12
			changeColor(MENUC);
			positionCursor(FIRST,BOTOM);
			printf ("WALL COLOR");
			changeColor(MENUA);
			positionCursor(FIRST,BOTOM+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(FIRST,BOTOM);
			printf ("WALL COLOR");
			changeColor(MENUC);
			positionCursor(FIRST,BOTOM+2);
			printf ("K");
		}

		if (selection==21) {                //21
			changeColor(MENUC);
			positionCursor(SECOND,TOP);
			printf ("PLAYER");
			changeColor(MENUA);
			positionCursor(SECOND,TOP+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(SECOND,TOP);
			printf ("PLAYER");
			changeColor(MENUC);
			positionCursor(SECOND,TOP+2);
			printf ("K");
		}

		if (selection==31) {                //31
			changeColor(MENUC);
			positionCursor(THIRD,TOP);
			printf ("BOT ALGORITHM");
			changeColor(MENUA);
			positionCursor(THIRD,TOP+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(THIRD,TOP);
			printf ("BOT ALGORITHM");
			changeColor(MENUC);
			positionCursor(THIRD,TOP+2);
			printf ("K");
		}

		if (selection==32) {                //32
			changeColor(MENUC);
			positionCursor(THIRD,BOTOM);
			printf ("BOT DIFFICULTY");
			changeColor(MENUA);
			positionCursor(THIRD,BOTOM+2);
			printf ("K");
		}
		else {
			changeColor(MENUC);
			positionCursor(THIRD,BOTOM);
			printf ("BOT DIFFICULTY");
			changeColor(MENUC);
			positionCursor(THIRD,BOTOM+2);
			printf ("K");
		}
		
		choice=controls(_getch());
		if ((choice==EXIT)||(choice==PAUSE)) break;

		switch (choice)	{
			case UP:	 if ((selection==12)||(selection==32)) selection--; 
						 else if (selection==11) selection=12; 
						 else if (selection==21) selection=21;
						 else selection=32; 
						 break;
			case DOWN:	 if ((selection==11)||(selection==31)) selection++; 
						 else if (selection==12) selection=11;
						 else if (selection==21) selection=21;
						 else selection=31; 
						 break;
			case LEFT:	 if (selection==11) selection=31; 
						 else if (selection==12) selection=32;
						 else if ((selection==31)||(selection==32)) selection=21;
						 else selection-=10;
						 break;
			case RIGHT:	 if (selection==31) selection=11; 
						 else if (selection==32) selection=12;
						 else if ((selection==11)||(selection==12)) selection=21;
						 else selection+=10;
						 break;
			case ENTER:	 switch (selection) {
							case 11: 
								while (1) {
									if (subselection==1) {
										changeColor(MENUA);positionCursor(FIRST+1,TOP+3);printf ("    a    ");
									}
									else {
										changeColor(126);positionCursor(FIRST+1,TOP+3);printf ("    a    ");
									}

									if (subselection==2) {
										changeColor(MENUA);positionCursor(FIRST+1,TOP+4);printf ("    b    ");
									}
									else {
										changeColor(126);positionCursor(FIRST+1,TOP+4);printf ("    b    ");
									}

									if (subselection==3) {
										changeColor(MENUA);positionCursor(FIRST+1,TOP+5);printf ("    c    ");
									}
									else {
										changeColor(126);positionCursor(FIRST+1,TOP+5);printf ("    c    ");
									}

									choice=controls(_getch());
									
									if (choice==ENTER) break;
									switch (choice) {
										case UP:	if (subselection>1) subselection--; else subselection=3; break;
										case DOWN:	if (subselection<3) subselection++; else subselection=1; break;
									}								
								}
								for (i=TOP+1;i<BOTOM-1;i++) {
									positionCursor(FIRST,i);changeColor(MENUC);printf ("                   ");
								}							
							break;

							case 12: break;

							case 21: break;

							case 31: break;

							case 32: break;

						 } break;
		}


	}
}