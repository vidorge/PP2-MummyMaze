#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "maze_create.h"
#include "maze_solve.h"
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
	int print = 0;
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

		 LivePrint(a, dimension);

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


int ** GenerateMinMatrix(dimension_t dimension)
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
	int print = 0;
	coordList_t *rear, *element;

	rear = NULL; element = NULL;

	primMatrix = GenerateMinMatrix(dimension);

	w = dimension.x / 2;
	h = dimension.y / 2;

	x = w / 2; y = h / 2;

	primMatrix[y][x] |= IN_MAZE;


	InsertElement(&rear, x, y);

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

		if ( ++print % 5 == 0 ) { ConvertFromMin(primMatrix, a, dimension); LivePrint(a, dimension); }

		// dodaj sve komsije koje nisu deo lafirinta u redic
		if ( y - 1 >= 0 && !(primMatrix[y-1][x] & IN_MAZE) ) 
		{// up

			if ( !FindInList(rear, x, y-1) )
				InsertElement(&rear, x, y-1);

		}
		if ( y + 1 < h && !(primMatrix[y+1][x] & IN_MAZE) ) 
		{//down

			if ( !FindInList(rear, x, y+1) )
				InsertElement(&rear, x, y+1);

		}
		if ( x - 1 >= 0 && !(primMatrix[y][x-1] & IN_MAZE) ) 
		{//left

			if ( !FindInList(rear, x-1, y) )
				InsertElement(&rear, x-1, y);

		}
			
			
		if ( x + 1 < w && !(primMatrix[y][x+1] & IN_MAZE) )
		{//right

			if ( !FindInList(rear, x+1, y) )
				InsertElement(&rear, x+1, y);

		}

	}

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


void ConvertPartial(int **minMatrix, int **a, int i, int j)
{

	if ( minMatrix[i][j] & UP_WALL )
	{
		a[i*2][j*2] = 1;
		a[i*2][j*2 + 1] = 1;
		a[i*2][j*2 + 2] = 1;
	}
	if ( minMatrix[i][j] & LEFT_WALL )
	{
		a[i*2][j*2] = 1;
		a[i*2 + 1][j*2] = 1;
		a[i*2 + 2][j*2] = 1;
	}
	if ( minMatrix[i][j] & DOWN_WALL )
	{
		a[i*2 + 2][j*2] = 1;
		a[i*2 + 2][j*2 + 1] = 1;
		a[i*2 + 2][j*2 + 2] = 1;
	}
	if ( minMatrix[i][j] & RIGHT_WALL )
	{
		a[i*2][j*2 + 2] = 1;
		a[i*2 + 1][j*2 + 2] = 1;
		a[i*2 + 2][j*2 + 2] = 1;
	}

	LiveChange(a, 2*i, 2*j);
	Sleep(100);


}


void recursive_push(coordList_t **stack, int x, int y)
{

		coordList_t *element;

		element = (coordList_t*) malloc( sizeof( coordList_t ) );

		element->i = y;
		element->j = x;
	
		element->next = *stack;
		*stack = element;

}


void RecursiveBacktrack(int **a, dimension_t dimension)
{

	int **minMatrix;
	int w, h, x, y, i;
	int un, rn, dn, ln;
	coordList_t *stack = NULL, *element;
	int randDir[] = {1, 2, 3, 4};
	int done;
	int print = 0;

	minMatrix = GenerateMinMatrix(dimension);

	w = dimension.x / 2;
	h = dimension.y / 2;

	x = w / 2;
	y = h / 2;

	

	minMatrix[y][x] |= IN_MAZE;

	// insert 
	element = (coordList_t*) malloc( sizeof(coordList_t) );
	element->i = y;
	element->j = x;
	element->next = stack;
	stack = element;
	//

	while ( stack != NULL )
	{

		x = stack->j;
		y = stack->i;
		
		element = stack;
		stack = stack->next;
		free(element);

		while ( 1 )
		{

			un = y - 1 >= 0 && !(minMatrix[y-1][x] & IN_MAZE);
			rn = x + 1 < w && !(minMatrix[y][x+1] & IN_MAZE);
			dn = y + 1 < h && !(minMatrix[y+1][x] & IN_MAZE);
			ln = x - 1 >= 0 && !(minMatrix[y][x-1] & IN_MAZE);

			if ( !(un || rn || dn || ln) ) break;

			ShuffleArray(randDir);

			done = 0;

			for ( i = 0; i < 4; i++ )
			{

				switch ( randDir[i] )
				{

				case 1: //up
					if ( un )
					{
						minMatrix[y][x] &= ~UP_WALL;
						minMatrix[y-1][x] &= ~DOWN_WALL;

						y = y - 1;

						minMatrix[y][x] |= IN_MAZE;
						recursive_push(&stack, x, y);

						done = 1;

					}


					break;

				case 2: //right
					if ( rn )
					{
						minMatrix[y][x] &= ~RIGHT_WALL;
						minMatrix[y][x+1] &= ~LEFT_WALL;

						x = x + 1;

						minMatrix[y][x] |= IN_MAZE;
						recursive_push(&stack, x, y);

						done = 1;

					}
					break;

				case 3: //down
					if ( dn )
					{
						minMatrix[y][x] &= ~DOWN_WALL;
						minMatrix[y+1][x] &= ~UP_WALL;

						y = y + 1;

						minMatrix[y][x] |= IN_MAZE;
						recursive_push(&stack, x, y);

						done = 1;

					}
					break;

				case 4: //left
					if ( ln )
					{
						minMatrix[y][x] &= ~LEFT_WALL;
						minMatrix[y+1][x] &= ~RIGHT_WALL;

						x = x - 1;

						minMatrix[y][x] |= IN_MAZE;
						recursive_push(&stack, x, y);

						done = 1;

					}
					break;

				} // end_switch

				if ( done ) break;

			} // end_for_rand

			if ( ++print % 5 == 0 ) { ConvertFromMin(minMatrix, a, dimension); LivePrint(a, dimension); }

		} // end_walk

		if ( ++print % 5 == 0 ) { ConvertFromMin(minMatrix, a, dimension); LivePrint(a, dimension); }

	} // end_while_everything




	ConvertFromMin(minMatrix, a, dimension);

}

