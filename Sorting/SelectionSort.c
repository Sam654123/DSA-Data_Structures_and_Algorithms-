#include <stdio.h>
int main()
{
    int i, j, position, swap, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < (n - 1); i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}