#include "LinkList_Dul.h"	//在表Ｌ的第ｉ个元素之前插入一个元素ｅ
DuLNode *GetElemp_DuL(DuLinkList L,int i)
{
	DuLinkList p;
	int j;
	p=L->next;
	j=1;
	while(p!=NULL&&j<i)		//查找第i个节点
	{
		p=p->next;
		++j;
	}
	if(p==L || j>i)
		return ERROR;
	return p;
}
int ListInsert_DuL(DuLinkList &L,int i,int e)  	//在表的第i个元素之前插入一个元素
{
	DuLinkList p,s;
	if(!(p=GetElemp_DuL(L,i)))		//如果p非空，p指向第ｉ个节点
		return ERROR;
	if(!(s=(DuLinkList)malloc(LEN)))
		return ERROR;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}
int ListDelete_DuL(DuLinkList &L,int i,int &e)		//删除表中第ｉ个元素，由变量ｅ返回其值
{
	DuLinkList p;
	if(!(p=GetElemp_DuL(L,i)))
		return ERROR;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return OK;
}
	
int TraverseList_DuL(DuLinkList L)
{
	DuLinkList p;
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
	DuLinkList L;
	int i,e;
	InitList_DuL(L);
	CreateLinkList_DuL(L);
/*	printf("Input the insert data:");
	scanf("%d",&i);
	printf("Input the insert location;");
	scanf("%d",&e);
	if(ListInsert_DuL(L,i,e))
	{
		printf("The insert data is %d\n",e);
		printf("OUtput the datas:");
		TraverseList_DuL(L);
	}
	else
	{
		printf("can't insert the data!");
	}
	printf("Input the delte location:");
	scanf("%d",&i);
	if(ListDelete_DuL(L,i,e))
	{
		printf("The delete data is %d\n",e);
		printf("Output the Double Cricle lists:");
		TraverseList_DuL(L);
	}
	else
	{
		printf("can't delete the data!");
	}
}
*/
	
		printf("Output the Double Cricle lists:");
		TraverseList_DuL(L);
}

