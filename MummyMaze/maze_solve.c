#include "maze_solve.h"
#include "maze_create.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "maze_gui.h"
#include "position_cursor.h"
#include "start_game.h"

int manhattanLength (int x1, int y1 , int x2, int y2 ){
	return abs(x2-x1)+abs(y2-y1);
}

elemPrioQueue_t* deletePrioQueue1(elemPrioQueue_t *q){
	elemPrioQueue_t *a;
	
	if (q==null) 
		return null;
	else 
	{
		
		a=q->succ;
		
		
		return a;
	}
}
void deletePrioQueue2(elemPrioQueue_t *q){
	elemPrioQueue_t *temp;
	
	
	 
	
		
		while(q)
		{
			temp=q;
			q=q->succ;
			free(temp);
			
		}
	
}
void insertPrioQueue(elemPrioQueue_t **q, elemTree_t* t, int len){
	elemPrioQueue_t * new1, *pred;
	
	elemPrioQueue_t* tmp;
	
	new1= (elemPrioQueue_t*) malloc(sizeof(elemPrioQueue_t)); 
	if(new1==null) exit(2);
	new1->menLen=len;
	new1->info=t;
	/*new1->succ=*q;
	*q=new1;*/

	if((*q)==null)
	{
		(*q)=new1;
		new1->succ=null;

	}
	else
	{

		pred=null;
		tmp=(*q);

		while (tmp!=null && new1->menLen >= tmp->menLen)
		{
			pred=tmp;
			tmp=tmp->succ;

		}
		if(pred==null)
		{
			new1->succ=tmp;
			(*q)=new1;
		}
		else
		{
			new1->succ=tmp;
			pred->succ=new1;
			
		}
	}




}
char neighbours(int **matrix,char **visited,int i , int j){

	char re;
	re=0;
	if(matrix[i+1][j] !=1 /*&& matrix[i+1][j] !=4*/ && visited[i+1][j]==0  )re+=4;
	 if(matrix[i-1][j] != 1 /*&& matrix[i-1][j] != 4*/ && visited[i-1][j]==0   )re+=1;
	 if( matrix[i][j-1] != 1 /*&& matrix[i][j-1] != 4*/ && visited[i][j-1]==0   )re+=8;
	 if( matrix[i][j+1] != 1 /*&& matrix[i][j+1] != 4 */ && visited[i][j+1]==0  ) re+=2;
	 return re;
	 
}
elemTree_t* createNode(int i, int j,elemTree_t* pre,int traveled){
	elemTree_t* re;

	re=malloc (sizeof(elemTree_t));
	re->status=0;
	re->pred=pre;
	re->i=i;
	re->j=j;
	re->traveled=traveled;
	re->arrayElem=null;

	return re;

}

