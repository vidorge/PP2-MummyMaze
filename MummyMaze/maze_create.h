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
*	@param	dimension_t dimension - dimension of matrix
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


/**
*	@desc	Shuffle 4 element array
*	@param	int *randDir - pointer to 4 element array
*	@author Vidor Gencel
*/
void ShuffleArray(int *randDir);

/**
*	@desc	Deallocate matrix
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void MazeDestroy(int **a, dimension_t dimension);


/**
*	@desc	Generate minimized matrix
*	@param	dimension_t dimension - dimension of matrix
*	@return	int ** - double pointer to minimized matrix
*	@author Vidor Gencel
*/
int ** GenerateMinMatrix(dimension_t dimension);

/**
*	@desc	Prim maze generation
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void Prim(int **a, dimension_t dimension, settings_t settings);

/**
*	@desc	sets exit of maze
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@return exit row id
*	@author Vidor Gencel
*/
int SetExit(int **a, dimension_t dimension);

/**
*	@desc	sets entrance of maze
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@return entrance row id
*	@author Vidor Gencel
*/
int SetEntrance(int **a, dimension_t dimension);

/**
*	@desc	DFS maze generation
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void RecursiveBacktrack(int **a, dimension_t dimension, settings_t settings);

/**
*	@desc	Binary maze generation
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void BinaryTreeMaze(int **a, dimension_t dimension, settings_t settings);

/**
*	@desc	Converts minimized matrix to normal representation
*	@param	int **minMatrix - minimized matrix
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void ConvertFromMin(int **minMatrix, int **a, dimension_t dimension);

/**
*	@desc	Iterates through maze and removes some dead ends
*	@param	int **a - matrix
*	@param	dimension_t dimension - dimension of matrix
*	@author Vidor Gencel
*/
void FilterDeadEnds(int **a, dimension_t dimension);


#endif