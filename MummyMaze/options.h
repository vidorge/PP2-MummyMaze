#ifndef _options_h
#define _options_h

//ROWS
#define TOPOPTIONS		22
#define BOTTOMOPTIONS	33

//COLUMNS
#define FIRST	20
#define SECOND	60
#define THIRD	93

//OPTIONS
#define	LEVELSIZE		11
#define	WALLCOLOR		12
#define	CHARACTER		21
#define	MAZEALGORTIHM	22
#define BOTNUMBER		31
#define BOTDIFFICULTY	32

//BOT DIFFICULTY
#define EASY	1
#define HARD	2

//MAZE ALGORITHM
#define PRIM	1
#define DFS		2

//WALL COLORS
#define LIGHT	1
#define DARK	2


typedef struct settings_t {
	int levelSize;
	int wallColor;
	int character;
	int mazeAlgorithm;
	int botDifficuly;
	int botNumber;
}settings_t;

void options (settings_t *settings);

#endif