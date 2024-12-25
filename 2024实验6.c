#include <stdio.h>
#include <stdlib.h>

// 定义元素类型
typedef int ElemType;

// 邻接表中的边节点
typedef struct EdgeNode {
    int adjvex; // 该边所指向的顶点的位置
    struct EdgeNode *next; // 指向下一条边的指针
} EdgeNode;

// 邻接表头节点
typedef struct VertexNode {
    ElemType data; // 顶点信息
    EdgeNode *firstedge; // 指向第一条依附该顶点的边的指针
} VertexNode, AdjList[100];

// 图的定义
typedef struct {
    AdjList adjlist;
    int numVertices, numEdges; // 图中当前顶点数和边数
} GraphAdjList;

// 创建图的函数
void createGraph(GraphAdjList *graph) {
    int i, start, end;
    EdgeNode *e;

    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &graph->numVertices, &graph->numEdges);

    // 初始化邻接表的头节点
    for (i = 0; i < graph->numVertices; ++i) {
        graph->adjlist[i].data = i;
        graph->adjlist[i].firstedge = NULL;
    }

    // 创建边
    for (i = 0; i < graph->numEdges; ++i) {
        printf("输入边(vi, vj)上的顶点序号:\n");
        scanf("%d %d", &start, &end);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = end;
        e->next = graph->adjlist[start].firstedge;
        graph->adjlist[start].firstedge = e;

        // 如果是无向图，还需添加另一条边
        // 注释掉下面两行如果是有向图
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = start;
        e->next = graph->adjlist[end].firstedge;
        graph->adjlist[end].firstedge = e;
    }
}

// 深度优先搜索
void DFS(GraphAdjList *graph, int visited[], int startVertex) {
    EdgeNode *e;

    printf("%d ", startVertex); // 打印访问的顶点
    visited[startVertex] = 1; // 标记为已访问

    e = graph->adjlist[startVertex].firstedge;
    while (e != NULL) {
        if (!visited[e->adjvex]) {
            DFS(graph, visited, e->adjvex);
        }
        e = e->next;
    }
}

// 广度优先搜索
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
    int visited[100] = {0}; // 初始化访问数组，全部设为未访问

    createGraph(&graph);

    printf("深度优先遍历结果: ");
    int i; 
    for ( i = 0; i < graph.numVertices; ++i) {
        if (!visited[i])
            DFS(&graph, visited, i);
    }
    printf("\n");

    // 重置访问数组以进行BFS
    for (i = 0; i < graph.numVertices; ++i)
        visited[i] = 0;

    printf("广度优先遍历结果: ");
    BFS(&graph, visited);
    printf("\n");

    return 0;
}
