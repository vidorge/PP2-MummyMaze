#ifndef _maze_create_h
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

void dfs(int **a, int r, int c, dimension_t dimension);


//int[] ShuffleArray(int randDir[]);


void DfsInit(int **a, dimension_t dimension);



void ShuffleArray(int *randDir);



void RemoveRandomWalls(int **a, dimension_t dimension, int probability);

void MazeDestroy(int **a, dimension_t dimension);

void RemoveAloneWalls(int **a, dimension_t dimension);

void PrimInit(int **a, dimension_t dimension);

int ** GeneratePrimMatrix(dimension_t dimension);


void Prim(int **a, dimension_t dimension);

#endif