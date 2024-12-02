#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ��������������ȼ�
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

// ����׺���ʽת��Ϊ��׺���ʽ
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '#') {
        if (isalpha(infix[i])) {
            // ������ֱ����ӵ���׺���ʽ��
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            // ������ֱ����ջ
            stack[++top] = infix[i++];
        } else if (infix[i] == ')') {
            // �����ţ�����ջ��Ԫ��ֱ������������
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // ����������
            } else {
                printf("���Ų�ƥ��\n");
                return;
            }
            i++;
        } else {
            // ���������
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i++];
        }
    }

    // ��ʣ���ջ�����������
    while (top >= 0) {
        if (stack[top] == '(') {
            printf("���Ų�ƥ��\n");
            return;
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // �����ַ���
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("������һ���� # ��������׺���ʽ��");
    scanf("%99[^\n]", infix); // ��ȡһ�����룬�����ո�

    infixToPostfix(infix, postfix);

    printf("��׺���ʽ�� %s\n", postfix);

    return 0;
}
