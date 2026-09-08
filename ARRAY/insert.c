#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int pos, value, key, found = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Insertion
    scanf("%d %d", &pos, &value);

    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    printf("After Insertion: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Deletion
    scanf("%d", &pos);

    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    printf("\nAfter Deletion: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Linear Search
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    if (found)
        printf("\nElement Found at index %d", i);
    else
        printf("\nElement Not Found");

    return 0;
}