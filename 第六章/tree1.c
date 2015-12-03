/*************************************************************************
	> File Name: tree1.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年10月27日 21时54分51秒 CST
 ************************************************************************/

#include<stdio.h>

#include<malloc.h>
 
//定义节点 
typedef struct BiNode{
        char data;
        struct BiNode *lch;
        struct BiNode *rch;
}BiNode,*BiTree;
 
//先序拓展序列建立二叉树 
void Create(BiTree &T)
{
        T =(BiNode*) malloc (sizeof(BiNode));
         
        printf("Enter the data \n");
        scanf(" %c",&T->data);
        if(T->data=='#') T = NULL;
        if(T){
                printf("");
                Create(T->lch);
                Create(T->rch);
        }
}
 
//先序遍历 (递归)
void Preorder (BiTree T)
{                    
   if (T) {
      printf(" %c",T->data);             // 访问根结点
       
      Preorder(T->lch); // 遍历左子树
      Preorder(T->rch);// 遍历右子树
   }
}
 
//中序遍历 （递归）
void Inorder (BiTree T)
{
     if(T) {
       Inorder(T->lch);
        
       printf(" %c",T->data);
        
       Inorder(T->rch);    
       }
} 
 
//后序遍历 （递归）
void Postorder (BiTree T)
{
     if(T) {
       Postorder(T->lch);
       Postorder(T->rch);
        
       printf(" %c",T->data); 
     }
} 
 
int main()
{
    //建树 
    printf("The fuction Create() is called.\n");
    BiTree T;
    Create(T);
     
    //三种遍历递归算法 
    printf("\n");    
    printf("The fuction Preorder() is called.\n");
    Preorder(T);
     
    printf("\n");
    printf("The fuction Inorder() is called.\n");
    Inorder(T);
     
    printf("\n");
    printf("The fuction Postorder() is called.\n");
    Postorder(T);
     
     
    printf("\n");
     
}
