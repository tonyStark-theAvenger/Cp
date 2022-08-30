#include <stdio.h>
#include <stdlib.h>
/*
TO INSERT NODE AT ALL 4 CONDITIONS COVERED
  **********HARRY METHOD***********
*/
struct Node
{
  int data;
  struct Node *link;
};

void printlist(struct Node *ptr)
{
  while (ptr != 0)
  {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->link;
  }
}

struct Node *insertatstart(struct Node *head, int data)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->link = head;
  head = newnode;
  return (head);
}

struct Node *insertatgivenindex(struct Node *head, int data, int index)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = head;
  int i = 0;

  while (i != index - 1)
  {
    p = p->link;
    i++;
  }
  ptr->data = data;
  ptr->link = p->link;
  p->link = ptr;
  return head;
}
struct Node *insertatend(struct Node *head, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = head;
  ptr->data = data;
  while (p->link != NULL)
  {
    p = p->link;
  }
  p->link = ptr;
  ptr->link = NULL;
  return head;
}

struct Node *insertatgiveafteranode(struct Node *head, int data, struct Node *prevnode)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  ptr->link = prevnode->link;
  prevnode->link = ptr;
  return head;
}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *new;
  //to give memory in heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 1;
  head->link = second;

  second->data = 2;
  second->link = third;

  third->data = 3;
  third->link = NULL;
  printf("previous list is\n");
  printlist(head);
  printf("new list after insertiion is\n");
  // head = insertatstart(head, 0);
  // head = insertatgivenindex(head, 11, 2);
  head = insertatend(head, 10);
  // head = insertatgiveafteranode(head, 15, second);
  printlist(head);

  return 0;
}