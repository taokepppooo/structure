#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
  int data;
  struct DNode *prior, *next;
}DNode, *DLinkList;

void InitDLinkList(DLinkList *L)
{
  *L = (DLinkList)malloc(sizeof(DNode));
  (*L)->prior = NULL;
  (*L)->next = NULL;
}

void ListInsert(DLinkList *L, int i, int e)
{
  // Start with head node
  DNode *p = *L;
  int j = 0;
  
  // Find the node at position i-1
  while(p && j < i-1)
  {
    p = p->next;
    j++;
  }
  
  // If position is invalid
  if(!p)
  {
    printf("插入位置不合法\n");
    return;
  }
  
  // Create new node
  DNode *s = (DNode *)malloc(sizeof(DNode));
  if(!s)
  {
    printf("内存分配失败\n");
    return;
  }
  s->data = e;
  
  // Insert the new node
  s->next = p->next;
  s->prior = p;
  
  // Handle connection to next node if it exists
  if(p->next)
  {
    p->next->prior = s;
  }
  
  // Connect the previous node to the new node
  p->next = s;
}

void ListDelete(DLinkList *L, int i, int *e)
{
  // Position must be valid
  if(i < 1)
  {
    printf("删除位置不合法\n");
    return;
  }
  
  // Start from head node
  DNode *p = *L;
  int j = 0;
  
  // Find node at position i-1
  while(p && j < i-1)
  {
    p = p->next;
    j++;
  }
  
  // If position is invalid or next node doesn't exist
  if(!p || !p->next)
  {
    printf("删除位置不合法\n");
    return;
  }
  
  // Get the node to delete
  DNode *q = p->next;
  *e = q->data;
  
  // Relink the list
  p->next = q->next;
  
  // Update prior pointer of next node if it exists
  if(q->next)
  {
    q->next->prior = p;
  }
  
  // Free the deleted node
  free(q);
}

void printfList(DLinkList L)
{
  DNode *p = L->next;
  while(p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  DLinkList L;
  int e;
  
  InitDLinkList(&L);
  printf("双向链表初始化完成\n");
  
  printf("开始插入元素：\n");
  ListInsert(&L, 1, 1);
  ListInsert(&L, 2, 2);
  ListInsert(&L, 3, 3);
  ListInsert(&L, 4, 4);
  ListInsert(&L, 5, 5);
  printf("所有元素插入完成\n");
  printf("当前链表：");
  printfList(L);
  ListDelete(&L, 3, &e);
  printf("删除位置 3 的元素（值为 %d）后：", e);
  printfList(L);
  
  return 0;
}

