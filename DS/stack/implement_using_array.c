// MADE IN SINGLE ATTEMPT WITHOUT COPING FROM ANYTHING

#include <stdio.h>
#define MAX 10

void push();
void pop();
void display();
int stack[MAX];
int top = -1;

int main()
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
            printf("You are out of program.");
            break;
        default:
            break;
        }
    }

    return 0;
}

void push()
{
    int value;
    if (top >= MAX - 1)
    {
        printf("Stack is in Overflow condition\n");
    }
    else
    {
        printf("Enter the value to be pushed into the stack\n");
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is in Underflow condition\n");
    }
    else
    {
        printf("Element %d is poped from a stack\n", stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is in Underflow condition\n");
    }

    else
    {

        printf("Elements of stack are: \n");
        for (i = 0; i < top + 1; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}