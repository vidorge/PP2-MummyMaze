#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "maze_create.h"
#include "stack.h"
#include "maze_gui.h"


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

void fillHelpMatrix(int **matrix, dimension_t dimension)
{
	int i, j;

	for (i=2; i<dimension.y-2; i++)
		for (j=2; j<dimension.x-2; j++)
			matrix[i][j] = 0;

	for  (i=12;i<dimension.y-2;i++)	{ matrix[i][7]=1;	matrix[i][8]=1;	 }
	for  (i=2;i<8;i++)				{ matrix[i][13]=1;	matrix[i][14]=1; }
	for  (i=7;i<13;i++)				{ matrix[6][i]=1;	matrix[7][i]=1;	 }
	for  (i=15;i<dimension.x-2;i++)	{ matrix[12][i]=1;	matrix[13][i]=1; }
	for  (i=2;i<9;i++)				{ matrix[i][20]=1;	matrix[i][21]=1; }
	for  (i=5;i<9;i++)				{ matrix[i][27]=1;	matrix[i][28]=1; }
	for  (i=22;i<27;i++)			{ matrix[7][i]=1;	matrix[8][i]=1; }
	for  (i=5;i<9;i++)				{ matrix[i][27]=1;	matrix[i][28]=1; }

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

				if(
					a[i-1][j] == 0 && a[i+1][j] == 0 && a[i][j-1] == 0 && a[i][j+1] == 0 &&
					a[i-1][j-1] == 0 && a[i+1][j+1] == 0 && a[i-1][j+1] == 0 && a[i+1][j-1] == 0
					
					)
					a[i][j] = 0;



			}
		}
	}



}


/* OVDE POCINJE PRIM */

/*
1. Početi sa mrežom zidova,
2. Nasumično izabrati ćeliju, označiti je kao deo lavirnta i dodati sve njene zidove u listu zidova,
3. Dok ima zidova u listi:
	1) Slučajno izabrati zid iz liste. Ako ćelija sa suprotne strane nije u listi, onda:
		1. Napraviti od zida prolaz, i označiti ćeliju sa suprotne strane kao deo lavirinta,
		2. Dodati susedne zidove ćelije u listu zidova. 
*/


void PrimInit(int **a, dimension_t dimension)
{

	int c, r;
	lElem *head;

	head = NULL;

	r = dimension.y / 2; //this must be more random for dense matrix
	c = dimension.y / 2;

	a[r][c] = PATH;

	if ( a[r-1][c] == WALL ) { push(&head, r-1); push(&head, c); }
	if ( a[r+1][c] == WALL ) { push(&head, r+1); push(&head, c); }
	if ( a[r][c-1] == WALL ) { push(&head, r); push(&head, c-1); }
	if ( a[r][c+1] == WALL ) { push(&head, r); push(&head, c+1); }

	while ( !stackEmpty(head) )
	{

		c = pop(&head);
		r = pop(&head);

		a[r][c] = PATH;

		if ( a[r-1][c] == WALL ) { push(&head, r-1); push(&head, c); }
		if ( a[r+1][c] == WALL ) { push(&head, r+1); push(&head, c); }
		if ( a[r][c-1] == WALL ) { push(&head, r); push(&head, c-1); }
		if ( a[r][c+1] == WALL ) { push(&head, r); push(&head, c+1); }

		
		printDebugMatrix(a, dimension);
		printf("\n");

	}

	

}