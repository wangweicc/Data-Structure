#include <stdio.h>
#include <stdlib.h>

// ����Ԫ������
typedef int ElemType;

// �ڽӱ��еı߽ڵ�
typedef struct EdgeNode {
    int adjvex; // �ñ���ָ��Ķ����λ��
    struct EdgeNode *next; // ָ����һ���ߵ�ָ��
} EdgeNode;

// �ڽӱ�ͷ�ڵ�
typedef struct VertexNode {
    ElemType data; // ������Ϣ
    EdgeNode *firstedge; // ָ���һ�������ö���ıߵ�ָ��
} VertexNode, AdjList[100];

// ͼ�Ķ���
typedef struct {
    AdjList adjlist;
    int numVertices, numEdges; // ͼ�е�ǰ�������ͱ���
} GraphAdjList;

// ����ͼ�ĺ���
void createGraph(GraphAdjList *graph) {
    int i, start, end;
    EdgeNode *e;

    printf("�����붥�����ͱ�����\n");
    scanf("%d %d", &graph->numVertices, &graph->numEdges);

    // ��ʼ���ڽӱ��ͷ�ڵ�
    for (i = 0; i < graph->numVertices; ++i) {
        graph->adjlist[i].data = i;
        graph->adjlist[i].firstedge = NULL;
    }

    // ������
    for (i = 0; i < graph->numEdges; ++i) {
        printf("�����(vi, vj)�ϵĶ������:\n");
        scanf("%d %d", &start, &end);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = end;
        e->next = graph->adjlist[start].firstedge;
        graph->adjlist[start].firstedge = e;

        // ���������ͼ�����������һ����
        // ע�͵������������������ͼ
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = start;
        e->next = graph->adjlist[end].firstedge;
        graph->adjlist[end].firstedge = e;
    }
}

// �����������
void DFS(GraphAdjList *graph, int visited[], int startVertex) {
    EdgeNode *e;

    printf("%d ", startVertex); // ��ӡ���ʵĶ���
    visited[startVertex] = 1; // ���Ϊ�ѷ���

    e = graph->adjlist[startVertex].firstedge;
    while (e != NULL) {
        if (!visited[e->adjvex]) {
            DFS(graph, visited, e->adjvex);
        }
        e = e->next;
    }
}

// �����������
void BFS(GraphAdjList *graph, int visited[]) {
    int queue[100], front = 0, rear = 0;
    int i, startVertex, w;
    EdgeNode *e;

    for (i = 0; i < graph->numVertices; ++i)
        if (!visited[i]) {
            startVertex = i;
            printf("%d ", startVertex);
            visited[startVertex] = 1;
            queue[rear++] = startVertex;

            while (front != rear) {
                w = queue[front++];
                e = graph->adjlist[w].firstedge;
                while (e != NULL) {
                    if (!visited[e->adjvex]) {
                        printf("%d ", e->adjvex);
                        visited[e->adjvex] = 1;
                        queue[rear++] = e->adjvex;
                    }
                    e = e->next;
                }
            }
        }
}

int main() {
    GraphAdjList graph;
    int visited[100] = {0}; // ��ʼ���������飬ȫ����Ϊδ����

    createGraph(&graph);

    printf("������ȱ������: ");
    int i; 
    for ( i = 0; i < graph.numVertices; ++i) {
        if (!visited[i])
            DFS(&graph, visited, i);
    }
    printf("\n");

    // ���÷��������Խ���BFS
    for (i = 0; i < graph.numVertices; ++i)
        visited[i] = 0;

    printf("������ȱ������: ");
    BFS(&graph, visited);
    printf("\n");

    return 0;
}
