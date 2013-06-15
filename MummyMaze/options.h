#ifndef _options_h
#define _options_h

#define TOP		22
#define BOTOM	33

#define FIRST	20
#define SECOND	60
#define THIRD	93

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