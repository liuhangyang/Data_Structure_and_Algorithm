/*************************************************************************
	> File Name: maxsmax1.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月09日 星期三 14时43分34秒
 ************************************************************************/

#include<stdio.h>
int max(int s[],int k,int j)
{
    int i,max1,t=k;
    for(i=k+1;i<j;i++)
    {
        if(s[i]>s[t])
        {
            t=i;
        }
    }
    return  t;
}
int main()
{
    int smax,fmax,k,i,j;
    int s[10]={99,4,99,10,5,6,8,7,9,9};
    i=max(s,0,5);
    j=max(s,5,10);
    if(s[i] >= s[j])
    {
        fmax=j;
        k=s[i];
        s[i]=s[j];
        s[j]=k;
        smax=max(s,0,5);
    }
    else
    {
        fmax = i;
        k=s[j];
        s[j]=s[i];
        s[i]=k;
        smax=max(s,5,10);
    }
    printf("samx=%d,famx=%d\n",s[smax],s[fmax]);

}
