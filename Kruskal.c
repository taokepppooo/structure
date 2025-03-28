#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define MAXEDGE 100
#define INFINITY 32768
#define MAXVERTEXNUM 100

typedef struct MGraph{
    VertexType vexs[MAXVEX];
    EdgeType arcs[MAXVEX][MAXVEX];
    int vexnum, arcnum;
}MGraph;

typedef struct{
    int begin;
    int end;
    int weight;
}Edge;

void CreateMGraph(MGraph *G){
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    getchar();  // 清除输入缓冲区中的换行符
    
    for(i = 0; i < G->vexnum; i++){
        printf("请输入第%d个顶点：", i+1);
        scanf(" %c", &G->vexs[i]);  // 注意前面有一个空格，用于忽略空白字符
    }
    
    // 初始化邻接矩阵
    for(i = 0; i < G->vexnum; i++){
        for(j = 0; j < G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }
    
    // 输入边的信息
    for(k = 0; k < G->arcnum; k++){
        printf("请输入边(vi, vj)上的下标i, j和权值w：");
        scanf("%d %d %d", &i, &j, &w);
        
        // 确保顶点索引在有效范围内
        if(i >= 0 && i < G->vexnum && j >= 0 && j < G->vexnum) {
            G->arcs[i][j] = w;
            G->arcs[j][i] = w;  // 无向图，矩阵对称
        } else {
            printf("顶点索引超出范围，请重新输入！\n");
            k--; // 重新输入这条边
        }
    }
}

int Find(int *parent, int f){
  while(parent[f] > 0){
    f = parent[f];
  }
  return f;
}

void MinSpanTree_Kruskal(MGraph *G){
  int i, j, k, n, m;
  Edge edges[MAXEDGE]; // 保存所有的边
  int parent[MAXVEX];  // 判断边与边是否形成环路
  int edgeCount = 0;
  
  // 收集图中所有的边
  for(i = 0; i < G->vexnum; i++){
    for(j = i+1; j < G->vexnum; j++){ // 只收集上三角矩阵中的边
      if(G->arcs[i][j] != INFINITY){
        edges[edgeCount].begin = i;
        edges[edgeCount].end = j;
        edges[edgeCount].weight = G->arcs[i][j];
        edgeCount++;
      }
    }
  }
  
  // 对所有边按权值从小到大排序
  for(i = 0; i < edgeCount; i++){
    for(j = 0; j < edgeCount-i-1; j++){
      if(edges[j].weight > edges[j+1].weight){
        // 交换edges[j]和edges[j+1]
        Edge temp = edges[j];
        edges[j] = edges[j+1];
        edges[j+1] = temp;
      }
    }
  }
  
  // 初始化parent数组
  for(i = 0; i < G->vexnum; i++){
    parent[i] = 0;
  }
  
  // 添加边构造最小生成树
  printf("\n最小生成树的边：\n");
  for(i = 0; i < edgeCount; i++){
    n = Find(parent, edges[i].begin);
    m = Find(parent, edges[i].end);
    if(n != m){ // 如果不构成回路
      parent[n] = m; // 合并两个集合
      printf("(%c, %c) 权值: %d\n", 
             G->vexs[edges[i].begin], 
             G->vexs[edges[i].end], 
             edges[i].weight);
    }
  }
}

int main(){
    MGraph G;
    CreateMGraph(&G);
    
    // 打印图的信息
    printf("\n图的顶点：\n");
    for(int i = 0; i < G.vexnum; i++) {
        printf("%c ", G.vexs[i]);
    }
    
    printf("\n\n邻接矩阵：\n");
    for(int i = 0; i < G.vexnum; i++) {
        for(int j = 0; j < G.vexnum; j++) {
            if(G.arcs[i][j] == INFINITY)
                printf("∞ ");
            else
                printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
    MinSpanTree_Kruskal(&G);
    return 0; 
}
