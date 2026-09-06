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

struct Node *LCA(struct Node *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node *left = LCA(root->left, p, q);
    struct Node *right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}

int main()
{
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int p, q;

    scanf("%d %d", &p, &q);

    struct Node *result = LCA(root, p, q);

    if (result != NULL)
        printf("LCA: %d", result->data);
    else
        printf("LCA not found");

    return 0;
}