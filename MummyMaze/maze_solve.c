#include "maze_solve.h"
#include "maze_create.h"
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
int neighbours(int **matrix,char **visited,int i , int j){

	char re;
	re=0;
	if(matrix[i+1][j] == 0 && visited[i-1][j]==0 )re+=4;
	 if(matrix[i-1][j] == 0 && visited[i+1][j]==0)re+=1;
	 if( matrix[i][j-1] == 0 && visited[i][j-1]==0)re+=8;
	 if( matrix[i][j+1] == 0 && visited[i][j+1]==0) re+=2;
	 return re;
	 
}
elemTree_t* createNode(int i, int j,elemTree_t* pre){
	elemTree_t* re;

	re=malloc (sizeof(elemTree_t));
	re->status=0;
	re->pred=pre;
	re->i=i;
	re->j=j;
	re->arrayElem =null;

	return re;

}

elemTree_t*  branchAndBound(int **matrix, int i1, int j1,int i2, int j2,dimension_t dimension){
	int i;
	int nb;
	elemPrioQueue_t *queue=null;
	elemTree_t *koren, *tmp;
								//ne zaboravi dealokaciju
	
	char **visited=malloc (sizeof(char*));
	
	for (i=0;i<dimension.x; i++)
		visited[i]=calloc(dimension.y,sizeof(char));
	visited[i1][j1]=1;

	koren= createNode(i1,j1,null);

	insertPrioQueue(&queue,koren,manhattanLength( i1, j1,i2, j2));
	tmp = deletePrioQueue(&queue);
	while(tmp->i!=i2 && tmp->j!=j2){
		nb=neighbours(matrix,visited,tmp->i,tmp->j);
		tmp->arrayElem= malloc(sizeof(elemTree_t*));
		for(i=0;i<sumBits(nb)+1;i++) 
			tmp->arrayElem[i]=malloc(sizeof(elemTree_t));
		i=0;
		
		if(isUp(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i+1,tmp->j,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i+1,tmp->j,i2, j2));
		}
		if(isRight(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j+1,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j+1,i2, j2));
		}
		if(isDown(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i-1,tmp->j,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i-1,tmp->j,i2, j2));
		}
		if(isLeft(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j-1,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j-1,i2, j2));
		}
		tmp->arrayElem[i]=null;
		
		tmp=deletePrioQueue(&queue);
		
	}




	
	

	//poceti petlju

	return koren;

}