/*   
��Ϊ������ԣ�����Ԫ�ض���Ϊ��typedef  int  Elemtype������������Ϊ20��
���ʵ�����¹��ܣ�
���û�����2���������������Ԫ�ص�˳���A��B������A����������A+B����Ч���ȡ����A��B����ϲ������A�У�A��B�������ظ�Ԫ�أ��ϲ���ֻ��1�Σ�Ȼ�����˳�������ݡ�
�밴������Ҫ���̣�����Դ�����ļ���ִ���ļ��ڴ��ϴ�����ִ���ļ�ֱ���ϴ�ϵͳ�����գ������ϴ�ѹ���ļ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 20

typedef int ElemType; 

typedef struct
{
	int *elem; // ����׵�ַ��ָ����� 
	int length;//���Ա�ĳ��� 
} SeqList;//�ṹ����

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

// �ϲ����������
void MergeLists(SeqList *A, SeqList *B)
{
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length)
    {
        if (A->elem[i] < B->elem[j])
        {
            A->elem[k++] = A->elem[i++];
        }
        else if (A->elem[i] > B->elem[j])
        {
            A->elem[k++] = B->elem[j++];
        }
        else
        {
            A->elem[k++] = A->elem[i++]; // ����һ����ͬԪ��
            j++;
        }
    }

    // ��ʣ���A��B�е�Ԫ����ӵ�A��
    while (i < A->length)
    {
        A->elem[k++] = A->elem[i++];
    }

    while (j < B->length)
    {
        A->elem[k++] = B->elem[j++];
    }

    A->length = k;
}

int main ()
{
	SeqList listA, listB;

    // ��ʼ������˳���
    InitList(&listA);
    InitList(&listB);

    // ����˳���A
    printf("������˳���A��Ԫ�أ�������������-1��ֹ����\n");
    Insert(&listA);

    // ����˳���B
    printf("������˳���B��Ԫ�أ�������������-1��ֹ����\n");
    Insert(&listB);

    // ���A�������Ƿ��㹻
    if (listA.length + listB.length > MAX_SIZE)
    {
        printf("A����������������A��B�ĺϲ���������������г���\n");
        return 1;
    }

    // �ϲ�A��B��A��
    MergeLists(&listA, &listB);

    // ��ӡ�ϲ����A
    printf("�ϲ����˳���A:\n");
    printList(&listA);

    // �ͷ��ڴ�
    free(listA.elem);
    free(listB.elem);

    return 0; 
	
}
