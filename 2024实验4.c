#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 8
typedef int ElemType;

typedef struct {
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, ElemType x) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

ElemType dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1; // Assuming -1 as an error code
    }
    ElemType x = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return x;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    do {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != q->rear);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    char ch;
    while ((ch = getchar()) != '\n') { // Read until newline or EOF
        if (isdigit(ch)) {
            // Convert character to integer and enqueue
            enqueue(&q, ch - '0');
        } else if (islower(ch) && !isQueueEmpty(&q)) {
            // Dequeue if it's a lowercase letter and queue is not empty
            dequeue(&q);
        } else if (!isdigit(ch) && !islower(ch)) {
            // End of input processing
            break;
        }
    }

    displayQueue(&q); // Display the final state of the queue

    return 0;
}
