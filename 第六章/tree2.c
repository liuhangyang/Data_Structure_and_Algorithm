/*************************************************************************
	> File Name: tree2.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月02日 星期一 20时20分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define N 100
#define LEN  sizeof(struct stacknode)
typedef  char ElemType;
/**************树的结构体*********************/
typedef struct treenode
{
    char data;
    struct treenode *lChild,*rChild;
}BiTNode,*BiTree;
/********************栈的结构体*******************/
typedef struct stacknode
{
    BiTree data;
    struct stacknode *next;
}linkStack;
/******************队列的结构体*****************/
typedef struct queuenode
{
    BiTree data;
    struct queuenode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LQueue;
/*****************栈的基本操作*****************/
linkStack *Init_SeqSatck(linkStack *top)
{
    top=(linkStack *)malloc(sizeof(LEN));
    top->next=NULL;
    return top;
}
int IsEmpty_SeqStack(linkStack *top)
{
    if(top->next == NULL)
    {
        return 1;
    }
    return 0;
}
int Push_SeqSatck(linkStack *top,BiTree data)
{
    linkStack *s=(linkStack *)malloc(LEN);
    if(s==NULL)
    {
        return 0;    
    }
    s->data=data;
    s->next=top->next;
    top->next=s;
    return 1;
}
int Pop_SeqStack(linkStack *top,BiTree *data)
{
    linkStack *s;
    if(top->next == NULL)
    {
        return 0;
    }
    s=top->next;
    *data=s->data;
    top->next=s->next;
    free(s);
    return 1;
}
int GetTop_SeqSatck(linkStack *top,BiTree *data)
{
    if(top->next == NULL)
    {
        return 0;
    }
    *data=top->next->data;
    return 1;
}
/**********************队列的基本操作*********************/
LQueue *Init_SeqQueue()
{
    LQueue *p;
    QNode *q;
    p=(LQueue *)malloc(sizeof(LQueue));
    q=(QNode *)malloc(sizeof(QNode));
    q->next=NULL;
    p->front=p->rear=q;
    return p;
}
int InLqueue(LQueue *p,BiTree data)
{
    QNode *s=(QNode *)malloc(sizeof(QNode));
    if(s == NULL)
    {
        return 0;
    }
    s->data=data;
    s->next=NULL;
    p->rear->next=s;
    p->rear=s;
    return 1;
}
int IsEmpty_Queue(LQueue *p)
{
    if(p->front == p->rear)
    {
        return 1;
    }
    return 0;
}
int Outqueue(LQueue *p,BiTree *data)
{
    QNode *s;
    if(IsEmpty_Queue(p))
    {
        printf("队为空!\n");
        return 0;
    }
    else
    {
        s=p->front->next;
        p->front->next=s->next;
        *data=s->data;
        free(s);
        if(p->front->next == NULL)
        {
            p->rear = p->front;
        }
        return 1;
    }
}
/***************递归返回值创建二叉树******************/
BiTree creatTree(BiTree root)
{
    char data;
   // data=getchar();
    scanf("%c",&data);
    if(data == '#')
    {
        return NULL; 
    }
    else
    {
        root=(BiTree)malloc(sizeof(BiTNode));
        root->data=data;
        root->lChild=creatTree(root->lChild);
        root->rChild=creatTree(root->rChild);
    }
    return root;    /*这里一定要返回root,因为传递的BiTNode型的指针，于是在函数中会生成一个形参也指向这个结构体,但在函数中root=(BiTree)malloc(sizeof(BiTNode));改变了形参的指向,所以形参不论怎么变化，都不会影响实参中指针的指向*/
}
/**************递归二级指针创建二叉树*****************/
void createTree1(BiTree *root)
{
    char data;
    data=getchar();
    //scanf("%c",&data);
    if(data == '#')
    {
        (*root)=NULL;
    }
    else
    {
        //printf("%c ",data);
        (*root)=(BiTree)malloc(sizeof(BiTNode));
        (*root)->data=data;
        createTree1(&(*root)->lChild);
        createTree1(&(*root)->rChild);
    }
}
/******************递归先序遍历*******************/
void PreOrder(BiTree root)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        PreOrder(root->lChild);
        PreOrder(root->rChild);
    }
}
/******************递归中序遍历****************/
void InOrder(BiTree root)
{
    if(root!=NULL)
    {
        InOrder(root->lChild);
        printf("%c ",root->data);
        InOrder(root->rChild);
    }
}
/**********************递归后序遍历***************************/
void PostOrder(BiTree root)
{
    if(root!=NULL)
    {
        PostOrder(root->lChild);
        PostOrder(root->rChild);
        printf("%c ",root->data);
    }
}
/*******************递归求二叉树的节点数******************/
int count=0;
int InOrder_count(BiTree root)
{
    if(root!=NULL)
    {
        InOrder_count(root->lChild);
        count++;
        InOrder_count(root->rChild);
    }
    return count;
}
/******************递归求二叉树的深度1*********************/
int depth=0;
int PostOrderDepth(BiTree T,int h)
{
    if(T)
    {
        if(h>depth)
        {
            depth=h;
        }
        PostOrderDepth(T->lChild,h+1);
        PostOrderDepth(T->rChild,h+1);
    }
}
/****************递归求二叉树的深度2**********************/
int PostOrderDepth1(BiTree T)
{
    int hl,hr;
    if(T)
    {
        hl=PostOrderDepth1(T->lChild);
        hr=PostOrderDepth1(T->rChild);
        return (hl>hr?hl:hr)+1;
    }
}
/*****************归求二叉树的叶子节点及其个数******************/
int leafcount=0;
int InOrder_leafcount(BiTree root)
{
    if(root!=NULL)
    {
        InOrder_leafcount(root->lChild);
        if(root->lChild == NULL && root->rChild == NULL)
        {
            printf("%c ",root->data);
            leafcount++;
        }
        InOrder_leafcount(root->rChild);
    }
    return leafcount;
}
/*****************递归求二叉树的双亲节点**********************/
BiTree Current(BiTree root,char data,BiTree *cur)
{
    if(root)
    {
        if(root->data == data)
        {
            *cur=root;
        }
        Current(root->lChild,data,cur);
        Current(root->rChild,data,cur);
    }
}
BiTree parent(BiTree root,BiTree cur,BiTree *par)
{
    if(root)
    {
        if(root->lChild == cur || root->rChild == cur)
        {
            *par=root;
            //printf("%c\n",root->data);
        }
        parent(root->lChild,cur,par);
        parent(root->rChild,cur,par);
    }
}
void tupletree(BiTree root,int h)
{
    if(root!=NULL)
    {
        printf("(%c,%d)",root->data,h);
        tupletree(root->lChild,h+1);
        tupletree(root->rChild,h+1);
    }

}
/*******************递归打印二叉树***************/
void printTree(BiTree root,int h)
{
    int i;
    if(root)
    {
        printTree(root->rChild,h+1);
        for(i=0;i<h;i++)
        {
            printf("      ");
        }
        printf("%c\n",root->data);
        printTree(root->lChild,h+1);
    }
}
/*************************输出从树的根到每个叶子节点的路径********************/
int top=0;
char str[N];
void Allpath(BiTree root)
{
    int i;
    if(root)
    {
        top++;
        str[top]=root->data;
        if(root->lChild == NULL && root->rChild == NULL)
        {
            printf("%c:",str[top]);
            for(i=1;i<top;i++)
            {
                printf("%c ",str[i]);
            }
            printf("\n");
        }
        else
        {
            
            Allpath(root->lChild);
            Allpath(root->rChild);
        }
        //printf("p:%c ",str[top]);
        top--;
    }
    }
