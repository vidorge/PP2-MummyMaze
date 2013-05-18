#include "maze_solve.h"
#include <math.h>
#include <stdlib.h>
int manhattanLength (int x1, int y1 , int x2, int y2 ){
	return abs(x2-x1)+abs(y2-y1);
}

elemTree_t* deletePrioQueue(elemPrioQueue_t **q){
	elemPrioQueue_t* temp;
	elemTree_t* temp2;
	if (q==null) 
		return null; else {
		temp=*q;
		*q=temp->succ;
		temp2= temp->info;
		free(temp);
		return temp2;
	}
}
void insertPrioQueue(elemPrioQueue_t **q, elemTree_t* t, int len){
	elemPrioQueue_t * new1;
	int tmp1;
	elemTree_t *tmp2;
	new1= (elemPrioQueue_t*) malloc(sizeof(elemPrioQueue_t));
	new1->menLen=len;
	new1->info=t;
	new1->succ=*q;
	*q=new1;

	while (new1!= null && new1->menLen > new1->succ->menLen){
		tmp1=new1->succ->menLen;
		tmp2=new1->succ->info;

		new1->succ->menLen=new1->menLen;
		new1->succ->info=new1->info;

		new1->menLen=tmp1;
		new1->info=tmp2;
		
		new1=new1->succ;

	}




}
elemTree_t*  branchAndBound(int ***matrix, int i1, int j1,int i2, int j2){
	elemPrioQueue_t queue=null;


	// od  matrix[i][j] knapraviti  koren stabla 

	//ubaciti u red pomocu insertPrioQueue()

	//poceti petlju
}