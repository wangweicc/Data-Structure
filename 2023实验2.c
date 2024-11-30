#include <stdio.h>
#include <stdlib.h>

//【2】宏定义部分 
#define bool char
#define true 1
#define false 0 

//【3】自定义数据类型
typedef int ElemType; 

// 结点结构体
typedef struct Node {
    int data;  // 数据域
    struct Node* next;  // 指向下一个节点的指针
} Node, *LNode;

// 创建新节点
Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// 创建链表
LNode create_list(int num) 
{
    if (num <= 0) {
        return NULL;
    }

int i; 
    LNode head = create_node(-1);  // 创建头结点，数据域设置为-1
    LNode tmp = head;  // 临时节点，用于更新下一节点

    for (i = 0; i < num; ++i) {
        int data;
        printf("请输入第%d个结点的数据: ", i + 1);
        scanf("%d", &data);

        Node* node = create_node(data);  // 创建新节点
        tmp->next = node;
        tmp = node;  // 更新临时节点
    }

    return head;  // 返回头节点
}

// 打印链表
void print_list(LNode head) {
    LNode current = head->next;  // 从头结点的下一个节点开始打印
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 拆分链表
void split_list(LNode head, LNode* A, LNode* B) {
    *A = create_node(-1);  // 创建A链表的头结点
    *B = create_node(-1);  // 创建B链表的头结点

    LNode current = head->next;  // 从头结点的下一个节点开始
    LNode tailA = *A;
    LNode tailB = *B;

    while (current != NULL) {
        if (current->data % 2 == 0) {  // 偶数节点
            tailA->next = current;
            tailA = current;
        } else {  // 奇数节点
            tailB->next = current;
            tailB = current;
        }
        current = current->next;
    }

    tailA->next = NULL;  // 结束A链表
    tailB->next = NULL;  // 结束B链表
}

int main() {
    int num;
    printf("请输入链表的结点数量: ");
    scanf("%d", &num);

    LNode list = create_list(num);

    // 打印原始链表
    printf("原始链表: ");
    print_list(list);

    // 拆分链表
    LNode A, B;
    split_list(list, &A, &B);

    // 打印拆分后的链表
    printf("链表A (偶数): ");
    print_list(A);

    printf("链表B (奇数): ");
    print_list(B);

    // 释放链表内存
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
