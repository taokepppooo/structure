#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;

#define MAXSIZE 100

typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

int InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int main(int argc, char *argv[]) {
    SqQueue Q;
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
