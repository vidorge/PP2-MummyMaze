#include "score_entry.h"

void scoreEntry() {
	FILE* output;
	highscore_t *player;

	output = fopen ("highscore.bin","wb+");

	printf ("DJOKA");

	
	player=malloc (sizeof(highscore_t));
	player->name = "paja ";
	player->score= 60.6;

	fwrite(player,sizeof(highscore_t),1,output);

	fclose (output);

}