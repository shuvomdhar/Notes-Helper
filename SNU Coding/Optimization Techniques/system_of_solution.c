#include <stdio.h>
#include <math.h>

float determinant(float, float[25][25]);
void cofactor(float[25][25], float);
void transpose(float[25][25], float[25][25], float);
void columnMatrix(float l, float inv[25][25]);
void printMatrix(float o, float m[25][25]);
void matrixMultiplication(float z, float inv[25][25], float col[25][25]);

int main()
{
    printf("INVERSE OF A MATRIX N × N USING C LANGUAGE\n");
    float a[25][25], k, d;
    int i, j;
    printf("Enter the order of the matrix: ");
    scanf("%f", &k);
    printf("Enter the elements in your matrix %.0f × %.0f \n", k, k);
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("a[%d][%d] = ",i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }
    d = determinant(k, a);
    if (d == 0)
    {
        printf("The inverse your matrix is not possible\n");
    }
    else
    {
        cofactor(a, k);
    }
    return 0;
}

float determinant(float n, float matrix[25][25])
{
    if (n == 1)
    {
        return matrix[0][0];
    }
    float det = 0.0;
    for (int i = 0; i < n; i++)
    {
        float submatrix[25][25];
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
    return (det);
}

void cofactor(float num[25][25], float f)
{
    float b[25][25], fac[25][25];
    int p, q, m, n, i, j;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                        {
                            n++;
                        }
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(f - 1, b);
        }
    }
    transpose(num, fac, f);
}

void transpose(float num[25][25], float fac[25][25], float r)
{
    int i, j;
    float b[25][25], inverse[25][25], d;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant(r, num);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            inverse[i][j] = b[i][j] / d;
        }
    }
    printf("The inverse of matrix is: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("\t %f", inverse[i][j]);
        }
        printf("\n");
    }
    columnMatrix(r, inverse);
}

void columnMatrix(float l, float inv[25][25])
{
    printf("Enter values in the column matrix:-\n");
    float col[25][25];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("col[%d][%d] = ",i+1, j+1);
            scanf("%f",&col[i][j]);
        }   
    }

    float sys[25][25];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            sys[i][j] = 0;
        }
    }
    matrixMultiplication(l, inv, col);
}

void matrixMultiplication(float z, float inv[25][25], float col[25][25])
{
    float sys[25][25];
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            sys[i][j] = 0;
        }
    }
    
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < z; k++)
            {
                sys[i][j] = (inv[i][k] * col[k][j]) + sys[i][j];
            }
        }
    }
    printf("system of linear equation is:-\n");
    printMatrix(z, sys);
}

void printMatrix(float o, float m[25][25])
{
    for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%f", m[i][j]);
        }
        printf("\n");
    }
}