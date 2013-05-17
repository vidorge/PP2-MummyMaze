#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "maze_create.h"


int **initMatrix(int dimension)
{
	int **a, i, j, r, c;

	a = (int**) malloc( dimension * sizeof(int*) );

	for (i=0; i<dimension; i++)
	{
		a[i]  = malloc( dimension * sizeof(int) );
		for (j=0; j<dimension; j++)
			a[i][j] = 1;
	}

	return a;

}


void DfsInit(int **a, int dimension)
{

	int c, r;

	srand( (unsigned)time(NULL) );

	c = rand() % dimension;
	while( c % 2 == 0 )
		c = rand() % dimension;

	r = rand() % dimension;
	while( r % 2 == 0 )
		r = rand() % dimension;

	a[r][c] = 0;

	dfs(a, r, c, dimension);

}

void dfs(int **a, int r, int c, int dimension)
{
	int randDir[] = {1, 2, 3, 4};
	int i;


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
             if (c + 2 >= dimension - 1) continue;
             if (a[r][c + 2] != 0) {
                 a[r][c + 2] = 0;
                 a[r][c + 1] = 0;
                 dfs(a, r, c + 2, dimension);
             }
             break;

         case 3: // Down
             if (r + 2 >= dimension - 1)  continue;
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