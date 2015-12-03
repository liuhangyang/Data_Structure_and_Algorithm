/*Copyright(C):yanglongfei;
 *All right reserved:
 *程序名:单链表的分离；
 *程序的描述:把ａ链表的奇数节点放到ｂ想、链表中，偶数节点放到ｃ中；
 *创建日期:2015年 06月 14日 星期日 15:24:57 CST
 */
#include "LinkList.h"
int CreateList(LinkList &L)
{
	LinkList p,q;
	printf("input the datas:");
	q=L;
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
	p->next=NULL;
	return OK;
}
int Splist_L(LinkList &La,LinkList &Lb)
{
	int i=0;
	LinkList pa=La,pb=Lb,p;
	p=La->next;
	La->next=NULL;
	while(p!=NULL)
	{ 
 	    i++;
	  if(i%2!=0)
	  {
	     pa->next=p;
	     pa=p;
	  }
	  else
	  {
           pb->next=p;
	   pb=p;
	  }
	 p=p->next;
	}
	pa->next=NULL;
	pb->next=NULL;
	return OK;
}
int TravseList_L(LinkList L)            //遍历单链表L
{
        LinkList   p;
        p=L->next;
        while(p)
        {
                printf("%d",p->data);
                p=p->next;
        }
	printf("\n");
        return OK;      
}

int  main()
{
	LinkList La,Lb,Lc;
	InitList_L(La);
	InitList_L(Lb);
	CreateList(La);
	Splist_L(La,Lb);
	printf("Output the datas;\n");
	TravseList_L(La);
	TravseList_L(Lb);
}		

		
