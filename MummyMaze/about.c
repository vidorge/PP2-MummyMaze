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

	for (i=49;i>18 && status;positionCursor (CENTER,19),printf ("                                  "),Sleep(250),i--) {
			if(_kbhit()) { 
						status=FALSE;
						continue;
			}
			if (((i-2)>18)&&((i-2)<47))  { positionCursor (CENTER,i-2);printf ("         A long time ago"); }
			if (((i-1)>18)&&((i-1)<47)) {positionCursor (CENTER,i-1);printf ("    in a galaxy far, far away"); }
			if (((i)>18)&&((i)<47)) {positionCursor (CENTER,i);printf (("It is a period of civil war. Rebel")); }
			if (((i+1)>18)&&((i+1)<47)) {positionCursor (CENTER,i+1);printf ("                                  "); }
	}		
}