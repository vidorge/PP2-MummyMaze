#include "maze_solve.h"
#include "maze_create.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "maze_gui.h"
#include "position_cursor.h"

int manhattanLength (int x1, int y1 , int x2, int y2 ){
	return abs(x2-x1)+abs(y2-y1);
}

elemTree_t* deletePrioQueue(elemPrioQueue_t **q){
	elemPrioQueue_t* temp;
	elemTree_t* temp2;
	if (*q==null) 
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

	while (new1!= null && new1->succ!=null && new1->menLen > new1->succ->menLen){
		tmp1=new1->succ->menLen;
		tmp2=new1->succ->info;

		new1->succ->menLen=new1->menLen;
		new1->succ->info=new1->info;

		new1->menLen=tmp1;
		new1->info=tmp2;
		
		new1=new1->succ;

	}




}
char neighbours(int **matrix,char **visited,int i , int j){

	char re;
	re=0;
	if(matrix[i+1][j] != 1 && visited[i+1][j]==0 )re+=4;
	 if(matrix[i-1][j] != 1 && visited[i-1][j]==0)re+=1;
	 if( matrix[i][j-1] != 1 && visited[i][j-1]==0)re+=8;
	 if( matrix[i][j+1] != 1 && visited[i][j+1]==0) re+=2;
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
	char nb;
	elemPrioQueue_t *queue=null;
	elemTree_t *root, *tmp;
								
	
	char **visited=malloc (sizeof(char*));
	
	for (i=0;i<dimension.y; i++)
		visited[i]=calloc(dimension.x,sizeof(char));
	visited[i1][j1]=1;

	root= createNode(i1,j1,null);

	insertPrioQueue(&queue,root,manhattanLength( i1, j1,i2, j2));
	tmp = deletePrioQueue(&queue);
	while(tmp->i != i2 || tmp->j != j2){
		nb=neighbours(matrix,visited,tmp->i,tmp->j);
		tmp->arrayElem= malloc(sizeof(elemTree_t*));
		for(i=0;i<sumBits(nb)+1;i++) 
			tmp->arrayElem[i]=malloc(sizeof(elemTree_t));
		i=0;
		
		if(isUp(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i-1,tmp->j,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i-1,tmp->j,i2, j2));
		visited[tmp->i-1][tmp->j]=1;
		}
		if(isRight(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j+1,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j+1,i2, j2));
		visited[tmp->i][tmp->j+1]=1;
		}
		if(isDown(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i+1,tmp->j,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i+1,tmp->j,i2, j2));
		visited[tmp->i+1][tmp->j]=1;
		}
		if(isLeft(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j-1,tmp);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j-1,i2, j2));
		visited[tmp->i][tmp->j-1]=1;
		}
		tmp->arrayElem[i]=null;
		
		tmp=deletePrioQueue(&queue);
		
	}
	while(tmp!=null){
	tmp->status=1;
	tmp=tmp->pred;
	}
	
	if(DEBUGE_MODE) 
		printf("Tree finished");

	while (deletePrioQueue(&queue));

	return root;

}
void dealocateTree_r( elemTree_t* tmp){
	int i=0;
	while(tmp->arrayElem!=null)
	{
		if(tmp->arrayElem[i]==null) return;
		dealocateTree_r(tmp->arrayElem[i++]);
	} 
	free(tmp);

	if(DEBUGE_MODE) 
		printf("Tree destroy");
}
void moveTo(int **matrix,int i1,int j1, int i2, int j2 ){
	matrix[i2][j2]=matrix[i1][j1];
	matrix[i1][j1]=0;
	
}
void go(int **matrix,elemTree_t* root,dimension_t dimension ){// moze i rekurzivno
	int i;
	elemTree_t* tmp2,*tmp1=root;
	

	while(tmp1->arrayElem!=null){
		i=0;
		while(tmp1->arrayElem[i++]->status!=1);
		tmp2=tmp1->arrayElem[--i];
		moveTo(matrix,tmp1->i,tmp1->j,tmp2->i,tmp2->j);
		positionCursor(0,0);
		printFormattedMatrix(matrix, dimension);
		Sleep(500);
		tmp1=tmp2;

	}


}
void spawnPlayer(int **matrix, dimension_t dimension,int *i,int *j){
	
	do
	{
	*i=(rand()/RAND_MAX)*(dimension.y-1-1)+1;
	*j=(rand()/RAND_MAX)*(dimension.x-1-1)+1;
	} while(matrix[(*i)][(*j)]!=0);
	matrix[(*i)][(*j)]=3;

}
void spawnEnemy(int **matrix,dimension_t dimension,int *i,int *j){


	do
	{
	*i=(rand()/(double)RAND_MAX)*(dimension.y-1-1)+1;
	*j=(rand()/(double)RAND_MAX)*(dimension.x-1-1)+1;
	} while(matrix[(*i)][(*j)]!=0);
	matrix[(*i)][(*j)]=4;
}