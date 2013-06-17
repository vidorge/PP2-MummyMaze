﻿#include <stdio.h>
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

	Dfs(a, r, c, dimension);

	RemoveRandomWalls(a, dimension, 4);
	RemoveAloneWalls(a, dimension);

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

void Dfs(int **a, int r, int c, dimension_t dimension)
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
                 Dfs(a, r - 2, c, dimension);
             }
             break;

         case 2: // Right
             if (c + 2 >= dimension.x - 1) continue;
             if (a[r][c + 2] != 0) {
                 a[r][c + 2] = 0;
                 a[r][c + 1] = 0;
                 Dfs(a, r, c + 2, dimension);
             }
             break;

         case 3: // Down
             if (r + 2 >= dimension.y - 1)  continue;
             if (a[r + 2][c] != 0) {
                 a[r+2][c] = 0;
                 a[r+1][c] = 0;
                 Dfs(a, r + 2, c, dimension);
             }
             break;

         case 4: // Left
             if (c - 2 <= 0) continue;
             if (a[r][c - 2] != 0) {
                 a[r][c - 2] = 0;
                 a[r][c - 1] = 0;
                 Dfs(a, r, c - 2, dimension);
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


void MazeDestroy(int **a, dimension_t dimension)
{
	int i;

	for(i=0; i<dimension.y; i++)
		free(a[i]);

	free(a);

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


int ** GeneratePrimMatrix(dimension_t dimension)
{

	int **a;
	int w, h, i, j;

	w = dimension.x / 2;
	h = dimension.x / 2;

	a = (int**) malloc( h * sizeof(int*) );
	for (i=0; i<h; i++)
	{
		a[i] = (int*) malloc( w * sizeof(int) );

		for (j=0; j<w; j++)
			a[i][j] = 0 | UP_WALL | DOWN_WALL | LEFT_WALL | RIGHT_WALL;

	}
		
	return a;

}


void InsertElement(coordList_t **rear, int x, int y)
{

		coordList_t *element;

		element = (coordList_t*) malloc( sizeof( coordList_t ) );

		element->i = y;
		element->j = x;
	
		if ( *rear == NULL )
			element->next = element;
		else {
			element->next = (*rear)->next;
			(*rear)->next = element;
		}

		*rear = element;

}

int FindInList(coordList_t *rear, int x, int y)
{

	int found = 0;
	coordList_t *current;

	current = rear; found = 0;

	if ( rear )
		do {
			if ( current->i == y  && current->j == x )  return 1;
			current = current->next;
		} while ( current->next != rear );

	return 0;

}

void Prim(int **a, dimension_t dimension)
{

	int w, h, x, y, i, j;
	int **primMatrix, count = 0;
	int randDir[] = {1, 2, 3, 4};
	int done = 0, randNum = 0;

	coordList_t *rear, *element;

	rear = NULL; element = NULL;

	primMatrix = GeneratePrimMatrix(dimension);

	w = dimension.x / 2;
	h = dimension.y / 2;

	x = w / 2; y = h / 2;

	primMatrix[y][x] |= IN_MAZE;


	InsertElement(&rear, x, y);
	//printf("\n Dodato  %d %d", x, y);


	while ( rear != NULL )
	{
		//delete
		count = rand() % 42; // if you ask why, you sir, aren't a geek!
		i = 0;
		while ( i < count )
		{
			rear = rear->next;
			i++;
		}
		
		element = rear->next;
		rear->next = element->next;
		x = element->j;
		y = element->i;
		if ( rear == element ) rear = NULL;
		free(element);

		//printf("\n Obrisano  %d %d", x, y);


		//delete

		primMatrix[y][x] |= IN_MAZE;

		// ako ima komsije koji su deo lavirinta odaberi jedan od komsija i probij put

		ShuffleArray(randDir);

		for ( i = 0, done = 0; i < 4; i++ )
		{

			switch ( randDir[i] )
			{

			case 1:
				if ( y - 1 >= 0 && (primMatrix[y-1][x] & IN_MAZE) )
				{// up
					primMatrix[y-1][x] &= ~DOWN_WALL;
					primMatrix[y][x] &= ~UP_WALL;
					done = 1;
					//printf("\n Probijen zid na gore  %d %d", x, y-1);
				}
				break;

			case 2:
				if ( y + 1 < h && (primMatrix[y+1][x] & IN_MAZE) )
				{//down
					primMatrix[y+1][x] &= ~UP_WALL;
					primMatrix[y][x] &= ~DOWN_WALL;
					done = 1;
					//printf("\n Probijen zid na dole  %d %d", x, y+1);
				}
				break;

			case 3:
				if ( x - 1 >= 0 && (primMatrix[y][x-1] & IN_MAZE) )
				{//left
					primMatrix[y][x-1] &= ~RIGHT_WALL;
					primMatrix[y][x] &= ~LEFT_WALL;
					done = 1;
					//printf("\n Probijen zid na levo  %d %d", x-1, y);
				}
				break;

			case 4:
				if ( x + 1 < w && (primMatrix[y][x+1] & IN_MAZE) )
				{//right
					primMatrix[y][x+1] &= ~LEFT_WALL;
					primMatrix[y][x] &= ~RIGHT_WALL;
					done = 1;
					//printf("\n Probijen zid na desno  %d %d", x+1, y);
				}
				break;

			default: printf("ZABOLO"), exit(64);

			}

			if ( done == 1 ) break;

		}



		// dodaj sve komsije koje nisu deo lafirinta u redic
		if ( y - 1 >= 0 && !(primMatrix[y-1][x] & IN_MAZE) ) 
		{// up


			if ( !FindInList(rear, x, y-1) )
			{
				InsertElement(&rear, x, y-1);
				//printf("\n Dodat komsija  %d %d", x, y-1);
			}


		}
		if ( y + 1 < h && !(primMatrix[y+1][x] & IN_MAZE) ) 
		{//down

			if ( !FindInList(rear, x, y+1) )
			{
				InsertElement(&rear, x, y+1);
				//printf("\n Dodat komsija  %d %d", x, y+1);
			}

		}
		if ( x - 1 >= 0 && !(primMatrix[y][x-1] & IN_MAZE) ) 
		{//left

			if ( !FindInList(rear, x-1, y) )
			{
				InsertElement(&rear, x-1, y);
				//printf("\n Dodat komsija  %d %d", x-1, y);
			}

		}
			
			
		if ( x + 1 < w && !(primMatrix[y][x+1] & IN_MAZE) )
		{//right

			if ( !FindInList(rear, x+1, y) )
			{
				InsertElement(&rear, x+1, y);
				//printf("\n Dodat komsija  %d %d", x+1, y);
			}

		}

	}


	/*
	printf("\n");
	for ( i = 0; i < h; i++, printf("\n") )
		for ( j = 0; j < w; j++ )
			printf("%4d", primMatrix[i][j] - 16);
	*/



	// promeni primovu u nasu sugavu reprezentaciju
	for ( i = 0; i < dimension.y; i++ )
		for ( j = 0; j < dimension.x; j++ )
			if ( i == 0 || i == dimension.y-1 || j == 0 || j == dimension.x-1 ) a[i][j] = 1;
			else a[i][j] = 0;
		
	for ( i = 0; i < h; i++ )
		for ( j = 0; j < w; j++ )
		{

			if ( primMatrix[i][j] & UP_WALL )
			{
				a[i*2][j*2] = 1;
				a[i*2][j*2 + 1] = 1;
				a[i*2][j*2 + 2] = 1;
			}
			if ( primMatrix[i][j] & LEFT_WALL )
			{
				a[i*2][j*2] = 1;
				a[i*2 + 1][j*2] = 1;
				a[i*2 + 2][j*2] = 1;

			}

		}
		
}

void CarveGateways(int **a, dimension_t dimension)
{

	int i, j;

	for( i = 1; i < dimension.y - 2; i++ )
		if ( a[i][1] == 0 )
		{
			a[i][0] = ENTRANCE;
			break;
		}

	for ( i = dimension.y - 2; i > 0; i-- )
		if ( a[i][dimension.x - 2] == 0 )
		{
			a[i][dimension.x - 1] = EXIT;
			break;

		}

}