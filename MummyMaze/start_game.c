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
#include "options.h"
#include "position_cursor.h"
#include "colors.h"


int startGame(settings_t settings)
{
	int **matrix, movement, newMovement, wave=0, i;

	position_t	playerPosition, *mummyPosition;
	dimension_t dimension;
	elemTree_t* root;
	int flag;
	clock_t begin=clock();
	float score, last=0;

	mummyPosition= malloc(settings.botNumber*sizeof(position_t));

	switch (settings.levelSize) {
		case SMALL:		dimension.x = 21;dimension.y = 15;break;
		case MEDIUM:	dimension.x = 31;dimension.y = 15;break;
		case LARGE:		dimension.x = 41;dimension.y = 15;break;
	}
	

	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN??? I <3 DORVI
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);


	if (settings.mazeAlgorithm==PRIM){

		Prim(matrix, dimension);
		RemoveRandomWalls(matrix, dimension, 4);
 		RemoveAloneWalls(matrix, dimension);
	}
	else {	
		DfsInit(matrix, dimension);
 		RemoveRandomWalls(matrix, dimension, 4);
 		RemoveAloneWalls(matrix, dimension);
	}

	CarveGateways(matrix, dimension);

	spawnPlayer(matrix,dimension,&playerPosition.x,&playerPosition.y);

	for (i=0; i<settings.botNumber; i++)
	{
		spawnEnemy(matrix,dimension,&mummyPosition[i].x,&mummyPosition[i].y);
	}
	printFormattedMatrix(matrix,dimension,settings);

	while (1) {
		score = timef(begin);

		positionCursor (0,49);
		changeColor(142);
		printf ("%.2f",score);

		newMovement=FALSE;

		if (_kbhit()) {
			movement=controls(_getch());
			if ((movement==PAUSE)||(movement==EXIT)) break;	
		
			switch (movement) {
				case UP:	if (matrix[playerPosition.x-1][playerPosition.y]!=1) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y,PLAYER,0,settings);
								playerPosition.x-=1;
								newMovement=TRUE;
								break;
							}else break;
				case DOWN:	if (matrix[playerPosition.x+1][playerPosition.y]!=1) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y,PLAYER,0,settings);
								playerPosition.x+=1;
								newMovement=TRUE;
								break;
							}else break;
				case LEFT:	if (matrix[playerPosition.x][playerPosition.y-1]!=1) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1,PLAYER,0,settings);
								playerPosition.y-=1;
								newMovement=TRUE;
								break;
							}else break;
				case RIGHT:	if (matrix[playerPosition.x][playerPosition.y+1]!=1) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1,PLAYER,0,settings);
								playerPosition.y+=1;
								newMovement=TRUE;
								break;
							}else break;
			}
		}
		
		
		if ((score-last)>0.2) {

			for(i=0;i<settings.botNumber;i++)
			{	
				if (settings.botDifficuly==EASY)
					mummyPosition[i]=dummyMummy(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,2,&wave,settings);
				else {
					root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension);
	
					mummyPosition[i]=go(matrix,root,dimension,1,&wave,settings);

					dealocateTree_r(root);
				}

			}
			last=score;

		}
		
			flag=0;
			for(i=0;i<settings.botNumber;i++) 
				if ((playerPosition.x==mummyPosition[i].x)&&(playerPosition.y==mummyPosition[i].y)) flag=1;

			if (flag) break;

	}
	
	// Sleep (1000);

	if(DEBUGE_MODE)
		printf("Tree Destroy");
	MazeDestroy(matrix, dimension);

	return 0;
}