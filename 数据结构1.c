//���Ա�
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int arr[MAX_SIZE];//��������arr����Ϊ100
	int length;//���Ա�ĳ��� 
} SeqList;//�ṹ���� 

/*
Ŀǰ�������ܣ�
1.InitList��ʼ�����Ա�   �����Ա�������
2.DestroyList�������Ա�  �����Ա�������
3.ListEmpty����Ƿ�Ϊ�ձ�  �ձ���1���ǿշ���0
4.ListLength���ر�  ������ֵlist->length
5.ListInsert����Ԫ��  ��position��������ֵ
6.printList ��ӡ���Ա�
7.GetElem  ��ȡԪ��  ��ȡposition����ֵ 
8.PriorElem ��ȡ����Ԫ��  ��ȡposition-1����ֵ
9.NextElem ��ȡ���Ԫ��  ��ȡposition+1����ֵ
10ListDelete  ɾ������Ԫ��  Ŀǰ�������� 

*/
void InitList(SeqList *list)//���Ա��ʼ���������Ա������� 
{
	list->length = 0;
}

void DestroyList(SeqList *list)
{
	list->length = 0;
} 

int ListEmpty(SeqList list)
{
	if (list.length==0)
	return 1;
	else 
	return 0;
} //�����Ƿ�Ϊ�ձ�Ϊ�ձ���1�����ز�Ϊ0 

int ListLength(SeqList *list)
{
	return list->length;
} //���ر���������ֵ���з��� 

int ListInsert (SeqList *list,int position,int value)//��position������Ԫ�أ�ʹ���Ա��ȼ�һ 
{
	if (position < 0||position > list-> length||position >= MAX_SIZE)//��positionλ�ý����ж� 
	{
		return -1;
	}
	int i;
	for ( i = list->length;i > position;i--)
	{
		list->arr[i] = list->arr[i-1];	
	}
	list->arr[position] = value;
	list->length++;
} //������position������value 

int ListDelete (SeqList *list,int position ,int *value)
{
	if (position < 0||position > list-> length||position >= MAX_SIZE)//��positionλ�ý����ж� 
	{
		return -1;
	}
	*value = list->arr[position-1];
	int i;
	for ( i = position - 1;i < position;i++)//��positionλ��ǰԪ��ǰ�� 
	{
		list->arr[i] = list->arr[i+1];	
	}
	list->length--;
	return 0 ;
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
} //��ӡ���Ա� 

int GetElem (SeqList *list,int position ,int *value)
{
	if (position < 1 || position > list->length)
	{
		return -1;//����ʧ�ܵķ���ֵ 
	}
	*value = list->arr[position - 1];
	return 0;//���سɹ��ķ���ֵ 
}  //��ȡposition����ֵ 

int PriorElem(SeqList *list,int position,int *value)
{
	if (position < 2 || position > list->length)
	{
		return -1;
	}
	*value = list->arr[position - 2];
	return 0 ;
} 

int NextElem(SeqList *list,int position,int *value)
{
	if (position < 0 || position > list->length)
	{
		return -1;
	}
	*value = list->arr[position];
	return 0 ;
}

int main (void)
{
	SeqList list;
	InitList (&list);
	
	ListInsert(&list,0,10);
	ListInsert(&list,1,20);
	ListInsert(&list,2,30);
	ListInsert(&list,3,40);
	ListInsert(&list,4,50);
	ListInsert(&list,5,60);
	ListInsert(&list,6,70);
	ListInsert(&list,7,80);
	ListInsert(&list,8,90);
	ListInsert(&list,9,100);
	

	
	int length = ListLength(&list);
	printf("Length:%d\n",length);
	
	printList(&list);
	
	int e;
	GetElem(&list,1,&e);
	
	
	int pre_e;
	PriorElem(&list,2,&pre_e);
	
	
	int next_e;
	NextElem(&list,0,&next_e);
	
	int value;
	ListDelete(&list,2,&value);
	
	printList(&list);
	
	int length2 = ListLength(&list);
	
	printf("%d\n",length);
	
	int testvalue = ListEmpty(list);
	printf("%d\n",testvalue);
	
	DestroyList (&list);
	
	ListInsert(&list,0,120);
	
	printList(&list);
	
	
	printf("%d\n",e);
	printf("%d\n",pre_e);
	printf("%d\n",next_e);
}
