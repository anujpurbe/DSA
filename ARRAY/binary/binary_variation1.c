#include <stdio.h>

int main()
{
    int arr[100], n, key;
    int low = 0, high, mid;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element: ");
    scanf("%d", &key);

    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Insert position: %d\n", low);

    return 0;
}