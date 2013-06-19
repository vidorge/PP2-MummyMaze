#include "score_entry.h"

void scoreEntry(settings_t settings, float score) {
	FILE* output;
	highscore_t *player, *highscores;
	int i;

	output = fopen ("highscore.bin","wb+");

	for (i=15;i<25;i++) {
		positionCursor (50,i);
		if (settings.wallColor==LIGHT)
			changeColor (LIGHTBLANK);
		else 
			changeColor (DARKBLANK);
		printf ("                                                 ");
	}

	positionCursor (67,16);
	if (settings.wallColor==LIGHT)
			changeColor (LIGHTDAZY);
		else 
			changeColor (DARKDAZY);
	printf ("HIGHSCORE ENTRY");

	positionCursor (52,18);
	printf ("Your highscore:  ");
	printf ("%.2f",score);

	positionCursor (52,20);
	printf ("Enter your name:  ");
	scanf ("%s");

	


	system ("pause");

	/*highscores = readFromFile (output);
	
	//UCITAVANJE PLAYERA;

	player=malloc (sizeof(highscore_t));
	player->name = "sdjo ";
	player->score= 60.3;

	createScoreElem (player->score,player->name,highscores);

	printInFile (highscores,output);

	fclose (output);*/

}