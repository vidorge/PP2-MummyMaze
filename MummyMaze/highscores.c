#include "highscores.h"

void highscores () {
	FILE *list,*list1;
	highscore_t *highscores, *highscores1;
	int input, i=1;
	int row=25, rowTemp=row+55, columnTemp=22, column=22;

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

	positionCursor (35,19);
	printf ("REAL TIME");
	positionCursor (100,19);
	printf ("POSITIONAL");

	list = fopen ("highscore.bin","rb");
	highscores = readFromFile (list);
	list1 = fopen ("highscore.bin","rb");
	highscores1 = readFromFile (list1);

	while (1) {
		if((highscores==null)||(highscores1==null)) break;
		positionCursor (row,column);
		printf ("%d. %.2f %s | ", i, highscores->score, highscores->name);
		printf(ctime(&(highscores->date)));
		
		positionCursor (rowTemp,column);
		column+=2;
		printf ("%d. %.2f %s | ", i++, highscores1->score, highscores1->name);
		printf(ctime(&(highscores->date)));
		

		highscores=highscores->succ;
		highscores1=highscores1->succ;
		
	}
	dealocateList(highscores);
	fclose(list);
	fclose(list1);

	while (1) {
		input=controls(_getch());
		if ((input==PAUSE)||(input==EXIT)) break;
	}

}