#ifndef _maze_gui_h
#define _maze_gui_h

#define PLAYER		3
#define MUMMY		4
#define JEWEL		5

#define MAZECOLUMN	1
#define MAZEROW		1

#include "maze_create.h"

void printFormattedMatrix(int **matrix, dimension_t dimension);

void printMovement (int beforeRow, int beforeColumn, int afterRow, int afterColumn, int whatToPrint, int *wave);

void printHelpMatrix(int **matrix, dimension_t dimension);

#endif