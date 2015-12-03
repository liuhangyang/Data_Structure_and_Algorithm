/*************************************************************************
	> File Name: xianxingbiao.c
	> AutmZor: yanglongfei
	> Mail: yanglongfei@xiyoulinux.org
	> Created Time: 2015年09月07日 星期一 16时24分56秒
 ************************************************************************/

#include<stdio.h>
#define MAXSIZE  100
typedef  int ElemType;
typedef char ElemType;
typedef struct
{
	ElemType  elem[MAXSIZE];
	int length;
}SeqList;
//初始化
void init_SeqList(SeqList *L)
{
	L->length=0;
}
int Insert_SeqList(SeqList *L,int i,ElemType x) //在第i个位置插入一个元素,1.判断表是否为满，2.判断位置是否合法；
{
	int j;
	if(L->length == MAXSIZE-1)
	{
		printf("线性表已满\n");
		return -1;
	}
	if(i < 1 || i > L->length+1)      //可以插入在L->length+1的位置
	{
		printf("插入的位置非法\n");
		return -1;
	}
	for(j=L->length;j>=i;j--)
	{
		L->elem[j+1]=L->elem[j];
	}
	L->elem[i]=x;
	L->length++;
	return 1;
}
int Delete_SeqList(SeqList *L,int i)  //删除第i个位置的元素，1.判断表是否为空和位置是否合法
{
	int j;
	if(i < 1 || i > L->length)
	{
		printf("第i个元素不存在\n");
		return -1;
	}
	for(j=i;j<L->length;j++)  //如果删除最后一个元素，直接L->length--就可以了
	{
		L->elem[j]=L->elem[j+1];
	}
	L->length--;
	return 1;
}
int Location_SeqList(SeqList *L,ElemType x)   //返回x的存储位置
{		
	int i=1;
	while(i<=L->length && L->elem[i]!=x)
	{
		i++;
	}
	if(i > L->length)
	{
		return -1;   //查找失败
	}	
	else 
	{
		return i;
	}
}
void  Reverse_SeqList(SeqList *L)	//逆置线性表
{
	int i,k;
	for(i=1;i<=L->length/2;i++)
	{
		k=L->elem[i];
	 	L->elem[i]=L->elem[L->length-i+1];
	 	L->elem[L->length-i+1]=k;
	}
}	
void merge(SeqList *La,SeqList *Lb,SeqList *Lc)
{
	int i=1,j=1,k=1;
	while(i<=La->length && j<=Lb->length)
	{
		if(La->elem[i] <= Lb->elem[j])
		{
			Lc->elem[k++]=La->elem[i++];
		}
		else
		{
			Lc->elem[k++]=Lb->elem[j++];
		}
	}
		while(i <= La->length)
		{
			Lc->elem[k++]=La->elem[i++];
		}
		while(j <= Lb->length)
		{
			Lc->elem[k++]=Lb->elem[j++];
		}
		Lc->length=La->length + Lb->length;
	
}	
void Create_SeqList(SeqList *L)
{
			
	int i,n;
	printf("请输入要初始化的个数:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个数",i);
		scanf("%d",&L->elem[i]);
		L->length++;
	}
}
void print_SeqList(SeqList *L)
{
	int i;
	for(i=1;i<=L->length;i++)
	{
		printf("%3d",L->elem[i]);
	}
	printf("\n");
}
void main()
{
	SeqList H;
	int choice;
	init_SeqList(&H);
	Create_SeqList(&H);
	printf("线性表的练习:\n");
	printf("1.插入\n");
	printf("2.删除\n");
	printf("3.合并\n");
	printf("4.逆置\n");
	printf("5.打印\n");
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
		      	int pos,x;
			printf("请输入插入的位置:");
			scanf("%d",&pos);
			printf("请输入要插入的数:");
			scanf("%d",&x);
			Insert_SeqList(&H,pos,x);
			print_SeqList(&H);
		      }
		      break;
		 case 2:
		      {
		      	  int pos;
		      	  printf("请输入要删除的位置:");
		      	  scanf("%d",&pos);
		      	  Delete_SeqList(&H,pos);
		      	  print_SeqList(&H);
		       }
		       break;
		  case 3:
			{
				SeqList La,Lb,Lc;
				init_SeqList(&La);
				init_SeqList(&Lb);
				init_SeqList(&Lc);
				printf("输入la的元素:\n");
	 			Create_SeqList(&La);
	 			printf("输入lb的元素:\n");
	 			Create_SeqList(&Lb);
	 			merge(&La,&Lb,&Lc);
	 			print_SeqList(&Lc);
	 		 }
	 		 break;
	 	   case 4:
	 	         {
	 	         	
	 			 Reverse_SeqList(&H);
	 			 print_SeqList(&H);
	 		  }
	 		  break;
	 	   case 5:
	 	         {
				print_SeqList(&H);
			 }
		   case 0:
		   	break;
	 	         		
	 }
   }
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
