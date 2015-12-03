#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define LEN sizeof(struct DuLNode)
typedef struct DuLNode
{
	int data;
	struct DuLNode  *prior;
	struct DuLNode  *next;
}DuNode,*DuLinkList;
int InitList_DuL(DuLinkList &L)
{
	L=(DuLinkList)malloc(LEN);
	if(!L)
	    return ERROR;
	L->next = L;
	L->prior = L;
	return OK;
}
int CreateLinkList_DuL(DuLinkList  &L) 		//建立一个带头节点的含ｎ个元素的双向循环链表;
{
	int i=0;
	DuLinkList p,q,r;
	printf("input the datas:\n");
	q=L;
	while(1)
	{
		i++;
	    p=(DuLinkList)malloc(LEN);
	    scanf("%d",&p->data);
		r=q;
	   if(p->data==0)
	   {
		free(p);
		break;
	   }
/*	  q->next=p;
	  p->prior=q;	注释部分相当于尾插法；
	  q=p;
	}
	q->next=L;
	L->prior=q;
*/
	  if(i==0)
	  {
	   q->next=p;
	   p->prior=q;
	   p->next=L;
	   L->prior=p;
	  }
	  else
	  {
	      q->next=r;
	      r->prior=q;	
	  }
       }
}
		
		
	
	
	

