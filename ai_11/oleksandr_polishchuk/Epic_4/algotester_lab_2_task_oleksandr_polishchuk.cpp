#include <iostream>
using namespace std;

int main()
{   int N=0;
    int a, b, c;
    cin >> N;
    int r[N];
    for (int i=0; i<N; i++)
    {
        cin>>r[i];
    }
    cin>> a >> b >>c;
    for (int i=0; i<N; i++)
        if (r[i]==a || r[i]==b || r[i]==c)
        {
            for (int k = i; k < N - 1; k++)
            {
                r[k] = r[k + 1];
            }
            N--;
            i--;
        }
    
    if (N!=0)
    {
        int S = N - 1;
        int n[S];
        
        cout<< S << endl;
        for (int i = 0; i < N; i++) 
        {
            n[i] = r[i] + r[i + 1];
        }
        
        for (int i = 0; i < S; i++)
        {
            cout << n[i] << " ";
        }
    }
    else 
    {
        cout << 0;
    }
    return 0;
}