/**************在以孩子兄弟二叉链表中，求树或森林的高度************************/
int depth1=0;
int BiTreeDepth(BiTree root,int h)
{
    
    if(root)
    {
      if(h>depth1)
        {
            depth1=h;
        }
        BiTreeDepth(root->lChild,h+1);
        BiTreeDepth(root->rChild,h);
    }
}


/*************************************************非递归创建二叉树1***************************************/

BiTree creatTree1()
{
    BiTree stack[N],root,newnode,t,m;
    char data[N],*p;
    int flag=0,top=0;
    scanf("%s",data);
    p=data;
    newnode=(BiTree)malloc(sizeof(BiTNode));
    if(newnode == NULL)
    {
        return;
    }
    newnode->data=*p;
    p++;
    newnode->lChild = NULL;
    newnode->rChild = NULL;
    stack[top++]=newnode;root=newnode;
    while(*p!='\0')
    {
        if(*p == '#' && flag == 0)
        {
            flag=1;
        }
        else if(*p == '#' && flag == 1)
        {
            t=stack[--top];
            while(stack[top-1]->rChild == t)
            {
                t=stack[--top];
            }
        }
        else
        {
            newnode=(BiTree)malloc(sizeof(BiTNode));
            if(newnode == NULL)
            {
                return;
            }
            newnode->data=*p;
            if(flag == 0)
            {
                stack[top-1]->lChild=newnode;
                stack[top++]=newnode;
            }
            else
            {
                stack[top-1]->rChild=newnode;
                flag=0;
                stack[top++]=newnode;
            }

        }
        p++;
    }
    return root;
}
/******************************非递归先序遍历*****************************/
void PreOrder1(BiTree root)
{
   linkStack *S;
    S=Init_SeqSatck(S);//复杂度为O(m）。
    BiTree p=root;
    while(p !=NULL || !IsEmpty_SeqStack(S))
    {
        if(p!=NULL)
        {
            printf("%c ",p->data);
            Push_SeqSatck(S,p);
            p=p->lChild;
        }
        else
        {
            Pop_SeqStack(S,&p);
            p=p->rChild;
        }
    }

}
/****************************非递归中序遍历*****************************/
void InOrder1(BiTree root)
{
    linkStack *S;
    S=Init_SeqSatck(S);
    BiTree p=root;
    while(p != NULL || !IsEmpty_SeqStack(S))
    {
        if(p!=NULL)
        {
            Push_SeqSatck(S,p);
            p=p->lChild;
        }
        else
        {
            Pop_SeqStack(S,&p);
            printf("%c ",p->data);
            p=p->rChild;
        }
    }
}
/***********************非递归后续遍历**************************/
void PostOrder1(BiTree root)
{
    linkStack *S;
    S=Init_SeqSatck(S);
    BiTree p=root,q=NULL;
    while(p!=NULL || !IsEmpty_SeqStack(S))
    {
        if(p!=NULL)
        {
            Push_SeqSatck(S,p);
            p=p->lChild;
        }
        else
        {
            GetTop_SeqSatck(S,&p);
            if(p->rChild == NULL || p->rChild == q)
            {
                Pop_SeqStack(S,&p);
                printf("%c ",p->data);
                q=p;
                p=NULL;
            }
              else
            {
                p=p->rChild;
            }
        }
    }
}
/***********************非递归正向打印二叉树************************/

