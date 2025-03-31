#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 32768

typedef struct {
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

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

void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D){
    int v, w, k;
    // 初始化
    for(v = 0; v < G.numVertexes; v++){
        for(w = 0; w < G.numVertexes; w++){
            (*D)[v][w] = G.arc[v][w];
            (*P)[v][w] = w;
        }
    }
    // 弗洛伊德算法
    for(k = 0; k < G.numVertexes; k++){
        for(v = 0; v < G.numVertexes; v++){
            for(w = 0; w < G.numVertexes; w++){
                if((*D)[v][w] > (*D)[v][k] + (*D)[k][w]){
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

int main(){
    MGraph G;
    Patharc P;
    ShortPathTable D;
    CreateMGraph(&G);
    ShortestPath_Floyd(G, &P, &D);
    return 0;
}
