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


int startGame(settings_t settings) {

	int **matrix, movement, newMovement, wave=0, i, j, firstMove=0, closed=0, doorItr=0, entranceTemp;

	position_t	playerPosition, *mummyPosition;
	dimension_t dimension;
	elemTree_t* root=null;
	int flag,br,ply,enm;
	clock_t begin = clock();
	float score=0, last=0, doorClosed=0;
	position_t entrance, exit;

	if (settings.wallColor==LIGHT)
		changeColor(LIGHTBACK);	
	else
		changeColor(DARKBACK);
	
	for (i=0;i<HEIGHT;i++)	{
		for (j=0;j<WIDTH;j++)
			printf ("\261");
	}



	mummyPosition= malloc(settings.botNumber*sizeof(position_t));

	switch (settings.levelSize) {
		case SMALL:		dimension.x = 21; dimension.y = 15; break;
		case MEDIUM:	dimension.x = 31; dimension.y = 15; break;
		case LARGE:		dimension.x = 41; dimension.y = 15; break;
	}
	
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	LivePrint(matrix, dimension);
	
	switch ( settings.mazeAlgorithm ) {
		case PRIM: Prim(matrix, dimension); break;
		//case DFS: DfsInit(matrix, dimension); break;
		case BACKTRACK: RecursiveBacktrack(matrix, dimension); break;
		case BINARY: BinaryTreeMaze(matrix, dimension); break;
	}

	FilterDeadEnds(matrix, dimension);

	entrance.x = 0;
	entrance.y = entranceTemp = SetEntrance(matrix, dimension);

	exit.x = dimension.x - 1;
	exit.y = SetExit(matrix, dimension);

	matrix [entrance.y][entrance.x]=6;
	matrix [exit.y][exit.x]=7;

	spawnPlayer(matrix,dimension,&playerPosition.x,&playerPosition.y);
	root=branchAndBound(matrix,playerPosition.x,playerPosition.y,exit.y,exit.x,dimension,&ply);




	for (i=0; i<settings.botNumber; i++)
	{

		spawnEnemy(matrix,dimension,&mummyPosition[i].x,&mummyPosition[i].y);
		root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,exit.y,exit.x,dimension,&enm);

		if(enm<ply) 
		{
			matrix[mummyPosition[i].x][mummyPosition[i].y]=0;
			i--;                           
		}
		
	}
	printFormattedMatrix(matrix,dimension,settings);

	while (1) {
		if (firstMove)
			score = timef(begin);

		if (firstMove)
			if (((score-doorClosed)>0.3)&&(!closed)) {
				positionCursor(MAZECOLUMN,MAZECOLUMN+doorItr+(entranceTemp*3));
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTWALL);
				else
					changeColor(DARKWALL);
				printf ("\262\260\261");
				
				doorItr++;
				if (doorItr==1) 
					matrix[entrance.y][entrance.x]=1;
				
				doorClosed=score;
				if (doorItr==3) closed=1;
			}



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
				case LEFT:	if ((matrix[playerPosition.x][playerPosition.y-1]!=1)&&(entrance.y!=playerPosition.x || entrance.x!=playerPosition.y)) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y-1,PLAYER,0,settings);
								playerPosition.y-=1;
								newMovement=TRUE;
								break;
							}else break;
				case RIGHT:	if ((matrix[playerPosition.x][playerPosition.y+1]!=1)&&(exit.y!=playerPosition.x || exit.x!=playerPosition.y)) {
								moveTo(matrix,playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1);
								printMovement(playerPosition.x,playerPosition.y,playerPosition.x,playerPosition.y+1,PLAYER,0,settings);
								playerPosition.y+=1;
								newMovement=TRUE;
								break;
							}else break;
			}
		}
		
		if (!firstMove)
			if ((playerPosition.x!=entrance.y)||(playerPosition.y!=entrance.x)) 
				firstMove=1;

		
		if (settings.playMetod==REALTIME) {
			if (((score-last)>0.2)&&(firstMove)) {

				for(i=0;i<settings.botNumber;i++)
				{	
					if (settings.botDifficuly==EASY)
						mummyPosition[i]=dummyMummy(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,2,&wave,settings);
					else {
						root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension,&br);
	
						mummyPosition[i]=go(matrix,root,dimension,1,&wave,settings);

						dealocateTree_r(root);
					}

				}
				last=score;

			}
		}
		else {
			if (newMovement) {
				for(i=0;i<settings.botNumber;i++)
				{	
					if (settings.botDifficuly==EASY)
						mummyPosition[i]=dummyMummy(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,2,&wave,settings);
					else {
						root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension,&br);
	
						mummyPosition[i]=go(matrix,root,dimension,1,&wave,settings);

						dealocateTree_r(root);
					}

				}
				last=score;

			}
		}

			flag=0;
			for(i=0;i<settings.botNumber;i++) 
				if ((playerPosition.x==mummyPosition[i].x)&&(playerPosition.y==mummyPosition[i].y)) flag=1;

			if ((playerPosition.x==exit.y)&&(playerPosition.y==exit.x)) {
				startGame(settings); flag=1;
			}

			if (flag) break;

	}
	
	MazeDestroy(matrix, dimension);

	return 0;
}