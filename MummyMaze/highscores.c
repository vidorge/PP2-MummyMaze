#include "highscores.h"

void highscores () {
	FILE* list;
	highscore_t *highscores;
	int input, i=1;
	int row=25, columnTemp=19, column=19;

	backgroundImage (TEXT);

	positionCursor(43,11);
	printf ("  _    _ _____ _____ _    _    _____  _____ ____  _____  ______ \n");
	positionCursor(43,12);
	printf (" | |  | |_   _/ ____| |  | |  / ____|/ ____/ __ \\|  __ \\|  ____|\n");
	positionCursor(43,13);
	printf (" | |__| | | || |  __| |__| | | (___ | |   | |  | | |__) | |__   \n");
	positionCursor(43,14);
	printf (" |  __  | | || | |_ |  __  |  \\___ \\| |   | |  | |  _  /|  __|  \n");
	positionCursor(43,15);
	printf (" | |  | |_| || |__| | |  | |  ____) | |___| |__| | | \\ \\| |____ \n");
	positionCursor(43,16);
	printf (" |_|  |_|_____\\_____|_|  |_| |_____/ \\_____\\____/|_|  \\_\\______|\n");
	positionCursor(43,17);
	printf ("                                                                ");

	list = fopen ("highscore.bin","rb");
	highscores = readFromFile (list);

	while (1) {
		positionCursor (row,column+=4);
		printf("%d. %.2f %s", i++, highscores->score, highscores->name);
		

		if (column>38) {row+=60; column=columnTemp;}
		highscores=highscores->succ;
	}


	while (1) {
		input=controls(_getch());
		if ((input==PAUSE)||(input==EXIT)) break;
	}

}