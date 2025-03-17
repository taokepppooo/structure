#include <stdio.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SequenceList;

void initList(SequenceList *L) {
    L->length = 0;
}

void clearList(SequenceList *L) {
    L->length = 0;
}

int getElem(SequenceList *L, int i, int *e) {
    if (i < 1 || i > L->length) {
        return 0;
    }

    *e = L->data[i - 1];
    return 1;
}

int listInsert(SequenceList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return 0;
    }

    if (L->length >= MAXSIZE) {
        return 0;
    }

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }

    L->data[i - 1] = e;
    L->length++;
    return 1;
}

int listDelete(SequenceList *L, int i, int *e) {
    if (i < 1 || i > L->length) {
        return 0;
    }
    
    *e = L->data[i - 1];
    for(int j = i; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }

    L->length--;
    return 1;
}

int main(int argc, char *argv[]) {
    SequenceList L;
    initList(&L);

    listInsert(&L, 1, 1);
    listInsert(&L, 2, 2);
    listInsert(&L, 3, 3);
    listInsert(&L, 4, 4);
    printf("The length of the list is %d\n", L.length);

    int e;
    getElem(&L, 2, &e);
    printf("The second element is %d\n", e);

    listDelete(&L, 2, &e);
    printf("The second element is %d\n", e);
    printf("The length of the list is %d\n", L.length);

    clearList(&L);
    printf("The length of the list is %d\n", L.length);
    
    return 0;
}
