#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct {
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void CreateMGraph(MGraph *G){
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    getchar();  // 清除输入缓冲区中的换行符
    
    for(i = 0; i < G->numVertexes; i++){
        printf("请输入第%d个顶点：", i+1);
        scanf(" %c", &G->vexs[i]);  // 注意前面有一个空格，用于忽略空白字符
    }
    
    // 初始化邻接矩阵
    for(i = 0; i < G->numVertexes; i++){
        for(j = 0; j < G->numVertexes; j++){
            G->arc[i][j] = INFINITY;
        }
    }
    
    // 输入边的信息
    for(k = 0; k < G->numEdges; k++){
        printf("请输入边(vi, vj)上的下标i, j和权值w：");
        scanf("%d %d %d", &i, &j, &w);
        
        // 确保顶点索引在有效范围内
        if(i >= 0 && i < G->numVertexes && j >= 0 && j < G->numVertexes) {
            G->arc[i][j] = w;
            G->arc[j][i] = w;  // 无向图，矩阵对称
        } else {
            printf("顶点索引超出范围，请重新输入！\n");
            k--; // 重新输入这条边
        }
    }
}

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D){
    int v, w, k, min;
    int final[MAXVEX];
    // 初始化
    for(v = 0; v < G.numVertexes; v++){
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;
    }
    // 初始化v0顶点
    (*D)[v0] = 0;
    // 初始化v0顶点为已求得最短路径的顶点
    final[v0] = 1;
    // 开始主循环，每次求得v0到某个顶点v的最短路径并加到集合S中
    for(v = 1; v < G.numVertexes; v++){
        min = INFINITY;
        // 找到当前未确定最短路径的顶点中距离v0最近的顶点k
        for(w = 0; w < G.numVertexes; w++){
            if(!final[w] && (*D)[w] < min){
                k = w;
                min = (*D)[w];
            }
        }
        // 将当前找到的最近的顶点k加入到已确定最短路径的集合
        final[k] = 1;
        // 更新当前最短路径及距离
        for(w = 0; w < G.numVertexes; w++){
            if(!final[w] && (min + G.arc[k][w] < (*D)[w])){
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}

int main(){
    MGraph G;
    Patharc P;
    ShortPathTable D;
    int v0;
    printf("请输入起始顶点(0-based): ");
    scanf("%d", &v0);
    CreateMGraph(&G);
    ShortestPath_Dijkstra(G, v0, &P, &D);
    return 0;
}
