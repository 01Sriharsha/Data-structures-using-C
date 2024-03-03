// Program to implement circular queue using static memory allocation

#include <stdio.h>
#define size 5

struct CircularQueue
{
    int queue[size];
    int front, rear;
} Q;

void enqueue(int item)
{
    if (Q.front == 0 && Q.rear == size - 1)
    {
        printf("Queue overflow");
        return;
    }
    if (Q.front == -1)
    {
        Q.front = 0;
    }
    Q.rear = (Q.rear + 1) % size;
    Q.queue[Q.rear] = item;
    printf("Rear after: %d", Q.rear);
}

void dequeue()
{
    if (Q.rear == -1 && Q.front == -1)
    {
        printf("Queue is empty");
        return;
    }
    if (Q.front == Q.rear)
    {
        printf("Queue is empty");
        Q.front = Q.rear = -1;
        return;
    }
    printf("Deleted item: %d", Q.queue[Q.front]);
    Q.front++;
}

void display()
{
    if (Q.rear == -1 && Q.front == -1)
    {
        printf("Queue is empty");
        return;
    }
    for (int i = Q.front; i <= Q.rear; i++)
    {
        printf("%d\t", Q.queue[i]);
    }
}

void main()
{
    Q.front = Q.rear = -1;
    int ch, item;

    while (1)
    {
        printf("\nMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...");
            return;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
