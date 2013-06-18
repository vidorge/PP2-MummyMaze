#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "score_entry.h"
#include "stack.h"
#include "maze_gui.h"
#include "maze_create.h"
#include "maze_solve.h"
#include "background.h"
#include "controls.h"
#include "options.h"
#include "position_cursor.h"
#include "colors.h"
#include "game_over.h"


int startGame(settings_t settings, float totalScore) {

	int **matrix, movement, newMovement, wave=0, i, j, firstMove=0, closed=0, doorItr=0, entranceTemp, size;

	position_t	playerPosition, *mummyPosition;
	dimension_t dimension;
	elemTree_t* root=null;
	int flag,br,ply,enm,dis;
	clock_t begin;
	float score=0, last=0, doorClosed=0;
	position_t entrance, exit;

	switch (settings.levelSize) {
		case SMALL: size=32;break;
		case MEDIUM: size=20;break;
		case LARGE: size=0;break;
	}

	if (settings.wallColor==LIGHT)
		changeColor(LIGHTBACK);	
	else
		changeColor(DARKBACK);
	
	for (i=0;i<HEIGHT;i++)	{
		for (j=0;j<WIDTH;j++)
			printf ("\261");
	}

	backgroundImage(SCORETABLE);

	mummyPosition = malloc(settings.botNumber*sizeof(position_t));

	switch (settings.levelSize) {
		case SMALL:		dimension.x = 27; dimension.y = 17; break;
		case MEDIUM:	dimension.x = 37; dimension.y = 17; break;
		case LARGE:		dimension.x = 49; dimension.y = 17; break;
	}
	
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);

	switch ( settings.mazeAlgorithm ) {
		case PRIM: Prim(matrix, dimension, settings); break;
		case BACKTRACK: RecursiveBacktrack(matrix, dimension, settings); break;
		case BINARY: BinaryTreeMaze(matrix, dimension, settings); break;
	}

	if (settings.filterEnds)
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

		root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension,&dis);
		if( dis <25 ) 
		{
			matrix[mummyPosition[i].x][mummyPosition[i].y]=0;
			i--;                           
		}
		
	}
	printFormattedMatrix(matrix,dimension,settings);

	begin = clock();

	while (1) {
		if (firstMove)
			score = timef(begin);
		
		if (firstMove)
			if (((score-doorClosed)>0.3)&&(!closed)) {
				positionCursor(MAZECOLUMN+size,MAZECOLUMN+doorItr+(entranceTemp*3));
				if (settings.wallColor==LIGHT)
					changeColor(LIGHTENTRANCE);
				else
					changeColor(DARKENTRANCE);
				printf ("\262\260\261");
				
				doorItr++;
				if (doorItr==1) 
					matrix[entrance.y][entrance.x]=1;
				
				doorClosed=score;
				if (doorItr==3) closed=1;
			}



		positionCursor (WIDTH-10,HEIGHT-3);
		if (settings.wallColor==LIGHT)
			changeColor(100);
		else
			changeColor(12);
		printf ("%.2f",score + totalScore);

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
				case HINT:	hint (matrix,playerPosition.x,playerPosition.y,exit.y,exit.x,dimension);
							printFormattedMatrix(matrix,dimension,settings);
							break;
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
			// OVDE GA JE POJEO BROJ POENA KONACAN RACUNAS KAO score + totalScore

			if ((playerPosition.x==exit.y)&&(playerPosition.y==exit.x)) {
			
				startGame(settings, score + totalScore); flag=1;
			}

			if (flag) {
				Sleep (250);
				gameover ();
				Sleep (5000);
				scoreEntry();
				break;
			} 

	}
	
	MazeDestroy(matrix, dimension);

	return 0;
}