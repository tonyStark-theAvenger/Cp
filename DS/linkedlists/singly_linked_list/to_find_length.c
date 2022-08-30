#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top;
// function to create list
void create_list()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data \n");
    scanf("%d", &value);
    newnode->data = value;
    newnode->link = top;
    top = newnode;
}
// function to display created list
void display()
{

    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("\nElements of list are :\n");
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}
// function to count elements of list
void count()
{
    int count = 0;
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp != 0)
        {
            temp = temp->link;
            count++;
        }
        printf("length of list is %d", count);
    }
}
int main(int argc, char const *argv[])
{
    int choice;
    printf("Enter choice number\n1)push\n2)display\n3)length\n4)Exit\n");

    while (choice != 4)
    {
        printf("\nchoice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            count();
            break;
        case 4:
            printf("\nYou are out of program.");
            break;
        default:
            printf("\nEnter valid Input\n");
            break;
        }
    }

    return 0;
}
