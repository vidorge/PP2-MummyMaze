#ifndef _maze_gui_h
#define _maze_gui_h

#define	BLANK		0
#define	WALL		1

#define PLAYER		3
#define MUMMY		4
#define HINT		5
#define ENTRANCE	6
#define EXIT		7
#define JEWEL		8

#define MAZECOLUMN	1
#define MAZEROW		1

#include <stdio.h>
#include <Windows.h>

#include "maze_create.h"
#include "maze_create.h"
#include "colors.h"
#include "position_cursor.h"
#include "options.h"
#include "screen_resolution.h"

void printFormattedMatrix(int **matrix, dimension_t dimension, settings_t settings);

void printMovement (int beforeRow, int beforeColumn, int afterRow, int afterColumn, int whatToPrint, int *wave, settings_t settings);

void printHelpMatrix(int **matrix, dimension_t dimension);

void LivePrint(int **matrix, dimension_t dimension);

void LiveChange(int **matrix, int row, int column);

#endif