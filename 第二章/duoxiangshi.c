/*************************************************************************
	> File Name: duoxiangshi.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月09日 星期三 18时15分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Polynomial
{
    float coef; //系数
    int expn;   //指数
    struct Polynomial *next;
}Poly;
Poly * Init_LinkList(Poly *H)
{
    H=(Poly *)malloc(sizeof(Poly));
    H->next=NULL;
    return H;
}
Poly * Create_LinkList(Poly *H)
{
    Poly *p=H,*s;
    int coef,expn;
    while(1)
    {
        printf("请输入系数:");
        scanf("%d",&coef);
        if(coef==0)
        {
            break;
        }
        printf("请输入指数:");
        scanf("%d",&expn);
        s=(Poly *)malloc(sizeof(Poly));
        s->coef=coef;
        s->expn=expn;
        p->next=s;
        p=s;
    }
    p->next=NULL;
    return H;
}
void print(Poly *H)
{
    Poly *p=H->next;
    int flag=1;
    if(p==NULL)
    {
        printf("0\n");
        printf("\n");
        return;
    }
    while(p)
    {
        if(p->coef > 0 && flag!=1)  
            putchar('+');
        if(p->coef != 1 && p->coef != -1)
        {
            printf("%g",p->coef);
            if(p->expn==1) putchar('X');
            else if(p->expn)  printf("X^%d",p->expn);
        }
        else
        {
            if(p->coef == 1)
            {
                if(!p->expn)  putchar('1');
                else if(p->expn == 1)  putchar('X');
                else if(p->expn)  printf("X^%d",p->expn);
            }
            else
            {
                if(!p->expn)  printf("-1");
                else if(p->expn == 1)  printf("-X");
                else if(p->expn)  printf("-X^%d",p->expn);
            }

        }
        p=p->next;
        flag++;
    }
}
Poly* AddPolyn(Poly *H,Poly *T)
{
    Poly *pre=H;
    Poly *La=H->next;
    Poly *Lb=T->next;
    Poly *p,*q,*Del;
    while(La && Lb)
    {
        if(La->expn < Lb->expn)
        {
            pre=La;
            La=La->next;
        }
        else if(La->expn == Lb->expn)
        {
            La->coef = La->coef + Lb->coef;
            if(La->coef == 0)
            {
                Del=La;
                pre->next=La->next;
                La=pre->next;
                free(Del);
            }
            else
            {
                pre=La;
                La=La->next;
                Lb=Lb->next;
            }
        }
        else
        {
            p=Lb;
            Lb=Lb->next;
            p->next=La;
            pre->next=p;
            pre=pre->next;

        }

    }
    while(La)
    {
        La=La->next;   
    }
    if(Lb!=NULL)
    {
        pre->next =Lb;
    }
    return H;

}
void MuitiPloyn(Poly *M,Poly *T)
{
    Poly *La=M->next;
    Poly *Lb=T->next;
    Poly *Lc;
    Poly *Ld;
    Poly *p,*q,*m,*n;
    Lc=Init_LinkList(Lc);
    Ld=Init_LinkList(Ld);
    m=Lc;
    n=Ld;
    int flag=1,t=0,s=0;
    while(La!=NULL)
    {
        Lb=T->next;
        while(Lb!=NULL)
        {
                if(flag==1)
                {
                    p=(Poly *)malloc(sizeof(Poly));
                    p->coef=La->coef * Lb->coef;
                    p->expn=La->expn + Lb->expn;
                    m->next=p;
                    m=p;
                }
                if(flag ==2)
                 {
                    q=(Poly *)malloc(sizeof(Poly));
                    q->coef=La->coef * Lb->coef;
                    q->expn=La->expn + Lb->expn;
                    n->next=q;
                    n=q;
                    t=1;
                    s=1;
                }
            Lb=Lb->next;
            
        }
        if(flag == 1)
        {
            m->next=NULL;
            flag=2;
        }
        else if(s ==1)
        {
            n->next=NULL;
            flag=2;
        }
        if(t==1)
        {
            Lc=AddPolyn(Lc,Ld);
            n=Ld;
        }
        La=La->next;
    }
    print(Lc);
    printf("\n");
}
Poly * SubtractPolyn(Poly *T)
{
    Poly *p=T;
    Poly *q=T->next;
    while(q)
    {
        q->coef*=-1;
        q=q->next;
    }
    return T;
}
void main()
{
    Poly *M,*T;
    int choice;
    printf("多项式的运算:\n");
    printf("0.退出\n");
    printf("1.多项式的加法\n");
    printf("2.多项式的减法\n");
    printf("3.多项式的乘法\n");
    while(1)
    {
        printf("请输入选择:");
        scanf("%d",&choice);
        if(choice == 0)
        {
            break;
        }
        switch(choice)
        {
            case 1:
            {
                M=Init_LinkList(M);
                T=Init_LinkList(T);
                M=Create_LinkList(M);
                T=Create_LinkList(T);
                AddPolyn(M,T);
                print(M);
                printf("\n");
            }
            break;
            case 2:
            {
                M=Init_LinkList(M);
                T=Init_LinkList(T);
                M=Create_LinkList(M);
                T=Create_LinkList(T);
                T=SubtractPolyn(T);
                AddPolyn(M,T);
                print(M);
                printf("\n");
            }
            break;
            case 3:
            {
                M=Init_LinkList(M);
                T=Init_LinkList(T);
                M=Create_LinkList(M);
                T=Create_LinkList(T);
                MuitiPloyn(M,T);
            }
            break;
        }
    }
}
