#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int stackEmpty(lElem *head)
{
    if(head == NULL)    return 1;
    else                return 0;
}

void push(lElem **head, int element)
{
    lElem *p;

    p = malloc( sizeof(lElem) );
    if(p == NULL) exit(10);

    p->val = element;
    p->next = *head;

    *head = p;
}

int pop(lElem **head)
{
    lElem *p;
    int ret;

    if(*head == NULL)
        exit(11);
    else
    {
        p = *head;
        *head = (*head)->next;
        ret = p->val;
        free(p);

        return ret;
    }
}
