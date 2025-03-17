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
}

void Free_SLL(StaticLinkList space, int k)
{
  space[k].cur = space[0].cur;
  space[0].cur = k;
}

int main(int argc, char *argv[])
{
  return 0;
}
