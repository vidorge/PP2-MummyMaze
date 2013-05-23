#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"
#include "about.h"

void about () {

	int i, input;

	int status=TRUE, change=0;

	backgroundImage (0);

	//***************************
	//****   HEADING   **********
	//***************************

	positionCursor(43,11);
	printf ("           ____   ____  _    _ _______  ");
	positionCursor(43,12);
	printf ("     /\\   |  _ \\ / __ \\| |  | |__   __| ");
	positionCursor(43,13);
	printf ("    /  \\  | |_) | |  | | |  | |  | |    ");
	positionCursor(43,14);
	printf ("   / /\\ \\ |  _ <| |  | | |  | |  | |    ");
	positionCursor(43,15);
	printf ("  / ____ \\| |_) | |__| | |__| |  | |    ");
	positionCursor(43,16);
	printf (" /_/    \\_\\____/ \\____/ \\____/   |_|    ");
	positionCursor(43,17);
	printf ("                                        ");

	for (i=93;i>19 && status;Sleep(700),i--) {
			if(_kbhit()) { 
						status=FALSE;
						continue;
			}
			if (((i-45)>18)&&((i-45)<47))	{ positionCursor (CENTER,i-45);	printf ("            A long time ago		   "); }
			if (((i-44)>18)&&((i-44)<47))	{ positionCursor (CENTER,i-44);	printf ("      in a galaxy far, far away	   "); }
			if (((i-43)>18)&&((i-43)<47))	{ positionCursor (CENTER,i-43);	printf ("  It is a period of civil war. Rebel  "); }
			if (((i-42)>18)&&((i-42)<47))	{ positionCursor (CENTER,i-42);	printf ("                   .                  "); }
			if (((i-41)>18)&&((i-41)<47))	{ positionCursor (CENTER,i-41);	printf ("                   .                  "); }
			if (((i-40)>18)&&((i-40)<47))	{ positionCursor (CENTER,i-40);	printf ("                   .                  "); }
			if (((i-39)>18)&&((i-39)<47))	{ positionCursor (CENTER,i-39);	printf ("              Oh, .. Wait..		   "); }
			if (((i-38)>18)&&((i-38)<47))	{ positionCursor (CENTER,i-38);	printf ("      ..that's from another movie	   "); }
			if (((i-37)>18)&&((i-37)<47))	{ positionCursor (CENTER,i-37);	printf ("                   .                  "); }
			if (((i-36)>18)&&((i-36)<47))	{ positionCursor (CENTER,i-36);	printf ("                   .                  "); }
			if (((i-35)>18)&&((i-35)<47))	{ positionCursor (CENTER,i-35);	printf ("                   .                  "); }
			if (((i-34)>18)&&((i-34)<47))	{ positionCursor (CENTER,i-34);	printf ("        and this is not a movie ,     "); }
			if (((i-33)>18)&&((i-33)<47))	{ positionCursor (CENTER,i-33);	printf ("             this is a game           "); }
			if (((i-32)>18)&&((i-32)<47))	{ positionCursor (CENTER,i-32);	printf ("       actually an awsome game        "); }
			if (((i-31)>18)&&((i-31)<47))	{ positionCursor (CENTER,i-31);	printf ("           as you may see ..          "); }
			if (((i-30)>18)&&((i-30)<47))	{ positionCursor (CENTER,i-30);	printf ("    This game was created as actual   "); }
			if (((i-29)>18)&&((i-29)<47))	{ positionCursor (CENTER,i-29);	printf ("      project by three awsome guys,   "); }
			if (((i-28)>18)&&((i-28)<47))	{ positionCursor (CENTER,i-28);	printf (" students of Electrotechnical Faculty "); }
			if (((i-27)>18)&&((i-27)<47))	{ positionCursor (CENTER,i-27);	printf ("   in Belgrade and their names are:   "); }
			if (((i-26)>18)&&((i-26)<47))	{ positionCursor (CENTER,i-26);	printf ("      jedi warrior Vidor Gencel ,     "); }
			if (((i-25)>18)&&((i-25)<47))	{ positionCursor (CENTER,i-25);	printf ("     the master mind of this whole    "); }
			if (((i-24)>18)&&((i-24)<47))	{ positionCursor (CENTER,i-24);	printf ("      operation .. thanks to him      "); }
			if (((i-23)>18)&&((i-23)<47))	{ positionCursor (CENTER,i-23);	printf ("    we got the opportunity to have    "); }
			if (((i-22)>18)&&((i-22)<47))	{ positionCursor (CENTER,i-22);	printf ("    fun working on this project ..    "); }
			if (((i-21)>18)&&((i-21)<47))	{ positionCursor (CENTER,i-21);	printf ("so in my name and in name of my fellow"); }
			if (((i-20)>18)&&((i-20)<47))	{ positionCursor (CENTER,i-20);	printf ("     jedi student Ivan Dimitrov       "); }
			if (((i-19)>18)&&((i-19)<47))	{ positionCursor (CENTER,i-19);	printf ("            THANKS VIDOR!!!           "); }
			if (((i-18)>18)&&((i-18)<47))	{ positionCursor (CENTER,i-18);	printf ("         next as you read Ivan        "); }
			if (((i-17)>18)&&((i-17)<47))	{ positionCursor (CENTER,i-17);	printf ("   was very important  in making of   "); }
			if (((i-16)>18)&&((i-16)<47))	{ positionCursor (CENTER,i-16);	printf ("    this game and in giving mummys    "); }
			if (((i-15)>18)&&((i-15)<47))	{ positionCursor (CENTER,i-15);	printf ("    all of their brains if you know   "); }
			if (((i-14)>18)&&((i-14)<47))	{ positionCursor (CENTER,i-14);	printf ("       what i mean... and lastly      "); }
			if (((i-13)>18)&&((i-13)<47))	{ positionCursor (CENTER,i-13);	printf (" me, myself and I .. Stefan Ilijevski "); }
			if (((i-12)>18)&&((i-12)<47))	{ positionCursor (CENTER,i-12);	printf ("  was responsible for all this retro  "); }
			if (((i-11)>18)&&((i-11)<47))	{ positionCursor (CENTER,i-11);	printf ("  look and feel that you see on your  "); }
			if (((i-10)>18)&&((i-10)<47))	{ positionCursor (CENTER,i-10);	printf ("    screen ... and finally i would    "); }
			if (((i-9)>18)&&((i-9)<47))		{ positionCursor (CENTER,i-9);	printf ("    like to thanks our Jedi masters   "); }
			if (((i-8)>18)&&((i-8)<47))		{ positionCursor (CENTER,i-8);	printf ("    Marko Misic and his aprentice     "); }
			if (((i-7)>18)&&((i-7)<47))		{ positionCursor (CENTER,i-7);	printf ("         Nikola Milutinovic...        "); }
			if (((i-6)>18)&&((i-6)<47))		{ positionCursor (CENTER,i-6);	printf ("                   .                  "); }
			if (((i-5)>18)&&((i-5)<47))		{ positionCursor (CENTER,i-5);	printf ("                   .                  "); }
			if (((i-4)>18)&&((i-4)<47))		{ positionCursor (CENTER,i-4);	printf ("                   .                  "); }
			if (((i-3)>18)&&((i-3)<47))		{ positionCursor (CENTER,i-3);	printf ("               Keep Calm              "); }
			if (((i-2)>18)&&((i-2)<47))		{ positionCursor (CENTER,i-2);	printf ("    and may the Force Be With You     "); }
			if (((i-1)>18)&&((i-1)<47))		{ positionCursor (CENTER,i-1);	printf ("                  ...                 "); }
			if (((i)>18)&&((i)<47))			{ positionCursor (CENTER,i);	printf ("      ETF 2013   GIT COMMIT TEAM      "); }
			if (((i+1)>18)&&((i+1)<47))		{ positionCursor (CENTER,i+1);	printf ("                                      "); }
	}
	
	_getch();

}