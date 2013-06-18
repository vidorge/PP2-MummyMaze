#ifndef _maze_create_h
#define _maze_create_h

#include "options.h"

#define UP_WALL		1 //0001
#define DOWN_WALL	2 //0010
#define LEFT_WALL	4 //0100
#define RIGHT_WALL	8 //1000
#define IN_MAZE		16

#define WALL 1
#define PATH 0

typedef struct
{
	int x;
	int y;

} dimension_t;

typedef struct CoordList
{
	int i, j;
	struct CoordList *next;

}	coordList_t;

/**
*	@desc	Initialize a matrix
*	@param	int dimension - dimension of matrix
*	@return	int ** - double pointer to matrix
*	@author Vidor Gencel
*/
int **initMatrix(dimension_t dimension);

/**
*	@desc	Fills matrix used in help
*	@param	int **matrix - double pointer to matrix
*	@param	int dimension - dimension of matrix	
*	@author Stefan Ilijevski
*/
void fillHelpMatrix(int **matrix, dimension_t dimension);

//mrzelo me majke mi

void ShuffleArray(int *randDir);

void MazeDestroy(int **a, dimension_t dimension);

int ** GenerateMinMatrix(dimension_t dimension);

void Prim(int **a, dimension_t dimension, settings_t settings);

int SetExit(int **a, dimension_t dimension);

int SetEntrance(int **a, dimension_t dimension);

void RecursiveBacktrack(int **a, dimension_t dimension, settings_t settings);

void BinaryTreeMaze(int **a, dimension_t dimension, settings_t settings);

void ConvertFromMin(int **minMatrix, int **a, dimension_t dimension);

void FilterDeadEnds(int **a, dimension_t dimension);


#endif