/***********************非递归层次遍历二叉树******mZ*****************/
void levelTree(BiTree root)
{
    LQueue *S;
    BiTree p;
    S=Init_SeqQueue(S);
    InLqueue(S,root);
    while(!IsEmpty_Queue(S))
    {
        Outqueue(S,&p);
        printf("%c ",p->data);
        if(p->lChild!=NULL)
        {
            InLqueue(S,p->lChild);
        }
        if(p->rChild!=NULL)
        {
            InLqueue(S,p->rChild);
        }   
    }
}
/***********************************递归树的恢复先序和中序*******************************/
BiTree recoverTree(BiTree *root,char *preroot,char *midroot,int lm,int rm,int lp,int rp) 
{
   // printf("%c\n",preroot[4]);
    (*root)=(BiTree)malloc(sizeof(BiTNode));
    (*root)->data=preroot[lp];
    (*root)->lChild=NULL;
    (*root)->rChild=NULL;
    int pos=lm;
    while(midroot[pos] != preroot[lp])
    {
        pos++;
    }
    int leftChild=pos-lm;
    if(pos > lm)
    {
        recoverTree(&((*root)->lChild),preroot,midroot,lm,pos-1,lp+1,lp+leftChild);
    }
    if(pos < rm)
    {
        recoverTree(&((*root)->rChild),preroot,midroot,pos+1,rm,lp+leftChild+1,rp);
    }
}
/*************************************递归树的恢复中序和后序******************************/
/*BiTree recoverTree1(BiTree *root,char *postroot,char *midroot,int lm,int rm,int lp,int rp)
{
    (*root)=(BiTree)malloc(sizeof(BiTNode));
    (*root)->data=postroot[rp];
    (*root)->lChild=NULL;
    (*root)->rChild=NULL;
    int pos=rm;
    while(midroot[pos] != postroot[rp])
    {
        pos--;
    }
    int rightChild =rm-pos;
    if(pos < rm)
    {
        recoverTree1(&((*root)->rChild),postroot,midroot,rm, pos+1,rp-1,rp-rightChild);
    }
    if(pos > lm)
    {
        recoverTree1(&((*root)->lChild),postroot,midroot,pos-1,lm,rp-rightChild-1,lp);
    }
        
}*/
int main()
{
    BiTree root;
    int count,leafcount;
   // root=creatTree1();
    char post[5]={"ABDCE"};
    char mid[5]={"BDAEC"};
    recoverTree(&root,post,mid,0,4,0,4);
    printf("**************递归先序遍历**************\n");
    PreOrder(root);
    printf("\n");
    printf("*************递归中序遍历***************\n");
    InOrder(root);
    printf("\n");
    printf("**************递归后序遍历************\n");
    PostOrder(root);
    printf("\n");
    tupletree(root,1);
    printf("**********递归求二叉树的节点数******************\n");
    count=InOrder_count(root);
    printf("二叉树的总结点数为:%d\n",count);
    printf("*********二叉树的叶子节点***********************\n");
    leafcount=InOrder_leafcount(root);
    printf("\n");
    printf("二叉树的叶子总数为:%d\n",leafcount);
    printf("*******************二叉树的深度1******************\n");
    PostOrderDepth(root,1);
    printf("二叉树的深度:%d\n",depth);
    printf("******************二叉树的深度2*******************\n");
    count=PostOrderDepth1(root);
    printf("二叉树的深度:%d\n",count);
    printf("******************二叉树的双亲节点*****************\n");
    BiTree cur,par;
    Current(root,'D',&cur);
    printf("当前的节点为:%c\n",cur->data);
    parent(root,cur,&par);
    printf("双亲节点为:%c\n",par->data);
    printf("************************遍历路径***********************\n");
    Allpath(root);动4位
    printf("*********************孩子兄弟表示法求树的高度****************\n");
    BiTreeDepth(root,1);
    printf("树的高度:%d",depth1);
    printf("二叉树的递归横向打印\n");
    printTree(root,1);
    printf("********************非递归先序遍历二叉树****************\n");
    PreOrder1(root);
    printf("\n");
    printf("********************非递归中序遍历二叉树***************\n");
    InOrder1(root);
    printf("\n");
    printf("********************非递归后序遍历二叉树****************\n");
    PostOrder1(root);
    printf("\n");
    printf("********************非递归层次遍历二叉树****************\n");
    levelTree(root);
    printf("\n");
}
