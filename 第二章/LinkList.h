#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW  0
#define LEN sizeof(struct LNode)
typedef  struct LNode
{
	int data;
	struct LNode *next;
}*LinkList;
int InitList_L(LinkList	&L)
{
	L=(LinkList)malloc(LEN);
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
		return OK;
}
