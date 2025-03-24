#include <stdio.h>
#include <stdlib.h>

typedef struct BiThrNode{
    int data;
    struct BiThrNode *lchild, *rchild;
    int ltag, rtag;
}BiThrNode, *BiThrTree;

BiThrTree pre;

void initBiThrTree(BiThrTree T){
    printf("请输入根节点（-1表示空）：");
    scanf("%d", &T->data);
    if (T->data == -1){
        T = NULL;
    }
    else{
      initBiThrTree(T->lchild);
      initBiThrTree(T->rchild);
    }
}

void InThreading(BiThrTree T){
  if (T){
    InThreading(T->lchild);
    if (!T->lchild){
      T->ltag = 1;
      T->lchild = pre;
    }
    if (!pre->rchild){
      pre->rtag = 1;
      pre->rchild = T;
    }
    pre = T;
    InThreading(T->rchild);
  }
}

// 中序线索化
void InOrderThreading(BiThrTree T){
  BiThrTree p;
  p = T->lchild;
  while (p != T){
    while (p->ltag == 0){
      p = p->lchild;
    }
    printf("%d ", p->data);
    while (p->rtag == 1 && p->rchild != T){
      p = p->rchild;
      printf("%d ", p->data);
    }
    p = p->rchild;
  }
  printf("\n");
}

int main(){
    BiThrTree T;
    initBiThrTree(T);
    InThreading(T);
    InOrderThreading(T);
    return 0;
}


