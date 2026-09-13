#include <stdio.h>

int main()
{
    int arr[100], prefix[100];
    int n, left, right;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Create prefix sum
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    printf("Enter left index: ");
    scanf("%d", &left);

    printf("Enter right index: ");
    scanf("%d", &right);

    int sum;

    if (left == 0)
        sum = prefix[right];
    else
        sum = prefix[right] - prefix[left - 1];

    printf("Range sum: %d\n", sum);

    return 0;
}