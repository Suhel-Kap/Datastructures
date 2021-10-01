#include<iostream>
using namespace std;
int main ()
{
    int i, j, m, n, flag = 0, A[10][10];
    cout << "Enter number of rows and columns : ";
    cin >> m >> n;
    if (m != n)
    {
        cout << "Matrix is not a square matrix!";
        exit(0);
    }
    cout << "Enter elements of matrix : ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)	
            cin >> A[i][j];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (i == j)
            {
                if (A[i][j] == 0)
                    flag = 1;
            }
            else
            {
                if (A[i][j] != 0)
                    flag = 1;
            }
    if (flag == 1)
        cout << "The given array is not a diagonal matrix.";
    else
    {
        cout << "The entered array is a diagonal matrix.\n ";	
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)	
                cout << A[i][j] << " ";
            cout << "\n ";
        }
    }
    return 0;
}
