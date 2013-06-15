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
	float score;

	mummyPosition= malloc(settings.botNumber*sizeof(position_t));
	backgroundImage (GAME);

	dimension.x = 41; //81
	dimension.y = 15; //23
	
	//OVO CEMO JEDNOM POZVATI I NIKEAD VISE DA LI SAM JASAN??? I <3 DORVI
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	Prim(matrix, dimension);

	
	//DfsInit(matrix, dimension);

	spawnPlayer(matrix,dimension,&playerPosition.x,&playerPosition.y);

	for (i=0; i<settings.botNumber; i++)
	{
		spawnEnemy(matrix,dimension,&mummyPosition[i].x,&mummyPosition[i].y);
	}
	printFormattedMatrix(matrix,dimension);

	while (1) {
		score = timef(begin);

		positionCursor (0,49);
		changeColor(142);
		printf ("%.2f",score);

		newMovement=FALSE;

		movement=controls(_getch());
		if ((movement==PAUSE)||(movement==EXIT)) break;
		switch (movement) {
			case UP:	if (matrix[playerPosition.x-1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y);
							printMovement(playerPosition.x,playerPosition.y,playerPosition.x-1,playerPosition.y,PLAYER,0);
							playerPosition.x-=1;
							newMovement=TRUE;
							break;
						}else break;
			case DOWN:	if (matrix[playerPosition.x+1][playerPosition.y]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y);
							printMovement(playerPosition.x,playerPosition.y,playerPosition.x+1,playerPosition.y,PLAYER,0);
							playerPosition.x+=1;
							newMovement=TRUE;
							break;
						}else break;
			case LEFT:	if (matrix[playerPosition.x][playerPosition.y-1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1);
							printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1,PLAYER,0);
							playerPosition.y-=1;
							newMovement=TRUE;
							break;
						}else break;
			case RIGHT:	if (matrix[playerPosition.x][playerPosition.y+1]!=1) {
							moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1);
							printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1,PLAYER,0);
							playerPosition.y+=1;
							newMovement=TRUE;
							break;
						}else break;
		}
		
		/*while (1) {		
			printMovement(mummyPosition.x,mummyPosition.y,mummyPosition.x,mummyPosition.y, MUMMY, & wave);
			Sleep (100);
			if(_kbhit()) {
				if (newMovement) {
					root=branchAndBound(matrix,mummyPosition.x,mummyPosition.y,playerPosition.x,playerPosition.y,dimension);// ovo koment ako upalite dummyMummy

					mummyPosition=go(matrix,root,dimension, 1, &wave);// ovo koment ako upalite dummyMummy
			
					// za glupu mumiju------ mummyPosition=dummyMummy(matrix,mummyPosition.x,mummyPosition.y,playerPosition.x,playerPosition.y,2);
		

					dealocateTree_r(root);// ovo koment ako upalite dummyMummy
				}
				break;
			}
		}*/

		
		if (newMovement) {
			for(i=0;i<settings.botNumber;i++)
			{	
				if (settings.botDifficuly==EASY)
					mummyPosition[i]=dummyMummy(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,2,&wave);
				else {
					root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension);
	
					mummyPosition[i]=go(matrix,root,dimension,1,&wave);

					dealocateTree_r(root);
				}

			}
		}
		
			flag=0;
			for(i=0;i<settings.botNumber;i++) 
				if ((playerPosition.x==mummyPosition[i].x)&&(playerPosition.y==mummyPosition[i].y)) flag=1;

			if (flag) break;

	}
	
	Sleep (1000);

	if(DEBUGE_MODE)
		printf("Tree Destroy");
	MazeDestroy(matrix, dimension);

	return 0;
}