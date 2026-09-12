#include <stdio.h>

int main()
{
    int arr[100], n, target;
    int left, right;
    int found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    left = 0;
    right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            printf("Pair: %d %d\n", arr[left], arr[right]);
            found = 1;
            break;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }

    if (!found)
        printf("No pair found\n");

    return 0;
}