#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define LIST_INIT_SIZE  100    //存储空间初始分配量
#define  LISTINCREMENT  10    //存储空间的分配增量
typedef struct 
{
	int *elem;
	int length;          //当前表长
	int listsize;		//当前分配的存储容量
}SqList;

int InitList_Sq(SqList  &L)     //构造一个空的顺序表
{
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
		return OK;
}
