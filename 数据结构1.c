//���Ա�
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int arr[MAX_SIZE];//��������arr����Ϊ10 
	int length;//���Ա�ĳ��� 
} SeqList;//�ṹ���� 


void InitList(SeqList *list)//���Ա��ʼ���������Ա������� 
{
	list->length = 0;
}


int ListInsert (SeqList *list,int position,int value)//��position������Ԫ�أ������Ա��ȼ�һ 
{
	if (position < 0||position > list-> length||position >= MAX_SIZE)//��positionλ�ý����ж� 
	{
		return -1;
	}
	int i;
	for ( i = list->length;i > position;i--)//��positionλ��ǰԪ��ǰ�� 
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
