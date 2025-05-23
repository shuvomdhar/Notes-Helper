#include <stdio.h>
#include <stdbool.h>
bool powerofTwo(int m)
{
    if (m <= 0)
    {
        printf("Please enter valid number!!");
        return false;
    }
    else
    {
        int i;
        i = m & (m - 1);
        if (i == 0)
        {
            printf("%d is the power of 2\n", m);
            return true;
        }
        else
        {
            printf("%d is not the power of 2. Please enter valid number!!\n", m);
        }
    }
}

int main()
{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    powerofTwo(n);
    return 0;
}