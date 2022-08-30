#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;
struct node *push();
struct node *pop();
void display();

int main(int argc, char const *argv[])
{
    int choice;
    printf("Enter choice number\n1)push\n2)pop\n3)display\n4)Exit\n");

    while (choice != 4)
    {
        printf("\nchoice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
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

struct node *push()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be pushed into the stack\n");
    scanf("%d", &value);
    newnode->data = value;
    newnode->link = top;
    top = newnode;
    return top;
}

struct node *pop()
{
    if (top == NULL)
    {
        printf("Stack is in underflow condition\n");
    }
    else
    {
        struct node *todel;
        if (top == NULL)
        {
            printf("stack is in Underflow contidion\n");
        }
        else
        {
            printf("Element %d iS poped from a stack", top->data);
            todel = top;
            top = top->link;
            free(todel);
        }
        return top;
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements of stack are\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}