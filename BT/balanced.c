#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = height(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int isBalanced(struct Node *root)
{
    return height(root) != -1;
}

int main()
{
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    if (isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");

    return 0;
}