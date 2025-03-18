#include <stdio.h>

#define MAXSIZE 1000

typedef struct {
  int data;
  int cur;
} Component, StaticLinkList[MAXSIZE];

void initSpace(StaticLinkList space)
{
  for(int i = 0; i < MAXSIZE - 1; i++)
  {
    space[i].cur = i + 1;
  }
  space[MAXSIZE - 1].cur = 0;
}

int Malloc_SLL(StaticLinkList space)
{
  int i = space[0].cur;
  if(space[0].cur)
  {
    space[0].cur = space[i].cur;
  }

  return i;
}

void Free_SLL(StaticLinkList space, int k)
{
  space[k].cur = space[0].cur;
  space[0].cur = k;
}

int listLength(StaticLinkList L)
{
  int j = 0;
  int i = L[MAXSIZE - 1].cur;
  while(i)
  {
    j++;
    i = L[i].cur;
  }
  return j;
}

void listInsert(StaticLinkList L, int i, int e)
{
  int j, k, l;
  k = MAXSIZE - 1;
  if(i < 1 || i > listLength(L) + 1)
  {
    printf("插入位置不合法\n");
    return;
  }

  j = Malloc_SLL(L);
  if(j)
  {
    L[j].data = e;
    for(l = 1; l <= i - 1; l++)
    {
      k = L[k].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;
  }
}

void listDelete(StaticLinkList L, int i)
{
  int j, k;
  if(i < 1 || i > listLength(L))
  {
    printf("删除位置不合法\n");
    return;
  }

  k = MAXSIZE - 1;

  for(j = 1; j <= i - 1; j++)
  {
    k = L[k].cur;
  }

  j = L[k].cur;
  L[k].cur = L[j].cur;
  Free_SLL(L, j);
}

void printfList(StaticLinkList L)
{
  int i = L[MAXSIZE - 1].cur;
  while(i)
  {
    printf("%d ", L[i].data);
    i = L[i].cur;
    printf("cur: %d\n", L[i].cur);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  StaticLinkList L;
  initSpace(L);
  printf("初始化完成\n");
  printfList(L);
  listInsert(L, 1, 1);
  listInsert(L, 1, 2);
  listInsert(L, 1, 3);
  listInsert(L, 1, 4);
  listInsert(L, 1, 5);
  printf("插入完成\n");
  printfList(L);
  listDelete(L, 3);
  printf("删除完成\n");
  printfList(L);
  return 0;
}
