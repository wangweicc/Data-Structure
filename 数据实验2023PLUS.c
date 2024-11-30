#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

// 定义顺序栈结构体
typedef struct {
    char data[MAX_SIZE];  // 存储栈元素的数组
    int top;              // 栈顶指针
} SeqStack;

// 初始化栈
void initStack(SeqStack *stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(SeqStack *stack) {
    return (stack->top == -1);
}

// 判断栈是否已满
int isFull(SeqStack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// 入栈操作
void push(SeqStack *stack, char value) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

// 出栈操作
char pop(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return '\0';  // 返回空字符表示错误
    }
    return stack->data[(stack->top)--];
}

// 查看栈顶元素
char peek(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return '\0';  // 返回空字符表示错误
    }
    return stack->data[stack->top];
}

// 打印栈内所有元素
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

// 检查并模拟给定序列的入栈出栈操作
void checkSequence(char *input) {
    SeqStack stack;
    initStack(&stack);

    int nextInput = 0;  // 下一个将要处理的输入字符索引
    int i, j;

    for (i = 0; i < strlen(input); i++) {
        if (nextInput <= input[i] - 'a') {
            // 模拟入栈操作
            for (j = nextInput; j <= input[i] - 'a'; j++) {
                push(&stack, 'a' + j);
                printf("Push %c\n", 'a' + j);
            }
            nextInput = input[i] - 'a' + 1;
        }

        // 准备出栈
        if (!isEmpty(&stack) && peek(&stack) == input[i]) {
            printf("Pop %c\n", pop(&stack));  // 模拟出栈操作
        } else {
            // 如果当前栈顶元素不等于期望出栈的元素，则不可能是合法的序列
            printf("The sequence is not possible.\n");
            return;
        }
    }

    printf("The sequence is possible.\n");
}

int main() {
    char input[MAX_SIZE + 1];

    // 第一部分：基本栈操作
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
