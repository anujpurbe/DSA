#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotateLeft(int arr[], int n, int k)
{
    k = k % n;

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

void rotateRight(int arr[], int n, int k)
{
    k = k % n;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[100], n, k, choice;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &choice);

    if (choice == 1)
    {
        reverse(arr, 0, n - 1);
        printArray(arr, n);
    }
    else if (choice == 2)
    {
        scanf("%d", &k);
        rotateLeft(arr, n, k);
        printArray(arr, n);
    }
    else if (choice == 3)
    {
        scanf("%d", &k);
        rotateRight(arr, n, k);
        printArray(arr, n);
    }

    return 0;
}