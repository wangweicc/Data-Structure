#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    char data[MAX_EXPRESSION_LENGTH];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(const Stack *s) {
    return s->top == -1;
}

bool isFull(const Stack *s) {
    return s->top == MAX_EXPRESSION_LENGTH - 1;
}

bool push(Stack *s, char item) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = item;
    return true;
}

bool pop(Stack *s, char *item) {
    if (isEmpty(s)) return false;
    *item = s->data[(s->top)--];
    return true;
}

char peek(const Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack operators;
    initStack(&operators);
    int i = 0, j = 0;
    
    while (infix[i] != '#') {
        // Skip spaces in the input
        if (isspace(infix[i])) {
            i++;
            continue;
        }

        if (isalpha(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&operators, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&operators) && peek(&operators) != '(') {
                pop(&operators, &postfix[j++]);
            }
            if (!isEmpty(&operators)) {
                char temp;
                pop(&operators, &temp); // Pop '(' and discard it
            }
            i++;
        } else {
            while (!isEmpty(&operators) && precedence(peek(&operators)) >= precedence(infix[i])) {
                pop(&operators, &postfix[j++]);
            }
            push(&operators, infix[i++]);
        }
    }
    
    while (!isEmpty(&operators)) {
        pop(&operators, &postfix[j++]);
    }
    
    postfix[j] = '\0'; // Null terminate the string
}

int main() {
    char infix[MAX_EXPRESSION_LENGTH], postfix[MAX_EXPRESSION_LENGTH];
    
    printf("请输入中缀表达式（以#结束）：");
    scanf("%99[^\n]", infix); // Read until newline or max length
    
    // Clear the newline character left in the buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    infixToPostfix(infix, postfix);
    
    printf("后缀表达式为：%s\n", postfix);
    
    return 0;
}
