#include <stdio.h>

int main()
{
    int arr[100], n, target;
    int found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Pair: %d %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No pair found\n");

    return 0;
}