/*************************************************************************
	> File Name: 1.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2015年11月21日 星期六 13时12分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
/***************************冒泡排序法**************************/
void maopao(int a[],int n)    //升序时,每次把最大的放到最后一个元素上,每次遍历的元素个数-1;从后面减
{
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++)
        {
            if(a[j-1] > a[j])
            {
                k=a[j-1];
                a[j-1]=a[j];
                a[j]=k;
            }
        }
    }
}
/******************************选择排序法******************************/
void xuanze(int a[],int n)
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n-1;j++){  //升序时,每次把最小的放在最前面,每次遍历的元素-1;从前面加
            if(a[k] > a[j])
            {
                k=j;
            }
        }
        if(k!=i)
        {
             temp = a[i];
             a[i]=a[k];
             a[k]=temp;
        }
    }
}
/****************************插入排序法*********************************/
void charupaixu(int a[],int n)  //插入排序
{
    int i,j,temp;
    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(a[j]<a[j-1] )
            {
                temp= a[j];
                a[j]= a[j-1];
                a[j-1]=temp;
            }
        }
    }
}
/****************************归并排序法*********************************/
int  merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,p=0;
    int *temp=(int *)malloc(sizeof(int));
    if(temp == NULL){
        return -1;
    }
    while(i<=mid && j<=high){
        temp[p++]=((a[i]<=a[j])?a[i++]:a[j++]);   
    }
    while(i<=mid){
        temp[p++]=a[i++];
    }
    while(j<=high){
        temp[p++]=a[j++];
    }
    for(p=0,i=low;i<=high;i++,p++){
        a[i]=temp[p];
    }
}
void guibing(int a[],int low,int high)
{
    int mid=(low + high)/2;
    if(low < high)
    {
        guibing(a,low,mid);
        guibing(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
/****************************快速排序法*************************/
void kuaisupaixu(int a[],int low,int high){
    if(low <high)
    {
        int i=low,j=high,temp=a[low];
        while( i < j )
        {
            while(a[j] > temp && i < j){
                j--;
            }
            a[i] = a[j];
            while(a[i] < temp && i<j){
                i++;   
            }
            a[j]=a[i];
        }
        a[i]=temp;
        kuaisupaixu(a,low,i-1);
        kuaisupaixu(a,i+1,high);
    }
}
void print(int a[],int n)
{
   int  i; 
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[10]={4,5,1,2,3,7,7,9,8,0},i;
   /* printf("*****************冒泡排序**********************\n");
    maopao(a,10);
    print(a,10);
    printf("\n");
    printf("*****************选择排序*********************\n");
    xuanze(a,10);
    print(a,10);
    printf("\n");
    printf("****************插入排序*************************\n");
    charupaixu(a,10);
    print(a,10);
    printf("\n");
    printf("***************归并排序法法***********************\n");
    guibing(a,0,9);
    print(a,10);
    printf("\n");*/
    printf("*************快速排序法**************************\n");
    kuaisupaixu(a,0,9);
    print(a,10);
    printf("\n");

}
