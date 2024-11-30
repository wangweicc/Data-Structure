#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

void checkSequence(char *input) {
    char stack[MAX + 1]; // ջ����
    int top = -1;        // ջ��ָ��
    int nextInput = 0;   // ��һ����Ҫ����������ַ�����
    int i, j;

    for (i = 0; i < strlen(input); i++) {
        if (nextInput <= input[i] - 'a') {
            // ģ����ջ����
            for (j = nextInput; j <= input[i] - 'a'; j++) {
                stack[++top] = 'a' + j;
                printf("Push %c\n", stack[top]);
            }
            nextInput = input[i] - 'a' + 1;
        }

        // ׼����ջ
        if (top >= 0 && stack[top] == input[i]) {
            printf("Pop %c\n", stack[top--]); // ģ���ջ����
        } else {
            // �����ǰջ��Ԫ�ز�����������ջ��Ԫ�أ��򲻿����ǺϷ�������
            printf("The sequence is not possible.\n");
            return;
        }
    }

    printf("The sequence is possible.\n");
}

int main() {
    char input[MAX + 1];
    printf("Enter a permutation of abcde: ");
    scanf("%s", input);

    if (strlen(input) != 5 || strchr(input, ' ') != NULL) {
        printf("Invalid input. Please enter exactly 5 characters without spaces and only from the set {a, b, c, d, e}.\n");
        return 1;
    }

    checkSequence(input);
    return 0;
}
