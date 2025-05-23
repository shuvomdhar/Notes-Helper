#include <stdio.h>

int print_matrix(int r, int c, int sum[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

int matrix_Addition(int r, int c, int a[r][c], int b[r][c])
{
    int result[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    print_matrix(r, c, result);
}

int main()
{
    int r, c;
    printf("Enter row number: ");
    scanf("%d", &r);
    printf("Enter column number: ");
    scanf("%d", &c);
    int a[r][c];
    printf("Enter elements in 1st matrix:-\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("a[%d][%d] = ",i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("1st matrix is:-\n");
    print_matrix(r, c, a);

    int b[r][c];
    printf("Enter elements in 2nd matrix:-\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("b[%d][%d] = ",i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("2nd matrix is:-\n");
    print_matrix(r, c, b);
    printf("Matrix Addition is:-\n");
    matrix_Addition(r, c, a, b);
    return 0;
}