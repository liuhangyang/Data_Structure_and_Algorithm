/*************************************************************************
	> File Name: duoxaingshi.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月09日 星期三 15时56分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct NodeType
{
    int id;
    int passwd;
    struct NodeType *next;
}LNode,*LinkList;
Init_LinkList(LinkList H)
{
    H=(LNode *)malloc(sizeof(LNode));
    H->next=NULL;
}
void Create_LinkLIst(LinkList H)
{
    LNode *p,*s;
    p=H;
    int id,passwd,i=1;
    while(1)
    {
        printf("请输入第%d个人的密码【0结束】:",i);
        scanf("%d",&passwd);
        if(passwd == 0)
        {
            break;
        }
        while(passwd <0)
        {
            printf("请输入第%d个人的密码【0结束】:",i);
            scanf("%d",&passwd);
        }
        s=(LNode *)malloc(sizeof(LNode));
        s->id=i;
        s->passwd=passwd;
        p->next=s;
        p=s;
        i++;
    }
    p->next=H;
}
void print(LinkList H)
{
    LNode *p=H->next;
    if(H->next==H)
    {
        printf("链表为空\n");
        exit(0);
    }
    printf("ID\t\t\tpasswd\n");
    while(p!=H)
    {
        printf("%2d\t\t\t%2d\n",p->id,p->passwd);
        p=p->next;
    }
}
int JosephusOperate(LinkList H,int passwd)
{
    LNode *pre=H;
    LNode *p=H;
    LNode *Del;
    int flag=1;
    int count;
    while(flag)
    {
        count=0;
        while(count != passwd)
        {
            pre=p;
            p=p->next;
            if(p!=H)
            {
                count++;
            }

        }
        if(p->next==pre)
        {
            flag=0;
        }
        Del=p;
        pre->next=p->next;
        passwd=Del->passwd;
        printf("第%d个人出列(密码为%d)\n",Del->id,Del->passwd);
        free(Del);
    
            
    }

}
int main()
{
    LNode *H;
    int passwd;
    Init_LinkList(H);
    Create_LinkLIst(H);
    printf("--------打印循环列表--------\n");
    print(H);
    printf("请输入初始密码:");
    scanf("%d",&passwd);
    JosephusOperate(H,passwd);
    return;
}
