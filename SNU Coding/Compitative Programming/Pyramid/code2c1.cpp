#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int l = 1; l <= i; l++)
        {
            cout << "*" << " ";
        }
        if (i > 1)
        {
            for (int k = 1; k <= i - 1; k++)
            {
                cout << "*" << " ";
            }
        }
        cout << " " << endl;
    }
}