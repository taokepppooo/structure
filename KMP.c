#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *ch;
    int length;
} String;

typedef struct {
    int *nextval;
    int len;
} KMP;

void getNext(String T, int *nextval) {
    int i = 1;
    int k = 0;
    nextval[1] = 0;
    
    while (i < T.length) {
        printf("i = %d, k = %d\n", i, k);
        printf("%c \n", T.ch[i-1]);
        printf("%c \n", T.ch[k-1]);
        // 因为nextval是从1开始存储的，所以需要减1
        if (k == 0 || T.ch[i-1] == T.ch[k-1]) {
            ++i;
            ++k;
            if(T.ch[i-1] != T.ch[k-1]) {
              nextval[i] = k;
            }
            else {
              nextval[i] = nextval[k];
            }
        } else {
          k = nextval[k];
        }
    }
}

void initString(String *S, char *str) {
    S->ch = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(S->ch, str);
    S->length = strlen(str);
}

int indexKMP(String S, String T, int pos) {
    int i = pos;
    int j = 1;
    int nextval[255];
    getNext(T, nextval);
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i-1] == T.ch[j-1]) {
            ++i;
            ++j;
        } else {
            j = nextval[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
}

int main(int argc, char *argv[])
{
    String S, T;
    initString(&S, "ababaaababaa");
    initString(&T, "ababaa");

    int pos = indexKMP(S, T, 2);
    printf("pos = %d\n", pos);
    
    return 0;
}