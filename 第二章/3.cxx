/*Copyright(c):yanglongfei;
 *All right reserved;
 *程序名:单链表；
 *程序描述:单链表的建立，插入，删除，查找;
 *创建日期:2015年 06月 14日 星期日 18:56:28 CST
 */
#include "LinkList.h"
int CreateList_L(LinkList &L,int n)     //建立含n个元素的单链表
{
        LinkList p,q;
        int i;
        printf("Input the datas:");
        q = L;
        while(1)
        {
                p=(LinkList)malloc(LEN);
                scanf("%d",&p->data);
		if(p->data==0)
		{
			free(p);
			break;
		}
                q->next=p;
		q=p;
        }
	q->next=NULL;
        return OK;
}
int GetElem_L(LinkList L,int i,int &e)   //若表中想】存在第i个元素，由变量e带回其值
{
	LinkList p;
	int j;
	p=L;
	j=0;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	e=p->data;		    
		return OK;
}
int ListInsert_L(LinkList &L,int i,int e)	//在表的第i个元素之前插入元素e
{
	LinkList p,s;
	int j;
	p=L;
	j=0;
	while(p&&j<i)
	{		
		p=p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	s=(LinkList)malloc(LEN);
	s->data = e;
	s->next=p->next;
	p->next=s;
	return OK;
}
int ListDelete_L(LinkList &L,int i,int &e)		//若表中存在第i个节点，删除之并由，变量e带回其值
{
	LinkList p,q;
	int j;
	p = L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1)
	{
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}
	
int TraverseList_L(LinkList  L)         //遍历单链表
{
        LinkList p;
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
     int n,i,e;
       LinkList L;
        InitList_L(L);
        CreateList_L(L,n);        
/*	printf("Input the search location:");
	scanf("%d",&i);   
	if(GetElem_L(L,i,e))
		printf("the data is the location %d is %d\n",i,e);
	else
	printf("Can't find the right location\n");
	printf("Input the insert location:");
	scanf("%d",&i);       
	printf("Input the insert data:");
	scanf("%d",&e);
	if(ListInsert_L(L,i,e))
	{ */
	 
	printf("Input the delete location:");
	scanf("%d",&i);
	if(ListDelete_L(L,i,e))
	{	printf("Output the datas:");
		TraverseList_L(L);
		printf("\n");
	}
	else
		printf("can't find the data!");
	
}

