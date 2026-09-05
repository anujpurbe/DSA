#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalance(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

int main()
{
    struct Node *root = createNode(50);

    root->left = createNode(30);
    root->right = createNode(70);

    root->height = 2;

    printf("Height: %d\n", height(root));
    printf("Balance Factor: %d", getBalance(root));

    return 0;
}