#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

void checkSequence(char *input) {
    char stack[MAX + 1]; // 栈数组
    int top = -1;        // 栈顶指针
    int nextInput = 0;   // 下一个将要处理的输入字符索引
    int i, j;

    for (i = 0; i < strlen(input); i++) {
        if (nextInput <= input[i] - 'a') {
            // 模拟入栈操作
            for (j = nextInput; j <= input[i] - 'a'; j++) {
                stack[++top] = 'a' + j;
                printf("Push %c\n", stack[top]);
            }
            nextInput = input[i] - 'a' + 1;
        }

        // 准备出栈
        if (top >= 0 && stack[top] == input[i]) {
            printf("Pop %c\n", stack[top--]); // 模拟出栈操作
        } else {
            // 如果当前栈顶元素不等于期望出栈的元素，则不可能是合法的序列
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
