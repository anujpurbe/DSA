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

int identical(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    if (root1->data != root2->data)
        return 0;

    return identical(root1->left, root2->left) &&
           identical(root1->right, root2->right);
}

int main()
{
    struct Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node *root2 = createNode(1);
    root2->left = createNode(1);
    root2->right = createNode(3);

    if (identical(root1, root2))
        printf("Trees are identical");
    else
        printf("Trees are not identical");

    return 0;
}