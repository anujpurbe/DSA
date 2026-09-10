#include <stdio.h>

int main()
{
    int arr[100], n, key;
    int low, high, mid;
    int first = -1, last = -1;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element: ");
    scanf("%d", &key);

    // First occurrence
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            first = mid;
            high = mid - 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Last occurrence
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            last = mid;
            low = mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (first == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("First occurrence: %d\n", first);
        printf("Last occurrence: %d\n", last);
        printf("Count: %d\n", last - first + 1);
    }

    return 0;
}