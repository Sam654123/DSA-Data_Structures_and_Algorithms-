#include <stdio.h>
#include <stdlib.h>

// Structure of Binary Tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Computing Height of Binary Tree Using Recursion
int maxDepth(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        // compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// Allocation of Node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Main Function
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("\n Height of tree is %d \n \n", maxDepth(root));

    return 0;
}