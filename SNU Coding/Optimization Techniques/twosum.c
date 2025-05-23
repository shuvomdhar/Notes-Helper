#include <stdio.h>
int twosum(int arr[], int n, int t)
{
    int i, j, sum;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            sum = arr[i] + arr[j];
            if (t == sum)
            {
                printf("[%d %d]", i, j);
            }
        }
    }
}

int main()
{
    int arr[50], n, i, t;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter elements in the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter a target value:");
    scanf("%d", &t);
    twosum(arr, n, t);
    return 0;
}