/*
2、用户从键盘输入一个由整数数字构成的字符串，把字符串从左到右每隔2个断开，每2个数字组成1个2位整型数，若最后位数不足2位，则值为1位数。

（1）先建一个非空单链表A（带头结点），把上述分割后的整型数分别按输入顺序插入链表的结点，然后输出显示。(例如：输入124356789，输出12，43，56，78，9)

（2）接着将A链表进行整理，使得A链表前面都是偶数值结点，后面都是奇数值结点。操作结束后输出链表A的结点值。（例如输出12，56，78，43，9）

（3）然后用户输入区间位置left,right，将A链表上的该区间的结点进行倒置排列，然后输出A链表的各结点值。（例如输入2，4， 输出12，43，78，56，9内容
*/


//【1】头文件部分 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
LNode create_list_from_string(const char* str) {
    LNode head = create_node(-1);  // 创建头结点，数据域设置为-1
    LNode tmp = head;  // 临时节点，用于更新下一节点
    int len = strlen(str);
    int i; 

    for ( i = 0; i < len; i += 2) {
        int num = 0;
        if (i + 1 < len) {
            num = (str[i] - '0') * 10 + (str[i + 1] - '0');
        } else {
            num = str[i] - '0';
        }

        Node* node = create_node(num);  // 创建新节点
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

// 将链表中的偶数节点移到前面
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

// 反转链表的一部分
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
    printf("请输入一个由整数数字构成的字符串: ");
    scanf("%s", str);

    // 创建链表A
    LNode list = create_list_from_string(str);

    // 输出原始链表
    printf("原始链表: ");
    print_list(list);

    // 整理链表A，使得前面都是偶数值结点，后面都是奇数值结点
    rearrange_list(list);
    printf("整理后的链表A: ");
    print_list(list);

    // 用户输入区间位置left, right
    int left, right;
    printf("请输入要倒置的区间位置left, right: ");
    scanf("%d %d", &left, &right);

    // 反转指定区间的结点
    reverse_sublist(list, left, right);
    printf("反转后的链表A: ");
    print_list(list);

    // 释放链表内存
    while (list != NULL) {
        LNode temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
