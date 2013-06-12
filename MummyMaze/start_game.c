#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "maze_solve.h"
#include "background.h"
#include "controls.h"


int startGame()
{
	int **matrix, movement, newMovement;

	position_t	playerPosition, mummyPosition;
	dimension_t dimension;
	elemTree_t* root;

	backgroundImage (GAME);

	dimension.x = 43; //81
	dimension.y = 21; //23
	
	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN??? I <3 DORVI
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	Prim(matrix, dimension);

	
	//DfsInit(matrix, dimension);

	spawnPlayer(matrix,dimension,&playerPosition.x,&playerPosition.y);
	spawnEnemy(matrix,dimension,&mummyPosition.x,&mummyPosition.y);

	while (1) {
		newMovement=FALSE;

		printFormattedMatrix(matrix,dimension,0,0);

		movement=controls(_getch());
		if ((movement==PAUSE)||(movement==EXIT)) break;
		switch (movement) {
			case UP:	if (matrix[playerPosition.x-1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y);
							playerPosition.x-=1;
							newMovement=TRUE;
							break;
						}else break;
			case DOWN:	if (matrix[playerPosition.x+1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y);
							playerPosition.x+=1;
							newMovement=TRUE;
							break;
						}else break;
			case LEFT:	if (matrix[playerPosition.x][playerPosition.y-1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1);
							playerPosition.y-=1;
							newMovement=TRUE;
							break;
						}else break;
			case RIGHT:	if (matrix[playerPosition.x][playerPosition.y+1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1);
							playerPosition.y+=1;
							newMovement=TRUE;
							break;
						}else break;
		}
		
		if (newMovement) {
			root=branchAndBound(matrix,mummyPosition.x,mummyPosition.y,playerPosition.x,playerPosition.y,dimension);// ovo koment ako upalite dummyMummy

			mummyPosition=go(matrix,root,dimension,1);// ovo koment ako upalite dummyMummy
			
			// za glupu mumiju------ mummyPosition=dummyMummy(matrix,mummyPosition.x,mummyPosition.y,playerPosition.x,playerPosition.y,2);
		

			dealocateTree_r(root);// ovo koment ako upalite dummyMummy
		}

		if ((playerPosition.x==mummyPosition.x)&&(playerPosition.y==mummyPosition.y)) break;
	}
	
	Sleep (1000);

	if(DEBUGE_MODE)
		printf("Tree Destroy");
	MazeDestroy(matrix, dimension);

	return 0;
}