#ifndef _maze_solve_h
#define _maze_solve_h
#include "maze_create.h"

/* makrooi za proveru statsa clanova glavne matrice */
#define null 0
#define isUp(A) (A & 0x01)
#define isRight(A) (A & 0x02)
#define isDown(A) (A & 0x04)
#define isLeft(A) (A & 0x08)
#define sumBits(A) (A&0x01+ A & 0x02+ A & 0x04+A & 0x08 )
typedef struct elemTree_t
{
	char status;
	int i,j;
	struct elemTree_t *pred;
	struct  elemTree_t **arrayElem; 
	
} elemTree_t; 

typedef struct elemPrioQueue_t
{
	int	menLen;
	struct elemTree_t *info;
	struct elemPrioQueue_t* succ;


} elemPrioQueue_t;
int manhattanLength (int cordinateX1, int cordinateY1 , int cordinateX2, int cordinateY2 );


elemTree_t* deletePrioQueue(elemPrioQueue_t** Q);
void insertPrioQueue(elemPrioQueue_t **Q, elemTree_t* T,int Len);
elemTree_t*  branchAndBound(int **matrix, int i, int j,int, int,dimension_t dimension);
elemTree_t* createNode(int i, int j,elemTree_t* pre);
int neighbours(int **matrix,char **visted,int i , int j);
#endif