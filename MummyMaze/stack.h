#ifndef _stack_h
#define _stack_h

struct listElem {
    int val;
    struct listElem *next;
};

typedef struct listElem lElem;

/**
*	@desc	See if stack empty
*	@param	lElem *head - head list element pointer
*	@return	1 - stack empty, 0 - stack not empty
*	@author Vidor Gencel
*/
int stackEmpty(lElem *head);

/**
*	@desc	Push new element to stack
*	@param	lElem **head - double pointer to list head
*	@param	int - value of new element
*	@author Vidor Gencel
*/
void push(lElem **head, int element);

/**
*	@desc	Remove and return element from stack
*	@param	lElem **head - double pointer to list head
*	@return	int - value of removed element
*	@author Vidor Gencel
*/
int pop(lElem **head);


#endif