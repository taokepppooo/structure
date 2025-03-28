#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100

typedef struct EdgeNode{
    int adjvex;
    EdgeType info;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
  AdjList adjList;
  int vexnum, arcnum;
}ALGraph;

void CreateALGraph(ALGraph *G){
  int i, j, k;
  EdgeNode *e;
  printf("请输入顶点数和边数：");
  scanf("%d %d", &G->vexnum, &G->arcnum);
  getchar();  // 清除输入缓冲区中的换行符

  for(i = 0; i < G->vexnum; i++){
    printf("请输入第%d个顶点：", i+1);
    scanf("%c", &G->adjList[i].data);
    getchar();  // 清除输入缓冲区中的换行符
    G->adjList[i].firstedge = NULL;
  }
  for(k = 0; k < G->arcnum; k++){
    printf("请输入边(vi, vj)上的顶点序号：\n");
    scanf("%d %d", &i, &j);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjList[j].firstedge;
    G->adjList[j].firstedge = e;
  }
}

int main(){
  ALGraph G;
  CreateALGraph(&G);
  return 0;
}