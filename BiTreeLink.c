#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeLink{
    int data;
    struct BiTreeLink *lchild, *rchild;
}BiTreeLink, *BiTree;

BiTree CreateBiTree(BiTree T){
    int ch;
    printf("请输入节点值（-1表示空）：");
    scanf("%d", &ch);
    
    if (ch == -1)
        T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTreeLink));
        if (!T) {
            printf("内存分配失败\n");
            return NULL;
        }
        T->data = ch;
        printf("请输入%d的左子节点：", ch);
        T->lchild = CreateBiTree(T->lchild);
        printf("请输入%d的右子节点：", ch);
        T->rchild = CreateBiTree(T->rchild);
    }
    return T;
}

void PreOrderTraverse(BiTree T){
    if (T){
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T){
    if (T){
        InOrderTraverse(T->lchild);
        printf("%d ", T->data);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T){
    if (T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);
    }
}

void LevelOrderTraverse(BiTree T){
    if (!T) return;
    
    // 使用数组模拟队列
    BiTree queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        printf("%d ", p->data);
        
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
}

int main(int argc, char *argv[])
{
    BiTree T = NULL;
    printf("开始创建二叉树：\n");
    T = CreateBiTree(T);
    
    if (T) {
        printf("\n前序遍历：");
        PreOrderTraverse(T);
        printf("\n中序遍历：");
        InOrderTraverse(T);
        printf("\n后序遍历：");
        PostOrderTraverse(T);
        printf("\n层序遍历：");
        LevelOrderTraverse(T);
        printf("\n");
    } else {
        printf("二叉树为空！\n");
    }
    
    return 0;
}
