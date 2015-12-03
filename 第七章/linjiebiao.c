/*************************************************************************
	> File Name: linjiebiao.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月26日 星期四 22时38分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAXVEX  20
typedef struct Stack
{
    int data;
    struct Stack *next;
}LinkStack;
typedef struct Queue
{
    int data;
    struct Queue *next;
}LNode;
typedef struct
{
    LNode *front;
    LNode *rear;
}LinkQueue;
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VertexNode
{
    char vexdata;
    ArcNode *head;
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;  //顶点数　
    int arcnum;  //边数
}AdjList;
/********************************栈的操作******************************************/
LinkStack *Init_LinkStack(LinkStack *T)
{
    T=(LinkStack *)malloc(sizeof(LinkStack));
    T->next=NULL;
    return T;
}
int IsEmpty_LinkStack(LinkStack *T)
{
    if(T->next!=NULL){
        return 0;
    }
    return 1;
}
LinkStack* Push_LinkStack(LinkStack *T,int t)
{
    LinkStack *s=(LinkStack *)malloc(sizeof(LinkStack));
    if(s==NULL){
        return NULL;
    }
    s->data=t;
    s->next=T->next;
    T->next=s;
}
LinkStack *Pop_LinkStack(LinkStack *T,int *t)
{
    LinkStack *p=T->next;
    if(T->next==NULL){
        return NULL;
    }
    *t=p->data;
    T->next=p->next;
    free(p);
}
/*************************队列的操作****************************/
LinkQueue *Init_LinkQueue()
{
    LinkQueue *q=(LinkQueue *)malloc(sizeof(LinkQueue));
    LNode *p=(LNode *)malloc(sizeof(LNode));
    p->next=NULL;
    q->front=q->rear=p;
    return q;
}
int IsEmpty_LinkQueue(LinkQueue *q)
{
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}
void EnterQueue(LinkQueue *q,int t)
{
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=t;
    s->next=NULL;
    q->rear->next=s;
    q->rear=s;
}
int OutQueue(LinkQueue *q,int *t)
{
    LNode *p;
    if(IsEmpty_LinkQueue(q)){
        printf("the Queue is Empty!\n");
        return 0;
    }else{
        p=q->front->next;
        *t=p->data;
        q->front->next=p->next;
        free(p);
        if(q->front->next==NULL){
            q->rear=q->front;
        }
        return 1;
    }
}
VertexNode *Insert(VertexNode *h,ArcNode *p) //此函数的意义是把每个链表根据adjvex的按从小到大的顺序排列;
{
     ArcNode *pre,*cur,*q;
    cur=h->head;
    if(cur == NULL){
        p->next=cur;
       cur->next=p;
    
    }else{
        pre =h->head;
        q=h->head->next;
        while(q){
            if(p->adjvex < q->adjvex ){
                p->next=q;
                pre->next=p;
                break;
            }
            pre = q;
            q=q->next;
        }
        if(q == NULL){  //当新的节点比当前链表中的所有的adjvex都大时，直接插在链表的最后面.
            p->next==NULL;
            pre->next = p;
        }
    }
    return h;
    
}
AdjList *Created_Graph(AdjList *G)
{
    int i,j,k,n1,n2;
    ArcNode *s;
    char vex1,vex2;
    G=(AdjList *)malloc(sizeof(AdjList));
    printf("请输入顶点的个数和边数:");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("请输入顶点:\n");
    for(i=1;i<=G->vexnum;i++)
    {
        printf("No.%d号顶点的值:",i);
        scanf(" %c",&G->vertex[i].vexdata);
        G->vertex[i].head=(ArcNode *)malloc(sizeof(ArcNode)); //为每个头节点开辟空间;有头节点的链表;
        G->vertex[i].head->next=NULL;   //头节点指向为空;
    }
    printf("请输入由两个顶点构成的边:");
    for(k=1;k<=G->arcnum;k++){
        scanf(" %c%c",&vex1,&vex2);
        for(i=1;i<=G->vexnum;i++){
            if(G->vertex[i].vexdata == vex1){  
                n1=i;
            }
            if(G->vertex[i].vexdata == vex2){
                n2=i;
            }
        }
        s=(ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = n2;
        Insert(&G->vertex[n1],s);
        /*如果是有向图，则下面的语句去掉就行*/
         s=(ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = n1;
        Insert(&G->vertex[n2],s);
    }
    return G;
}
int visited[MAXVEX]={0};
void dfs(AdjList *G,int i)
{
  ArcNode *p;
  printf("%c ",G->vertex[i].vexdata);
  visited[i]=1;
  p=G->vertex[i].head->next; 
    while(p){
        if(visited[p->adjvex]==0){
            dfs(G,p->adjvex);
        }
        p=p->next;
    }
}
void trans_dfs(AdjList *G)
{
    int v;
    for(v=1;v<=G->vexnum;v++){
        visited[v]=0;
    }
    for(v=1;v<=G->vexnum;v++){   
        if(visited[v]==0){
            dfs(G,v);      //当图只有一个连通分量时，此句只会执行一次;
        }
    }
}
void undfs(AdjList *G,int vo)
{
    LinkStack *T;
    ArcNode *p;
    T=Init_LinkStack(T);
    int visited[MAXVEX]={0},i, t;
    Push_LinkStack(T,vo);
    while(!IsEmpty_LinkStack(T)){
        Pop_LinkStack(T,&t);
        if(visited[t]==0){
            printf("%c ",G->vertex[t].vexdata);
            visited[t]=1;
        }
        p=G->vertex[t].head->next;
        while(p){
            if(visited[p->adjvex] == 0){
                printf("%c ",G->vertex[p->adjvex].vexdata);
                visited[p->adjvex]=1;
                Push_LinkStack(T,p->adjvex);
                p=G->vertex[p->adjvex].head->next;
            }else{
            p=p->next;
            }
    }
}
    //for(i=1;i<=G->vexnum;i++){}
}
void bfs(AdjList *G,int v)
{
    int i,t;
    ArcNode *p;
    LinkQueue *S=Init_LinkQueue();
    for(i=1;i<=G->vexnum;i++)
    {
        visited[i]=0;
    }
    visited[v]=1;
    printf("%c ",G->vertex[v].vexdata);
    EnterQueue(S,v);
    while(!IsEmpty_LinkQueue(S)){
        OutQueue(S,&t);
        p=G->vertex[t].head->next;
        while(p){
            if(visited[p->adjvex]==0){
                printf("%c ",G->vertex[p->adjvex].vexdata);
                visited[p->adjvex]=1;
                EnterQueue(S,p->adjvex);
            }
            p=p->next;
        }
    }
}
void  print(AdjList *G)
{
    ArcNode *p;
    int i;
    for(i=1;i<=G->vexnum;i++){
        printf(" %c:",G->vertex[i].vexdata);
        p=G->vertex[i].head->next;
        while(p)
        {
            printf("%d ",p->adjvex);
            p=p->next;
        }
        printf("\n");
    }
}
int main(int argc,char *argv[])
{
    AdjList *G;
    G=Created_Graph(G);
    print(G);
    printf("**************dfs递归遍历*****************************\n");
    dfs(G,1);
    printf("\n");
    printf("*************dfs递归遍历多个连通分量********************\n");
    trans_dfs(G);
    printf("\n");
    printf("*******************dfs非递归遍历*************************\n");
    undfs(G,1);
    printf("\n");
    printf("*********************bfs遍历****************************\n");
    bfs(G,1);
    printf("\n");
    return 0;
}
