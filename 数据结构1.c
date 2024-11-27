//���Ա�
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef int ElemType; 

typedef struct
{
	ElemType *elem;
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
	list->length = 0;//��ʶ���Ա���Ϊ��
	list->elem = (ElemType *)malloc(MAX_SIZE*sizeof(ElemType));
	//list->elem Ϊ�洢�ռ��ַ����(ElemType*)Ϊint *���ڴ� ���� MAX_SIZE*sizeof(ElemType) Ϊ�ڴ�100��4�˻�һ���İ��ֽ� 
	if (list->elem == NULL)//�ж��Ƿ����ɹ� 
	{
		printf("Memory allocation failed��");
		exit(1);
	} 
}

void DestroyList(SeqList *list)
{
	if(list->elem != NULL)
	{
		free(list->elem);
		list->elem = NULL;
	} 
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
}//ɾ��position��Ԫ�� 

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
} //��ȡǰ��Ԫ�� 

int NextElem(SeqList *list,int position,int *value)
{
	if (position < 0 || position > list->length)
	{
		return -1;
	}
	*value = list->arr[position];
	return 0 ;
}//��ȡ���Ԫ�� 



void Menu()
{
	printf("===================���Ա��������=============\n"); 
	printf("===================1.�������Ա�===============\n"); 
	printf("===================2.��ָ��λ�ò���Ԫ��=======\n"); 
	printf("===================3.��ȡָ��Ԫ��=============\n"); 
	printf("===================4.��ȡǰ��Ԫ��=============\n"); 
	printf("===================5.��ȡ���Ԫ��=============\n"); 
	printf("===================6.����=================\n"); 
	printf("===================7.��ӡ���Ա�===============\n"); 
	printf("===================8.�����Ƿ�Ϊ�ձ�=========\n"); 
	printf("===================9.�������Ա�===============\n"); 
	printf("===================0.�˳��˵�=================\n"); 
	printf("===================���Ա��������=============\n"); 
	printf("===================���Ա��������=============\n"); 
	printf("===================���Ա��������=============\n"); 
	printf("===================���Ա��������=============\n"); 
} 

int main (void)
{

	 
	SeqList list;
/*	int i;
	while(1)
	{
		Menu();
		scanf("��ѡ������Ա�Ĳ���%d",i);
		switch(i)
		{
			case 0: exit(0) ; //�˳�ϵͳ
			case 1: InitList(&list) ; //�������Ա�
			case 2; ListInsert(&list);
			
			 
		}
		
		
	}
*/
	
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
