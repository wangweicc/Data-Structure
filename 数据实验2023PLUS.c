#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

// ����˳��ջ�ṹ��
typedef struct {
    char data[MAX_SIZE];  // �洢ջԪ�ص�����
    int top;              // ջ��ָ��
} SeqStack;

// ��ʼ��ջ
void initStack(SeqStack *stack) {
    stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(SeqStack *stack) {
    return (stack->top == -1);
}

// �ж�ջ�Ƿ�����
int isFull(SeqStack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// ��ջ����
void push(SeqStack *stack, char value) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

// ��ջ����
char pop(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return '\0';  // ���ؿ��ַ���ʾ����
    }
    return stack->data[(stack->top)--];
}

// �鿴ջ��Ԫ��
char peek(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return '\0';  // ���ؿ��ַ���ʾ����
    }
    return stack->data[stack->top];
}

// ��ӡջ������Ԫ��
void printStack(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    int i; 
    for ( i = 0; i <= stack->top; ++i) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

// ��鲢ģ��������е���ջ��ջ����
void checkSequence(char *input) {
    SeqStack stack;
    initStack(&stack);

    int nextInput = 0;  // ��һ����Ҫ����������ַ�����
    int i, j;

    for (i = 0; i < strlen(input); i++) {
        if (nextInput <= input[i] - 'a') {
            // ģ����ջ����
            for (j = nextInput; j <= input[i] - 'a'; j++) {
                push(&stack, 'a' + j);
                printf("Push %c\n", 'a' + j);
            }
            nextInput = input[i] - 'a' + 1;
        }

        // ׼����ջ
        if (!isEmpty(&stack) && peek(&stack) == input[i]) {
            printf("Pop %c\n", pop(&stack));  // ģ���ջ����
        } else {
            // �����ǰջ��Ԫ�ز�����������ջ��Ԫ�أ��򲻿����ǺϷ�������
            printf("The sequence is not possible.\n");
            return;
        }
    }

    printf("The sequence is possible.\n");
}

int main() {
    char input[MAX_SIZE + 1];

    // ��һ���֣�����ջ����
    SeqStack stack;
    initStack(&stack);

    int choice, value;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print\n5. Check Sequence\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push (a-e): ");
                scanf(" %c", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != '\0') {
                    printf("Popped: %c\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != '\0') {
                    printf("Top element: %c\n", value);
                }
                break;
            case 4:
                printStack(&stack);
                break;
            case 5:
                printf("Enter a permutation of abcde: ");
                scanf("%s", input);
                if (strlen(input) == 5) {
                    checkSequence(input);
                } else {
                    printf("Invalid input. Please enter exactly 5 characters from the set {a, b, c, d, e}.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
