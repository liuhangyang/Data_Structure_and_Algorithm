/*************************************************************************
	> File Name: mataqipan1.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年10月02日 星期五 09时32分54秒
 *************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define  STACK_INIT_SIZE  100
#define  STACKINCREMENT  10
#define N 8
#define  CLOCK_PER_SEC ((clock_t)1000)
clock_t begin, end;
double cost;
typedef struct //记录坐标位置
{
    int x;
    int y;
}PosType;
typedef  struct  
{
    PosType seat;
    int dir;
}SElemType;
typedef struct 
{
    SElemType  *base;
    SElemType  *top;
    int length;
}SqStack;
int Init1[N][N]={{0}};
int Init2[N][N] ={
    {2,3,4,4,4,4,3,2},
    {3,4,6,6,6,6,4,3},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {4,6,8,8,8,8,6,4},
    {3,4,6,6,6,6,4,3},
    {2,3,4,4,4,4,3,2},
};       
int Hx[N] = {-2,-1,1,2,2,1,-1,-2};
int Hy[N] = {1,2,2,1,-1,-2,-2,-1};
SqStack* InitStack(SqStack *s)
{
    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(s->base == NULL)
    {
        return NULL;
    }
    s->top = s->base;
    s->length =STACK_INIT_SIZE;
    return s;
}
int Push_Stack(SqStack *s,SElemType e)
{
    if(s->top - s->base >= s->length)
    {
        s->base = (SElemType *)realloc(s->base,(STACK_INIT_SIZE + STACKINCREMENT)*sizeof(SElemType));
        if(s->base == NULL)
        {
            return 0;
        }
        s->top = s->base + s->length;
        s->length += STACKINCREMENT;
    }
    *s->top++ = e;
    return 1;
}
int Pop_Stack(SqStack *s,SElemType *e)
{
    if(s->top == s->base)
    {
        return 0;
    }
    *e = *--s->top;
    return 1;
}
int IsEmpty_Stack(SqStack *s)
{
    if(s->top == s->base)
    {
        return 1;
    }
    return 0;
}
void print()
{
    int i,j;
	for(i = 0; i < 8; i++)  
    {
			for(j = 0; j < 8; j++)
            {
				printf("%-5d",Init1[i][j]);
            }
			printf("\n"); printf("\n");
	}
	printf("\n");
	//getchar();
}  
void MarkPrint(PosType pos)
{
	Init1[pos.x][pos.y] = 0;
}
PosType NextPos(PosType curpos,int t)
{ 
	PosType MinCurpos,temp;

	MinCurpos.x = -1;
	MinCurpos.y = -1;//初始化最小位
	for(;t < 8; t++) 
    {
		temp.x = curpos.x + Hx[t];
		temp.y = curpos.y + Hy[t];
        if(temp.x < 0 || temp.x > 7 || temp.y < 0 || temp.y > 7 || Init1[temp.x][temp.y]) 
        {
            continue;
        }
		if(MinCurpos.x == -1 && MinCurpos.y == -1)
			MinCurpos = temp;
		else if(Init2[MinCurpos.x][MinCurpos.y] > Init2[ temp.x][temp.y] )
			MinCurpos= temp;
	}
	if(MinCurpos.x == -1 && MinCurpos.y == -1)
			return curpos;
	return MinCurpos;
}
void FootPrint(PosType curpos,int curstep) 
{
	Init1[curpos.x][curpos.y] = curstep;
}

int Pass(PosType curpos)
{
	if(!Init1[curpos.x][curpos.y])
		return 1;
	else return 0;
}
void DestroyStack(SqStack *s)
{
    s->base = s->top;
    s->length = 0;
}
int main()
{

    begin = clock();
    int i=1;
    SqStack *s=(SqStack *)malloc(sizeof(SqStack));
    SElemType  e,m;
    PosType Mincurpos,curpos,start;
    int curstep;
    s=InitStack(s);
    printf("请输入初始坐标:(0-7)");
     scanf("%d%d",&start.x,&start.y);
    printf("\n\n");
    if(start.x <0 || start.x>7 || start.y<0 || start.y > 7)
    {
        printf("输入的初始位置有误!\n");
        return 0;
    }
    curpos = start;
    curstep =1;
    //int i=0;
    do{
        if(Pass(curpos)){
            FootPrint(curpos,curstep);
            e.dir = 0;
            e.seat = curpos;
            Push_Stack(s,e);
            //printf("%d\n",i++);
            // print();
             //printf("i=%d\n",i++);
            //print();
            if(curstep == 64)
            {
                print();
                DestroyStack(s);
                end = clock();
                cost =(double)(end-begin) / CLOCK_PER_SEC;
                printf("time=%f(ms)\n", cost);
                return 1;
            }
            curpos = NextPos(curpos,e.dir);
            curstep++;
        }
        else
        {
            if(!IsEmpty_Stack(s))
            {
                Pop_Stack(s,&e);
                curstep--; 
                while(e.dir == 7 && !IsEmpty_Stack(s))
                {
                    MarkPrint(e.seat);
                    Pop_Stack(s,&e);
                    curstep--;
                }
                if(e.dir < 7)
                {
                    Mincurpos = curpos;
                    e.dir++;
                    curpos =  NextPos(e.seat,e.dir);
                    while(Mincurpos.x == curpos.x && Mincurpos.y == curpos.y && e.dir <7)
                    {
                        e.dir++;
                        curpos=NextPos(e.seat,e.dir);
                    }
                    Push_Stack(s,e);
                    curstep++;
                }
            }
        }
    }while(!IsEmpty_Stack(s));
    DestroyStack(s);
    return 0;
}
















