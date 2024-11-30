//���Ա�
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef int ElemType; 

typedef struct
{
	int *elem; // ����׵�ַ��ָ����� 
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

//int arr[MAX_SIZE];//��������arr����Ϊ100

*////////////
void InitList(SeqList *list)//���Ա��ʼ���������Ա������� 
{
	list->length = 0;//��ʶ���Ա���Ϊ��
	list->elem = (ElemType *)malloc(MAX_SIZE*sizeof(ElemType));
	//list->elem Ϊ�洢�ռ��ַ����(ElemType*)Ϊint *���ڴ� ���� MAX_SIZE*sizeof(ElemType) Ϊ�ڴ�100��4�˻�һ���İ��ֽ� 
	if (list->elem == NULL)//�ж��Ƿ����ɹ� 
	{
		printf("Memory allocation failed��\n");
		printf("��ʼ��ʧ��\n"); 
		exit(1);
	} 
	else
	{
		printf("��ʼ���ɹ�\n"); 
	}
}

void DestroyList(SeqList *list)
{
	if(list->elem != NULL)
	{
		free(list->elem);
		printf("ɾ���ɹ�\n"); 
		list->elem = NULL;
	} 
	list->length = 0;
} 


void ListEmpty(SeqList *list)
{
	if (list->length==0)
	{
	printf("��һ���ձ�\n");
	}
	else
	{
	printf("���ǿձ�\n");
	} 
}   //�����Ƿ�Ϊ�ձ�Ϊ�ձ���1�����ز�Ϊ0 


void ListLength(SeqList *list)
{
	printf("���Ա�ĳ�����%d\n",list->length);
} //���ر���������ֵ���з��� 


void Insert (SeqList *list)
{
	int i;
	int value; 
	printf("��������Ҫ�������б�Ԫ��(����-1��ֹ����)\n");
	for (i = 0;i < MAX_SIZE;i++)
	{
		scanf("%d",&value);
		if (value == -1)
		{
			printf("�����������Ա�\n");
			break;
		}
		list->elem[list->length] = value;
		list->length++;
	}
}  //˳����� 

void ListInsert (SeqList *list)//��position������Ԫ�أ�ʹ���Ա��ȼ�һ 
{
	int position;
	int j ;
	int value;
	int i;
	for (i = 0; i < MAX_SIZE ;i++)
	{
		printf("������Ҫ����Ԫ�ص�λ��(����-1����)��");
		scanf("%d",&position);
		if (position == -1)
		{
			printf("�������������\n");
			break;
		}
		printf("������Ҫ����Ԫ�ص�ֵ��");
		scanf("%d",&value);
		if (position < 0||position > list-> length||position >= MAX_SIZE)//��positionλ�ý����ж� 
		{
			printf("������Ч��λ����Ч�����б�����\n");
		}
		else
		{
	 		for ( i = list->length ;i > position ;i--)
			{
			list->elem[i] = list->elem[i-1];	
			}
			list->elem[position] = value;
			list->length++;
			printf("Ԫ���Ѿ��ɹ�����\n");
		}
	}
}//������position������value

void ListDelete (SeqList *list)
{
	int position;
	int *value;
	int i;
	int j;
	for (j = 0 ; j < MAX_SIZE ;j++)
	{
		printf("������Ҫɾ��Ԫ�ص�λ��(����-1����ɾ��)��");
		scanf("%d",&position); 
		if (position == -1)
		{
			printf("����ɾ��������\n");
			break;
		}
		if (position < 0||position > list-> length||position >= MAX_SIZE)//��positionλ�ý����ж� 
		{
			printf("�����ɾ��λ�ò��Ϸ���\n");
			break;
		}
	
		for ( i = position - 1;i < list->length-1 ; ++i)//��positionλ��ǰԪ��ǰ�� 
		{
			list->elem[i] = list->elem[i+1];	
		}
		list->length--;
		printf("ɾ���ɹ�\n");
}
	//break ;
}//ɾ��position��Ԫ�� 

void printList(SeqList *list)
{
	int i;
	printf("���Ա�����\n"); 
	for (i=0 ; i<list->length ;i++)
	{
		printf("%d\t",list->elem[i]);
	}
	printf("\n");
} //��ӡ���Ա� 

void GetElem (SeqList *list)
{
	int position;
	int value;
	int i,j;
	for (i = 0; i < list->length ; i++ )
	{
		printf("������Ҫ��ȡԪ�ص�λ��(����-1������ȡ)��\n");
		scanf("%d",&position);
		if (position == -1)
		{
			printf("������ȡԪ�أ�\n");
			break;
		}
		value = list->elem[position-1];
		if (position < 1 || position > list->length)
		{
			printf("����λ����Ч\n");
			break;
		}
		printf("��λ��Ԫ��Ϊ%d\n",value);
	}
}  //��ȡposition����ֵ 

void PriorElem(SeqList *list)
{
	int position,value;
	int i;
	for (i = 0 ; i < list->length; i++)
	{	
	printf("������Ҫ��ȡǰ��Ԫ�ص�λ��(����-1������ȡ)��");
	scanf("%d",&position); 
	if (position < 2 || position > list->length)
	{
		break;
	}
	if (position == -1)
	{
		printf("�������룡\n");
		break;
	}
	value = list->elem[position - 2];
	printf("��ǰ��Ԫ��Ϊ%d\n",value);
	}

} //��ȡǰ��Ԫ�� 

void NextElem(SeqList *list)
{
	int position,value;
	int i;
	for (i = 0 ; i < list->length; i++)
	{	
	printf("������Ҫ��ȡ���Ԫ�ص�λ�ã�");
	scanf("%d",&position); 
	if (position < 0 || position > list->length)
	{
		break;
	}
	if (position == -1)
	{
		break;
	}
	value = list->elem[position];
	printf("�ú��Ԫ��Ϊ%d\n",value);
	}

}//��ȡ���Ԫ�� 



void Menu()
{
	int choice;
	SeqList list;
	int i;
	printf("-------------------���Ա��������-------------\n"); 
	printf("-------------------0.�˳��˵�-----------------\n"); 
	printf("-------------------1.�������Ա�---------------\n"); 
	printf("-------------------2.�������Ա�Ԫ��-----------\n"); 
	printf("-------------------3.��ȡָ��Ԫ��-------------\n"); 
	printf("-------------------4.��ȡǰ��Ԫ��-------------\n"); 
	printf("-------------------5.��ȡ���Ԫ��-------------\n"); 
	printf("-------------------6.����-----------------\n"); 
	printf("-------------------7.��ӡ���Ա�---------------\n"); 
	printf("-------------------8.�����Ƿ�Ϊ�ձ�---------\n"); 
	printf("-------------------9.�������Ա�---------------\n"); 
	printf("-------------------10.��ָ��λ�ò���Ԫ��------\n");
	printf("-------------------11.��ָ��λ��ɾ��Ԫ��------\n");
	
	for(i = 0 ; i < INT_MAX ; i++)
	{
		printf("���������Ա������Ӧ����ţ�");
		scanf("%d",&choice);
		if(choice < 0 || choice > 11 )
		{
			printf("���벻�Ϸ�������������!\n");
			continue;
		}
		else
		{
			switch(choice)
			{
				case 0: printf("�˳��˵��ɹ�!\n"); exit(0); //�˳��˵�
				case 1: InitList(&list); break;
				case 2: Insert(&list); break;
				case 3: GetElem(&list); break;
				case 4: PriorElem(&list); break;
				case 5: NextElem(&list); break;
				case 6: ListLength(&list); break;
				case 7: printList(&list); break;
				case 8: ListEmpty(&list); break;
				case 9: DestroyList(&list); break;
				case 10: ListInsert(&list); break;
				case 11: ListDelete(&list); break;
			}
		}
	} 
} 

int main (void)
{	
	SeqList list;
	Menu();
	/*InitList (&list);
	Insert(&list);
	printList(&list); 
	ListInsert(&list);
	printList(&list); */ 

}



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
	
/*	InitList (&list);
	
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
	InitList (&list);
	Insert(&list);
	ListInsert(&list);
	ListEmpty(&list);
	ListLength(&list);
	GetElem(&list);
	PriorElem(&list);
	NextElem(&list); 
	printList(&list);
	ListDelete(&list);
	printList(&list);
	DestroyList(&list);*/
	


