#include <stdio.h>

int main()
{
    int a[100], b[100], c[200];
    int n, m;
    int i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter elements of first sorted array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter elements of second sorted array: ");
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    i = 0;
    j = 0;

    // Merge
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Remaining elements of first array
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    // Remaining elements of second array
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged array: ");

    for (i = 0; i < n + m; i++)
        printf("%d ", c[i]);

    return 0;
}