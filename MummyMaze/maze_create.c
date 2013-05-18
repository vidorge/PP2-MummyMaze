#include <stdio.h>
#include <stdlib.h>

#include "maze_create.h"


int **initMatrix(dimension_t dimension)
{
	int **a, i, j;

	a = (int**) malloc( dimension.y * sizeof(int*) );

	for (i=0; i<dimension.y; i++)
	{
		a[i] = (int*) malloc( dimension.x * sizeof(int) );
		for (j=0; j<dimension.x; j++)
			a[i][j] = 1;
	}

	return a;

}


void DfsInit(int **a, dimension_t dimension)
{

	int c, r;

	r = dimension.y / 2; //this must be more random for dense matrix
	c = dimension.y / 2;

	a[r][c] = 0;

	dfs(a, r, c, dimension);

}

void ShuffleArray(int *randDir)
{
	int i, j, temp;

	for(i=0; i<4; i++)
	{
		j = rand() % 4;

		temp = randDir[i];
		randDir[i] = randDir[j];
		randDir[j] = temp;
	}

}

void dfs(int **a, int r, int c, dimension_t dimension)
{
	int randDir[] = {1, 2, 3, 4};
	int i;

	ShuffleArray(randDir);

	for (i = 0; i < 4; i++) {
 
         switch(randDir[i]){
         case 1: // Up
             if (r - 2 <= 0) continue;
             if (a[r - 2][c] != 0) {
                 a[r-2][c] = 0;
                 a[r-1][c] = 0;
                 dfs(a, r - 2, c, dimension);
             }
             break;

         case 2: // Right
             if (c + 2 >= dimension.x - 1) continue;
             if (a[r][c + 2] != 0) {
                 a[r][c + 2] = 0;
                 a[r][c + 1] = 0;
                 dfs(a, r, c + 2, dimension);
             }
             break;

         case 3: // Down
             if (r + 2 >= dimension.y - 1)  continue;
             if (a[r + 2][c] != 0) {
                 a[r+2][c] = 0;
                 a[r+1][c] = 0;
                 dfs(a, r + 2, c, dimension);
             }
             break;

         case 4: // Left
             if (c - 2 <= 0) continue;
             if (a[r][c - 2] != 0) {
                 a[r][c - 2] = 0;
                 a[r][c - 1] = 0;
                 dfs(a, r, c - 2, dimension);
             }
             break;

         }
     }

}


void printDebugMatrix(int **matrix, dimension_t dimension)
{
	int i, j;

	for (i=0; i<dimension.y; i++, printf("\n") )
		for (j=0; j<dimension.x; j++)
			printf("%d", matrix[i][j]);

}

void RemoveRandomWalls(int **a, dimension_t dimension, int probability)
{
	int i, j;

	for(i=1; i< dimension.y - 1; i++)
	{
		for(j=1; j < dimension.x - 1; j++)
		{
			if( !a[i][j] ) continue;
			else
			{

				if( (rand() % probability) == 1 )
					a[i][j] = 0;

			}


		}


	}


}

/*
int hasUnvisitedNeighbour(int **matrix)
{



}
*/


void MazeDestroy(int **a, dimension_t dimension)
{
	int i;

	for(i=0; i<dimension.y; i++)
		free(a[i]);

	free(a);

}

void RemoveAloneWalls(int **a, dimension_t dimension)
{
	int i, j;

	for(i=1; i< dimension.y - 1; i++)
	{
		for(j=1; j < dimension.x - 1; j++)
		{
			if( !a[i][j] ) continue;
			else
			{

				if( a[i-1][j] == 0 && a[i+1][j] == 0 && a[i][j-1] == 0 && a[i][j+1] == 0 )
					a[i][j] = 0;

			}


		}


	}



}