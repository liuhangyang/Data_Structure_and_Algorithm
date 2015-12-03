/*Copyright(C):yanglongfei
 *All right reserved:
 *程序名:循环链表的建立查找和输出;
 *程序描述：建立一个单链表，让其尾节点指向头节点；
 *创建日期:2015年 06月 14日 星期日 16:22:13 CST
 */
 
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR  0
#define  OVERFLOW  0
#define LEN  sizeof(struct CLNode)
typedef struct CLNode
{
	int data;
	struct CLNode *next;
}CLNode,*CLinkList;
int InitList_CL(CLinkList &L)	//生成只含有头节点的空循环链表
{
	L=(CLinkList)malloc(LEN);
	if(!L)
	{
		exit(OVERFLOW);
	}
	L->next=NULL;
	return OK;
}	
int CreateList_CL(CLinkList &L)
{
	CLinkList p,q;
	printf("Input the datas:\n");
	q=L;
	while(1)
	{
		p=(CLinkList)malloc(LEN);
		scanf("%d",&p->data);
		if(p->data==0)
		{
			free(p);
			break;
		}
		q->next=p;
		q=p;
	}
	q->next=L;
	return OK;
}
int GetELem_CL(CLinkList L,int i,int &e)    //在表中查找第ｉ个元素，若存在，右变量ｅ带回;
{
	CLinkList p;
	int j=1;
	p=L->next;
	while(p!=L&&j<i)
	{
		p=p->next;	
		++j;	
	}
	if(p==L || j>i)
		return ERROR;
	e=p->data;
	return OK;
}
int TraseList_CL(CLinkList L)
{
	CLinkList p;
	p=L->next;
	while(p!=L)
	{
		printf("%d",p->data);
		p=p->next;
	}
	return OK;
}
int main()
{
	CLinkList L;
	int i,e;
	InitList_CL(L);
	CreateList_CL(L);
	printf("Input the serch location:");
	scanf("%d",&i);
	if(GetELem_CL(L,i,e))
	{
		printf("the data in %dth location is %d\n",i,e);
		printf("Output the Cricle List");
		TraseList_CL(L);
	}
	else
	{
		printf("can't find the data!\n");
	}
}
