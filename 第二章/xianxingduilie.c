/*************************************************************************
	> File Name: xianxingduilie.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月22日 星期二 22时29分24秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int Elemtype; 
typedef struct node
{
    Elemtype  data[MAXSIZE];
    int front,rear;
}SeQueue;
void Init_Queue(SeQueue *S)
{
    S->front=MAXSIZE -1;
    S->rear=MAXSIZE -1;
}
int IsEmpty_Queue(SeQueue *S)
{
    if(S->front == S->rear)
    {
        S->front = S->rear = MAXSIZE-1;
        return 1;
    }
    return 0;
}
int IsFull_Queue(SeQueue *S)
{
    if((S->rear+1) %MAXSIZE ==S->front)
    {
        return 1;
    }
    return 0;
}
int Push_Queue(SeQueue *S,Elemtype x)
{
    if(!IsFull_Queue(S))
    {
        S->rear=(S->rear+1)%MAXSIZE; 
        S->data[S->rear]=x;
        return 1;
    }
    printf("队满了\n");
    return 0;
}
int Pop_Queue(SeQueue *S,Elemtype *x)
{
    if(!IsEmpty_Queue(S))
    {
        S->front=(S->front+1)%MAXSIZE;
        *x=S->data[(S->front)];
        return 1;
    }
    return 0;
}
void  main()
{
    SeQueue S;
    Init_Queue(&S);
    int choice,x;
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
            printf("请输入入队元素:");
            scanf("%d",&x);
            Push_Queue(&S,x);
            break;
        case 2:
            printf("出队元素为:");
            if(Pop_Queue(&S,&x))
            {
                printf("%d\n",x);
            }
            else
            {
                printf("队为空!\n");
            }
        break;
    
        }  
    }
}
