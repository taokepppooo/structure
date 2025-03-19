#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

int InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) {
        return 0;
    }
    Q->front->next = NULL;
    Q->rear->next = NULL;
    return 1;
}

int EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) {
        return 0;
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return 1;
}

int DeQueue(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return 0;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return 1;
}

int QueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        length++;
        p = p->next;
    }
    return length;
}

int main(int argc, char *argv[]) {
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    QElemType e;
    DeQueue(&Q, &e);
    printf("%d\n", e);
    printf("%d\n", QueueLength(Q));
    return 0;
}
