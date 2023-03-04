#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Implement a BST and traverse the tree using Pre-order, inorder and Post-order (by taking user choice) Traversal using linked list.
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-08-23 (14:31)
 *
 * @returns int
 */

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }
    if ((*root)->data > data)
        insert(&(*root)->left, data);
    else if ((*root)->data < data)
        insert(&(*root)->right, data);
}

void traverse(struct Node *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return;
    }
    printf("Choose traversal type:\n1. Pre-order\n2. In-order\n3. Post-order\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return;
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n2. Traverse\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            traverse(root);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
