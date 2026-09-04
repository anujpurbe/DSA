#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Minimum: %d\n", findMin(root)->data);
    printf("Maximum: %d", findMax(root)->data);

    return 0;
}