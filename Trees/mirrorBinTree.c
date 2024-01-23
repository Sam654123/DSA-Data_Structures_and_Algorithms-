#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Inserting Node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Mirroring Binary Tree
void mirror(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        struct Node *temp;

        mirror(root->left);
        mirror(root->right);

        // Swapping Nodes
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// Printing Binary Tree in InOrder Pattern
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main Function
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Binary Tree in InOrder Traversal: \n");
    inOrder(root);

    mirror(root);

    printf("\n\nAfter Mirroring,\nBinary Tree in InOrder Traversal: \n");
    inOrder(root);

    return 0;
}