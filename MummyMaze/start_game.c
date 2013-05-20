#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "maze_solve.h"


int startGame()
{
	int **matrix,i1,j1,i2,j2;
	dimension_t dimension;
	elemTree_t* root;

	dimension.x = 7; //80
	dimension.y = 7; //23
	
	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN??? I <3 DORVI
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	DfsInit(matrix, dimension);
	RemoveRandomWalls(matrix, dimension, 4);
	RemoveAloneWalls(matrix, dimension);
	
	spawnPlayer(matrix,dimension,&i1,&j1);
	spawnEnemy(matrix,dimension,&i2,&j2);
	
	root=branchAndBound(matrix,i1,j1,i2,j2,dimension);
	go(matrix,root,dimension);
	

	dealocateTree_r(root);
	if(DEBUGE_MODE)
		printf("Tree Destroy");
	MazeDestroy(matrix, dimension);

	//DEBUGING
	system ("pause"); 

	return 0;
}