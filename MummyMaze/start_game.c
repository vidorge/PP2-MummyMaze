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
	int **matrix, movement, newMovement, wave=0, i, j, firstMove=0; // VIDORE SKI TE MNOGO VOLI

	position_t	playerPosition, *mummyPosition;
	dimension_t dimension;
	elemTree_t* root;
	int flag;
	clock_t begin = clock();
	float score=0, last=0;
	position_t entrance, exit;

	changeColor(0);
	for (i=0;i<HEIGHT;i++)	{
		for (j=0;j<WIDTH;j++)
			printf (" ");
	}

	mummyPosition= malloc(settings.botNumber*sizeof(position_t));

	switch (settings.levelSize) {
		case SMALL:		dimension.x = 21; dimension.y = 15; break;
		case MEDIUM:	dimension.x = 31; dimension.y = 15; break;
		case LARGE:		dimension.x = 41; dimension.y = 15; break;
	}
	
	srand( (unsigned) time(NULL) );

	matrix = initMatrix(dimension);
		
	switch ( settings.mazeAlgorithm ) {
		case PRIM: Prim(matrix, dimension); break;
		//case DFS: DfsInit(matrix, dimension); break;
		case BACKTRACK: RecursiveBacktrack(matrix, dimension); break;
		case BINARY: BinaryTreeMaze(matrix, dimension); break;
	}

	FilterDeadEnds(matrix, dimension);

	entrance.x = 0;
	entrance.y = SetEntrance(matrix, dimension);

	exit.x = dimension.x - 1;
	exit.y = SetExit(matrix, dimension);

	matrix [entrance.y][entrance.x]=6;
	matrix [exit.y][exit.x]=7;

	spawnPlayer(matrix,dimension,&playerPosition.x,&playerPosition.y);

	for (i=0; i<settings.botNumber; i++)
	{
		spawnEnemy(matrix,dimension,&mummyPosition[i].x,&mummyPosition[i].y);
	}
	printFormattedMatrix(matrix,dimension,settings);

	while (1) {
		if (firstMove)
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
						root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension);
	
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
						root=branchAndBound(matrix,mummyPosition[i].x,mummyPosition[i].y,playerPosition.x,playerPosition.y,dimension);
	
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
	
	// Sleep (1000);

	if(DEBUGE_MODE)
		printf("Tree Destroy");
	MazeDestroy(matrix, dimension);

	return 0;
}