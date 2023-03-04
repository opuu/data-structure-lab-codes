#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Implement a C program that is able to insert element at beginning, last and any specific position using linked list.
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-08-18 (21:04)
 *
 * @returns int
 */

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_last(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_position(int data, int position)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        struct Node *temp = head;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void print_list()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Insert at beginning\n2. Insert at last\n3. Insert at position\n4. Print list\n5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_at_last(data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_at_position(data, position);
            break;
        case 4:
            print_list();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
