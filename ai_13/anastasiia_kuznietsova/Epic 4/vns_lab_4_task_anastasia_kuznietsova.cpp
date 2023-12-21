#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int N=100, n=0;


int main()
{
int a[N], value;

    cout<<"Enter the length of the array: ";
    cin>>N;

    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<N; i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }

    cout<<"\nEnter a value you want to delete: ";
    cin>>value;

    for (int i=0; i<N; i++)
    {
        if (a[i]!=value)
        {
            a[n]=a[i];
            n++;
        }
    }

    for (int i=n-1; i>0; i--)
    {
        if (a[i]%2==0)
        {
            for (int j = n; j > i; j--) 
            {
                a[j] = a[j - 1];
            }
            a[i] = 0;
            n++;
        }
    }

    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

return 0;
}