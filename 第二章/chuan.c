/************************************************************************
	> File Name: chuan.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月23日 星期三 18时31分48秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#define MAXSIZE 13
typedef int Status;
typedef char Elemtype;
typedef struct node
{
    char ch[MAXSIZE];
    int length;
}HString;
HString StrAssign(HString S,char *chars)
{
    int i;
    for(i=0;(chars[i]!='\0'&&i<MAXSIZE);i++)
    {
        S.ch[i]=chars[i];
    }
    S.ch[i]='\0';
    S.length=i;
    return S;
}
HString StrCopy(HString S,HString T)
{
    int i;
    for(i=0;i<T.length;i++)
    {
        S.ch[i]=T.ch[i];
    }
    S.ch[i]='\0';
    return S;
}
Status StrLength(HString S)
{
    return S.length;
}
HString StrInsert(HString S,int pos,HString T)
{
    int i,j,t;
    if(pos <1 || pos >S.length +1)
    {
        return S;
    }
    if(T.length + S.length <= MAXSIZE)
    {
        for(i=S.length-1;i>=pos-1;i--)
        {
            S.ch[i+T.length]=S.ch[i];
        }
        for(i=pos-1,j=0;j<T.length;j++,i++)
        {
            S.ch[i]=T.ch[j];
        }
        S.length = S.length + T.length;
        S.ch[S.length]='\0';
    }
    else
    {
        for(i=S.length-1,j=0;i>=pos-1;i--,j++)
        {
            S.ch[MAXSIZE-1-j] = S.ch[i];
        }
        printf("%s\n",S.ch);
        for(i=pos-1,t=0;t<MAXSIZE-S.length;i++,t++)
        {
            S.ch[i]=T.ch[t];
        }
        S.length=MAXSIZE;
        S.ch[S.length]='\0';
    }
    return S;
}
HString StrDelete(HString S,int pos,int len)
{
    int i,j;
    if(pos <=0 || pos > S.length ||len < 0 || pos+len > S.length+1)
    {
        printf("参数不正确!\n");
        return S;
    }
    for(i=pos-1;i<S.length-len;i++)
    {
        S.ch[i]=S.ch[i+len];
    }
    S.length = S.length - len;
    S.ch[S.length]='\0';
    return S;
}
Status StrCompare(HString S,HString T)
{
    int i,comlen;
    if(S.length < T.length)
    {
        comlen = S.length;
    }
    else
    {
        comlen=T.length;
    }
    for(i=0;i<comlen;i++)
     {
        if(S.ch[i] < T.ch[i] )
        {
            return -1;
        }
        else if(S.ch[i] > T.ch[i])
        {
            return 1;
        }
    }
        if(S.length == T.length)
        {
            return 0;
        }
        else if(S.length < T.length)
        {
            return -1;
        }
        else
        {
            return 1;
        }
}
HString StrCat(HString S,HString T)
{
    int i,j;
    for(i=S.length,j=0;i<S.length +T.length;i++,j++)
    {
        S.ch[i]=T.ch[j];
    }
    S.length=S.length+T.length;
    return S;
}
HString SubString(HString S,HString T,int pos,int len)
{
   int i,j;
    if(pos <1 || pos > S.length || len <0 || pos + len >S.length +1) 
    {
        printf("参数不正确\n");
        return S;
    }
    for(i=pos-1,j=0;i<pos+len;i++,j++)
    {
        T.ch[j]=S.ch[i];
    }
    T.length=j;
    return T;
}
Status StrIndex(HString S,int pos,HString T)
{
    int i=pos-1,j=0;
    if(pos < 1 || pos >S.length) 
    {
        printf("参数有误!\n");
        return 0;
    }
    while(i<=S.length && j<=T.length)
    {
        if(S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
        if(j >=T.length)
        {
            return  i-T.length+1;
        }
    }
        
            return -1;
       
}
HString StrReplace(HString S,HString T,HString V)
{
    int i,j;
}
void main()
{
    HString S,T;
    char p[]="yanglongfei";
    char q[]="liong";
    S=StrAssign(S,p);
    printf("S=%s\n",S.ch);
    T=StrAssign(T,q);
    printf("T=%s\n",T.ch);
    /*T=StrCopy(T,S);
    printf("%s\n",S.ch);
    printf("%s\n",T.ch);
    int n=StrLength(T);
    printf("%d\n",n);*/
    //S=StrInsert(S,2,T);
   // S=StrDelete(S,2,2);
    //    int n=StrCompare(S,T);
    //S=StrCat(S,T);
    int n=StrIndex(S,1,T);
    printf("%d\n",n);
}
