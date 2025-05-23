#include <stdio.h>

int print_matrix(int r, int c, int s[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

int matrix_Multiplication(int row1, int col1, int a[row1][col1], int row2, int col2, int b[row2][col2])
{
    if (col1 != row2)
    {
        printf("Matrix multiplication is not possible\n");
    }
    else
    {
        printf("Matrix Multiplication is:-\n");
        int result[row1][col2];
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < col1; k++)
                {
                    result[i][j] = (a[i][k] * b[k][j]) + result[i][j];
                }
            }
        }
        print_matrix(row1, col2, result);
    }
}

int main()
{
    int row1, col1;
    printf("Enter row number: ");
    scanf("%d", &row1);
    printf("Enter column number: ");
    scanf("%d", &col1);
    int a[row1][col1];
    printf("Enter elements in 1st matrix:-\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("a[%d][%d] = ",i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("1st matrix is:-\n");
    print_matrix(row1, col1, a);

    int row2, col2;
    printf("Enter row number: ");
    scanf("%d", &row2);
    printf("Enter column number: ");
    scanf("%d", &col2);
    int b[row2][col2];
    printf("Enter elements in 2nd matrix:-\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("b[%d][%d] = ",i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("2nd matrix is:-\n");
    print_matrix(row2, col2, b);
    matrix_Multiplication(row1, col1, a, row2, col2, b);
    return 0;
}