#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
/**
 * @brief circular queue implementation
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-08-07 (16:57)
 *
 * @returns int
 */

int isFull(int *queue, int size)
{
    if (size == SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(int *queue, int size)
{
    if (size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int *queue, int *size, int item)
{
    if (isFull(queue, *size))
    {
        printf("Queue overflow\n");
    }
    else
    {
        queue[(*size)++] = item;
    }
}

void dequeue(int *queue, int *size)
{
    if (isEmpty(queue, *size))
    {
        printf("Queue underflow\n");
    }
    else
    {
        queue[--(*size)];
    }
}

void display(int *queue, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int queue[SIZE],
        size = 0,
        item,
        choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an item: ");
            scanf("%d", &item);
            enqueue(queue, &size, item);
            break;
        case 2:
            dequeue(queue, &size);
            break;
        case 3:
            display(queue, size);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            exit(0);
        }
    }

    return 0;
}
