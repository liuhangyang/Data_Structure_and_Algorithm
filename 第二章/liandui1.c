/*************************************************************************
	> File Name: liandui.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月22日 星期二 23时27分03秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct queuenode
{
    Elemtype data;
    struct queuenode *next;
}Qnode;
typedef struct
{
    Qnode *rear;
}LQueue;
LQueue* Init_Queue()
{
    LQueue *q;
    Qnode *p;
    p=(Qnode *)malloc(sizeof(Qnode));
    q=(LQueue *)malloc(sizeof(LQueue));
    p->next=p;
    q->rear=p;
    return q;
}
int IsEmpty_Queue(LQueue *q)
{
    if(q->rear == q->rear->next)
    {
        return 1;
    }
    return 0;
}
void Push_Queue(LQueue *q,Elemtype x)
{
    Qnode *p;
    p=(Qnode *)malloc(sizeof(Qnode));
    p->data=x;
    p->next=q->rear->next;
    q->rear->next=p;
    q->rear=p;
}
int  Pop_Queue(LQueue *q,Elemtype *x)
{
    Qnode *p;
    if(!IsEmpty_Queue(q))
    {
        p=q->rear->next;
        q->rear->next=p->next;
        p=p->next;
        *x=p->data;
        free(p);
       /* if(q->rear->next->next == NULL)
        {
            q->rear=q->front;
        }
        return 1;*/
    }
    else
    {
        printf("队为空!\n");
        return 0;
    }
}
void main()
{
    LQueue *q;
    int i;
    q=Init_Queue();
    for(i=0;i<10;i++)
    {
        Push_Queue(q,i);
    }
    while(!IsEmpty_Queue(q))
    {
        Pop_Queue(q,&i);
        printf("%3d",i);
    }
    printf("\n");
}
