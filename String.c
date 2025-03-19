#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *ch;
    int length;
} String;

int StrLength(String S) {
    return S.length;
}

String SubString(String S, int pos, int len) {
    String sub;
    sub.ch = (char *)malloc(sizeof(char) * len);
    sub.length = len;
    for (int i = 0; i < len; i++) {
        sub.ch[i] = S.ch[pos + i];
    }
}

int StrCompare(String S, String T) {
    for (int i = 0; i < S.length && i < T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

int Index(String S, String T, int pos) {
    if (pos > 0) {
        int n = StrLength(S);
        int m = StrLength(T);
        int i = pos;
        int j = 1;
        while (i <= n && j <= m) {
            if (S.ch[i] == T.ch[j]) {
                i++;
                j++;
            } else {
                i = i - j + 2;
                j = 1;
            }
        }
        if (j > m) {
            return i - m;
        }
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    String S;
    S.ch = (char *)malloc(sizeof(char) * 100);
    S.length = 0;
    return 0;
}

