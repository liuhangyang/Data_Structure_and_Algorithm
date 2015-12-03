/*Copyright(c):yanglongfei;
 *All right reserved:
 *程序名:双向链表的建立和遍历
 *程序描述:创建一个含ｎ个元素的双链表，并输出
 *创建日期:2015年 06月 14日 星期日 15:46:30 CST
 */
 
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR  0
#define OVERFLOW  0
#define LEN sizeof(struct DLNode)
typedef struct DLNode
{
	int data;
	struct DLNode *prior;
	struct DLNode  *next;
}DLNode,*DLinkList;
int InitList_DL(DLinkList &L)
{
	L=(DLinkList)malloc(LEN);
	if(!L)
		return  OVERFLOW;
	L->prior=NULL;
	L->next=NULL;
	return OK;
}
int CreateList_DL(DLinkList &L)
{
	DLinkList p,q;
	printf("Input the datas:");
	q=L;
	while(1)
	{
		p=(DLinkList)malloc(LEN);
		scanf("%d",&p->data);
		if(p->data==0)
		{
		    free(p);
		     break;
		}
		q->next=p;
		p->prior=q;
		q=p;
	}
	q->next=NULL;
}
int TraverseList_DL(DLinkList &L)
{
	DLinkList  p;
	p=L->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
	return OK;
}
int main()
{
	DLinkList  L;
	InitList_DL(L);
	CreateList_DL(L);
	printf("Output the datas:");
	TraverseList_DL(L);
}			
