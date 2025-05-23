#include <stdio.h>
void printMatrix(int r, int c, int matrix[r][c])
{
    printf("The matrix is:-\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void setMatrix(int row, int col, int m[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j] == 0)
            {
                for (int k = 0; k < row; k++)
                {
                    m[k][j] = -1;
                }
                for (int l = 0; l < col; l++)
                {
                    m[i][l] = -1;
                }
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(m[i][j] == -1)
            {
                m[i][j] = 0;
            }
        }
    }
}

int main() 
{
    int row, col;
    printf("Enter the row number: ");
    scanf("%d",&row);
    printf("Enter the column number: ");
    scanf("%d",&col);
    int a[row][col];
    printf("Enter elements in the matrix:-\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printMatrix(row, col, a);
    setMatrix(row, col, a);
    printMatrix(row, col, a);
    return 0;
}