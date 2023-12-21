#include <iostream>
using namespace std;
#define N 100

void trans(int A[N][N], int AT[N][N], int &n)
{

    cout<<"Enter the matrix size: ";
    cin>>n;

    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            cout<<"Enter the matrix element: ";
            cin>>A[i][j];

        }
    }
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            cout<<" "<<A[i][j];
            if (j == n-1)
            {
                cout<<"\n";
            }
        }
    }
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++) 
        {
            AT[j][i] = A[i][j];
        }
    }

    cout<<"\n";

    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            cout<<" "<<AT[i][j];
            if (j == n-1)
            {
                cout<<"\n";
            }
        }
    }
}

int symetric(int A[N][N], int AT[N][N], int n)
{

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) 
        {
            if (A[i][j]!=AT[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main ()
{
    int A[N][N], AT[N][N], n;
    
    trans(A, AT, n);

    if (symetric(A, AT, n))
    {
        cout<<"The matrix is symetric";
    }
    else
    {
        cout<<"The matrix isn't symetric";
    }

return 0;
}