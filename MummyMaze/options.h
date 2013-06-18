#ifndef _options_h
#define _options_h

//ROWS
#define TOPOPTIONS		22
#define BOTTOMOPTIONS	33

//COLUMNS
#define FIRST	31
#define SECOND	55
#define THIRD	81
#define FOURTH	101

//OPTIONS
#define	LEVELSIZE		11
#define	WALLCOLOR		12
#define	PLAYMETOD		21
#define	MAZEALGORTIHM	22
#define BOTNUMBER		31
#define BOTDIFFICULTY	32

//BOT DIFFICULTY
#define EASY	1
#define HARD	2

//MAZE ALGORITHM
#define PRIM	1
#define DFS		2
#define BACKTRACK 3
#define BINARY 4

//MAZE SIZE
#define	SMALL	1
#define MEDIUM	2
#define LARGE	3

//WALL COLORS
#define LIGHT	1
#define DARK	2

//PLAY METOD
#define REALTIME	1
#define POSITIONAL	2


typedef struct settings_t {
	int levelSize;
	int wallColor;
	int character;
	int mazeAlgorithm;
	int botDifficuly;
	int botNumber;
	int playMetod;
}settings_t;

void options (settings_t *settings);

#endif