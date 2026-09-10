#include <stdio.h>

int main()
{
    int arr[100], n;
    int visited[100] = {0};

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nFrequency:\n");

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d -> %d\n", arr[i], count);
    }

    printf("\nDuplicate elements: ");

    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            printf("%d ", arr[i]);
            found = 1;

            while (i + 1 < n && arr[i] == arr[i + 1])
                i++;
        }
    }

    if (!found)
        printf("None");

    printf("\n");

    return 0;
}