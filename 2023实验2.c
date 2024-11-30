#include <stdio.h>
#include <stdlib.h>

//��2���궨�岿�� 
#define bool char
#define true 1
#define false 0 

//��3���Զ�����������
typedef int ElemType; 

// ���ṹ��
typedef struct Node {
    int data;  // ������
    struct Node* next;  // ָ����һ���ڵ��ָ��
} Node, *LNode;

// �����½ڵ�
Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("�ڴ����ʧ�ܡ�\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// ��������
LNode create_list(int num) 
{
    if (num <= 0) {
        return NULL;
    }

int i; 
    LNode head = create_node(-1);  // ����ͷ��㣬����������Ϊ-1
    LNode tmp = head;  // ��ʱ�ڵ㣬���ڸ�����һ�ڵ�

    for (i = 0; i < num; ++i) {
        int data;
        printf("�������%d����������: ", i + 1);
        scanf("%d", &data);

        Node* node = create_node(data);  // �����½ڵ�
        tmp->next = node;
        tmp = node;  // ������ʱ�ڵ�
    }

    return head;  // ����ͷ�ڵ�
}

// ��ӡ����
void print_list(LNode head) {
    LNode current = head->next;  // ��ͷ������һ���ڵ㿪ʼ��ӡ
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �������
void split_list(LNode head, LNode* A, LNode* B) {
    *A = create_node(-1);  // ����A�����ͷ���
    *B = create_node(-1);  // ����B�����ͷ���

    LNode current = head->next;  // ��ͷ������һ���ڵ㿪ʼ
    LNode tailA = *A;
    LNode tailB = *B;

    while (current != NULL) {
        if (current->data % 2 == 0) {  // ż���ڵ�
            tailA->next = current;
            tailA = current;
        } else {  // �����ڵ�
            tailB->next = current;
            tailB = current;
        }
        current = current->next;
    }

    tailA->next = NULL;  // ����A����
    tailB->next = NULL;  // ����B����
}

int main() {
    int num;
    printf("����������Ľ������: ");
    scanf("%d", &num);

    LNode list = create_list(num);

    // ��ӡԭʼ����
    printf("ԭʼ����: ");
    print_list(list);

    // �������
    LNode A, B;
    split_list(list, &A, &B);

    // ��ӡ��ֺ������
    printf("����A (ż��): ");
    print_list(A);

    printf("����B (����): ");
    print_list(B);

    // �ͷ������ڴ�
    while (list != NULL) {
        LNode temp = list;
        list = list->next;
        free(temp);
    }

    while (A != NULL) {
        LNode temp = A;
        A = A->next;
        free(temp);
    }

    while (B != NULL) {
        LNode temp = B;
        B = B->next;
        free(temp);
    }

    return 0;
}
