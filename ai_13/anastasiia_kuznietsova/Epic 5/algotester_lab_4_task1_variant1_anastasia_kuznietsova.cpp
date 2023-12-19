#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int A, B;

int main()
{
    int A, B;
    cin>>A;
    int N[A];

    for(int i=0; i<A; i++)
    {
        cin>>N[i];
    }
    cin>>B;
    int M[B];

    for(int i=0; i<B; i++)
    {
        cin>>M[i];
    }
    
    sort(N, N+A);
    sort(M, M+B);
    const int maxsize = A + B;
    int v[maxsize];

    int* a = set_difference(N, N+A, M, M+B, v);
    cout << a-v <<"\n";
    for (int* i=v; i!=a; i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    int* b=set_difference(M, M+B, N, N+A, v);
    cout << b - v << "\n";
    for (int* i=v; i!=b; i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    int* c=set_intersection(M, M+B, N, N+A, v);
    cout<<c-v<<"\n";
    for (int* i=v; i!=c; i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    int* d=set_union(M, M+B, N, N+A, v);
    cout<<d-v<<"\n";
    for (int* i=v; i!=d; i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    int* e=set_symmetric_difference(M, M+B, N, N+A, v);
    cout<<e-v <<"\n";
    for (int* i=v; i!=e; i++)
    {
        cout<<*i<<" ";
    }

return 0;
}