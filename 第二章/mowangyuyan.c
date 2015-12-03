/*************************************************************************
	> File Name: mowangyuyan.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月24日 星期四 00时39分58秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef int Status;
typedef char ElemType;
typedef struct Stacknode
{
    ElemType data;
    struct Stacknode *next;
}SeqStack;
typedef struct Queuenode
{
    ElemType data;
    struct Queuenode *next;
}Qnode;
typedef struct 
{
    Qnode *front;
    Qnode *rear;
}LQueue;
struct des_word
{
    ElemType ch;
    ElemType *word;
}chap[]={
            {'t',"天"},
            {'d',"地"},
            {'s',"上"},
            {'a',"一只"},
            {'e',"鹅"},
            {'z',"追"},
            {'g',"赶"},
            {'x',"下"},
            {'n',"蛋"},
            {'h',"恨"}
};
/******************栈***************************/
SeqStack* Init_SeqStack(SeqStack *S)
{
    S=(SeqStack *)malloc(sizeof(SeqStack));
    S->next=NULL;
    return S;
}
Status IsEmpty_SeqStack(SeqStack *S)
{
    if(S->next == NULL)
    {
        return 1;
    }
    return 0;
}
Status Push_SeqStack(SeqStack *S,ElemType x)
{
    SeqStack *p;
    p=(SeqStack *)malloc(sizeof(SeqStack));
    if(p==NULL)
    {
        printf("内存分配失败!\n");
        return 0;
    }
    p->data=x;
    p->next=S->next;
    S->next=p;
    return 1;
}
char Get_SeqStack(SeqStack *S)
{
    if(!IsEmpty_SeqStack(S))
    {
        SeqStack *p=S->next;
        ElemType x;
        x=p->data;
        return x;
    }
}
char Pop_SeqSatck(SeqStack *S)
{
    if(!IsEmpty_SeqStack(S))
    {
        SeqStack *p=S->next;
        ElemType x;
        x=p->data;
        S->next=p->next;
        free(p);
        return x;
    }
}
/*************************队列************************/
LQueue* Init_Queue(LQueue *T)
{
    Qnode *p;
    T=(LQueue *)malloc(sizeof(LQueue));
    p=(Qnode *)malloc(sizeof(Qnode));
    p->next=NULL;
    T->front=T->rear=p;
    return T;
}
LQueue* Push_SeqQueue(LQueue *T,ElemType x)
{
    Qnode *s;
    s=(Qnode *)malloc(sizeof(Qnode));
    s->data=x;
    s->next=NULL;
    T->rear->next =s;
    T->rear=s;
    return T;
}
Status IsEmpty_Queue(LQueue *T)
{
    if(T->rear == T->front)
    {
        return 1;
    }
    return 0;
}
char Pop_Queue(LQueue *T)
{
    if(!IsEmpty_Queue(T))
    {
        ElemType x;
        Qnode *s;
        s=T->front->next;
        T->front->next=s->next;
        x=s->data;
        if(T->front->next == NULL)
        {
            T->rear=T->front;
        }
        free(s);
        return x;
    }
}
/********************************栈和队列的应用*****************************/
void print_Queue(LQueue *p)
{
    int len=sizeof(chap)/sizeof(chap[0]);
    while(!IsEmpty_Queue(p))
    {
        char x=Pop_Queue(p);
        int i;
        for(i=0;i<len;i++)
        {
            if(x==chap[i].ch)
            {
                printf("%s ",chap[i].word);
            }
        }
    }
    printf("\n");
}
void translate(char str[])
{
    char *p;
    LQueue  *T,*Q;
    SeqStack *S;
    char x;
    T=Init_Queue(T);
    Q=Init_Queue(Q);
    S=Init_SeqStack(S);
    for(p=str;*p!='\0';p++)
    {
        switch(*p)
        {
            case 'A':
                Push_SeqQueue(T,'s');
                Push_SeqQueue(T,'a');
                Push_SeqQueue(T,'e');
                break;
            case 'B':
                Push_SeqQueue(T,'t');
                Push_SeqQueue(T,'A');
                Push_SeqQueue(T,'d');
                Push_SeqQueue(T,'A');
                break;
            case '\n':
                break;
            case '(':
                p++;
                x=*p;
                p++;
                for(p;*p!=')';p++)
                {
                    Push_SeqStack(S,*p);
                }
                while(!IsEmpty_SeqStack(S))
                {
                    Push_SeqQueue(T,x);
                    Push_SeqQueue(T,Pop_SeqSatck(S));
                }
                Push_SeqQueue(T,x);
                break;
            default:
                Push_SeqQueue(T,*p);
                   break;
	}
    }
    //print_Queue(T);
    while(!IsEmpty_Queue(T))
    {
        x=Pop_Queue(T);
        if(x=='A')
        {
            Push_SeqQueue(Q,'s');
            Push_SeqQueue(Q,'a');
            Push_SeqQueue(Q,'e');
        }
        else
        {
            Push_SeqQueue(Q,x);
        }
    }
    print_Queue(Q);
}
void main()
{
    char str[100];
    printf("请输入魔王语言：");
    scanf("%s",str);
    translate(str);
}
