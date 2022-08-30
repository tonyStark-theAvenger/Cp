#include <stdio.h>
#define MAX 10

void enqueue();
void dequeue();
void display();
int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice;

    printf("Enter choice number\n1)enqueue\n2)dequeue\n3)display\n4)Exit");
    while (choice != 4)
    {
        printf("\nChoice number: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You are out of program\n");
            break;
        default:
            printf("\nEnter valid choice");
            break;
        }
    }
}

void enqueue()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("Queue is in Overflow condition\n");
    }
    else if (rear == -1 && front == -1)
    {
        printf("Enter value to be enqueued: ");
        scanf("%d", &value);
        rear == front == 0;
        queue[rear] = value;
    }

    else
    {
        printf("Enter value to be enqueued: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (rear == -1 || front > rear)
    {
        printf("Queue is in Underflow condition\n");
    }
    else if (rear == front)
    {
        printf("Element %d is dequeued from queue\n", queue[front]);
        rear = front = -1;
    }
    else
    {
        printf("Element %d is dequeued from queue\n", queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if (rear == -1 || front > rear)
    {
        printf("Queue is in Underflow condition\n");
    }
    else
    {
        printf("Elements of queue are\n");
        for (i = front; i < rear + 1; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}