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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int balancefactor(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
struct Node *rightrotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t1 = x->right;
    x->right = y;
    y->left = t1;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
struct Node *leftrotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t1 = y->left;
    y->left = x;
    x->right = t1;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balancefactor(root);
    if (balance > 1 && data < root->left->data)
    {
        return rightrotation(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return leftrotation(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}
struct Node *minValuesNodes(struct Node *root)
{
    struct Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct Node *delete(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = minValuesNodes(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balancefactor(root);
    if (balance > 1 && balancefactor(root->left) >= 0)
    {
        return rightrotation(root);
    }
    if (balance < -1 && balancefactor(root->right) <= 0)
    {
        return leftrotation(root);
    }
    if (balance > 1 && balancefactor(root->left) < 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (balance < -1 && balancefactor(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    int n, value, deleteValue;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    scanf("%d", &deleteValue);
    root = delete(root, deleteValue);
    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    return 0;
}
