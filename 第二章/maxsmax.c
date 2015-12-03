/*************************************************************************
	> File Name: maxsmax.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月09日 星期三 14时03分13秒
 ************************************************************************/

#include<stdio.h>
void maxandsmax(int s[],int n)
{
    int i,k;
    int max=s[0];
    int smax=s[n];
    for(i=1;i<n;i++)
    {
        if(s[i]>smax)
        {
            smax=s[i];
        }
        if(smax>max)
        {
            k=smax;
            smax=max;
            max=k;
        }
    }
    printf("max=%d,smax=%d\n",max,smax);
}
int main()
{
    int s[9]={10,1,2,9,3,3,4,6,7};
    maxandsmax(s,9);
}
