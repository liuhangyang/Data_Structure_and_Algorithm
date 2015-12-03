/*************************************************************************
	> File Name: kuohaopedui.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月16日 星期三 14时04分45秒
 ************************************************************************/

#include <stdio.h>
#define MAXSIZE 100
typedef char ElemType;
typedef struct  node
{
    ElemType elem[MAXSIZE];
    int top;
}SeqStack;
void Init_Stack(SeqStack *S)
{
    S->top=-1;
}
int IsEmpty_Stack(SeqStack *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull_Stack(SeqStack *S)
{
    if(S->top==MAXSIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Push_Stack(SeqStack *S,ElemType x)
{
    if(S->top == MAXSIZE -1)
    {
        return 0;
    }
    else
    {
        S->top++;
        //printf("%d",S->top);
        S->elem[S->top]=x;
        return 1;
    }
}
int Pop_Stack(SeqStack *S,ElemType *x)
{
    if(S->top == -1)
    {
        return 0;
    }
    else
    {
        *x=S->elem[S->top];
        S->top--;
        return 1;
    }
}
int Get_StackTop(SeqStack *S,ElemType *x)
{
    if(S->top==-1)
    {
        return 0;
    }
    else
    {
        *x=S->elem[S->top];
        return 1;
    }
}
int Match(ElemType a,ElemType b)
{
    if((a=='(' && b==')') ||(a==')' && b== '('))
    {
        return 1;
    }
    else if((a=='{' && b=='}') || (a=='}' && b== '{'))
     {
        return 1;
    }
    else if((a=='[' && b==']') || (a==']' && b=='['))  
    {
        return 1;
    }
    else
    {
        return 0; 
    }
}
void brackets()
{
    char input1[MAXSIZE];
    SeqStack S;
    char x;
    char m;
    Init_Stack(&S);
    int i;
    printf("请输入要检验的括号字符串:");
    scanf("%s",input1);
    for(i=0;input1[i]!='\0';i++)
    {
        switch(input1[i])
        {
            case '{':
            case '(':
            case '[':
            	Push_Stack(&S,input1[i]);
            	break;
            case '}':
            case ']':
            case ')':
            	if(IsEmpty_Stack(&S))   //调用函数时，只写函数名也可以调用，注意，参数；
            	{
            		printf("右括号多余!\n");
            		return;
            	}
            	else
            	{
            		Get_StackTop(&S,&x);
            		if(Match(x,input1[i]))
            		{
            			Pop_Stack(&S,&m);
            		}
            		else
            		{
            			printf("左右括号不配对!\n");
            			return;
            		}
            	}
            	break;
            default:
            	printf("输入有误!\n");
            	return;
            		
        }
    }
    if(IsEmpty_Stack(&S))
    {
    	printf("括号配对成功!\n");
    }
    else
    {
    	printf("左括号多余!\n");
    }

}
void main()
{
	brackets();
}
