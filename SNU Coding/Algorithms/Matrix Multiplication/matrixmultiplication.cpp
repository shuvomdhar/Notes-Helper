#include <stdio.h>
#include <limits.h>
int m[20][20], s[20][20];
int min = INT_MAX;
int printdimensions(int arr[], int d)
{
    for (int i = 0; i < d; i++)
    {
        printf("dim[%d]=%d\n", i, arr[i]);
    }
}

int Matrix_Multiplication(int arr[], int d)
{
    int i, j, k, n = d - 1;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 33273;
            for (k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
                if (q < min)
                {
                    min = q;
                }
            }
        }
    }
}

int display(int arr[], int d)
{
    int i, j;
    printf("The minimum value matrix is:\n");
    for (i = 1; i < d; i++)
    {
        for (j = 1; j < d; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("The cutting point matrix is:\n");
    for (i = 1; i < d; i++)
    {
        for (j = 1; j < d; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    printf("The minimum value of the matrix is %d", min);
}

int main()
{
    int arr[100], i, d;
    printf("Enter the size of the dimensions:");
    scanf("%d", &d);
    printf("Enter values in the dimensions:\n");
    for (i = 0; i < d; i++)
    {
        scanf("%d", &arr[i]);
    }
    printdimensions(arr, d);
    Matrix_Multiplication(arr, d);
    display(arr, d);
}