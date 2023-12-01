#include <iostream>

using namespace std;

int look(int array[], int size, int a)
{   
    for(int i = 0;(i<size);i++)
    {
        if(array[i]==a)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int result=0;
    int n,m;
    cin>>n;
    int narray[n];
    for(int i = 0;i<n;i++)
    {
        cin>>narray[i];
    }
    cin>>m;
    int marray[m];
    for(int i = 0;i<m;i++)
    {
        cin>>marray[i];
    }
    for(int i = 0;i<n;i++)
    {
        result += look(marray, m ,narray[i]);
    }
    cout<<result<<"\n";
    cout<<m+n-result;
}