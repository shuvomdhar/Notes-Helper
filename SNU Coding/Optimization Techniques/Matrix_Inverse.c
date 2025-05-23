#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // This library will help us to call Time() function
#include <windows.h>

float determinant(float, float[25][25]);
void cofactor(float[25][25], float);
void transpose(float[25][25], float[25][25], float);

int main()
{
    time_t t;
    time(&t);
    printf("The program has been written on: %s", ctime(&t));
    printf("\n");
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
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    d = determinant(k, a);
    printf("Dterminant of the matrix is: %d", d);
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

// FINDING THE TRANSPOSE AND THE INVERSE
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
    // printf("\t ===========================================================================================\n");
    // printf("\t We are working on your request, please wait 5 seconds......................................\n");
    // printf("\t ===========================================================================================\n");
    // Sleep(5000);
    // system("cls");
    printf("The inverse of matrix is: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("\t %f", inverse[i][j]);
        }
        printf("\n");
    }
}