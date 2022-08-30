#include <stdio.h>
#include <stdlib.h>
/*
TO INSERT NODE AT ENDING OF LINKED LIST
**********MYSG METHOD***********
*/
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

// struct node *createnode()
// {
//     struct node *n;
//    n = (struct node *)malloc(sizeof(struct node));
//     return (n);
// }
// void insert()
// {
//     struct node *temp, *x;
//     temp = createnode();
//     printf("Enter the data to be inserted at last of a list\n");
//     scanf("%d", &temp->data);
//     temp->link = NULL;
//     if (start == NULL)
//     {
//         start = temp;
//     }
//     else
//     {

//         x = start;
//         while (x->link != 0)
//         {
//             x = x->link;
//             /* code */
//         }
//         x->link = temp;
//     }
// }

void push(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->link = start;
    start = newnode;
    printf("The value %d is pushed into the stack\n", value);
}
void display()
{

    struct node *temp;
    temp = start;
    if (start == 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->link;
            /* code */
        }
    }
}
int main()
{
    int choice, value;
    while (1)
    {

        printf("\n1)push\n2)display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &value);
            push(value);
            /* code */
            break;
        case 2:
            printf("linked list is:\n");
            display();
            break;

        default:
            printf("Enter valid choice\n");
            break;
        }
    }
}