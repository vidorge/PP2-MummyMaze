#ifndef _maze_create_h
#define _maze_create_h

#define DIM 15

/**
*	@desc	Initialize a matrix
*	@param	int dimension - dimension of matrix
*	@return	int ** - double pointer to matrix
*	@author Vidor Gencel
*/
int **initMatrix(int dimension);


/**
*	@desc	Prints debug-formated matrix 1/0
*	@param	int **matrix - double pointer to matrix
*	@param	int dimension - dimension of matrix
*	@author Vidor Gencel
*/
void printDebugMatrix(int **matrix, int dimension);


/**
*	@desc	See if a cell from game board has unvisited neighbours
*	@param	int **matrix - double pointer to game board matrix
*	@return	1 - has unvisited, 0 - doesn't
*	@author Vidor Gencel
*/
//int hasUnvisitedNeighbour(int **matrix);


//mrzelo me majke mi

void dfs(int **a, int r, int c, int dimension);


//int[] ShuffleArray(int randDir[]);


void DfsInit(int **a, int dimension);

#endif