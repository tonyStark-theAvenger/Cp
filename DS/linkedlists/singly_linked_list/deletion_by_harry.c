#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
    /* data */
};
void printlist(struct Node *ptr)
{
    while (ptr != 0)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->link;
    }
}
struct Node *deleting_from_start(struct Node *head)
{
    struct Node *temp;
    temp = head;
    head = head->link;
    free(temp);
    return head;
}
struct Node *deleting_from_indexnumber(struct Node *head, int index)
{
    struct Node *predel;
    struct Node *todel;

    predel = head;
    todel = head->link;
    int i = 0;
    while (i != index - 1)
    {
        todel = todel->link;
        predel = predel->link;
        i++;
    }

    predel->link = todel->link;
    free(todel);
    return head;
}

struct Node *deleting_lastnode(struct Node *head)
{
    struct Node *predel;
    struct Node *todel;
    predel = head;
    todel = head->link;
    while (todel->link != NULL)
    {
        predel = predel->link;
        todel = todel->link;
    }
    predel->link = NULL;
    free(todel);
    return head;
}
struct Node *deleting_from_givendata(struct Node *head, int data)
{
    struct Node *predel;
    struct Node *todel;

    predel = head;
    todel = head->link;
    while (todel->data != data && todel->link != NULL)
    {
        todel = todel->link;
        predel = predel->link;
    }

    if (todel->data == data)
    {
        predel->link = todel->link;
        free(todel);
    }
    else
    {
        printf("Enter element is not in list\n");
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    //to give memory in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->link = second;

    second->data = 2;
    second->link = third;

    third->data = 3;
    third->link = fourth;

    fourth->data = 4;
    fourth->link = fifth;

    fifth->data = 5;
    fifth->link = NULL;

    printf("--- Before ---\n");
    printlist(head);
    head = deleting_from_givendata(head, 3);
    printf("--- After ---\n");
    printlist(head);
    return 0;
}