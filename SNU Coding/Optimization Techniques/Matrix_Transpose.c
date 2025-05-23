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

void Matrix_Transpose(int row, int col, int c[row][col])
{
    int t[col][row];
    printf("Transposed Matrix is:-\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            t[j][i] = c[i][j];
        }
    }
    print_matrix(col, row, t);
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
    Matrix_Transpose(r, c, a);
    return 0;
}