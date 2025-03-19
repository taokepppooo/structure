#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

int InitStack(LinkStack *S) {
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    S->top = NULL;
    S->count = 0;
    return 1;
}

int Push(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return 1;
}

SElemType Pop(LinkStack *S, SElemType *e) {
    if (S->top == NULL) {
        return 0;
    }

    *e = S->top->data;
    LinkStackPtr p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
}

void printfStack(LinkStack *S) {
    LinkStackPtr p = S->top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(int argc, char *argv[]) {
    LinkStack S;
    InitStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    SElemType e;
    Pop(&S, &e);
    printf("%d\n", e);
    printfStack(&S);
    return 0;
}


