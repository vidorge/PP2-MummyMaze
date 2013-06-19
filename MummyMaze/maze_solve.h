#ifndef _maze_solve_h
#define _maze_solve_h
#include "maze_create.h"
#include <stdio.h>
#include <time.h>
#include "options.h"
/* makrooi za proveru statsa clanova glavne matrice */
#define null 0
#define isUp(A) (A & 0x01)
#define isRight(A) (A & 0x02)
#define isDown(A) (A & 0x04)
#define isLeft(A) (A & 0x08)
#define sumBits(A) ((A&0x01)?1:0 + (A & 0x02)?1:0 + (A & 0x04)?1:0 +(A & 0x08)?1:0  )
#define DEBUGE_MODE 0
#define MAX_INT 32000
typedef struct elemTree_t
{
	char status;
	int i,j,traveled;

	struct elemTree_t *pred;
	struct  elemTree_t **arrayElem; 
	
} elemTree_t;  	

typedef struct elemPrioQueue_t
{
	int	menLen;
	struct elemTree_t *info;
	struct elemPrioQueue_t* succ;


} elemPrioQueue_t;
typedef struct position_t
{
	int x;
	int y;
} position_t;

typedef struct highscore_t
{
	float score;
	char  name[250] ;
	struct highscore_t * succ;
	time_t date;

}highscore_t;


int manhattanLength (int cordinateX1, int cordinateY1 , int cordinateX2, int cordinateY2 );


elemPrioQueue_t* deletePrioQueue(elemPrioQueue_t* Q);
void insertPrioQueue(elemPrioQueue_t **Q, elemTree_t* T,int Len);
elemTree_t*  branchAndBound(int **matrix, int i, int j,int, int,dimension_t dimension,int *br ); 
elemTree_t* createNode(int i, int j,elemTree_t* pre,int traveled); 
char neighbours(int **matrix,char **visted,int i , int j); 
void dealocateTree_r	( elemTree_t* root);
void moveTo(int **matrix,int i1,int j1, int i2, int j2 ); 
position_t go(int **matrix,elemTree_t* root,dimension_t dimension,int steps ,int *wave, settings_t settings); 
void spawnPlayer(int **matrix, dimension_t dimension,int *i,int *j); 
void spawnEnemy(int **matrix,dimension_t dimension,int *i,int *j);
position_t dummyMummy(int **matrix,int i1,int j1, int i2, int j2,int steps ,int *wave,settings_t settings);
void deletePrioQueue2(elemPrioQueue_t *q);
float timef(clock_t begin); 
void hint (int **matrix, int i1, int j1,int i2, int j2,dimension_t dimension); 
highscore_t * createScoreElem(float score,char * str,time_t date, highscore_t *first);	
highscore_t* readFromFile( FILE* output);
void printInFile(highscore_t* first, FILE* output);
highscore_t* dealocateList(highscore_t*);
highscore_t *createScoreElem2(float score,char * str,time_t date,highscore_t *first);
#endif