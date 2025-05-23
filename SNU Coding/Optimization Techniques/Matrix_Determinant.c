#include <stdio.h>

double determinant(int n, double matrix[][n]);
void displayMatrix(int n, double matrix[][n]);

int main()
{
    int n;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid input. The order of the matrix should be a positive integer.\n");
        return 1;
    }
    double matrix[n][n];
    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("\nEntered Matrix:\n");
    displayMatrix(n, matrix);
    double det = determinant(n, matrix);
    printf("\nDeterminant: %.2f\n", det);
    return 0;
}

double determinant(int n, double matrix[][n])
{
    if (n == 1)
    {
        return matrix[0][0];
    }
    double det = 0.0;
    for (int i = 0; i < n; i++)
    {
        double submatrix[n - 1][n - 1];
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k < i)
                {
                    submatrix[j - 1][k] = matrix[j][k];
                }
                else if (k > i)
                {
                    submatrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(n - 1, submatrix);
    }
    return det;
}

void displayMatrix(int n, double matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}