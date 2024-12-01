/*
2���û��Ӽ�������һ�����������ֹ��ɵ��ַ��������ַ���������ÿ��2���Ͽ���ÿ2���������1��2λ�������������λ������2λ����ֵΪ1λ����

��1���Ƚ�һ���ǿյ�����A����ͷ��㣩���������ָ����������ֱ�����˳���������Ľ�㣬Ȼ�������ʾ��(���磺����124356789�����12��43��56��78��9)

��2�����Ž�A�����������ʹ��A����ǰ�涼��ż��ֵ��㣬���涼������ֵ��㡣�����������������A�Ľ��ֵ�����������12��56��78��43��9��

��3��Ȼ���û���������λ��left,right����A�����ϵĸ�����Ľ����е������У�Ȼ�����A����ĸ����ֵ������������2��4�� ���12��43��78��56��9����
*/


//��1��ͷ�ļ����� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
LNode create_list_from_string(const char* str) {
    LNode head = create_node(-1);  // ����ͷ��㣬����������Ϊ-1
    LNode tmp = head;  // ��ʱ�ڵ㣬���ڸ�����һ�ڵ�
    int len = strlen(str);
    int i; 

    for ( i = 0; i < len; i += 2) {
        int num = 0;
        if (i + 1 < len) {
            num = (str[i] - '0') * 10 + (str[i + 1] - '0');
        } else {
            num = str[i] - '0';
        }

        Node* node = create_node(num);  // �����½ڵ�
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

// �������е�ż���ڵ��Ƶ�ǰ��
void rearrange_list(LNode head) {
    LNode even_head = create_node(-1);
    LNode odd_head = create_node(-1);
    LNode even_tail = even_head;
    LNode odd_tail = odd_head;
    LNode current = head->next;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            even_tail->next = current;
            even_tail = current;
        } else {
            odd_tail->next = current;
            odd_tail = current;
        }
        current = current->next;
    }

    even_tail->next = odd_head->next;
    odd_tail->next = NULL;
    head->next = even_head->next;

    free(even_head);
    free(odd_head);
}

// ��ת�����һ����
void reverse_sublist(LNode head, int left, int right) {
    if (left >= right) return;

    LNode prev = head;
    int i;
    for ( i = 0; i < left - 1 && prev != NULL; ++i) {
        prev = prev->next;
    }

    LNode start = prev->next;
    LNode then = start->next;

    for ( i = 0; i < right - left && then != NULL; ++i) {
        LNode temp = then->next;
        then->next = start;
        start = then;
        then = temp;
    }

    prev->next->next = then;
    prev->next = start;
}

int main() {
    char str[100];
    printf("������һ�����������ֹ��ɵ��ַ���: ");
    scanf("%s", str);

    // ��������A
    LNode list = create_list_from_string(str);

    // ���ԭʼ����
    printf("ԭʼ����: ");
    print_list(list);

    // ��������A��ʹ��ǰ�涼��ż��ֵ��㣬���涼������ֵ���
    rearrange_list(list);
    printf("����������A: ");
    print_list(list);

    // �û���������λ��left, right
    int left, right;
    printf("������Ҫ���õ�����λ��left, right: ");
    scanf("%d %d", &left, &right);

    // ��תָ������Ľ��
    reverse_sublist(list, left, right);
    printf("��ת�������A: ");
    print_list(list);

    // �ͷ������ڴ�
    while (list != NULL) {
        LNode temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
