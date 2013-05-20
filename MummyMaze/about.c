#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"

void about () {

	int input;

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

	while (status) {		
		switch (change) {
			case 0:		positionCursor (19,20); printf ("         A long time ago");
						positionCursor (19,21); printf ("    in a galaxy far, far away");
						positionCursor (19,22); printf ("It is a period of civil war. Rebel ");
						positionCursor (19,23); printf ("spaceships, striking from a hidden");
						positionCursor (19,24); printf ("base, have won their first victory ");
						positionCursor (19,25); printf ("against the evil Galactic Empire. ");

						if(_kbhit()) { 
							status=FALSE;
							continue;
						}
						Sleep (1000);
						change=1;
						break;

			case 1:		positionCursor (19,20); printf ("    in a galaxy far, far away");
						positionCursor (19,21); printf ("It is a period of civil war. Rebel ");
						positionCursor (19,22); printf ("spaceships, striking from a hidden");
						positionCursor (19,23); printf ("base, have won their first victory ");
						positionCursor (19,24); printf ("against the evil Galactic Empire. ");
						positionCursor (19,25); printf ("                                   ");

						if(_kbhit()) { 
							status=FALSE;
							continue;
						}
						Sleep (1000);
						change=2;	
						break;

			case 2:		positionCursor (19,20); printf ("It is a period of civil war. Rebel ");
						positionCursor (19,21); printf ("spaceships, striking from a hidden");
						positionCursor (19,22); printf ("base, have won their first victory ");
						positionCursor (19,23); printf ("against the evil Galactic Empire. ");
						positionCursor (19,24); printf ("                                   ");
						positionCursor (19,25); printf ("                                   ");

						if(_kbhit()) { 
							status=FALSE;
							continue;
						}
						Sleep (1000);
						change=3;	
						break;

			case 3:		positionCursor (19,20); printf ("spaceships, striking from a hidden");
						positionCursor (19,21); printf ("base, have won their first victory ");
						positionCursor (19,22); printf ("against the evil Galactic Empire. ");
						positionCursor (19,23); printf ("                                   ");
						positionCursor (19,24); printf ("                                   ");
						positionCursor (19,25); printf ("                                   ");

						if(_kbhit()) { 
							status=FALSE;
							continue;
						}

						break;

		}		
	}
}