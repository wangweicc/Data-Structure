//�������ʵ��
/*
1.��ʽ�ṹ���߼����������ģ�������ṹ�ϲ�һ������
2.���һ���ǴӶ��������
3.����Ŀռ䣬����һ�����Է��䣬�����������ܲ�����
4. ***����ĵײ���ͨ��ָ�뽫һ������ɢ���ڴ�����������������ÿһ���ڴ��Ϊ�ڵ�
*/

//��1��ͷ�ļ����� 

#include<stdio.h>
#include<stdlib.h>

//��2���궨�岿�� 
#define MAX_SIZE 10
#define bool char
#define true 1
#define false 0 

//��3���Զ�����������
typedef int ElemType; 

//���ṹ��
/*
����ṹ���������������
һ����������
һ���ǽṹ��ָ�루ָ���� 
*/ 

typedef struct Node //***Ϊʲô������Node???
//struct��� NodeΪ�ṹ���������ÿ���ʹ���ܹ��ڽṹ������ȥʹ��
//Node���ģ���ʾ typedef�� ���������ƣ����������´�ʹ�ò��ùؼ���structȥ�������� 
{
	int data;//��Ա�����������洢�ڵ������ֵ 
	struct Node* next; //�����Լ�����ΪNode�������û����ȫ����ã�������struct˵��
	//ͬʱ nextָ��ָ��Node �� ʹ��ÿһ����㶼��ָ����һ���������� 
}Node,*LNode;
//Node ����struct Node ����
//*LNode ��������ָ��Node��ָ�� 

//typedef int Node*;������Ҫȥ��Node*���ж��� ������Node*����Ϊ�ṹ������ָ��  ��

Node* create_node(int data) // ��ʼ������ �������� Node* Ϊ int 
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (node == NULL)
	{
		printf("�ڴ����ʧ�ܡ�");
	} 
	return node; // �����´����Ľڵ��ַ 
}

Node* create_list (int num)
{
/*	
Node* head = create_node(1);//����ͷ��� 
	Node* tmp = head;//tmpΪ��ʱ��㣬����Ϊ������һ��� 
	int i;
	for (i = 2;i <= num ;++i)//Ϊʲôʹ�� ++i ������ i++ ?
	//����Ҫ����ʹ��i��ֵ������£�++i��i++������ʹ��
	//������ĳЩ���������Ż���++i���i++���Ӹ�Ч
	//++i��ֱ�۵ر��������ӵ���ͼ 
	{
		Node* node = create_node(i);//nodeΪ��ʱ��㣬����Ϊ����tmpͬʱ�����½�� 
		tmp->next = node;
		tmp = node; //���� 
	}
*/
	if (num <= 0)
	{
		return NULL;
	}
	LNode head = NULL;
	LNode tmp = NULL;
	int i;
	for(i = 0 ; i < num ; ++i)
	{
		int data;
		int j = i + 1;
		printf("�������%d����������:\n",j);
		scanf("%d",&data);
		Node* node = create_node(data);
		if (head == NULL)
		{
			head = node;
			tmp = head;
		}
		else 
		{
			tmp->next = node;
			tmp = node;
		}
	}
	return head;
}

void print_list(Node* head)
{
	Node* current = head;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}//��ӡ����������дʱ�������ں�����head    ��Ҫ�ں����������� 

void free_list() 

//size_t list_len()
int main()
{
	int num;
	printf("����������Ľ������ \n");
	scanf("%d",&num);
	
	LNode list =create_list(num);
	
	print_list(list);
	
	return 0;
}

