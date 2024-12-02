#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// 返回运算符的优先级
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

// 将中缀表达式转换为后缀表达式
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '#') {
        if (isalpha(infix[i])) {
            // 操作数直接添加到后缀表达式中
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            // 左括号直接入栈
            stack[++top] = infix[i++];
        } else if (infix[i] == ')') {
            // 右括号，弹出栈顶元素直到遇到左括号
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // 弹出左括号
            } else {
                printf("括号不匹配\n");
                return;
            }
            i++;
        } else {
            // 处理运算符
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i++];
        }
    }

    // 将剩余的栈内运算符弹出
    while (top >= 0) {
        if (stack[top] == '(') {
            printf("括号不匹配\n");
            return;
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // 结束字符串
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("请输入一个以 # 结束的中缀表达式：");
    scanf("%99[^\n]", infix); // 读取一行输入，包括空格

    infixToPostfix(infix, postfix);

    printf("后缀表达式： %s\n", postfix);

    return 0;
}
