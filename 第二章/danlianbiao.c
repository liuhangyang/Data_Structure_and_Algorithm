/*************************************************************************
	> File Name: danlianbiao.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月08日 星期二 08时18分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node 
{
    ElemType  data;
    struct node *next;
}LNode,*LinkList;
//初始化
LinkList Init_LinkList(LinkList H)
{
    H=(LNode *)malloc(sizeof(LNode));
    H->next=NULL;
    return H;
}
//头插法创建一个链表
LinkList Create_LinkList(LinkList H)
{
    LNode *s;
    int x;
    //H->next=NULL;
    while(1)
    {
        printf("请输入数据:");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=H->next;
        H->next=s;
    }
    return H;
}
//尾插法创建一个链表
LinkList Create_LinkList1(LinkList H)
{
    LNode *s,*r=H;
    int x;
    while(1)
    {
        printf("请输入数据:");
        scanf("%d",&x);
        if(x == -1)
        {
            break;
        }
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return H;
}
//求表长
int  Length_Link_List(LinkList H)
{
    LNode *s=H;
    int j=0;
    while(s->next!=NULL)
    {
        j++;
        s=s->next;
    }
    return j;
}
//按序号查找
LinkList Get_LinkList(LinkList H,int k)
{
    int j=0;
    LNode *p=H;
    while(p && j<k)
    {
        p=p->next;
        j++;
    }
    if(j == k && k != 0)   //当k==0时，应该返回的是NULL;
    {
        return p;
    }
    else 
    {
        return NULL;
    }
}
//按值查找
int  Locate_LinkList(LinkList H,ElemType x)  //如果找到，返回其位置，没找到，p=NULL,所以两种情况都返回p
{
    int j=1;
    LNode *p=H->next;
    while(p!=NULL && p->data!=x)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        printf("查找的值不存在\n");
        return -1;
    }
    return j;
}
//插入
int Insert_LinkList(LinkList H,int i,ElemType x)   //在第i个位置上插入x
{
    LNode *p,*s;
    p=Get_LinkList(H,i-1);   //判断插入节点的前驱节点是否存在
    if(p==NULL)
    {
        printf("第%d-1个节点不存在\n",i);
        return -1;
    }
    s->data=x;
    s->next=p->next;
    p->next=s;
    return 1;

}
//删除操作
int Delete_LinkList(LinkList H,int i)
{
    LNode *p,*s;
    p=Get_LinkList(H,i-1);
    if(p==NULL)
    {
        printf("第%d-1个节点不存在\n",i);
        return -1;
    }
    if(p->next==NULL)
    {
        printf("第%d个节点不存在\n",i);
        return -1;
    }
    s=p->next;
    p->next=s->next;
    free(s);
    return 1;
}
//单链表的逆置
void Reverse_LinkList(LinkList H)
{
    LNode *p,*q;
    p=H->next;
    H->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=H->next;
        H->next=q;
        /*或者
         q=p->next;
         p->next=H->next;
         H->next=p;
         p=q;*/

    }
}
//
void pur_LinkList(LinkList H)
{
    LNode *p,*q,*r;
    p=H->next;
    if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            q=p->next;
            while(q!=NULL)
            {
                    if(p->data == q->data)
                    {
                        r=q;
                        p->next=q->next;
                        free(r);
                    }
                q=q->next;
            }
        }
        p=p->next;
    }
}
void  merge_LinkList(LinkList La,LinkList Lb)
{
    LNode *p,*q,*r,*last;
    p=La->next;
    q=Lb->next;
    last=La;
    last->next=NULL;
    while(p && q)
    {
        if(p->data < q->data)
        {
            r=p;
            p=p->next;
        }
        else
        {
            r=q;
            q=q->next;
        }
        r->next=last->next;
        last->next=r;
        last=r;
    }
    //将未空集合中的元素连接道La后面
    if(p)
    {
        last->next=p;
    }
    else
    {
        last->next=q;
    }
    free(Lb);
 }
