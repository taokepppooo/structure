#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef int SElemType;

typedef struct {
    SElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1;
}

void Push(SqStack *S, SElemType e) {
    S->data[++S->top] = e;
}

SElemType Pop(SqStack *S) {
    return S->data[S->top--];
}

int main(int argc, char *argv[]) {
    SqStack S;
    InitStack(&S);
    Push(&S, 1);
    printf("%d\n", S.data[S.top]);
    Push(&S, 2);
    printf("%d\n", S.data[S.top]);
    Push(&S, 3);
    printf("%d\n", S.data[S.top]);
    Push(&S, 4);
    printf("%d\n", S.data[S.top]);
    Push(&S, 5);
    printf("%d\n", S.data[S.top]);
    printf("%d\n", Pop(&S));
    printf("%d\n", Pop(&S));
    printf("%d\n", Pop(&S));
    printf("%d\n", Pop(&S));
    printf("%d\n", Pop(&S));
    return 0;
}
