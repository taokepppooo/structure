#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int SElemType;

typedef struct {
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

int InitStack(SqDoubleStack *S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return 0;
}

void Push(SqDoubleStack *S, SElemType e, int stackNumber) {
    if (S->top1 + 1 == S->top2) {
        return;
    }
    if (stackNumber == 1) {
        S->data[++S->top1] = e;
    } else if (stackNumber == 2) {
        S->data[--S->top2] = e;
    }
}

SElemType Pop(SqDoubleStack *S, int stackNumber) {
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return -1;
        }
        return S->data[S->top1--];
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return -1;
        }
        return S->data[S->top2++];
    }
}

int main(int argc, char *argv[]) {
    SqDoubleStack S;
    InitStack(&S);
    Push(&S, 1, 1);
    Push(&S, 2, 2);
    Push(&S, 3, 1);
    Push(&S, 4, 2);
    printf("%d\n", Pop(&S, 1));
    printf("%d\n", Pop(&S, 2));
    return 0;
}