LinkList merge1_LinkList(LinkList La,LinkList Lb)
{
	LNode *p,*q,*r,*last;
    
	int m,n;
	m=Length_Link_List(La);
	n=Length_Link_List(Lb);
	p=La->next;
	q=Lb->next;
	last=La;
	last->next=NULL;
    int t=1;
    printf("%d,%d\n",m,n);
	while(p&&q)
	{
	     	if(m<=n)
	     	{
                if(t==1)
                {
                    r=p;
                    p=p->next;
                    t=0;
                }
                else
                {
                    r=q;
                    q=q->next;
                    t=1;
                    
                }
                
            }
	     	
	     	else
	     	{
                    if(t==1)
                    {
                        r=q;
                        q=q->next;
                        t=0;
                    }
                    else
                    {
                        r=p;
                        p=p->next;
                        t=1;
                    }
	     	    
            }
	     	r->next=last->next;
	     	last->next=r;
	     	last=r;
	 }
    if(p)
    {
        last->next=p;
    }
    else
    {
        last->next=q;
    }
    return La;
}			
		

//求两个集合的差集
void Different_LinkList(LinkList La,LinkList Lb)
{
    LNode *pre,*p,*r,*q;
    pre=La;
    p=La->next;
    while(p!=NULL)
    {
        q=Lb->next;
        while(q!=NULL && p->data!=q->data)
        {
            q=q->next;
        }
        if(q!=NULL)
        {
            r=p;
            pre->next=p->next;
            p=p->next;
            free(r);
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }

}
//打印单链表
void print(LinkList H)
{
    LNode *p=H->next;
    if(p==NULL)
    {
        printf("链表为空\n");
    }
    else
    {
        while(p)
        {
            printf("%3d",p->data);
            p=p->next;
        }
    }

}
void main()
{
    LNode *H,*M;
    int choice;
    H=Init_LinkList(H);
    M=Init_LinkList(M);
    printf("单链表的练习:\n");
    printf("0.退出\n");
    printf("1.头插法创建链表\n");
    printf("2.尾插法创建链表\n");
    printf("3.链表的删除\n");
    printf("4.链表的插入\n");
    printf("5.链表的按位置查找\n");
    printf("6.链表的合并\n");
    printf("7.链表的差集\n");
    printf("8.链表的逆置\n");
    printf("9.求链表长度\n");
    printf("10.打印链表\n");
    printf("11.链表的按值查找\n");
    printf("12.链表的合并1\n");
    while(1)
    {
        
    printf("请选择:");
    scanf("%d",&choice);
        if(choice == 0)
        {
            break;
        }
        switch(choice)
        {
            case 1:
                   H=Create_LinkList(H);
                   break;
            case 2:
                    M=Create_LinkList1(M);
                    break;
            case 3:
            {
                int i;
                printf("请输入要删除的位置:");
                scanf("%d",&i);
                Delete_LinkList(H,i);
                break;
            }
            case 4:
            {
                int i;
                ElemType x;
                printf("请输入要插入的位置:");
                scanf("%d",&i);
                printf("请输入要插入的值:");
                scanf("%d",&x);
                Insert_LinkList(H,i,x);
                break;
            }
            case 6:
                merge_LinkList(H,M);
                break;
            case 5:
            {
                int i;
                printf("请输入要查找的位置:");
                scanf("%d",&i);
                LNode *p;
                p=Get_LinkList(H,i);
                printf("要查找的值为:%d",p->data);
                printf("\n");
                break;
            }
            case 7:
            {
                Different_LinkList(H,M);
                print(H);
                break;
            }
            case 8:
            {
                Reverse_LinkList(H);
            }
            break;
            case 9:
            {
                int i;
                i=Length_Link_List(H);
                printf("Length=%d",i);
                printf("\n");
            }
            break;
            case 10:
            {
                print(H);       
            }
            break;
            case 11:
            {
                int i;
                ElemType x;
                printf("请输入查找的值:");
                scanf("%d",&x);
                i=Locate_LinkList(H,x);
                printf("pos=%d",i);
                printf("\n");
            }
            case 12:
            {
                LNode *La,*Lb;
                La=Init_LinkList(La);
                Lb=Init_LinkList(Lb);
                La=Create_LinkList1(La);
               // int n=Length_Link_List(La);
                //printf("%d\n",n);
                Lb=Create_LinkList1(Lb);
            	H=merge1_LinkList(La,Lb);
                print(La);
            }
            break;
            default:
            break;

        }
    }

}
