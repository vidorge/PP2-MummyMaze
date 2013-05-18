#ifndef _maze_solve_h
#define _maze_solve_h


/* makrooi za proveru statsa clanova glavne matrice */
#define null 0
/*#define isWall(char A ) ( A & 0x01)
#define isHint (char A )	(A & 0x02)
#define isPlayer(char A ) (A & 0x04)
*/
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
elemTree_t*  branchAndBound(int ***matrix, int i, int j,int, int);


#endif