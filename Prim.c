#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 32768
#define MAXVERTEXNUM 100

typedef struct MGraph{
    VertexType vexs[MAXVEX];
    EdgeType arcs[MAXVEX][MAXVEX];
    int vexnum, arcnum;
}MGraph;

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

void MinSpanTree_Prim(MGraph *G){
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];

    lowcost[0] = 0;
    adjvex[0] = 0;
    for(i = 1; i < G->vexnum; i++){
        lowcost[i] = G->arcs[0][i];
        adjvex[i] = 0;
    }
    for(i = 1; i < G->vexnum; i++){
        min = INFINITY;
        j = 1;
        k = 0;
        while(j < G->vexnum){
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k);
        lowcost[k] = 0;
        for(j = 1; j < G->vexnum; j++){
            if(G->arcs[k][j] < lowcost[j]){
                lowcost[j] = G->arcs[k][j];
                adjvex[j] = k;
            }
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
    MinSpanTree_Prim(&G);
    return 0; 
}
