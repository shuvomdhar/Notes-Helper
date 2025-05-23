#include <stdio.h>
void Gauss(float A[20][20], int n)
{
    int i, j, k;
    float c, x[10], sum = 0.0;
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i > j)
            {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    x[n] = A[n][n + 1] / A[n][n];
    for (i = n - 1; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }
    printf("The solution is:");
    for (i = 1; i <= n; i++)
    {
        printf("\nx%d = %f\t", i, x[i]);
    }
}

int main()
{
    int n;
    float Aug[20][20];
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements into augmented matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n + 1); j++)
        {
            printf("Aug[%d][%d] = ", i, j);
            scanf("%f", &Aug[i][j]);
        }
    }
    Gauss(Aug, n);
    return 0;
}
