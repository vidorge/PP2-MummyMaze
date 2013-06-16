#ifndef _options_h
#define _options_h

#define TOPOPTIONS		22
#define BOTTOMOPTIONS	33

#define FIRST	20
#define SECOND	60
#define THIRD	93

#define EASY	1
#define HARD	2

#define PRIM	1
#define DFS		2

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