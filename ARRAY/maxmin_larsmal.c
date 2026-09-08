#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[100], n;
    int max, min;
    int secondMax = INT_MIN;
    int secondMin = INT_MAX;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondMax && arr[i] < max)
            secondMax = arr[i];

        if (arr[i] < secondMin && arr[i] > min)
            secondMin = arr[i];
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    if (secondMax == INT_MIN)
        printf("Second Largest does not exist\n");
    else
        printf("Second Largest: %d\n", secondMax);

    if (secondMin == INT_MAX)
        printf("Second Smallest does not exist\n");
    else
        printf("Second Smallest: %d\n", secondMin);

    return 0;
}