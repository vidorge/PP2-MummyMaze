﻿#ifndef _maze_create_h
#define _maze_create_h

#define DIM 15

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
*	@desc	Prints debug-formated matrix 1/0
*	@param	int **matrix - double pointer to matrix
*	@param	int dimension - dimension of matrix
*	@author Vidor Gencel
*/
void printDebugMatrix(int **matrix, dimension_t dimension);


/**
*	@desc	See if a cell from game board has unvisited neighbours
*	@param	int **matrix - double pointer to game board matrix
*	@return	1 - has unvisited, 0 - doesn't
*	@author Vidor Gencel
*/
//int hasUnvisitedNeighbour(int **matrix);

/**
*	@desc	Fills matrix used in help
*	@param	int **matrix - double pointer to matrix
*	@param	int dimension - dimension of matrix	
*	@author Stefan Ilijevski
*	PS		Sorry, Dorvi for messing with your code
*/

void fillHelpMatrix(int **matrix, dimension_t dimension);

//mrzelo me majke mi


void ShuffleArray(int *randDir);

void MazeDestroy(int **a, dimension_t dimension);

int ** GenerateMinMatrix(dimension_t dimension);

void Prim(int **a, dimension_t dimension);

void CarveGateways(int **a, dimension_t dimension);

int SetExit(int **a, dimension_t dimension);

int SetEntrance(int **a, dimension_t dimension);

void RecursiveBacktrack(int **a, dimension_t dimension);

void BinaryTreeMaze(int **a, dimension_t dimension);

void ConvertFromMin(int **minMatrix, int **a, dimension_t dimension);

void FilterDeadEnds(int **a, dimension_t dimension);


/*
//RIP DFS 
void Dfs(int **a, int r, int c, dimension_t dimension);
void DfsInit(int **a, dimension_t dimension);
void RemoveRandomWalls(int **a, dimension_t dimension, int probability);
void RemoveAloneWalls(int **a, dimension_t dimension);
*/

#endif