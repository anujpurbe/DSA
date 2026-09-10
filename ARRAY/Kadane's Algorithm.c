#include <stdio.h>
int main()
{
    int arr[100], n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int currentSum = arr[0];
    int maxSum = arr[0];

    //  -2 1 -3 4 -1 2 1 -5 4

    for (int i = 1; i < n; i++)
    {
        if (currentSum + arr[i] < arr[i])
            currentSum = arr[i];
        else
            currentSum = currentSum + arr[i];
        if (currentSum > maxSum)
            maxSum = currentSum;
    }
    printf("Maximum subarray sum: %d\n", maxSum);
    return 0;
}