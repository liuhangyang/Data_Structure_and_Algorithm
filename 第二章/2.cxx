/*Copyright(c):yanglongfei;
 *All right reserved:
 *程序名:顺序表;
 *程序描述:顺序表的建立，插入，查找，删除;
 *创建日期:2015年 06月 14日 星期日 18:53:52 CST
 */
#include "sqlist.h"                                                        
 int CreatList_Sq(SqList &L)             //建立顺序表
{

        int i;
        printf("Input the datas:");
        for(i=0;i<L.length;i++)
                scanf("%d",&L.elem[i]);
        return OK; 
}
int ListInsert_Sq(SqList &L,int i,int e)//在第i个元素之前插入元素e至顺序表
{
	int *p,*q,*newbase;
	if((i<1) || (i>L.length+1))
	{
		return ERROR;
	}
	if(L.length >= L.listsize)   //当前空间已满，增加分配;
	{
		newbase=(int *)realloc(L.elem,(L.length+LISTINCREMENT)*sizeof(int));
		if(!newbase)
		{
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize +=LISTINCREMENT;
	}
	q=&L.elem[i-1];  //q指向插入位置
	for(p=&L.elem[L.length-1];p>=q;--p)   //第n至第i个元素依次后移一个位置
		*(p+1) = *p;
		*q = e;
		L.length++;
		return OK;
}
int ListDelete_Sq(SqList &L,int i,int &e)
{
	int *p,*q;
	if((i<1) || (i>L.length))
		return ERROR;
	p=&L.elem[i-1];    		//取第i个元素的地址
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;p++)  			//从第i+1至第n个元素依次前移
	  *(p-1) = *p;
	-- L.length;
	return OK;
}
int LocateElem(SqList L,int e,int (*compare)(int ,int))    	//查找表中第一个与e相等的元素的位序号为i，compare为函数指针
{	
		int i, *p;
		i=1;
		p = L.elem;
		while(i<=L.length  &&  !(compare)(*p++,e))
			++i;
		if(i<=L.length)
			return i;
		else
			return 0;
}
int compare(int a,int b)
{
	if(a==b)
		return 1;
	else
		return 0;
}
			
			
int main()
{
        int i,n,e;
        SqList L;
        InitList_Sq(L);
        printf("\nInput the length of the list L:");   //输入顺序表的长度
        scanf("%d",&n);
        L.length = n;
        CreatList_Sq(L);
/*	printf("Input the insert data:");
	scanf("%d",&e);
	printf("Input the insert location:");
	scanf("%d",&i);
	if(ListInsert_Sq(L,i,e))
	{
          printf("Output the datas:");
          for(i=0;i<L.length;i++)
                printf("%d",L.elem[i]);
		printf("\n");
	}
	else
	{
		printf("can't insert the data！");
	}

	printf("Input the delete location:");
	scanf("%d",&i);
	if(ListDelete_Sq(L,i,e))
	{
		printf("Delete the data %d:\n",e);
		printf("Output the datas");
		for(i=0;i<L.length;i++)
		{
			printf("%d",L.elem[i]);
		}
			printf("\n");
	}
	else
	{
		printf("Cant't find the delete data!");
	}
*/
	printf("Input search data:");
	scanf("%d",&e);
	i=LocateElem(L,e,compare);
	if(i)
	{
		printf("The search data is in the %dth location in the L\n",i);
	}
	else
	{
		printf("There is no search data in the L\n");
	}
	printf("Output  the datas:");
		for(i=0;i<L.length;i++)
			printf("%3d",L.elem[i]);
				printf("\n");
}                
