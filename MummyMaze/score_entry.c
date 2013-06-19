#include "score_entry.h"
#include <time.h>

void scoreEntry(settings_t settings, float score) {
	FILE* output;
	
	highscore_t *player, *highscores=null;
	int i;

	output = fopen ("highscore.bin","rb+");
	highscores = readFromFile (output);
	player=malloc (sizeof(highscore_t));

	


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

	
	highscores=createScoreElem (player->score,player->name,time(null),highscores);

	printInFile (highscores,output);

	fclose (output);

}
void scoreEntry2(settings_t settings, float score)
{
	FILE* output;
	
	highscore_t *player, *highscores=null;
	int i;

	output = fopen ("highscore1.bin","rb+");
	highscores = readFromFile (output);
	player=malloc (sizeof(highscore_t));

	


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

	
	highscores=createScoreElem2 (player->score,player->name,time(null),highscores);

	printInFile (highscores,output);

	fclose (output);
}