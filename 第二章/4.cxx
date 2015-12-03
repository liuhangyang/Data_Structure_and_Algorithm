/*Copyright(c):yanglongfei;
 *All right reserved:
 *程序名:合并两个单链表；
 *程序描述:创建La,Lb,两个升序的单链表，让其合并后仍然有序;
 *创建日期:2015年 06月 14日 星期日 13:47:38 CST
 */
#include "LinkList.h"
int CreateList_L(LinkList &L)
{
	LinkList   p,q;
	printf("Input the data in creasing order:");
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
int MergeList_L(LinkList  &La,LinkList &Lb,LinkList  &Lc)   //合并两个有序的单链表，使Lc仍然是有序单链表
{
	LinkList   pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
		if(pa->data <= pb->data)		//插入La的节点
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else					//插入Lb的节点
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa ? pa:pb;	//插入剩余节点
	 free(Lb);
	return OK;
}
int TravseList_L(LinkList L)		//遍历单链表L
{
	LinkList   p;
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
	int n;
	LinkList La,Lb,Lc;
	InitList_L(La);
	InitList_L(Lb);
	CreateList_L(La);
	CreateList_L(Lb);
	MergeList_L(La,Lb,Lc);
	printf("output the data in Lc");
	TravseList_L(Lc);
}
