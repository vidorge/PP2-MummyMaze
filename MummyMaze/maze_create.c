#include <stdio.h>
#include <stdlib.h>

#include "maze_create.h"


int **initMatrix(int dimension)
{
	int **a, i, j;

	a = (int**) malloc( dimension * sizeof(int*) );

	for (i=0; i<dimension; i++)
	{
		a[i] = (int *) malloc( dimension * sizeof(int) );
		for (j=0; j<dimension; j++)
			a[i][j] = 0;
	}

	return a;

}


void printDebugMatrix(int **matrix, int dimension)
{
	int i, j;

	for (i=0; i<dimension; i++, printf("\n") )
		for (j=0; j<dimension; j++)
			printf("%d", matrix[i][j]);

}

/*
int hasUnvisitedNeighbour(int **matrix)
{



}
*/