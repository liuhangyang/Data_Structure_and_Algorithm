/*************************************************************************
	> File Name: migong1.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年10月05日 星期一 08时38分09秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MAX  100
struct  dir
{
    int dx;
    int dy;
}Dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
typedef struct node
{
    int x;
    int y;
}Node;
int maze[N-1][N-1];
Node recod[N-1][N-1],queue[MAX];
void bfs()
{
    int head=0,tail=0,i;
    Node curpos,nextpos;
    curpos.x=1;
    curpos.y=1;
    queue[head].x=1;
    queue[head].y=1;
    tail++;
    while(head < tail)
    {
        curpos = queue[head++];
        for(i=0;i<4;i++)
        {
            nextpos.x=curpos.x+Dir[i].dx;
            nextpos.y=curpos.y+Dir[i].dy;
            if(nextpos.x >= 1 && nextpos.y >= 1 && nextpos.y <= N-2 && nextpos.x <= N-2 && maze[nextpos.x][nextpos.y]==0)
            {
                recod[nextpos.x][nextpos.y].x= curpos.x;
                recod[nextpos.x][nextpos.y].y = curpos.y;
                //printf("(%d,%d)\n",recod[nextpos.x][nextpos.y].x,recod[nextpos.x][nextpos.y].y);
                if(nextpos.x == N-2 && nextpos.y == N-2)
                {
                    return;
                }
                else
                {
                    maze[nextpos.x][nextpos.y]=3;
                    queue[tail++]=nextpos;
                }
            }
        }
        if(head == tail)
        {
            printf("走不通!\n");
            exit(0);
        }

    }
}
void  Initmaze()
{
    int i,j;
    for(i=0;i<=N-1;i++)
    {
        maze[0][i] = maze[N-1][i]=8;
    }
    for(i=0;i<N-1;i++)
    {
        maze[i][0]=maze[i][N-1]=8;
    }
  //  srand((unsigned)time(NULL));
    for(i=1;i<N-1;i++)
    {
        for(j=1;j<N-1;j++)
        {
            //maze[i][j]=rand()%2;
            scanf("%d",&maze[i][j]);
        }
    }
    if(maze[1][1]==1 || maze[N-2][N-2]==1)
    {
        printf("此迷宫出口没有入口或出口");
        exit(0);
    }
}
int main()
{
    int i,j,k,m,n;
    Initmaze();
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%3d",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    bfs();
    k=0;
    queue[k].x=N-2;
    queue[k++].y=N-2;
    i=j=N-2;
    while(i!=1 || j!=1)
    {
        m=i;n=j;
        i=recod[m][n].x;
        j=recod[m][n].y;
        queue[k].x=i;
        queue[k++].y=j;
    }
    for(i=k-1;i>=0;i--)
    {
           maze[queue[i].x][queue[i].y]=5;
    }
    char a='*';
    char b='@';
    char d= '#';
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            switch(maze[i][j])
            {
                case 3:
                     printf("\033[34m%3c\033[0m",b);
                    break;
                case 5:
                    printf("\033[35m%3c\033[0m",a);
                    break;
                case 8:
                    printf("%3c",d);
                    break;
                default:
                    printf("%3d",maze[i][j]);
                    break;
            }
        }
        printf("\n");
    }
}