void ConvertFromMin(int **minMatrix, int **a, dimension_t dimension)
{
	int i, j;
	int w, h;

	w = dimension.x / 2;
	h = dimension.y / 2;

	for ( i = 0; i < dimension.y; i++ )
		for ( j = 0; j < dimension.x; j++ )
			if ( i == 0 || i == dimension.y-1 || j == 0 || j == dimension.x-1 ) a[i][j] = 1;
			else a[i][j] = 0;
		
	for ( i = 0; i < h; i++ )
		for ( j = 0; j < w; j++ )
		{

			if ( minMatrix[i][j] & UP_WALL )
			{
				a[i*2][j*2] = 1;
				a[i*2][j*2 + 1] = 1;
				a[i*2][j*2 + 2] = 1;
			}
			if ( minMatrix[i][j] & LEFT_WALL )
			{
				a[i*2][j*2] = 1;
				a[i*2 + 1][j*2] = 1;
				a[i*2 + 2][j*2] = 1;

			}

		}



}

void BinaryTreeMaze(int **a, dimension_t dimension)
{
	int **minMatrix;
	int w, h, x, y;
	int dn, rn;
	int print = 0;

	minMatrix = GenerateMinMatrix(dimension);

	w = dimension.x / 2;
	h = dimension.y / 2;

	x = w / 2;
	y = h / 2;


	//north west biast
	//up right biast

	for ( y = 0; y < h; y++ )
		for ( x = 0; x < w; x++)
		{
			dn = y + 1 < h;
			rn = x + 1 < w;
			
			if ( dn && !rn )
			{
				minMatrix[y][x] &= ~DOWN_WALL;
				minMatrix[y+1][x] &= ~UP_WALL;
			}
			else if ( rn && !dn )
			{
				minMatrix[y][x] &= ~RIGHT_WALL;
				minMatrix[y][x+1] &= ~LEFT_WALL;
			}
			else if ( rn && dn )
			{

				switch ( rand() & 1 )
				{
				case 0:
					minMatrix[y][x] &= ~DOWN_WALL;
					minMatrix[y+1][x] &= ~UP_WALL;
					break;

				case 1:
					minMatrix[y][x] &= ~RIGHT_WALL;
					minMatrix[y][x+1] &= ~LEFT_WALL;
					break;
				}

			}

			if ( ++print % 10 == 0 ) { ConvertFromMin(minMatrix, a, dimension); LivePrint(a, dimension); }
	
		}

	ConvertFromMin(minMatrix, a, dimension);

}

void CarveGateways(int **a, dimension_t dimension)
{

	int i;

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

int SetEntrance(int **a, dimension_t dimension)
{

	int i;

	for( i = 1; i < dimension.y - 1; i++ )
		if ( a[i][1] == 0 )
			break;
	
	return i;


}

int SetExit(int **a, dimension_t dimension)
{

	int i;

	for ( i = dimension.y - 2; i > 0; i-- )
		if ( a[i][dimension.x - 2] == 0 )
			break;

	return i;

}

void FilterDeadEnds(int **a, dimension_t dimension)
{

	int i, j, count = 0;
	int ude, rde, dde, lde;

	for ( i = 0; i < dimension.y; i++ )
		for ( j = 0; j < dimension.x; j++ )
		{

			if ( a[i][j] == PATH )
			{

				ude = a[i][j-1] == WALL && a[i][j+1] == WALL && a[i-1][j] == WALL && i-1>0;
				rde = a[i-1][j] == WALL && a[i+1][j] == WALL && a[i][j+1] == WALL && j+1<dimension.x-1;
				dde = a[i][j-1] == WALL && a[i][j+1] == WALL && a[i+1][j] == WALL && i+1<dimension.y-1;
				lde = a[i-1][j] == WALL && a[i+1][j] == WALL && a[i][j-1] == WALL && j-1>0;


				if ( (ude || rde || dde || lde) && ( ++count % 3 == 0 ) )
				{

					if ( ude ) a[i-1][j] = PATH;
					if ( rde ) a[i][j+1] = PATH;
					if ( dde ) a[i+1][j] = PATH;
					if ( lde ) a[i][j-1] = PATH;
			
				} 


			}



		}



}