//�������ʵ��
/*
1.��ʽ�ṹ���߼����������ģ�������ṹ�ϲ�һ������
2.���һ���ǴӶ��������
3.����Ŀռ䣬����һ�����Է��䣬�����������ܲ�����
4. ***����ĵײ���ͨ��ָ�뽫һ������ɢ���ڴ�����������������ÿһ���ڴ��Ϊ�ڵ�
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
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
}Node;
/*
typedef int Node*;
 
Node* create_node(int data) // ��ʼ������ �������� Node* Ϊ int 
{
	Node* node = (Node*)malloc(MAX_SIZE*sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node; // �����´����Ľڵ��ַ 
} 
*/
/*Node* create_list (int num)
{
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
}*/
int main()
{
	Node Node1 = {1 , NULL};//����������ݣ�����������1����������ݿ� 
	
	return 0;
}

