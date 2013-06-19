#include "score_entry.h"

void scoreEntry(settings_t settings, float score) {
	FILE* output;
	highscore_t *player, *highscores;
	int i;

	output = fopen ("highscore.bin","wb+");
	highscores = readFromFile (output);
	player=malloc (sizeof(highscore_t));
	player->name = malloc (50*sizeof(char));


	for (i=15;i<25;i++) {
		positionCursor (50,i);
		if (settings.wallColor==LIGHT)
			changeColor (LISCBK);
		else 
			changeColor (DKSCBK);
		printf ("                                                 ");
	}

	positionCursor (67,16);
	if (settings.wallColor==LIGHT)
			changeColor (LISCTX);
		else 
			changeColor (DKSCTX);
	printf ("HIGHSCORE ENTRY");

	positionCursor (52,18);
	printf ("Your highscore:  ");
	printf ("%.2f",score);
	player->score=score;

	positionCursor (52,20);
	printf ("Enter your name:  ");
	scanf ("%s",player->name);

	
	createScoreElem (player->score,player->name,highscores);

	printInFile (highscores,output);

	fclose (output);

}