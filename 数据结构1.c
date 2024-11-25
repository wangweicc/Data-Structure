//线性表
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int arr[MAX_SIZE];//定义数组arr长度为10 
	int length;//线性表的长度 
} SeqList;//结构体名 


void InitList(SeqList *list)//线性表初始化，把线性表长度置零 
{
	list->length = 0;
}


int ListInsert (SeqList *list,int position,int value)//在position处插入元素，是线性表长度加一 
{
	if (position < 0||position > list-> length||position >= MAX_SIZE)//对position位置进行判断 
	{
		return -1;
	}
	int i;
	for ( i = list->length;i > position;i--)//将position位置前元素前移 
	{
		list->arr[i] = list->arr[i-1];	
	}
	list->arr[position] = value;
	list->length++;
}

void printList(SeqList *list)
{
	int i;
	for (i=0 ; i<list->length ;i++)
	{
		printf("%d",list->arr[i]);
		printf("\n");
	}
	printf("\n");
}


int main (void)
{
	SeqList list;
	InitList (&list);
	
	ListInsert(&list,0,10);
	ListInsert(&list,1,20);
	ListInsert(&list,2,30);
	ListInsert(&list,3,40);
	
	printList(&list);
	 
	
	
}
