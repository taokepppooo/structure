#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;
typedef struct Node *LinkList;

void createListHead(LinkList *L, int n)
{
  LinkList p;
  *L = (LinkList)malloc(sizeof(Node));
  (*L)->next = NULL;
  for (int i = 0; i < n; i++)
  {
    p = (LinkList)malloc(sizeof(Node));
    p->data = i;
    p->next = (*L)->next;
    (*L)->next = p;
  }
}
void createListTail(LinkList *L, int n)
{
  LinkList p, r;
  *L = (LinkList)malloc(sizeof(Node));
  r = *L;
  for (int i = 0; i < n; i++)
  {
    p = (LinkList)malloc(sizeof(Node));
    p->data = i;
    r->next = p;
    r = p;
  }
  r->next = NULL;
}

void printList(LinkList L) {
  LinkList p = L->next;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

void getElem(LinkList L, int i, int *e) {
  LinkList p = L->next;
  int j = 0;
  while(p && j < i)
  {
    p = p->next;
    j++;
  }
  
  if(!p || j > i)
  {
    printf("第%d个元素不存在\n", i);
    return;
  }

  *e = p->data;
}

void listInsert(LinkList *L, int i, int e) {
  LinkList p, s;
  p = *L;
  int j = 0;
  s = (LinkList)malloc(sizeof(Node));
  while(p && j < i)
  {
    p = p->next;
    j++;
  }

  s->data = e;
  s->next = p->next;
  p->next = s;
}

void listDelete(LinkList *L, int i, int *e) {
  LinkList p, q;
  p = *L;
  int j = 1; // 从1开始
  while(p->next && j < i)
  {
    p = p->next;
    j++;
  }

  q = p->next;
  *e = q->data;
  p->next = q->next;
  free(q);
}



int main(int argc, char *argv[])
{
  LinkList L;
  int e;
  createListHead(&L, 10);
  printList(L);
  printf("\n");
  createListHead(&L, 20);
  printList(L);
  printf("\n");
  listInsert(&L, 1, 100);
  printList(L);
  printf("\n");
  listDelete(&L, 3, &e);
  printList(L);
  printf("\n");
  printf("删除的元素是：%d\n", e);
  return 0;
}
