#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
typedef enum {false, true} Boolean;
Boolean visited[MAXVEX];

typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    int in;
    int data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

typedef struct {
    int data[MAXVEX];
    int front;
    int rear;
} Queue;

void CreateGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
}

void DFS(GraphAdjList *G, int i) {
  int j;
  EdgeNode *p;
  visited[i] = true;
  printf("%d ", G->adjList[i].data);
  p = G->adjList[i].firstedge;
  while (p) {
    j = p->adjvex;
    if (!visited[j]) {
      DFS(G, j);
    }
    p = p->next;
  }
}

void DFSTraverse(GraphAdjList *G) {
    int i;
    for (i = 0; i < G->numVertexes; i++) {
        visited[i] = false;
    }
    for (i = 0; i < G->numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

void InitQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

void EnQueue(Queue *Q, int i) {
    Q->data[Q->rear] = i;
    Q->rear = (Q->rear + 1) % MAXVEX;
}

void DeQueue(Queue *Q, int *i) {
    *i = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXVEX;
}

Boolean QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

void BFSTraverse(GraphAdjList *G) {
    int i, j;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < G->numVertexes; i++) {
        visited[i] = false;
    }
    InitQueue(&Q);
    for (i = 0; i < G->numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            printf("%d ", G->adjList[i].data);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);
                p = G->adjList[i].firstedge;
                while (p) {
                    j = p->adjvex;
                    if (!visited[j]) {
                        visited[j] = true;
                        printf("%d ", G->adjList[j].data);
                        EnQueue(&Q, j);
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main() {
    GraphAdjList G;
    CreateGraph(&G);
    DFSTraverse(&G);
    BFSTraverse(&G);
    return 0;
}
