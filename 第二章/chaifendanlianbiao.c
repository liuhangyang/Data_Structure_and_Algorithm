/*************************************************************************
	> File Name: chaifendanlianbiao.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月10日 星期四 10时15分14秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *next;
}LNode,*LinkList;
LinkList Init_LinkList(LinkList H)
{
    H=(LNode *)malloc(sizeof(LNode));
    H->next=NULL;
}
void print(LinkList H)
{
    LNode *p=H->next;
    if(p==NULL)
    {
        printf("LinkList is Empty!\n");
        return;
    }
    while(p)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
void Create(LinkList H)
{
    LNode *p=H,*s;
    printf("Please input data:\n");
    while(1)
    {
        char str[100];
        int i;
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
        {
            s=(LNode *)malloc(sizeof(LNode));
            s->data=str[i];
            p->next=s;
            p=s;
        }       
            break;
    }
    p->next=NULL;
}
void Spilt_LinkList(LinkList H)
{
    LNode *p=H->next;
    LNode *La,*a;
    LNode *Lb,*b;
    LNode *Lc,*c;
    LNode *s;
    La=Init_LinkList(La);
    Lb=Init_LinkList(Lb);
    Lc=Init_LinkList(Lc);
    a=La;
    b=Lb;
    c=Lc;
    while(p)
    {
        if((p->data >= 'A' && p->data <= 'Z') || (p->data >= 'a' && p->data <= 'z')) 
        {
            a->next = p;
            a=p;
            p=p->next;
        }
        else
        {
            if(p->data >= '0' && p->data <= '9')
            {
                b->next = p;
                b=p;
                p=p->next;
            }
            else
            {
                c->next = p;
                c=p;
                p=p->next;
            }
        }
               
            
    }
    a->next=NULL;
    b->next=NULL;
    c->next=NULL;
    printf("letter:\n");
    print(La);
    printf("number:\n");
    print(Lb);
    printf("other:\n");
    print(Lc);
}
int main()
{
    LNode *H;
    H=Init_LinkList(H);
    Create(H);
    Spilt_LinkList(H);
}

