/*************************************************************************
	> File Name: tree4.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月17日 星期二 21时11分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct CSNode
{
    char data;
    struct CSNode *FristChild;
    struct CSNode *NextSibling;
}CSNode,*CSTree;
CSTree Created(CSTree root)
{
    int ch;
    ch=getchar();
    if(ch == '#')
    {
        return NULL;
    }
    else
    {
        root=(CSTree)malloc(sizeof(CSNode));
        root->data=ch;
        root->FristChild=Created(root->FristChild);
        root->NextSibling=Created(root->NextSibling);
        return root;
    }
}

void RootFrist(CSTree root)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        CSTree p=root->FristChild;
        while(p!=NULL)
        {
            RootFrist(p);
            p=p->NextSibling;
        }
    }
}
void RootFrist1(CSTree root)
{
    if(root != NULL)
    {
        printf("%c",root->data);
        RootFrist1(root->FristChild);
        RootFrist1(root->NextSibling);
    }
}
int main()
{
    CSTree root;
    root=Created(root);
   // printf("%c",root->data);
    RootFrist(root);
    printf("\n");
    RootFrist1(root);
}
