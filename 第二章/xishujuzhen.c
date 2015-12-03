/*************************************************************************
	> File Name: xishujuzhen.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月19日 星期四 19时52分12秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
typedef int ElementType;
#define MAXSIZE 1000
typedef struct 
{
    int row,col;
    ElementType value;
}Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int rows,cols,nums;
}TSMatrix; 
TSMatrix* Created(TSMatrix *T,int s[][MAXSIZE],int row,int col)
{
    int i,j,t=0;
    T=(TSMatrix *)malloc(sizeof(TSMatrix));
    T->rows=row;
    T->cols=col;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            if(s[i][j]!=0)
            {
                t++;
                T->data[t].row=i;
                T->data[t].col=j;
                T->data[t].value=s[i][j];
            }
        }
    }
    T->nums=t;
    return T;
}
void print(TSMatrix *T)
{
    int i;
    printf("rows\t\tcol\t\tvalue\n");
    for(i=1;i<=T->nums;i++)
    {
        printf("%d\t\t%d\t\t%d\n",T->data[i].row,T->data[i].col,T->data[i].value);
    }
}
TSMatrix *Trans(TSMatrix *T,TSMatrix *S)
{
    int nums[MAXSIZE],postion[MAXSIZE];
    int col,p,t,q;
    S=(TSMatrix *)malloc(sizeof(TSMatrix));
    S->rows=T->cols;
    S->cols=T->rows;
    S->nums=T->nums;
    if(S->nums)
    {
        for(col=1;col<=T->cols;col++)
        {
            nums[col]=0;
        }
        for(t=1;t<=T->nums;t++)
        {
            nums[T->data[t].col]++;
        }
        postion[1]=1;
        for(col=2;col<=T->cols;col++)
        {
            postion[col]=postion[col-1]+nums[col-1];
        }
        for(p=1;p<=T->nums;p++)
        {
            col=T->data[p].col;
            q=postion[col];
            S->data[q].row=T->data[p].col;
            S->data[q].col=T->data[p].row;
            S->data[q].value=T->data[p].value;
            postion[col]++;

        }
    }
    return S;

}
int main()
{
    TSMatrix *T,*S;
    int row,col,i,j,s[MAXSIZE][MAXSIZE];
    printf("请输入矩阵的行和列:");
    scanf("%d%d",&row,&col);
    printf("请输入矩阵:\n");
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    T=Created(T,s,row,col);
    print(T);
    S=Trans(T,S);
    printf("转置后的稀疏表为:\n");
    print(S);
    

}
