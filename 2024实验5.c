#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 15
#define NAME_LEN 2

typedef struct Node {
    int weight;
    char name[NAME_LEN];
    struct Node *left, *right;
} Node;

// 创建新节点
Node* createNode(int weight, const char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->weight = weight;
    strcpy(node->name, name);
    node->left = node->right = NULL;
    return node;
}

// 最小堆
typedef struct MinHeap {
    int size;
    Node **array;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->array = (Node **)malloc(capacity * sizeof(Node *));
    return minHeap;
}

void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(MinHeap *minHeap) {
    int n = minHeap->size - 1;
    int i; 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

Node* extractMin(MinHeap *minHeap) {
    Node *min = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return min;
}

void insertMinHeap(MinHeap *minHeap, Node *node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    minHeap->array[i] = node;
    while (i && minHeap->array[i]->weight < minHeap->array[(i - 1) / 2]->weight) {
        swapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 构建赫夫曼树
Node* buildHuffmanTree(int weights[], char names[][NAME_LEN], int size) {
    MinHeap *minHeap = createMinHeap(size);
    int i;

    for (i = 0; i < size; ++i)
        insertMinHeap(minHeap, createNode(weights[i], names[i]));

    buildMinHeap(minHeap);

    while (!minHeap->size || minHeap->size > 1) {
        Node *left = extractMin(minHeap);
        Node *right = extractMin(minHeap);

        static int tempNodeCounter = 0;
        char tempName[NAME_LEN];
        sprintf(tempName, "T%d", tempNodeCounter++);

        Node *top = createNode(left->weight + right->weight, tempName);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    Node *root = extractMin(minHeap);
    free(minHeap->array);
    free(minHeap);
    return root;
}

// 层次遍历赫夫曼树并打印
void printLevelOrder(Node *root) {
    if (!root) return;

    // 使用队列进行层次遍历
    Node *queue[MAX_NODES * 2];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int i;
        for ( i = levelSize - 1; i >= 0; --i) {
            Node *current = queue[front++];
            printf("%s(%d) ", current->name, current->weight);
            if (current->right) queue[rear++] = current->right;
            if (current->left) queue[rear++] = current->left;
        }
        printf("\n");
    }
}

int main() {
    int weights[MAX_NODES];
    char names[MAX_NODES][NAME_LEN];

    printf("请输入不超过15个整数作为节点的权值(输入-1结束程序):\n");
    int n;
    for (n = 0; n < MAX_NODES; ++n) {
        if (scanf("%d", &weights[n]) != 1) break;
        if (weights[n] == -1){
        	break;
		} 
    }

    if (n == 0) {
        printf("没有输入任何数据。\n");
        return 1;
    }

int i;
    for ( i = 0; i < n; ++i) {
        sprintf(names[i], "%c", 'A' + i);
    }

    Node *root = buildHuffmanTree(weights, names, n);
    printLevelOrder(root);

    // 清理内存
    // 注意：这里应递归释放所有节点，但为了简化示例，省略了这部分代码

    return 0;
}
