/*************************************************************************
	> File Name: tree3.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月13日 星期五 07时43分04秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define T 65535
#define N 6
#define M 2*N-1
typedef char * Huffcode[M+1];
typedef struct
{
    int weight;
    int parent;
    int Rchild;
    int Lchild;
}HTNode,HuffmanTree[M+1];      /*0号单元不用*/
//结构体数组只能在定义的时候的初始化
void Select(HuffmanTree ht,int *fm,int *sm,int n)
{
    int fmin=T;
    int i;
    int smin=T;
    for(i=1;i<=n;i++)
    {
        if(ht[i].parent == 0)
        {
            if(ht[i].weight < fmin)
            {
                smin=fmin;
                *sm=*fm;
                fmin=ht[i].weight;
                *fm=i;
            }
            else if(ht[i].weight>=fmin && ht[i].weight < smin)
            {
                smin=ht[i].weight;
                *sm=i;
            }
        }
   }
    

}
void CriHuffmanTree(HuffmanTree ht,Huffcode hc,int *w,int n)
{
    int m=2*n-1,i;
    char *code;
    int s1,s2,c,p;
    int start;
    for(i=1;i<=n;i++)
    {
        ht[i].weight=w[i];
        ht[i].parent=0;
        ht[i].Rchild=0;
        ht[i].Lchild=0;

    }
    for(i=n+1;i<=m;i++)
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].Rchild=0;
        ht[i].Lchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        Select(ht,&s1,&s2,i-1);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[i].Lchild=s1;
        ht[i].Rchild=s2;
        ht[s1].parent=i;
        ht[s2].parent=i;
    } 
 //   hc=(char **)malloc(n*sizeof(char *));
    code=(char *)malloc(n*sizeof(char));
    code[n-1]='\0';
    for(i=1;i<=n;i++)
    {
        start=n-1;
        c=i;
        p=ht[i].parent;
        while(p!=0)
        {
            --start;
            if(ht[p].Lchild == c)
            {
                code[start]='0';
            }
            else
            {
                code[start]='1';
            }
            c=p;
            p=ht[p].parent;
        }
        hc[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy(hc[i],&code[start]);
    }
    free(code);
}
void print(HuffmanTree hc,int n)
{
    int i;
    printf("Weight\t\tParent\t\tLchild\t\tRchild\n");
    for(i=1;i<=2*n-1;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n",hc[i].weight,hc[i].parent,hc[i].Rchild,hc[i].Lchild);   
    }
    printf("\n");
}
int main()
{
    int i,j;
    char key[N]={'0','A','B','C','D','E'},m[N];
    int w[N]={0,1,2,6,7,8};
    HuffmanTree ht;
    Huffcode hc;
    CriHuffmanTree(ht,hc,w,N-1);
    print(ht,N-1);
    for(i=1;i<N;i++)
    {
        printf("%c:%s\n",key[i],hc[i]);
    }
    printf("\n");
    printf("请输入要编码的字符串:");
    scanf("%s",m);
    for(i=0;i<strlen(m);i++)
    {
        for(j=1;j<N;j++)
        {
            if(m[i] == key[j])
            {
                printf("%c:%s\n",key[i],hc[j]);
            }
        }
    }
}
