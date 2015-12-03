/*************************************************************************
	> File Name: lingjiejuzhen.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月26日 星期四 22时25分30秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define MAXVEX  20   //最大顶点数
#define INFINITY  32768  //表示极大值
typedef char Vextype;
typedef struct
{
    int arcs[MAXVEX][MAXVEX];
    Vextype vex[MAXVEX];
    int vexnum;
    int arcnum;
    
}AdjMatrix;
AdjMatrix* Created(AdjMatrix *G)
{
    int i,j,k,weight,s1,s2;
    G=(AdjMatrix *)malloc(sizeof(AdjMatrix));
    char vex1,vex2;
    printf("请输入无向网中的顶点数和边数:");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for(i=1;i<=G->vexnum;i++){
        for(j=1;j<G->vexnum;j++){
            G->arcs[i][j]=INFINITY;
        }
    }
    printf("请输入无向网中%d个顶点:",G->vexnum);
    for(i=1;i<=G->vexnum;i++){
        printf("No.%d个顶点:",i);
        scanf(" %c",&G->vex[i]);
    }
    printf("请输入无向网中%d个边数:",G->arcnum);
    for(k=0;k<G->arcnum;k++){
        printf("No.%d个边:",k+1);
        scanf(" %c",&vex1);
        scanf(" %c",&vex2);
        for(i=1;i<=G->vexnum;i++){
            if(G->vex[i] == vex1){
                s1=i;
                break;
            }
        }
        for(j=1;j<=G->vexnum;j++){
            if(G->vex[j] == vex2){
                s2=j;
            }
        }
        printf("请输入权值:");
        scanf("%d",&weight);
        G->arcs[s1][s2]=weight;
        G->arcs[s2][s1]=weight;
    }
    return G;
}
void print(AdjMatrix *G)
{
    int i,j;
    for(i=1;i<=G->vexnum;i++){
        printf(" %c\t",G->vex[i]);
    }
    printf("\n");
    for(i=1;i<=G->vexnum;i++){
        printf("%c:",G->vex[i]);
        for(j=1;j<=G->vexnum;j++){
            printf("%d\t",G->arcs[i][j]);
        }
        printf("\n\n\n");
    }
}
int main(int argc,char *argv[])
{
    AdjMatrix *G;
    G=Created(G);
    print(G);
    return 0;
}
