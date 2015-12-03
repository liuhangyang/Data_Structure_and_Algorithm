/*************************************************************************
> File Name: tree.c
> AutmZor: yanglongfei
> Mail: yanglongfei@xiyoulinux.org
> Created Time: 2015年10月27日 16时40分17秒 CST
************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char  data;
    struct Node *lChild;
    struct Node *rChild;
}BiTNode,*BiTree;
int CreateBiTree(BiTNode **T)
{
    char  data;
    int i=0;
    scanf("%c",&data);
    if(data == '#')
    { 
        (*T)=NULL;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=data;  //生成根节点
        CreateBiTree(&(*T)->lChild);
        CreateBiTree(&(*T)->rChild);
    }
    return 1;
}
void Visit(BiTree T)
{
    if(T->data != '#')
    {
        printf("%c",T->data);
    }
}
//先序遍历
void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        Visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}
//中序遍历统计节点个数
int count =0;
int InOrder(BiTree T)
{
    if(T!=NULL)
    {   count++;
        InOrder(T->lChild);
        Visit(T);
        InOrder(T->rChild);
    }
    return count;
}
//后序遍历
void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        if(!T->lChild && !T->rChild)
        {
            Visit(T);
        }
    }
}
int leaf(BiTree T)
{
    int nl,nr;
    if(T==NULL)
    {
        return 0;
    }
    if(T->lChild == NULL && T->rChild == NULL)
    {
        return 1;
    }
    nl=leaf(T->lChild);
    nr=leaf(T->rChild);
    return nl+nr;
}
int depth=0;
void TreeDepth(BiTree T,int h)
{
    if(T)
    {
        if(h>depth)
        {
            depth = h;
        }
        TreeDepth(T->lChild,h+1);
        TreeDepth(T->rChild,h+1);
    }
}
int PostTreeDepth(BiTree T)
{
    int hl,hr,h;
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        hl=PostTreeDepth(T->lChild);
        hr=PostTreeDepth(T->rChild);
        return (hl>hr? hl:hr)+1;
    }
}
//求双亲节点
BiTree returncurrent(BiTree T,char data,BiTree *root)
{
    BiTree node;
    if(T==NULL)
    {
	return NULL;	
    }
    else
    {
	
	if(T->data == data )
	{
	   *root=T;
        }
	returncurrent(T->lChild,data,root);
	returncurrent(T->rChild,data,root);
	
    	}    
}
BiTree parent(BiTree T,BiTree current)
{
    //在以root为根的二叉树中找节点current的双亲
    BiTNode *p;
    if(T==NULL)
    {
        return NULL;
    }
    else
    {
	if(T->lChild==current || T->rChild == current)
	{
		printf("T:%p",T);
		return  T;
	}
	parent(T->lChild,current);
	parent(T->rChild,current);
    }

}
//按树状打印二叉树
void PrintTree(BiTree T,int h)
{
    int i;
    if(T==NULL)
    {
        return;
    }
    PrintTree(T->rChild,h+1);
    for(i=0;i<h;i++)
    {
        printf("   ");
    }
    printf("%c\n",T->data);
    PrintTree(T->lChild,h+1);

}
int main()
{
    BiTNode *T;
    int n;
    CreateBiTree(&T);
    /*printf("-----------先序遍历:------------\n");
    PreOrder(T);
    printf("\n");
    printf("-----------中序遍历-------------\n");
    n=InOrder(T);
    printf("\n");
    printf("节点总数:%d\n",n);
    printf("\n");
    printf("-----------后序遍历-------------\n");
    PostOrder(T);
    printf("\n");
    printf("----------叶子总数--------------\n");
    n=leaf(T);
    printf("%d",n);
    *///printf("树的深度:");
    //TreeDepth(T,1);
    //depth=PostTreeDepth(T);
    //printf("%d",depth);
    /*BiTree p,q;
    returncurrent(T,'C',&p);
    printf("current:%c\n",p->data);
    q=parent(T,p); 
    printf("求节点的双亲节点:");
    printf("%p",q);
    printf("q:%c\n",q->data);
    */PrintTree(T,1);
        return 0;
}
