/*************************************************************************
	> File Name: biaodashiqiuzhi.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月16日 星期三 17时51分47秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#define MAXLEN 100
typedef float ElemType;
typedef int StatusInt;
typedef char  StatusChar;
typedef char CElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
}SeqStack;
typedef struct nodeChar
{

	CElemType data;
	struct nodeChar *next;
}SeqStackChar;
/***********************操作数栈**************************/
SeqStack *Init_SeqStack(SeqStack *top)
{
	top=(SeqStack *)malloc(sizeof(SeqStack));
	top->next=NULL;
    return top;
}
StatusInt IsEmpty_SeqStack(SeqStack *top)
{
	if(top->next==NULL)
	{
		return 1;
	}
	return 0;
}
StatusInt Push_SeqStack(SeqStack *top,ElemType x)
{
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
    if(s==NULL)
    {
        return 0;
    }
    s->data=x;
    s->next=top->next;
    top->next=s;
    return 1;
}
StatusInt Pop_SeqStack(SeqStack *top,ElemType *x)
{
    SeqStack *s;
    if(top->next==NULL)
    {
        return 0;
    }
    s=top->next;
    *x=s->data;
    top->next=s->next;
    return 1;
}
StatusInt GetTop_SeqStack(SeqStack *top,ElemType *x)
{
    SeqStack *s;
    if(top->next==NULL)
    {
        return 0;
    }
    s=top->next;
    *x=s->data;
    return 1;
}
/*********************操作符栈**************************/
SeqStackChar* Init_SeqStackChar(SeqStackChar *top)
{
   top=(SeqStackChar *)malloc(sizeof(SeqStackChar));
   top->next=NULL;
    return top;
}
StatusInt IsEmpty_SeqStackChar(SeqStackChar *top)
{
    if(top->next==NULL)
    {
        return 1;
    }
    return 0;
}
StatusInt Push_SeqStackChar(SeqStackChar *top,CElemType x)
{
    SeqStackChar *s;
    s=(SeqStackChar *)malloc(sizeof(SeqStackChar));
    if(s==NULL)
    {
        return 0;
    }
    s->data=x;
    s->next=top->next;
    top->next=s;
    return 1;
}
StatusInt Pop_SeqStackChar(SeqStackChar *top,CElemType *x)
{
    SeqStackChar *s;
    if(top->next==NULL)
    {
        return 0;
    }
    s=top->next;
    *x=s->data;
    top->next=s->next;
    free(s);
    return 1;
}
StatusChar GetTop_SeqStackChar(SeqStackChar *top)
{
    SeqStackChar *s;
    CElemType x;
    if(top->next == NULL)
    {
        return 0;
    }
    s=top->next;
    x=s->data;
    return x;
}
StatusInt Is_operator(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return  1;
            break;
        default:
        	return 0;
        	break;
    }
}
StatusChar predece(char op1,char op2)
{
    switch(op1) 
    {
        case '+':
            switch(op2)
            {
                    case '*':
                    case '/':
                    case '(':
                           return '<';
                           break;
                    default:
                            return '>';
                            break;
            }
            break;
        case '-':
            switch(op2)
            {
                    case '*':
                    case '/':
                    case '(':
                           return '<';
                           break;
                    default:
                           return '>';
                           break;
            }
            break;
        case '*':
            switch(op2)
            {
                    case '(':
                           return '<';
                           break;
                    default:
                           return '>';
                           break;
            }
            break;
        case '/':
            switch(op2)
            {
                case '(':
                       return '<';
                       break;
                default:
                       return '>';
                       break;
            }
            break;
         case '(':
            switch(op2)
            {
                case ')':
                    return '=';
                    break;
                default:
                    return '<';
                    break;
            }
            break;
        case ')':
            switch(op2)
            {
                default:
                return '>';
                break;
            }
            break;
        case '#':
            switch(op2)
            {
                case '#':
                    return '=';
                    break;
                default:
                return '<';
                break;
            }
            break;
        default:
                       break;

    }
}
float operate(ElemType a,CElemType op,ElemType b)
{
    float  result;
    switch(op)
    {
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':
             if(b==0)
             {
             	printf("除数不能为0\n");
             	exit(0);
             }
            result = a/b;
            break;
        default:
        	 break;
    }
    //rintf("%f %c %f",a,op,b);
    return result;
}
void Standard(char exp[])
{
    char *p,*q;
    p=exp;
    while(*p!='\0')
    {
        if(*p==' ')
        {
            q=p;
            do{
                *q=*(q+1);
                 q++;
            }while(*q!='\0');
            p--;
        }
       	 p++;
    }
    *p++='#';
    *p='\0';
    //printf("%s",exp);
}
StatusInt IsTrue(char c)
{
    if(((c >='0') && (c <= '9')) || (c=='.'))
    {
        return 1;
    }
    return 0;
}
void Exp(char exp[])
{
    SeqStack *OPRD;
    SeqStackChar *OPTR;
    char *x=exp;
    float tmp,sum=0,a,b,result;
    int t,m,i;
    char ther,op1;
    OPRD=Init_SeqStack(OPRD);
    OPTR=Init_SeqStackChar(OPTR);
    Push_SeqStackChar(OPTR,'#');
    while(*x!='#' || GetTop_SeqStackChar(OPTR)!='#')
    {
        if(*x=='\0')
        {
            break;
        }
        if(Is_operator(*x)==0)
        {
            m=0;
            t=0;
            sum=0;
            while(Is_operator(*x)==0)
            {
                if(IsTrue(*x)==0)
                {
                    printf("表达式输入有误!\n");
                    exit(0);
        }
               if(*x=='.')
               {
                 m=t;
                 x++;
                continue;
               }
               else
               {
                tmp=*x-'0';
                sum=sum*10+tmp;
                t++;
                x++;
               }
            }
            if(m!=0)
            {
            	for(i=1;i<=t-m;i++)
            	{
                	sum=sum/10;
            	}
            }
            Push_SeqStack(OPRD,sum);
        }
        else if(Is_operator(*x)==1)
        {
            ther=predece(GetTop_SeqStackChar(OPTR),*x);
            switch(ther)
            {
                case '<':
                    Push_SeqStackChar(OPTR,*x);
                    x++;
                    break;
                case '=':
                    Pop_SeqStackChar(OPTR,&ther);
                    x++;
                    break;
                case '>':
                    Pop_SeqStackChar(OPTR,&op1);
                    Pop_SeqStack(OPRD,&b);
                    Pop_SeqStack(OPRD,&a);
                   // printf("%f,%f",a,b);
                    result=operate(a,op1,b);
                    Push_SeqStack(OPRD,result);
                    break;
            }
        } 
        
    }
    GetTop_SeqStack(OPRD,&result);
   printf("表达式的值为:%f\n",result);
}
void main()
{
    char exp[MAXLEN];
    printf("请输入你要计算的表达式:");
    gets(exp);
    Standard(exp);
    Exp(exp);
}
