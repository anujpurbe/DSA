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

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // RR
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // LR
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *minValueNode(struct Node *root)
{
    struct Node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    // Search for node
    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Only right child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Only left child
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance
    int balance = getBalance(root);

    // LL
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
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

    root = deleteNode(root, deleteValue);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    return 0;
}