elemTree_t*  branchAndBound(int **matrix, int i1, int j1,int i2, int j2,dimension_t dimension, int* br){
	int i,j,n;
	char nb;
	char **visited;
	elemPrioQueue_t *queue=null,*first;
	elemTree_t *root, *tmp;
	*br=0;
								
	n=0;
	visited=(char**)malloc( dimension.y * sizeof(char*)); 
	
	for (i=0;i<dimension.y; i++)
	{
		visited[i]=malloc(dimension.x*sizeof(char));
		for (j=0;j<dimension.x; j++) visited[i][j]=0;	
	}
	visited[i1][j1]=1;

	root= createNode(i1,j1,null,n);

	insertPrioQueue(&queue,root,manhattanLength( i1, j1,i2, j2)+n);
	first=queue;
	tmp=queue->info;
	queue=deletePrioQueue1(queue);
	while(tmp->i != i2 || tmp->j != j2)
	{
		n=tmp->traveled;

		nb=neighbours(matrix,visited,tmp->i,tmp->j);
		
		tmp->arrayElem=(elemTree_t**) malloc((1+sumBits(nb))*sizeof(elemTree_t*));
		for(i=0;i<sumBits(nb);i++)
		 {
			
			tmp->arrayElem[i]=malloc(sizeof(elemTree_t));
		}
		i=0;
		
		if(isUp(nb)) { 
		tmp->arrayElem[i]=createNode(tmp->i-1,tmp->j,tmp,n+1);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i-1,tmp->j,i2, j2)+n+1);
		visited[tmp->i-1][tmp->j]=1;
		}
		if(isRight(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j+1,tmp,n+1);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j+1,i2, j2)+n+1);
		visited[tmp->i][tmp->j+1]=1;
		}
		if(isDown(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i+1,tmp->j,tmp,n+1);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i+1,tmp->j,i2, j2)+n+1);
		visited[tmp->i+1][tmp->j]=1;
		}
		if(isLeft(nb)) {
		tmp->arrayElem[i]=createNode(tmp->i,tmp->j-1,tmp,n+1);
		insertPrioQueue(&queue,tmp->arrayElem[i++],manhattanLength(tmp->i,tmp->j-1,i2, j2)+n+1);
		visited[tmp->i][tmp->j-1]=1;
		}
		tmp->arrayElem[i]=null;
		
		tmp=queue->info;
		queue=deletePrioQueue1(queue);
	}
	while(tmp!=null)
	{
		(*br)++;
		tmp->status=1;
		tmp=tmp->pred;
	}
	
	if(DEBUGE_MODE) 
		printf("Tree finished");

	deletePrioQueue2(first);

	for(i=0; i<dimension.y; i++)
		 free(visited[i]);
		
	free(visited);


	return root;

}
void dealocateTree_r( elemTree_t* tmp)
{
	int i=0;
	if(tmp->arrayElem!=null) 
	{
	
		while(tmp->arrayElem[i]!=null)
		{
			dealocateTree_r(tmp->arrayElem[i++]);
		} 
	
	
	}
	
	free(tmp);
	tmp=null;

}
void moveTo(int **matrix,int i1,int j1, int i2, int j2 ){
	matrix[i2][j2]=matrix[i1][j1];
	matrix[i1][j1]=0;
	
}
position_t go(int **matrix,elemTree_t* root,dimension_t dimension,int steps ,int *wave, settings_t settings){// moze i rekurzivno
	int i;
	position_t re;
	elemTree_t* tmp2,*tmp1=root;
	

	while(steps!=0 && tmp1->arrayElem!=null ){
		i=0;
		while(tmp1->arrayElem[i++]->status!=1);
		
			tmp2=tmp1->arrayElem[--i];
		if(matrix[tmp2->i][tmp2->j]!=4 )
		{
			moveTo(matrix,tmp1->i,tmp1->j,tmp2->i,tmp2->j);
			printMovement(tmp1->i,tmp1->j,tmp2->i,tmp2->j, MUMMY,wave,settings);
			tmp1=tmp2;

			steps--;
		}
		else break;
	}
	re.x=tmp1->i;
	re.y=tmp1->j;

	return re; 


}
void spawnPlayer(int **matrix, dimension_t dimension,int *i,int *j){
	
	
	*i= SetEntrance(matrix, dimension);
	*j=0;
	
	matrix[(*i)][(*j)]=PLAYER;

}
void spawnEnemy(int **matrix,dimension_t dimension,int *i,int *j){


	do
	{
	*i= (int) ((rand()/(double)RAND_MAX)*(dimension.y-1-1)+1);
	*j= (int) ((rand()/(double)RAND_MAX)*(dimension.x-1-1)+1);
	} while(matrix[(*i)][(*j)]!=0);
	matrix[(*i)][(*j)]=MUMMY;
}
position_t dummyMummy(int **matrix,int i1,int j1, int i2, int j2,int steps ,int *wave,settings_t settings)
{	
	int k , m;
	int min,i;
	position_t re;
	k=0;
	m=0;

	

	re.x=i1;
	re.y=j1;
	for(i=0;i<steps;i++)
	{
		min=MAX_INT;
		k=0;
		m=0;
		if(matrix[re.x][re.y+1]!=1) 
		{
			if(min>manhattanLength(re.x,re.y+1,i2,j2))
			{
				min=manhattanLength(re.x,re.y+1,i2,j2);
				k=re.x;
				m=re.y+1;
			}

		}
		if(matrix[re.x][re.y-1]!=1) 
		{
			if(min>manhattanLength(re.x,re.y-1,i2,j2))
			{
				min=manhattanLength(re.x,re.y-1,i2,j2);
				k=re.x;
				m=re.y-1;
			}

		}
		if(matrix[re.x+1][re.y]!=1) 
		{
			if(min>manhattanLength(re.x+1,re.y,i2,j2))
			{
				min=manhattanLength(re.x+1,re.y,i2,j2);
				k=re.x+1;
				m=re.y;
			}

		}
		if(matrix[re.x-1][re.y]!=1) 
		{
			if(min>manhattanLength(re.x-1,re.y,i2,j2))
			{
				min=manhattanLength(re.x-1,re.y,i2,j2);
				k=re.x-1;
				m=re.y;
			}

		}
		if(k==0 || min>manhattanLength(re.x,re.y,i2,j2)  ) return re;
		else 
		{
		moveTo(matrix,re.x,re.y,k,m);
		printMovement(re.x,re.y,k,m, MUMMY,wave,settings);
		re.x=k;
		re.y=m;
		

		}
	}
	return re;

}
float timef (clock_t begin)
{
	clock_t end= clock();



	return (float)(end-begin)/CLOCKS_PER_SEC;
}