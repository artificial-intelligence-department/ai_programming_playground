#include <iostream>

using namespace std;

int main()
{   
    
    int N;
    int K;
    cin >> N >> K;;
    int a[N];
    for (int i=0; i<N; i++)
    {
        cin >> a[i];
    }    
    for (int k=0; k<N; k++)
    {
        for (int f=1; f<N-k; f++)
        {
            if (a[k]==a[k+f])
            {   
                for (int r = k + f; r < N - 1; r++)
                {
                    a[r] = a[r + 1];
                }
                N--;
                k--;
            }
        }
    
    }
    for( int j = 0; j < N - 1; j++)
    {
        for(int i = 0; i < N - j - 1; i++)
        {
            
            if(a[i] > a[i+1]) 
                {
                    int t = a[i];
                    a[i] = a[i+1];
                    a[i+1] = t;
                }
        }
    }
    for(int i = 0; i < K; i++)
    {
        int temp = a[0];
        for (int j = 1; j < N ; j++)
            {
                a[j-1]=a[j];
                
            }
        a[N - 1] = temp;
    }
    cout << N << endl;
    for (int b = 0; b < N; b++)
    {
        cout << a[b] << " ";
    }
    return 0;
}