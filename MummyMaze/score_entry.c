#include "score_entry.h"

void scoreEntry() {
	FILE* output;
	highscore_t *player, *highscores;

	output = fopen ("highscore.bin","wb+");

	printf ("INTERFEJS");

	highscores = readFromFile (output);
	
	//UCITAVANJE PLAYERA;

	player=malloc (sizeof(highscore_t));
	player->name = "sdjo ";
	player->score= 60.3;

	createScoreElem (player->score,player->name,highscores);

	printInFile (highscores,output);

	fclose (output);

}